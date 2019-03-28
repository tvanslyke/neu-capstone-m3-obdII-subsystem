#ifndef M3_PORT_MUTEX_H
#define M3_PORT_MUTEX_H

#include "freertos/portmacro.h"
#include <mutex>

namespace m3 {

struct PortMutex {
	PortMutex() = default;

	PortMutex(const PortMutex&) = default;
	PortMutex(PortMutex&&) = default;

	PortMutex& operator=(const PortMutex&) = default;
	PortMutex& operator=(PortMutex&&) = default;

	void lock() {
		portENTER_CRITICAL(&m);
	}

	void unlock() {
		portEXIT_CRITICAL(&m);
	}

private:
	portMUX_TYPE m = portMUX_INITIALIZER_UNLOCKED;
};


} /* namespace m3 */

#endif /* M3_PORT_MUTEX_H */
