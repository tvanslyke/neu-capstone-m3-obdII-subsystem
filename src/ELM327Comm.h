#ifndef M3_ELM327_COMM_H
#define M3_ELM327_COMM_H

#include "ArduinoFix.h"
#include <string_view>
#include <climits>
#include <array>
#include <cstring>
#include <SPI.h>
#include "PortMutex.h"

#define PIN_LINK_SPI_CS 2
#define PIN_LINK_SPI_READY 13
#define SPI_FREQ 1000000

namespace m3 {

template <std::size_t N>
constexpr std::uint_least64_t encode_str(const char (&cmd)[N]) {
	static_assert(N <= 9u, "Command name too long.");
	static_assert(CHAR_BIT == 8u);
	std::uint_least64_t encoding = 0u;
	for(int i = (N - 1u); i >= 0; --i) {
		encoding <<= 8u;
		encoding |= static_cast<unsigned char>(cmd[i]);
	}
	return encoding;
}

constexpr std::array<char, 9u> decode_str(std::uint_least64_t encoding) {
	std::array<char, 9u> str = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	for(char& c: str) {
		if(not encoding) {
			break;
		}
		c = static_cast<unsigned char>(encoding & 0xFFu);
		encoding >>= 8u;
	}
	return str;
}


enum class ELM327_AT_CMD: std::uint_least64_t {
	RepeatLast                   = encode_str("\r"),
	TryBaudRateDivisor           = encode_str("BRD"),
	SetBaudRateTimeout           = encode_str("BRT"),
	SetAllToDefaults             = encode_str("D"),
	EchoOff                      = encode_str("E0"),
	EchoOn                       = encode_str("E1"),
	ForgetEvents                 = encode_str("FE"),
	PrintVersionID               = encode_str("I"),
	LinefeedsOff                 = encode_str("L0"),
	LinefeedsOn                  = encode_str("L1"),
	LowPowerMode                 = encode_str("LP"),
	MemoryOff                    = encode_str("M0"),
	MemoryOn                     = encode_str("M1"),
	ReadStoredData               = encode_str("RD"),
	WarmStart                    = encode_str("WS"),
	ResetAll                     = encode_str("Z"),
	DisplayDeviceDescription     = encode_str("@1"),
	DisplayDeviceIdendifier      = encode_str("@2"),
	StoreDeviceIdenfitier        = encode_str("@3"),
	ProgParam                    = encode_str("PP"),
	ProgParamSummary             = encode_str("PPS"),
	CalibrateVoltage             = encode_str("CV"),
	CalibrateVoltageDefault      = encode_str("CV 0000"),
	ReadInputVoltage             = encode_str("RV"),
	ReadIgnMonInputLevel         = encode_str("IGN"),
	AllowLongMessages            = encode_str("AL"),
	DisplayActivityMonitorCount  = encode_str("AMC"),
	SetActivityMonitorTimeout    = encode_str("AMT"),
	AutomaticallyReceive         = encode_str("AR"),
	AdaptiveTimingOff            = encode_str("AT0"),
	AdaptiveTimingAuto1          = encode_str("AT1"),
	AdaptiveTimingAuto2          = encode_str("AT2"),
	BufferDump                   = encode_str("BD"),
	BypassInitSequence           = encode_str("BI"),
	DescribeCurrentProtocol      = encode_str("DP"),
	DescribeProtocolByNumber     = encode_str("DPN"),
	HeadersOff                   = encode_str("H0"),
	HeadersOn                    = encode_str("H1"),
	MonitorAll                   = encode_str("MA"),
	MonitorReceiver              = encode_str("MR"),
	MonitorTransmitter           = encode_str("MT"),
	NormalLengthMessages         = encode_str("NL"),
	ProtocolClose                = encode_str("PC"),
	ResponsesOff                 = encode_str("R0"),
	ResponsesOn                  = encode_str("R1"),
	SetReceiveAddr               = encode_str("RA"),
	PrintSpacesOff               = encode_str("S0"),
	PrintSpacesOn                = encode_str("S1"),
	SetHeader                    = encode_str("SH"),
	SetProtocol                  = encode_str("SP"),
	EraseStoredProtocol          = encode_str("SP 00"),
	AutoProtocol                 = encode_str("SP A"),
	UseStandardSearchOrder       = encode_str("SS"),
	SetTimeout                   = encode_str("ST"),
	SetTesterAddr                = encode_str("TA"),
	TryProtocol                  = encode_str("TP"),
	TryProtocolAutoSearch        = encode_str("TP A"),
	IFROff                       = encode_str("IFR0"),
	IFRAuto                      = encode_str("IFR1"),
	IFROn                        = encode_str("IFR2"),
	IFRValueFromHeader           = encode_str("IFR H"),
	FastInit                     = encode_str("FI"),
	SetISOBaudRateTo10400        = encode_str("IB 10"),
	SetISOBaudRateTo4800         = encode_str("IB 48"),
	SetISOBaudRateTo9600         = encode_str("IB 96"),
	SetISOSlowInitAddr           = encode_str("IIA"),
	DisplayKeyWords              = encode_str("KW"),
	KeyWordCheckingOff           = encode_str("KW0"),
	KeyWordCheckingOn            = encode_str("KW1"),
	SlowInit                     = encode_str("SI"),
	SetWakeupInterval            = encode_str("SW"),
	StopSendingWakeupMessages    = encode_str("SW 00"),
	SetWakeupMessage             = encode_str("WM"),
	DisableCANExtendedAddressing = encode_str("CEA"),
	UseCANExtendedAddress        = encode_str("CEA"),
	AutomaticFormattingOff       = encode_str("CAF0"),
	AutomaticFormattingOn        = encode_str("CAF1"),
	SetIdFilter                  = encode_str("CF"),
	FlowControlsOff              = encode_str("CFC0"),
	FlowControlsOn               = encode_str("CFC1"),
	SetIdMask                    = encode_str("CM"),
	SetCANPriority               = encode_str("CP"),
	ResetRecevieAddressFilters   = encode_str("CRA"),
	ShowCANStatusCounts          = encode_str("CS"),
	SilentMonitoringOff          = encode_str("CSM0"),
	SilentMonitoringOn           = encode_str("CSM1"),
	SetTimerMultiplierTo1        = encode_str("CTM1"),
	SetTimerMultiplierTo5        = encode_str("CTM5"),
	DisplayDLCOff                = encode_str("D0"),
	DisplayDLCOn                 = encode_str("D1"),
	FlowControlSetMode           = encode_str("FC SM"),
	FlowControlSetHeader         = encode_str("FC SH"),
	FlowControlSetData           = encode_str("FC SD"),
	ProtocolBOptionsAndBaudRate  = encode_str("PB"),
	SendRTRMessage               = encode_str("RTR"),
	VariableDLCOff               = encode_str("V0"),
	VariableDLCOn                = encode_str("V1"),
	MontiroForDM1Messages        = encode_str("DM1"),
	UseJ1939ElmDataFormat        = encode_str("JE"),
	HeaderFormattingOff          = encode_str("JFH0"),
	HeaderFormattingOn           = encode_str("JFH1"),
	UseJ1939SAEDataFormat        = encode_str("JS"),
	MonitorPGN                   = encode_str("MP"),
};

constexpr std::array<char, 9u> at_command_string(ELM327_AT_CMD cmd) {
	return decode_str(static_cast<std::uint_least64_t>(cmd));
}


inline bool spi_is_ready() {
	return digitalRead(PIN_LINK_SPI_READY) == LOW;
}

inline bool spi_is_done() {
	return digitalRead(PIN_LINK_SPI_READY) == HIGH;
}

inline void wait_for_spi_done() {
	if(not spi_is_done()) {
		do {
			delay(1);
		} while(not spi_is_done());
	}
}

inline void wait_for_spi_ready() {
	if(not spi_is_ready()) {
		do {
			delay(1);
		} while(not spi_is_ready());
	}
}


struct ScopedSPITransaction {
	void lock() const {
		wait_for_spi_ready();
	}

