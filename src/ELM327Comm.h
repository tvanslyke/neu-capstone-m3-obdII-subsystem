#ifndef M3_ELM327_COMM_H
#define M3_ELM327_COMM_H

#include <string_view>
#include <climits>
#include <SPI.h>

namespace m3 {


namespace spi {

char spi_receive_byte() {
	
}

} /* namespace spi */

template <std::size_t N>
constexpr std::uint_least64_t encode_str(const char (&cmd)[N]) {
	static_assert(N <= 9u, "Command name too long.");
	static_assert(CHAR_BIT == 8u);
	std::uint_least64_t encoding = 0u;
	for(int i = (N - 1u); i >= 0; --i) {
		encoding <<= 8u;
		encoding |= static_cast<unsigned char>(cmd[i]);
	}
	return encoding
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

enum class ELM327_OBD_CMD: std::uint_least64_t {

};


struct ELM327Comm {
	static constexpr std::string_view prompt_str = ">";
	static constexpr std::string_view newline_str = "\r";
	static constexpr std::string_view error_str = "?";
	static constexpr std::string_view ok_str = "OK";
	static constexpr std::string_view reset_command = "ATZ";

	
	ELM327Comm() = default;

	
};


} /* namespace m3 */

#endif /* M3_ELM327_COMM_H */
