#ifndef M3_SINK_ITERATOR_H
#define M3_SINK_ITERATOR_H

namespace m3 {

template <class Sink>
struct SinkIterator {

	struct reference {
		reference() = delete;
		reference(const reference&) = default;
		reference(reference&&) = default;
		reference& operator=(const reference&) = delete;
		reference& operator=(reference&&) = delete;

		reference(Sink& s):
			sink_(s)
		{
			
		}

		template <
			class T,
			std::enable_if_t<
				std::is_invocable_v<Sink&, T&&>,
				bool
			> = false
		>
		reference& operator=(T&& v) {
			sink_(std::forward<T>(v));
			return *this;
		}

	private:
		Sink& sink_;
	};

	using value_type        = void;
	using difference_type   = void;
	using pointer           = void;
	using iterator_category = std::output_iterator_tag;
	
	SinkIterator() = default;
	SinkIterator(const SinkIterator&) = default;
	SinkIterator(SinkIterator&&) = default;

	SinkIterator& operator=(const SinkIterator&) = default;
	SinkIterator& operator=(SinkIterator&&) = default;

	constexpr SinkIterator(const Sink& s):
		sink_(s)
	{
		
	}

	constexpr SinkIterator(Sink&& s):
		sink_(std::move(s))
	{
		
	}

	constexpr SinkIterator& operator++() { return *this; }
	constexpr SinkIterator operator++(int) { return *this; }

	constexpr reference operator*() { return {sink_}; }

private:
	Sink sink_;
};

template <class T>
SinkIterator(T) -> SinkIterator<T>;

} /* namespace m3 */

#endif /* M3_SINK_ITERATOR_H */