	void unlock() const {
		wait_for_spi_done();
	}

};

template <auto PinNum>
struct ScopedLowPin {
	void lock() const {
                digitalWrite(PinNum, LOW);
	}

	void unlock() const {
                digitalWrite(PinNum, HIGH);
	}

};


struct ELM327Comm {
	static constexpr std::string_view prompt_str = ">";
	static constexpr std::string_view newline_str = "\r";
	static constexpr std::string_view error_str = "?";
	static constexpr std::string_view ok_str = "OK";
	static constexpr std::string_view reset_command = "ATZ";

	
	ELM327Comm() = default;

	

	static void send_raw_command(std::string_view cmd) {
		char header[] = "$OBD";
		char carriage_return = '\r';
		char tail = '\x1B';
		PortMutex port_mux;
		ScopedLowPin<PIN_LINK_SPI_CS> link_pin;
		{
			auto lock_mux = std::lock_guard(port_mux);
			auto hold_low = std::lock_guard(link_pin);
			delay(1);
			SPI.writeBytes(reinterpret_cast<std::uint8_t*>(header), 4u);
			std::uint8_t buff[64u];
			while(cmd.size() >= sizeof(buff)) {
				std::memcpy(buff, cmd.data(), sizeof(buff));
				SPI.writeBytes(buff, sizeof(buff));
				cmd.remove_prefix(sizeof(buff));
			}
			std::memcpy(buff, cmd.data(), cmd.size());
			SPI.writeBytes(buff, cmd.size());
			SPI.writeBytes(reinterpret_cast<std::uint8_t*>(&carriage_return), 1);
			SPI.writeBytes(reinterpret_cast<std::uint8_t*>(&tail), 1);
			delay(1);
		}
	}

	template <class DestIt>
	static void receive_command_response(DestIt dest) {
		constexpr char header[] = "$OBD";
		const char* header_pos = header;
		PortMutex port_mux;
		ScopedLowPin<PIN_LINK_SPI_CS> link_pin;
		ScopedSPITransaction trans;
		auto transaction_lock = std::lock_guard(trans);
		for(bool done = false; not done; not done ? wait_for_spi_ready() : (void)0) {
			auto hold_mux = std::lock_guard(port_mux);
			auto hold_low = std::lock_guard(link_pin);
			while(spi_is_ready()) {
				char c = SPI.transfer(' ');
				if(c == '\0' && c == '\xFF') {
					continue;
				}
				if(!done) {
					done = (c == '\x09');
				}
				if(done) {
					continue;
				}
				if(*header_pos != '\0') {
					if(*header_pos == c) {
						++header_pos;
					} else {
						dest = std::copy(header, header_pos, dest);
						*dest++ = c;
						header_pos = header;
					}
				} else {
					*dest++ = c;
				}
			}
		}
	}

	static void initialize_spi() {
		pinMode(PIN_LINK_SPI_READY, INPUT);
		pinMode(PIN_LINK_SPI_CS, OUTPUT);
		digitalWrite(PIN_LINK_SPI_CS, HIGH);
		SPI.begin();
		SPI.setFrequency(1000000);
	}
private:
};


} /* namespace m3 */

#endif /* M3_ELM327_COMM_H */
