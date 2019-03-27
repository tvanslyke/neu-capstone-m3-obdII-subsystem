#ifndef M3_OBD_PID_H
#define M3_OBD_PID_H

#include <cstdint>
#include <bitset>
#include <units.h>

namespace m3::obd {

enum class PID: unsigned char {
	SupportedPids0                                                      = 0x0,
	MonitorStatusSinceDTCCleared                                        = 0x1,
	FreezeDTC                                                           = 0x2,
	FuelSystemStatus                                                    = 0x3,
	CalculatedEngineLoad                                                = 0x4,
	EngineCoolantTemperature                                            = 0x5,
	ShortTermFuelTrimBank1                                              = 0x6,
	LongTermFuelTrimBank1                                               = 0x7,
	ShortTermFuelTrimBank2                                              = 0x8,
	LongTermFuelTrimBank2                                               = 0x9,
	FuelPressure                                                        = 0x0A,
	IntakeManifoldAbsolutePressure                                      = 0x0B,
	EngineRPM                                                           = 0x0C,
	VehicleSpeed                                                        = 0x0D,
	TimingAdvance                                                       = 0x0E,
	IntakeAirTemperature                                                = 0x0F,
	MAFAirFlowRate                                                      = 0x10,
	ThrottlePosition                                                    = 0x11,
	CommandedSecondaryAirStatus                                         = 0x12,
	OxygenSensorsPresent2Banks                                          = 0x13,
	OxygenSensor1VoltageAndShortTermFuelTrim                            = 0x14,
	OxygenSensor2VoltageAndShortTermFuelTrim                            = 0x15,
	OxygenSensor3VoltageAndShortTermFuelTrim                            = 0x16,
	OxygenSensor4VoltageAndShortTermFuelTrim                            = 0x17,
	OxygenSensor5VoltageAndShortTermFuelTrim                            = 0x18,
	OxygenSensor6VoltageAndShortTermFuelTrim                            = 0x19,
	OxygenSensor7VoltageAndShortTermFuelTrim                            = 0x1A,
	OxygenSensor8VoltageAndShortTermFuelTrim                            = 0x1B,
	SupportedOBDStandards                                               = 0x1C,
	OxygenSensorsPresent4Banks                                          = 0x1D,
	AuxiliaryInputStatus                                                = 0x1E,
	RunTimeSinceEngineStart                                             = 0x1F,
	SupportedPids1                                                      = 0x20,
	DistanceTraveledWithMIL                                             = 0x21,
	FuelRailPressure                                                    = 0x22,
	FuelRailGaugePressure                                               = 0x23,
	OxygenSensor1FuelAirEquivalenceRatioAndVoltage                      = 0x24,
	OxygenSensor2FuelAirEquivalenceRatioAndVoltage                      = 0x25,
	OxygenSensor3FuelAirEquivalenceRatioAndVoltage                      = 0x26,
	OxygenSensor4FuelAirEquivalenceRatioAndVoltage                      = 0x27,
	OxygenSensor5FuelAirEquivalenceRatioAndVoltage                      = 0x28,
	OxygenSensor6FuelAirEquivalenceRatioAndVoltage                      = 0x29,
	OxygenSensor7FuelAirEquivalenceRatioAndVoltage                      = 0x2A,
	OxygenSensor8FuelAirEquivalenceRatioAndVoltage                      = 0x2B,
	CommandedEGR                                                        = 0x2C,
	EGRError                                                            = 0x2D,
	CommandedEvaporativePurge                                           = 0x2E,
	FuelTankLevelInput                                                  = 0x2F,
	WarmUpsSinceCodesCleared                                            = 0x30,
	DistanceTraveledSinceCodesCleared                                   = 0x31,
	EvapSystemVaporPressure                                             = 0x32,
	AbsoluteBarometricPressure                                          = 0x33,
	OxygenSensor1FuelAirEquivalenceRatioAndCurrent                      = 0x34,
	OxygenSensor2FuelAirEquivalenceRatioAndCurrent                      = 0x35,
	OxygenSensor3FuelAirEquivalenceRatioAndCurrent                      = 0x36,
	OxygenSensor4FuelAirEquivalenceRatioAndCurrent                      = 0x37,
	OxygenSensor5FuelAirEquivalenceRatioAndCurrent                      = 0x38,
	OxygenSensor6FuelAirEquivalenceRatioAndCurrent                      = 0x39,
	OxygenSensor7FuelAirEquivalenceRatioAndCurrent                      = 0x3A,
	OxygenSensor8FuelAirEquivalenceRatioAndCurrent                      = 0x3B,
	CatalystTemperatureBank1Sensor1                                     = 0x3C,
	CatalystTemperatureBank2Sensor1                                     = 0x3D,
	CatalystTemperatureBank1Sensor2                                     = 0x3E,
	CatalystTemperatureBank2Sensor2                                     = 0x3F,
	SupportedPids2                                                      = 0x40,
	MonitorStatusThisDriveCycle                                         = 0x41,
	ControlModuleVoltage                                                = 0x42,
	AbsoluteLoadValue                                                   = 0x43,
	FuelAirCommandedEquivalenceRatio                                    = 0x44,
	RelativeThrottlePosition                                            = 0x45,
	AmbientAirTemperature                                               = 0x46,
	AbsoluteThrottlePositionB                                           = 0x47,
	AbsoluteThrottlePositionC                                           = 0x48,
	AcceleratorPedalPositionD                                           = 0x49,
	AcceleratorPedalPositionE                                           = 0x4A,
	AcceleratorPedalPositionF                                           = 0x4B,
	CommandedThrottleActuator                                           = 0x4C,
	TimeRunWithMIL                                                      = 0x4D,
	TimeSinceTroubleCodesCleared                                        = 0x4E,
	MaximumSensorValues                                                 = 0x4F,
	MaximumAirFlowRate                                                  = 0x50,
	FuelType                                                            = 0x51,
	EthanolFuelPercentage                                               = 0x52,
	AbsoluteEvapSystemVaporPressure                                     = 0x53,
	EvapSystemVaporPressure                                             = 0x54,
	ShortTermSecondaryOxygenSensorTrimBanks1And3                        = 0x55,
	LongTermSecondaryOxygenSensorTrimBanks1And3                         = 0x56,
	ShortTermSecondaryOxygenSensorTrimBanks2And4                        = 0x57,
	LongTermSecondaryOxygenSensorTrimBanks2And4                         = 0x58,
	FuelRailAbsolutePressure                                            = 0x59,
	RelativeAcceleratorPedalPosition                                    = 0x5A,
	HybridBatteryPackRemainingLife                                      = 0x5B,
	EngineOilTemperature                                                = 0x5C,
	FuelInjectionTiming                                                 = 0x5D,
	EngineFuelRate                                                      = 0x5E,
	EmissionRequirements                                                = 0x5F,
	SupportedPids3                                                      = 0x60,
	DemandedPercentTorque                                               = 0x61,
	ActualPercentTorque                                                 = 0x62,
	ReferenceTorque                                                     = 0x63,
	EnginePercentTorqueData                                             = 0x64,
	AuxiliaryInputOutputSupported                                       = 0x65,
	MassAirFlowSensor                                                   = 0x66,
	EngineCoolantTemperature                                            = 0x67,
	IntakeAirTemperatureSensor                                          = 0x68,
	CommandedEGRAndEGRError                                             = 0x69,
	CommandedDieselIntakeAirFlowControlAndRelativeIntakeAirFlowPosition = 0x6A,
	ExhaustGasRecirculationTemperature                                  = 0x6B,
	CommandedThrottleActuatorControlAndRelativeThrottlePosition         = 0x6C,
	FuelPressureControlSystem                                           = 0x6D,
	InjectionPressureControlSystem                                      = 0x6E,
	TurbochargerCompressorInletPressure                                 = 0x6F,
	BoostPressureControl                                                = 0x70,
	VariableGeometryTurboControl                                        = 0x71,
	WastegateControl                                                    = 0x72,
	ExhaustPressure                                                     = 0x73,
	TurbochargerRPM                                                     = 0x74,
	TurbochargerTemperature                                             = 0x75,
	TurbochargerTemperature                                             = 0x76,
	ChargeAirCoolerTemperature                                          = 0x77,
	ExhaustGasTemperatureBank1                                          = 0x78,
	ExhaustGasTemperatureBank2                                          = 0x79,
	DieselParticulateFilter1                                            = 0x7A,
	DieselParticulateFilter2                                            = 0x7B,
	DieselParticulateFilterTemperature                                  = 0x7C,
	NOxNTEControlAreaStatus                                             = 0x7D,
	PMNTEControlAreaStatus                                              = 0x7E,
	EngineRunTime                                                       = 0x7F,
	SupportedPids4                                                      = 0x80,
	EngineRunTimeAECD1                                                  = 0x81,
	EngineRunTimeAECD2                                                  = 0x82,
	NOxSensor                                                           = 0x83,
	ManifoldSurfaceTemperature                                          = 0x84,
	NOxReagentSystem                                                    = 0x85,
	ParticulateMatterSensor                                             = 0x86,
	IntakeManifoldAbsolutePressure                                      = 0x87,
	SCRInduceSystem                                                     = 0x88,
	AECDRunTime11_15                                                    = 0x89,
	AECDRunTime16_20                                                    = 0x8A,
	DieselAftertreatment                                                = 0x8B,
	O2Sensor                                                            = 0x8C,
	ThrottlePositionG                                                   = 0x8D,
	EngineFrictionPercentTorque                                         = 0x8E,
	PMSensorBank1And2                                                   = 0x8F,
	WWH_OBDVehicleOBDSystemInformation1                                 = 0x90,
	WWH_OBDVehicleOBDSystemInformation2                                 = 0x91,
	FuelSystemControl                                                   = 0x92,
	WWH_OBDVehicleOBDCountersSupport                                    = 0x93,
	NOxWarningAndInducementSystem                                       = 0x94,
	ExhaustGasTemperatureSensor1                                        = 0x98,
	ExhaustGasTemperatureSensor2                                        = 0x99,
	HybridEVVehicleSystemData                                           = 0x9A,
	DieselExhaustFluidSensorData                                        = 0x9B,
	O2SensorData                                                        = 0x9C,
	EngineFuelRate                                                      = 0x9D,
	EngineExhaustFlowRate                                               = 0x9E,
	FuelSystemPercentageUse                                             = 0x9F,
	SupportedPids5                                                      = 0xA0,
	NOxSensorCorrectedData                                              = 0xA1,
	CylinderFuelRate                                                    = 0xA2,
	EvapSystemVaporPressure                                             = 0xA3,
	TransmissionActualGear                                              = 0xA4,
	DieselExhaustFluidDosing                                            = 0xA5,
	Odometer                                                            = 0xA6,
	SupportedPids6                                                      = 0xC0
};

constexpr PID pid_from_code(unsigned char code) {
	return static_cast<PID>(code);
}

using namespace units::literals;

constexpr auto decode_percentage(unsigned char value) noexcept
	-> units::dimensionless::scalar_t
{
	return (100 * units::dimensionless::scalar_t(value)) / 255;
}

constexpr auto decode_signed_percentage(unsigned char value) noexcept
	-> units::dimensionless::scalar_t
{
	return units::dimensionless::scalar_t((100.0 * value) / 128 - 100);
}

template <PID Pid>
struct pid_unit_traits {
	using type = void;
};

template <>
struct pid_unit_traits<PID::CalculatedEngineLoad> {
	using type = units::dimensionless::scalar_t;
	static constexpr type minm = 0;
	static constexpr type maxm = 100;

	static constexpr type decode(unsigned char A) noexcept {
		return decode_percentage(A);
	}
};

template <>
struct pid_unit_traits<PID::EngineCoolantTemperature> {
	using type = units::temperature::celsius_t;
	static constexpr type minm = -40;
	static constexpr type maxm = 215;

	static constexpr type decode(unsigned char A) noexcept {
		return type(static_cast<signed>(A) - 40);
	}
};

template <>
struct pid_unit_traits<PID::ShortTermFuelTrimBank1> {
	using type = units::dimensionless::scalar_t;
	static constexpr type minm = -100;
	static constexpr type maxm = 99.2;

	static constexpr type decode(unsigned char A) noexcept {
		return decode_signed_percentage(A);
	}
};

template <>
struct pid_unit_traits<PID::ShortTermFuelTrimBank2> {
	using type = units::dimensionless::scalar_t;
	static constexpr type minm = -100;
	static constexpr type maxm = 99.2;

	static constexpr type decode(unsigned char A) noexcept {
		return decode_signed_percentage(A);
	}
};

template <>
struct pid_unit_traits<PID::LongTermFuelTrimBank1> {
	using type = units::dimensionless::scalar_t;
	static constexpr type minm = -100;
	static constexpr type maxm = 99.2;

	static constexpr type decode(unsigned char A) noexcept {
		return decode_signed_percentage(A);
	}
};

template <>
struct pid_unit_traits<PID::LongTermFuelTrimBank2> {
	using type = units::dimensionless::scalar_t;
	static constexpr type minm = -100;
	static constexpr type maxm = 99.2;

	static constexpr type decode(unsigned char A) noexcept {
		return decode_signed_percentage(A);
	}
};

template <>
struct pid_unit_traits<PID::FuelPressure> {
	using type = units::kilo<units::pressure::pascal>;
	static constexpr type minm = 0;
	static constexpr type maxm = 765;

	static constexpr type decode(unsigned char A) noexcept {
		return 3 * type(A);
	}
};

template <>
struct pid_unit_traits<PID::IntakeManifoldAbsolutePressure> {
	using type = units::kilo<units::pressure::pascal>;
	static constexpr type minm = 0;
	static constexpr type maxm = 255;

	static constexpr type decode(unsigned char A) noexcept {
		return type(A);
	}
};

template <>
struct pid_unit_traits<PID::EngineRPM> {
	using type = units::angular_velocity::revolutions_per_minute_t;
	static constexpr type minm = 0;
	static constexpr type maxm = 16383.75;

	static constexpr type decode(unsigned char A, unsigned char B) noexcept {
		return (256.0 * A + B) / 4.0;
	}
};

template <>
struct pid_unit_traits<PID::VehicleSpeed> {
	using type = units::velocity::kilometers_per_hour_t;
	static constexpr type minm = 0;
	static constexpr type maxm = 255;

	static constexpr type decode(unsigned char A) noexcept {
		return static_cast<type>(A);
	}
};

template <>
struct pid_unit_traits<PID::TimingAdvance> {
	using type = units::angle::degree_t;
	static constexpr type minm = -64;
	static constexpr type maxm = 63.5;

	static constexpr type decode(unsigned char A) noexcept {
		return A / 2.0 - 65_deg;
	}
};

template <>
struct pid_unit_traits<PID::IntakeAirTemperature> {
	using type = units::temperature::celsius_t;
	static constexpr type minm = -40;
	static constexpr type maxm = 215;

	static constexpr type decode(unsigned char A) noexcept {
		return A / 2.0 - 65_deg;
	}
};

template <>
struct pid_unit_traits<PID::MAFAirFlowRate> {
	using type = units::compound_unit<
		units::mass::gram_t,
		units::inverse<units::time::second_t>
	>;
	static constexpr type minm = 0;
	static constexpr type maxm = 655.35;

	static constexpr type decode(unsigned char A, unsigned char B) noexcept {
		return (256.0 * type(A) + type(B)) / 100.0;
	}
};

template <>
struct pid_unit_traits<PID::ThrottlePosition> {
	using type = units::dimensionless::scalar_t;
	static constexpr type minm = 0;
	static constexpr type maxm = 100;

	static constexpr type decode(unsigned char A) noexcept {
		return decode_percentage(A);
	}
};

template <>
struct pid_unit_traits<PID::OxygenSensor1VoltageAndShortTermFuelTrim> {
	using type = std::pair<
		units::voltage::volts_t,
		units::dimensionless::scalar_t
	>;
	static constexpr type minm = type{0, -100};
	static constexpr type maxm = type{1.275, 99.2};

	static constexpr type decode(unsigned char A, unsigned char B) noexcept {
		return type{A / 200.0, decode_signed_percentage(B)};
	}
};

template <>
struct pid_unit_traits<PID::OxygenSensor2VoltageAndShortTermFuelTrim> {
	using type = std::pair<
		units::voltage::volts_t,
		units::dimensionless::scalar_t
	>;
	static constexpr type minm = type{0, -100};
	static constexpr type maxm = type{1.275, 99.2};

	static constexpr type decode(unsigned char A, unsigned char B) noexcept {
		return type{A / 200.0, decode_signed_percentage(B)};
	}
};

template <>
struct pid_unit_traits<PID::OxygenSensor3VoltageAndShortTermFuelTrim> {
	using type = std::pair<
		units::voltage::volts_t,
		units::dimensionless::scalar_t
	>;
	static constexpr type minm = type{0, -100};
	static constexpr type maxm = type{1.275, 99.2};

	static constexpr type decode(unsigned char A, unsigned char B) noexcept {
		return type{A / 200.0, decode_signed_percentage(B)};
	}
};

template <>
struct pid_unit_traits<PID::OxygenSensor4VoltageAndShortTermFuelTrim> {
	using type = std::pair<
		units::voltage::volts_t,
		units::dimensionless::scalar_t
	>;
	static constexpr type minm = type{0, -100};
	static constexpr type maxm = type{1.275, 99.2};

	static constexpr type decode(unsigned char A, unsigned char B) noexcept {
		return type{A / 200.0, decode_signed_percentage(B)};
	}
};

template <>
struct pid_unit_traits<PID::OxygenSensor5VoltageAndShortTermFuelTrim> {
	using type = std::pair<
		units::voltage::volts_t,
		units::dimensionless::scalar_t
	>;
	static constexpr type minm = type{0, -100};
	static constexpr type maxm = type{1.275, 99.2};

	static constexpr type decode(unsigned char A, unsigned char B) noexcept {
		return type{A / 200.0, decode_signed_percentage(B)};
	}
};

template <>
struct pid_unit_traits<PID::OxygenSensor6VoltageAndShortTermFuelTrim> {
	using type = std::pair<
		units::voltage::volts_t,
		units::dimensionless::scalar_t
	>;
	static constexpr type minm = type{0, -100};
	static constexpr type maxm = type{1.275, 99.2};

	static constexpr type decode(unsigned char A, unsigned char B) noexcept {
		return type{A / 200.0, decode_signed_percentage(B)};
	}
};

template <>
struct pid_unit_traits<PID::OxygenSensor7VoltageAndShortTermFuelTrim> {
	using type = std::pair<
		units::voltage::volts_t,
		units::dimensionless::scalar_t
	>;
	static constexpr type minm = type{0, -100};
	static constexpr type maxm = type{1.275, 99.2};

	static constexpr type decode(unsigned char A, unsigned char B) noexcept {
		return type{A / 200.0, decode_signed_percentage(B)};
	}
};

template <>
struct pid_unit_traits<PID::OxygenSensor8VoltageAndShortTermFuelTrim> {
	using type = std::pair<
		units::voltage::volts_t,
		units::dimensionless::scalar_t
	>;
	static constexpr type minm = type{0, -100};
	static constexpr type maxm = type{1.275, 99.2};

	static constexpr type decode(unsigned char A, unsigned char B) noexcept {
		return type{A / 200.0, decode_signed_percentage(B)};
	}
};

template <>
struct pid_unit_traits<PID::RunTimeSinceEngineStart> {
	using type = units::time::second_t;
	static constexpr type minm = 0;
	static constexpr type maxm = 65535;

	static constexpr type decode(unsigned char A, unsigned char B) noexcept {
		return 256u * A + B;
	}
};

template <>
struct pid_unit_traits<PID::DistanceTraveledWithMIL> {
	using type = units::kilo<units::distance::meter_t>;
	static constexpr type minm = 0;
	static constexpr type maxm = 65535;

	static constexpr type decode(unsigned char A, unsigned char B) noexcept {
		return 256u * A + B;
	}
};

template <>
struct pid_unit_traits<PID::FuelRailPressure> {
	using type = units::kilo<units::pressure::pascal_t>;
	static constexpr type minm = 0;
	static constexpr type maxm = 5177.275;

	static constexpr type decode(unsigned char A, unsigned char B) noexcept {
		return type(256u * A + B) * 0.079;
	}
};
template <>
struct pid_unit_traits<PID::FuelRailGaugePressure> {
	using type = units::kilo<units::pressure::pascal_t>;
	static constexpr type minm = 0;
	static constexpr type maxm = 655350;

	static constexpr type decode(unsigned char A, unsigned char B) noexcept {
		return type(static_cast<long>(256u * A + B) * 10);
	}
};
template <>
struct pid_unit_traits<PID::OxygenSensor1FuelAirEquivalenceRatioAndVoltage> {
	using type = std::pair<
		units::dimentionless::scalar_t,
		units::voltage::volt_t
	>;
	static constexpr type minm = type{0, 0};
	static constexpr type maxm = type{2, 8};

	static constexpr type decode(unsigned char A, unsigned char B, unsigned char C, unsigned char D) noexcept {
		return type{(2l * (256l * A + B)) / 65536.0, (8l * (256l * C + D)) / 65536.0};
	}
};
template <>
struct pid_unit_traits<PID::OxygenSensor2FuelAirEquivalenceRatioAndVoltage> {
	using type = std::pair<
		units::dimentionless::scalar_t,
		units::voltage::volt_t
	>;
	static constexpr type minm = type{0, 0};
	static constexpr type maxm = type{2, 8};

	static constexpr type decode(unsigned char A, unsigned char B, unsigned char C, unsigned char D) noexcept {
		return type{(2l * (256l * A + B)) / 65536.0, (8l * (256l * C + D)) / 65536.0};
	}
};
template <>
struct pid_unit_traits<PID::OxygenSensor3FuelAirEquivalenceRatioAndVoltage> {
	using type = std::pair<
		units::dimentionless::scalar_t,
		units::voltage::volt_t
	>;
	static constexpr type minm = type{0, 0};
	static constexpr type maxm = type{2, 8};

	static constexpr type decode(unsigned char A, unsigned char B, unsigned char C, unsigned char D) noexcept {
		return type{(2l * (256l * A + B)) / 65536.0, (8l * (256l * C + D)) / 65536.0};
	}
};
template <>
struct pid_unit_traits<PID::OxygenSensor4FuelAirEquivalenceRatioAndVoltage> {
	using type = std::pair<
		units::dimentionless::scalar_t,
		units::voltage::volt_t
	>;
	static constexpr type minm = type{0, 0};
	static constexpr type maxm = type{2, 8};

	static constexpr type decode(unsigned char A, unsigned char B, unsigned char C, unsigned char D) noexcept {
		return type{(2l * (256l * A + B)) / 65536.0, (8l * (256l * C + D)) / 65536.0};
	}
};
template <>
struct pid_unit_traits<PID::OxygenSensor5FuelAirEquivalenceRatioAndVoltage> {
	using type = std::pair<
		units::dimentionless::scalar_t,
		units::voltage::volt_t
	>;
	static constexpr type minm = type{0, 0};
	static constexpr type maxm = type{2, 8};

	static constexpr type decode(unsigned char A, unsigned char B, unsigned char C, unsigned char D) noexcept {
		return type{(2l * (256l * A + B)) / 65536.0, (8l * (256l * C + D)) / 65536.0};
	}
};
template <>
struct pid_unit_traits<PID::OxygenSensor6FuelAirEquivalenceRatioAndVoltage> {
	using type = std::pair<
		units::dimentionless::scalar_t,
		units::voltage::volt_t
	>;
	static constexpr type minm = type{0, 0};
	static constexpr type maxm = type{2, 8};

	static constexpr type decode(unsigned char A, unsigned char B, unsigned char C, unsigned char D) noexcept {
		return type{(2l * (256l * A + B)) / 65536.0, (8l * (256l * C + D)) / 65536.0};
	}
};
template <>
struct pid_unit_traits<PID::OxygenSensor7FuelAirEquivalenceRatioAndVoltage> {
	using type = std::pair<
		units::dimentionless::scalar_t,
		units::voltage::volt_t
	>;
	static constexpr type minm = type{0, 0};
	static constexpr type maxm = type{2, 8};

	static constexpr type decode(unsigned char A, unsigned char B, unsigned char C, unsigned char D) noexcept {
		return type{(2l * (256l * A + B)) / 65536.0, (8l * (256l * C + D)) / 65536.0};
	}
};
template <>
struct pid_unit_traits<PID::OxygenSensor8FuelAirEquivalenceRatioAndVoltage> {
	using type = std::pair<
		units::dimentionless::scalar_t,
		units::voltage::volt_t
	>;
	static constexpr type minm = type{0, 0};
	static constexpr type maxm = type{2, 8};

	static constexpr type decode(unsigned char A, unsigned char B, unsigned char C, unsigned char D) noexcept {
		return type{(2l * (256l * A + B)) / 65536.0, (8l * (256l * C + D)) / 65536.0};
	}
};
template <>
struct pid_unit_traits<PID::CommandedEGR> {
	using type = units::dimentionless::scalar_t;
	static constexpr type minm = 0;
	static constexpr type maxm = 100;

	static constexpr type decode(unsigned char A) noexcept {
		return decode_percentage(A);
	}
};
template <>
struct pid_unit_traits<PID::EGRError> {
	using type = units::dimentionless::scalar_t;
	static constexpr type minm = -100;
	static constexpr type maxm = 99.2;

	static constexpr type decode(unsigned char A) noexcept {
		return decode_signed_percentage(A);
	}
};
template <>
struct pid_unit_traits<PID::CommandedEvaporativePurge> {
	using type = units::dimentionless::scalar_t;
	static constexpr type minm = 0;
	static constexpr type maxm = 100;

	static constexpr type decode(unsigned char A) noexcept {
		return decode_percentage(A);
	}
};

template <>
struct pid_unit_traits<PID::FuelTankLevelInput> {
	using type = units::dimentionless::scalar_t;
	static constexpr type minm = 0;
	static constexpr type maxm = 100;

	static constexpr type decode(unsigned char A) noexcept {
		return decode_percentage(A);
	}
};
template <>
struct pid_unit_traits<PID::WarmUpsSinceCodesCleared> {
	using type = units::data::byte_t;
	static constexpr type minm = 0;
	static constexpr type maxm = 255;

	static constexpr type decode(unsigned char A) noexcept {
		return type(A);
	}
};
template <>
struct pid_unit_traits<PID::DistanceTraveledSinceCodesCleared> {
	using type = units::kilo<units::distance::meter_t>;
	static constexpr type minm = 0;
	static constexpr type maxm = 65535;

	static constexpr type decode(unsigned char A) noexcept {
		return type(A);
	}
};
template <>
struct pid_unit_traits<PID::EvapSystemVaporPressure> {
	using type = units::pressure::pascal_t;
	static constexpr type minm = -8192;
	static constexpr type maxm = 8191.75;

	static constexpr type decode(unsigned char A, unsigned char B) noexcept {
		std::int16_t numer = (static_cast<std::int16_t>(A) << 8) | static_cast<std::uint16_t>(B);
		return type(numer) / 4.0;
	}
};
template <>
struct pid_unit_traits<PID::AbsoluteBarometricPressure> {
	using type = units::kilo<units::pressure::pascal_t>;
	static constexpr type minm = 0;
	static constexpr type maxm = 255;

	static constexpr type decode(unsigned char A) noexcept {
		return type(A);
	}
};
template <>
struct pid_unit_traits<PID::OxygenSensor1FuelAirEquivalenceRatioAndCurrent> {
	using type = std::pair<
		units::dimensionless::scalar_t,
		units::milli<units::current::ampere_t>
	>;
	static constexpr type minm = 0;
	static constexpr type maxm = 255;

	static constexpr type decode(unsigned char A, unsigned char B, unsigned char C, unsigned char D) noexcept {
		return type{(2l * (256l * A + B)) / 65536.0, (256l * C + D) / 256.0 - 128.0};
	}
};
template <>
struct pid_unit_traits<PID::OxygenSensor2FuelAirEquivalenceRatioAndCurrent> {
	using type = std::pair<
		units::dimensionless::scalar_t,
		units::milli<units::current::ampere_t>
	>;
	static constexpr type minm = 0;
	static constexpr type maxm = 255;

	static constexpr type decode(unsigned char A, unsigned char B, unsigned char C, unsigned char D) noexcept {
		return type{(2l * (256l * A + B)) / 65536.0, (256l * C + D) / 256.0 - 128.0};
	}
};
template <>
struct pid_unit_traits<PID::OxygenSensor3FuelAirEquivalenceRatioAndCurrent> {
	using type = std::pair<
		units::dimensionless::scalar_t,
		units::milli<units::current::ampere_t>
	>;
	static constexpr type minm = 0;
	static constexpr type maxm = 255;

	static constexpr type decode(unsigned char A, unsigned char B, unsigned char C, unsigned char D) noexcept {
		return type{(2l * (256l * A + B)) / 65536.0, (256l * C + D) / 256.0 - 128.0};
	}
};
template <>
struct pid_unit_traits<PID::OxygenSensor4FuelAirEquivalenceRatioAndCurrent> {
	using type = std::pair<
		units::dimensionless::scalar_t,
		units::milli<units::current::ampere_t>
	>;
	static constexpr type minm = 0;
	static constexpr type maxm = 255;

	static constexpr type decode(unsigned char A, unsigned char B, unsigned char C, unsigned char D) noexcept {
		return type{(2l * (256l * A + B)) / 65536.0, (256l * C + D) / 256.0 - 128.0};
	}
};
template <>
struct pid_unit_traits<PID::OxygenSensor5FuelAirEquivalenceRatioAndCurrent> {
	using type = std::pair<
		units::dimensionless::scalar_t,
		units::milli<units::current::ampere_t>
	>;
	static constexpr type minm = 0;
	static constexpr type maxm = 255;

	static constexpr type decode(unsigned char A, unsigned char B, unsigned char C, unsigned char D) noexcept {
		return type{(2l * (256l * A + B)) / 65536.0, (256l * C + D) / 256.0 - 128.0};
	}
};
template <>
struct pid_unit_traits<PID::OxygenSensor6FuelAirEquivalenceRatioAndCurrent> {
	using type = std::pair<
		units::dimensionless::scalar_t,
		units::milli<units::current::ampere_t>
	>;
	static constexpr type minm = 0;
	static constexpr type maxm = 255;

	static constexpr type decode(unsigned char A, unsigned char B, unsigned char C, unsigned char D) noexcept {
		return type{(2l * (256l * A + B)) / 65536.0, (256l * C + D) / 256.0 - 128.0};
	}
};
template <>
struct pid_unit_traits<PID::OxygenSensor7FuelAirEquivalenceRatioAndCurrent> {
	using type = std::pair<
		units::dimensionless::scalar_t,
		units::milli<units::current::ampere_t>
	>;
	static constexpr type minm = 0;
	static constexpr type maxm = 255;

	static constexpr type decode(unsigned char A, unsigned char B, unsigned char C, unsigned char D) noexcept {
		return type{(2l * (256l * A + B)) / 65536.0, (256l * C + D) / 256.0 - 128.0};
	}
};
template <>
struct pid_unit_traits<PID::OxygenSensor8FuelAirEquivalenceRatioAndCurrent> {
	using type = std::pair<
		units::dimensionless::scalar_t,
		units::milli<units::current::ampere_t>
	>;
	static constexpr type minm = 0;
	static constexpr type maxm = 255;

	static constexpr type decode(unsigned char A, unsigned char B, unsigned char C, unsigned char D) noexcept {
		return type{(2l * (256l * A + B)) / 65536.0, (256l * C + D) / 256.0 - 128.0};
	}
};
template <>
struct pid_unit_traits<PID::CatalystTemperatureBank1Sensor1> {
	using type = units::temperature::celsius_t;
	
	static constexpr type minm = -40;
	static constexpr type maxm = 6513.5;

	static constexpr type decode(unsigned char A, unsigned char B) noexcept {
		return type(256l * A + B) / 10 - type(40);
	}
};
template <>
struct pid_unit_traits<PID::CatalystTemperatureBank2Sensor1> {
	using type = units::temperature::celsius_t;
	
	static constexpr type minm = -40;
	static constexpr type maxm = 6513.5;

	static constexpr type decode(unsigned char A, unsigned char B) noexcept {
		return type(256l * A + B) / 10 - type(40);
	}
};
template <>
struct pid_unit_traits<PID::CatalystTemperatureBank1Sensor2> {
	using type = units::temperature::celsius_t;
	
	static constexpr type minm = -40;
	static constexpr type maxm = 6513.5;

	static constexpr type decode(unsigned char A, unsigned char B) noexcept {
		return type(256l * A + B) / 10 - type(40);
	}
};
template <>
struct pid_unit_traits<PID::CatalystTemperatureBank2Sensor2> {
	using type = units::temperature::celsius_t;
	
	static constexpr type minm = -40;
	static constexpr type maxm = 6513.5;

	static constexpr type decode(unsigned char A, unsigned char B) noexcept {
		return type(256l * A + B) / 10 - type(40);
	}
};
template <>
struct pid_unit_traits<PID::ControlModuleVoltage> {
	using type = units::voltage::volt_t;
	static constexpr type minm = 0;
	static constexpr type maxm = 65.535;

	static constexpr type decode(unsigned char A, unsigned char B) noexcept {
		return type(256u * A + B) / 1000.0
	}
};
template <>
struct pid_unit_traits<PID::AbsoluteLoadValue> {
	using type = units::dimensionless::scalar_t;
	static constexpr type minm = 0;
	static constexpr type maxm = 25700;

	static constexpr type decode(unsigned char A, unsigned char B) noexcept {
		return type(256u * A + B) / 255;
	}
};
template <>
struct pid_unit_traits<PID::FuelAirCommandedEquivalenceRatio> {
	using type = units::dimensionless::scalar_t;
	static constexpr type minm = 0;
	static constexpr type maxm = 2;

	static constexpr type decode(unsigned char A, unsigned char B) noexcept {
		return type(2ul * (256ul * A + B)) / 65536ul;
	}
};
template <>
struct pid_unit_traits<PID::RelativeThrottlePosition> {
	using type = units::dimensionless::scalar_t;
	static constexpr type minm = 0;
	static constexpr type maxm = 100;

	static constexpr type decode(unsigned char A) noexcept {
		return decode_percentage(A);
	}
};
template <>
struct pid_unit_traits<PID::AmbientAirTemperature> {
	using type = units::temperature::celsius_t;
	static constexpr type minm = -40;
	static constexpr type maxm = 215;

	static constexpr type decode(unsigned char A) noexcept {
		return type(A) - 40;
	}
};
template <>
struct pid_unit_traits<PID::AbsoluteThrottlePositionB> {
	using type = units::temperature::celsius_t;
	static constexpr type minm = 0;
	static constexpr type maxm = 100;

	static constexpr type decode(unsigned char A) noexcept {
		return decode_percentage(A);
	}
};
template <>
struct pid_unit_traits<PID::AbsoluteThrottlePositionC> {
	using type = units::temperature::celsius_t;
	static constexpr type minm = 0;
	static constexpr type maxm = 100;

	static constexpr type decode(unsigned char A) noexcept {
		return decode_percentage(A);
	}
};
template <>
struct pid_unit_traits<PID::AcceleratorPedalPositionD> {
	using type = units::temperature::celsius_t;
	static constexpr type minm = 0;
	static constexpr type maxm = 100;

	static constexpr type decode(unsigned char A) noexcept {
		return decode_percentage(A);
	}
};
template <>
struct pid_unit_traits<PID::AcceleratorPedalPositionE> {
	using type = units::temperature::celsius_t;
	static constexpr type minm = 0;
	static constexpr type maxm = 100;

	static constexpr type decode(unsigned char A) noexcept {
		return decode_percentage(A);
	}
};
template <>
struct pid_unit_traits<PID::AcceleratorPedalPositionF> {
	using type = units::temperature::celsius_t;
	static constexpr type minm = 0;
	static constexpr type maxm = 100;

	static constexpr type decode(unsigned char A) noexcept {
		return decode_percentage(A);
	}
};
template <>
struct pid_unit_traits<PID::CommandedThrottleActuator> {
	using type = units::temperature::celsius_t;
	static constexpr type minm = 0;
	static constexpr type maxm = 100;

	static constexpr type decode(unsigned char A) noexcept {
		return decode_percentage(A);
	}
};
template <>
struct pid_unit_traits<PID::TimeRunWithMIL> {
	using type = units::time::minute_t;
	static constexpr type minm = 0;
	static constexpr type maxm = 65535;

	static constexpr type decode(unsigned char A, unsigned char B) noexcept {
		return type(256ul * A + B);
	}
};
template <>
struct pid_unit_traits<PID::TimeSinceTroubleCodesCleared> {
	using type = units::time::minute_t;
	static constexpr type minm = 0;
	static constexpr type maxm = 65535;

	static constexpr type decode(unsigned char A, unsigned char B) noexcept {
		return type(256ul * A + B);
	}
};
template <>
struct pid_unit_traits<PID::MaximumSensorValues> {
	struct type {
		units::dimensionless::scalar_t         fuel_air_equivalence_ratio;
		units::voltage::volt_t                 oxygen_sensor_voltage;
		units::milli<units::current::ampere_t> oxygen_sensor_current;
		units::kilo<units::pressure::pascal_t> intake_manifold_absolute_pressure;
	};
	static constexpr type minm = type{0, 0, 0, 0};
	static constexpr type maxm = type{255, 255, 255, 2550};

	static constexpr type decode(unsigned char A, unsigned char B, unsigned char C, unsigned char D) noexcept {
		return type{A, B, C, 10u * D}; 
	}
};
template <>
struct pid_unit_traits<PID::MaximumAirFlowRate> {
	using type = units::compound_unit<
		units::mass::gram_t,
		units::inverse<units::time::second_t>
	>;
	static constexpr type minm = 0;
	static constexpr type maxm = 2550;

	static constexpr type decode(unsigned char A, unsigned char B, unsigned char C, unsigned char D) noexcept {
		// reserved by the OBD-II standard for future use:
		(void)B;
		(void)C;
		(void)D;
		return type(10u * A);
	}
};
template <>
struct pid_unit_traits<PID::EthanolFuelPercentage> {
	using type = units::dimensionless::scalar_t;
	static constexpr type minm = 0;
	static constexpr type maxm = 100;

	static constexpr type decode(unsigned char A) noexcept {
		return decode_percentage(A);
	}
};
template <>
struct pid_unit_traits<PID::AbsoluteEvapSystemVaporPressure> {
	using type = units::kilo<units::pressure::pascal_t>;
	static constexpr type minm = 0;
	static constexpr type maxm = 327.675;

	static constexpr type decode(unsigned char A) noexcept {
		return type(256u * A + B) / 200u;
	}
};
template <>
struct pid_unit_traits<PID::EvapSystemVaporPressure> {
	using type = units::pressure::pascal_t;
	static constexpr type minm = -32767l;
	static constexpr type maxm = 32768l;

	static constexpr type decode(unsigned char A, unsigned char B) noexcept {
		std::int32_t value = (static_cast<std::int16_t>(A) << 8u) | B;
		return type(value - 32767);
	}
};
template <>
struct pid_unit_traits<PID::ShortTermSecondaryOxygenSensorTrimBanks1And3> {
	using type = std::pair<
		units::dimensionless::scalar_t,
		units::dimensionless::scalar_t
	>;
	static constexpr type minm = -100;
	static constexpr type maxm = 99.2;

	static constexpr type decode(unsigned char A, unsigned char B) noexcept {
		return type{decode_signed_percentage(A), decode_signed_percentage(B)};
	}
};
template <>
struct pid_unit_traits<PID::LongTermSecondaryOxygenSensorTrimBanks1And3> {
	using type = std::pair<
		units::dimensionless::scalar_t,
		units::dimensionless::scalar_t
	>;
	static constexpr type minm = -100;
	static constexpr type maxm = 99.2;

	static constexpr type decode(unsigned char A, unsigned char B) noexcept {
		return type{decode_signed_percentage(A), decode_signed_percentage(B)};
	}
};
template <>
struct pid_unit_traits<PID::ShortTermSecondaryOxygenSensorTrimBanks2And4> {
	using type = std::pair<
		units::dimensionless::scalar_t,
		units::dimensionless::scalar_t
	>;
	static constexpr type minm = -100;
	static constexpr type maxm = 99.2;

	static constexpr type decode(unsigned char A, unsigned char B) noexcept {
		return type{decode_signed_percentage(A), decode_signed_percentage(B)};
	}
};
template <>
struct pid_unit_traits<PID::LongTermSecondaryOxygenSensorTrimBanks2And4> {
	using type = std::pair<
		units::dimensionless::scalar_t,
		units::dimensionless::scalar_t
	>;
	static constexpr type minm = -100;
	static constexpr type maxm = 99.2;

	static constexpr type decode(unsigned char A, unsigned char B) noexcept {
		return type{decode_signed_percentage(A), decode_signed_percentage(B)};
	}
};
template <>
struct pid_unit_traits<PID::FuelRailAbsolutePressure> {
	using type = units::kilo<units::pressure::pascal_t>;
	static constexpr type minm = 0;
	static constexpr type maxm = 655'350l;

	static constexpr type decode(unsigned char A, unsigned char B) noexcept {
		return 10l * (256l * A + B);
	}
};
template <>
struct pid_unit_traits<PID::RelativeAcceleratorPedalPosition> {
	using type = units::dimensionless::scalar_t;
	static constexpr type minm = 0;
	static constexpr type maxm = 100;

	static constexpr type decode(unsigned char A) noexcept {
		return decode_percentage(A);
	}
};
template <>
struct pid_unit_traits<PID::HybridBatteryPackRemainingLife> {
	using type = units::dimensionless::scalar_t;
	static constexpr type minm = 0;
	static constexpr type maxm = 100;

	static constexpr type decode(unsigned char A) noexcept {
		return decode_percentage(A);
	}
};
template <>
struct pid_unit_traits<PID::EngineOilTemperature> {
	using type = units::temperature::celsius_t;
	static constexpr type minm = -40;
	static constexpr type maxm = 215;

	static constexpr type decode(unsigned char A) noexcept {
		return type(static_cast<signed>(A) - 40);
	}
};
template <>
struct pid_unit_traits<PID::FuelInjectionTiming> {
	using type = units::angle::degree_t;
	static constexpr type minm = -210;
	static constexpr type maxm = 301.992;

	static constexpr type decode(unsigned char A, unsigned char B) noexcept {
		return type(256l * A + B) / 128 - type(210);
	}
};
template <>
struct pid_unit_traits<PID::EngineFuelRate> {
	using type = units::compound_unit<
		units::volume::liter_t,
		units::inverse<units::time::hour_t>
	>;
	static constexpr type minm = 0;
	static constexpr type maxm = 3212.75;

	static constexpr type decode(unsigned char A, unsigned char B) noexcept {
		return type(256l * A + B) / 20;
	}
};
template <>
struct pid_unit_traits<PID::DemandedPercentTorque> {
	using type = units::dimensionless::scalar_t;
	static constexpr type minm = -125;
	static constexpr type maxm = 130;

	static constexpr type decode(unsigned char A) noexcept {
		return type(static_cast<signed>(A) - 125);
	}
};
template <>
struct pid_unit_traits<PID::ActualPercentTorque> {
	using type = units::dimensionless::scalar_t;
	static constexpr type minm = -125;
	static constexpr type maxm = 130;

	static constexpr type decode(unsigned char A) noexcept {
		return type(static_cast<signed>(A) - 125);
	}
};
template <>
struct pid_unit_traits<PID::ReferenceTorque> {
	using type = units::torque::newton_meter_t;
	static constexpr type minm = 0;
	static constexpr type maxm = 65535u;

	static constexpr type decode(unsigned char A, unsigned char B) noexcept {
		return 256u * A + B;
	}
};

template <>
struct pid_unit_traits<PID::EnginePercentTorqueData> {
	struct type {
		units::dimensionless::scalar_t idle;
		units::dimensionless::scalar_t engine_point1;
		units::dimensionless::scalar_t engine_point2;
		units::dimensionless::scalar_t engine_point3;
		units::dimensionless::scalar_t engine_point4;
	};
	static constexpr type minm = type{-125, -125, -125, -125, -125};
	static constexpr type maxm = type{130, 130, 130, 130, 130};

	static constexpr type decode(unsigned char A, unsigned char B, unsigned char C, unsigned char D, unsigned char E) noexcept {
		return type{
			static_cast<signed>(A) - 125,
			static_cast<signed>(B) - 125,
			static_cast<signed>(C) - 125,
			static_cast<signed>(D) - 125,
			static_cast<signed>(E) - 125
		};
	}
};

template <>
struct pid_unit_traits<PID::ExhaustGasTemperatureBank1> {
	using type = std::array<std::optional<units::temperature::celsius_t>, 4u>;

	static constexpr type minm = type{   -40,    -40,    -40,    -40};
	static constexpr type maxm = type{6513.5, 6513.5, 6513.5, 6513.5};

	static constexpr type decode(
		unsigned char A,
		unsigned char B, unsigned char C,
		unsigned char D, unsigned char E
		unsigned char F, unsigned char G,
		unsigned char H, unsigned char I
	) noexcept {
		type result;
		if(A & 0b0001u) {
			result[0] = units::temperature::celsius_t(256u * B + C) / 10
				- units::temperature::celsius_t(40);
		}
		if(A & 0b0010u) {
			result[1] = units::temperature::celsius_t(256u * D + E) / 10
				- units::temperature::celsius_t(40);
		}
		if(A & 0b0100u) {
			result[2] = units::temperature::celsius_t(256u * F + G) / 10
				- units::temperature::celsius_t(40);
		}
		if(A & 0b1000u) {
			result[3] = units::temperature::celsius_t(256u * H + I) / 10
				- units::temperature::celsius_t(40);
		}
		return result;
	}
};

template <>
struct pid_unit_traits<PID::ExhaustGasTemperatureBank2> {
	using type = std::array<std::optional<units::temperature::celsius_t>, 4u>;

	static constexpr type minm = type{   -40,    -40,    -40,    -40};
	static constexpr type maxm = type{6513.5, 6513.5, 6513.5, 6513.5};

	static constexpr type decode(
		unsigned char A,
		unsigned char B, unsigned char C,
		unsigned char D, unsigned char E
		unsigned char F, unsigned char G,
		unsigned char H, unsigned char I
	) noexcept {
		pid_unit_traits<PID::ExhaustGasTemperatureBank1>::decode(
			A, B, C, D, E, F, G, H, I
		);
	}

template <>
struct pid_unit_traits<PID::ThrottlePositionG> {
	using type = units::dimensionless::scalar_t;
	static constexpr type minm = 0;
	static constexpr type maxm = 100;

	static constexpr type decode(unsigned char A) noexcept {
		return decode_percentage(A);
	}
};
template <>
struct pid_unit_traits<PID::EngineFrictionPercentTorque> {
	using type = units::dimensionless::scalar_t;
	static constexpr type minm = -125;
	static constexpr type maxm = 130;

	static constexpr type decode(unsigned char A) noexcept {
		return type(static_cast<signed>(A) - 125);
	}
};

inline constexpr auto std::array<unsigned char, 256u> pid_encoding_sizes = [](){
	// This is all exectuted at compile-time; don't worry about the stack!
	std::array<unsigned char, 256u> encoding_sizes{0u};
	encoding_sizes[0]   = 4;
	encoding_sizes[1]   = 4;
	encoding_sizes[2]   = 2;
	encoding_sizes[3]   = 2;
	encoding_sizes[4]   = 1;
	encoding_sizes[5]   = 1;
	encoding_sizes[6]   = 1;
	encoding_sizes[7]   = 1;
	encoding_sizes[8]   = 1;
	encoding_sizes[9]   = 1;
	encoding_sizes[10]  = 1;
	encoding_sizes[11]  = 1;
	encoding_sizes[12]  = 2;
	encoding_sizes[13]  = 1;
	encoding_sizes[14]  = 1;
	encoding_sizes[15]  = 1;
	encoding_sizes[16]  = 2;
	encoding_sizes[17]  = 1;
	encoding_sizes[18]  = 1;
	encoding_sizes[19]  = 1;
	encoding_sizes[20]  = 2;
	encoding_sizes[21]  = 2;
	encoding_sizes[22]  = 2;
	encoding_sizes[23]  = 2;
	encoding_sizes[24]  = 2;
	encoding_sizes[25]  = 2;
	encoding_sizes[26]  = 2;
	encoding_sizes[27]  = 2;
	encoding_sizes[28]  = 1;
	encoding_sizes[29]  = 1;
	encoding_sizes[30]  = 1;
	encoding_sizes[31]  = 2;
	encoding_sizes[32]  = 4;
	encoding_sizes[33]  = 2;
	encoding_sizes[34]  = 2;
	encoding_sizes[35]  = 2;
	encoding_sizes[36]  = 4;
	encoding_sizes[37]  = 4;
	encoding_sizes[38]  = 4;
	encoding_sizes[39]  = 4;
	encoding_sizes[40]  = 4;
	encoding_sizes[41]  = 4;
	encoding_sizes[42]  = 4;
	encoding_sizes[43]  = 4;
	encoding_sizes[44]  = 1;
	encoding_sizes[45]  = 1;
	encoding_sizes[46]  = 1;
	encoding_sizes[47]  = 1;
	encoding_sizes[48]  = 1;
	encoding_sizes[49]  = 2;
	encoding_sizes[50]  = 2;
	encoding_sizes[51]  = 1;
	encoding_sizes[52]  = 4;
	encoding_sizes[53]  = 4;
	encoding_sizes[54]  = 4;
	encoding_sizes[55]  = 4;
	encoding_sizes[56]  = 4;
	encoding_sizes[57]  = 4;
	encoding_sizes[58]  = 4;
	encoding_sizes[59]  = 4;
	encoding_sizes[60]  = 2;
	encoding_sizes[61]  = 2;
	encoding_sizes[62]  = 2;
	encoding_sizes[63]  = 2;
	encoding_sizes[64]  = 4;
	encoding_sizes[65]  = 4;
	encoding_sizes[66]  = 2;
	encoding_sizes[67]  = 2;
	encoding_sizes[68]  = 2;
	encoding_sizes[69]  = 1;
	encoding_sizes[70]  = 1;
	encoding_sizes[71]  = 1;
	encoding_sizes[72]  = 1;
	encoding_sizes[73]  = 1;
	encoding_sizes[74]  = 1;
	encoding_sizes[75]  = 1;
	encoding_sizes[76]  = 1;
	encoding_sizes[77]  = 2;
	encoding_sizes[78]  = 2;
	encoding_sizes[79]  = 4;
	encoding_sizes[80]  = 4;
	encoding_sizes[81]  = 1;
	encoding_sizes[82]  = 1;
	encoding_sizes[83]  = 2;
	encoding_sizes[84]  = 2;
	encoding_sizes[85]  = 2;
	encoding_sizes[86]  = 2;
	encoding_sizes[87]  = 2;
	encoding_sizes[88]  = 2;
	encoding_sizes[89]  = 2;
	encoding_sizes[90]  = 1;
	encoding_sizes[91]  = 1;
	encoding_sizes[92]  = 1;
	encoding_sizes[93]  = 2;
	encoding_sizes[94]  = 2;
	encoding_sizes[95]  = 1;
	encoding_sizes[96]  = 4;
	encoding_sizes[97]  = 1;
	encoding_sizes[98]  = 1;
	encoding_sizes[99]  = 2;
	encoding_sizes[100] = 5;
	encoding_sizes[101] = 2;
	encoding_sizes[102] = 5;
	encoding_sizes[103] = 3;
	encoding_sizes[104] = 7;
	encoding_sizes[105] = 7;
	encoding_sizes[106] = 5;
	encoding_sizes[107] = 5;
	encoding_sizes[108] = 5;
	encoding_sizes[109] = 6;
	encoding_sizes[110] = 5;
	encoding_sizes[111] = 3;
	encoding_sizes[112] = 9;
	encoding_sizes[113] = 5;
	encoding_sizes[114] = 5;
	encoding_sizes[115] = 5;
	encoding_sizes[116] = 5;
	encoding_sizes[117] = 7;
	encoding_sizes[118] = 7;
	encoding_sizes[119] = 5;
	encoding_sizes[120] = 9;
	encoding_sizes[121] = 9;
	encoding_sizes[122] = 7;
	encoding_sizes[123] = 7;
	encoding_sizes[124] = 9;
	encoding_sizes[125] = 1;
	encoding_sizes[126] = 1;
	encoding_sizes[127] = 13;
	encoding_sizes[128] = 4;
	encoding_sizes[129] = 21;
	encoding_sizes[130] = 21;
	encoding_sizes[131] = 5;
	encoding_sizes[132] = 1;
	encoding_sizes[133] = 10;
	encoding_sizes[134] = 5;
	encoding_sizes[135] = 5;
	encoding_sizes[136] = 13;
	encoding_sizes[137] = 41;
	encoding_sizes[138] = 41;
	encoding_sizes[139] = 7;
	encoding_sizes[140] = 16;
	encoding_sizes[141] = 1;
	encoding_sizes[142] = 1;
	encoding_sizes[143] = 5;
	encoding_sizes[144] = 3;
	encoding_sizes[145] = 5;
	encoding_sizes[146] = 2;
	encoding_sizes[147] = 3;
	encoding_sizes[148] = 12;
	encoding_sizes[152] = 9;
	encoding_sizes[153] = 9;
	encoding_sizes[154] = 6;
	encoding_sizes[155] = 4;
	encoding_sizes[156] = 17;
	encoding_sizes[157] = 4;
	encoding_sizes[158] = 2;
	encoding_sizes[159] = 9;
	encoding_sizes[160] = 4;
	encoding_sizes[161] = 9;
	encoding_sizes[162] = 2;
	encoding_sizes[163] = 9;
	encoding_sizes[164] = 4;
	encoding_sizes[165] = 4;
	encoding_sizes[166] = 4;
	encoding_sizes[192] = 4;
	return encoding_sizes;
}();

template <PID BasePid>
struct PidSupportMap {
	static_assert(
		Pid == PID::SupportedPids0
		or Pid == PID::SupportedPids1
		or Pid == PID::SupportedPids2
		or Pid == PID::SupportedPids3
		or Pid == PID::SupportedPids4
		or Pid == PID::SupportedPids5
		or Pid == PID::SupportedPids6
	);

	constexpr pid_support_map(std::uint_least32_t mp):
		map_(mp)
	{
		
	}

	constexpr bool operator[](PID pid) const {
		assert(pid > BasePid);
		auto ofs = (static_cast<unsigned char>(pid) - static_cast<unsigned char>(BasePid));
		assert(ofs <= 32u);
		ofs -= 1u;
		auto mp = map_;
		mp >>= (31u - ofs);
		return (mp & 0x01u) == 0x01u;
	}

private:
	std::uint_least32_t map_;
};

template <PID Pid>
struct pid_bitwise_traits {
	using type = void;
};

template <PID Pid>
struct pid_bitwise_support_traits {
	using type = PidSupportMap<Pid>;
	static constexpr type decode(unsigned char A, unsigned char B, unsigned char C, unsigned char D) noexcept {
		return type(
			  (static_cast<std::uint_least32_t>(A) << 24u)
			| (static_cast<std::uint_least32_t>(B) << 16u)
			| (static_cast<std::uint_least32_t>(C) <<  8u)
			| (static_cast<std::uint_least32_t>(D) <<  0u)
		);
	}
};

template <>
struct pid_bitwise_traits<PID::SupportedPids0>:
	pid_bitwise_support_traits<PID::SupportedPids0>
{
	using type = pid_bitwise_support_traits<PID::SupportedPids0>::type;
};

template <>
struct pid_bitwise_traits<PID::SupportedPids1>:
	pid_bitwise_support_traits<PID::SupportedPids1>
{
	using type = pid_bitwise_support_traits<PID::SupportedPids1>::type;
};

template <>
struct pid_bitwise_traits<PID::SupportedPids2>:
	pid_bitwise_support_traits<PID::SupportedPids2>
{
	using type = pid_bitwise_support_traits<PID::SupportedPids2>::type;
};

template <>
struct pid_bitwise_traits<PID::SupportedPids3>:
	pid_bitwise_support_traits<PID::SupportedPids3>
{
	using type = pid_bitwise_support_traits<PID::SupportedPids3>::type;
};

template <>
struct pid_bitwise_traits<PID::SupportedPids4>:
	pid_bitwise_support_traits<PID::SupportedPids4>
{
	using type = pid_bitwise_support_traits<PID::SupportedPids4>::type;
};

template <>
struct pid_bitwise_traits<PID::SupportedPids5>:
	pid_bitwise_support_traits<PID::SupportedPids5>
{
	using type = pid_bitwise_support_traits<PID::SupportedPids5>::type;
};

template <>
struct pid_bitwise_traits<PID::SupportedPids6>:
	pid_bitwise_support_traits<PID::SupportedPids6>
{
	using type = pid_bitwise_support_traits<PID::SupportedPids6>::type;
};

struct SparkIgnitionMonitorStatus {
	bool egr_system_test_available           : 1u; // C7
	bool oxygen_sensor_heater_test_available : 1u; // C6
	bool oxygen_sensor_test_available        : 1u; // C5
	bool ac_refrigerant_test_available       : 1u; // C4
	bool secondary_air_system_test_available : 1u; // C3
	bool evaporative_system_test_available   : 1u; // C2
	bool heated_catalyst_test_available      : 1u; // C1
	bool catalyst_test_available             : 1u; // C0

	bool egr_system_test_incomplete           : 1u; // D7
	bool oxygen_sensor_heater_test_incomplete : 1u; // D6
	bool oxygen_sensor_test_incomplete        : 1u; // D5
	bool ac_refrigerant_test_incomplete       : 1u; // D4
	bool secondary_air_system_test_incomplete : 1u; // D3
	bool evaporative_system_test_incomplete   : 1u; // D2
	bool heated_catalyst_test_incomplete      : 1u; // D1
	bool catalyst_test_incomplete             : 1u; // D0
};

struct CompressionIgnitionMonitorStatus {
	bool egr_and_or_vvt_system_test_available : 1u; // C7
	bool pm_filter_monitoring_test_available  : 1u; // C6
	bool exhaust_gas_sensor_test_available    : 1u; // C5
	bool boost_pressure_test_available        : 1u; // C3
	bool nox_scr_monitor_test_available       : 1u; // C1
	bool nmhc_catalyst_test_available         : 1u; // C0

	bool egr_and_or_vvt_system_test_incomplete : 1u; // D7
	bool pm_filter_monitoring_test_incomplete  : 1u; // D6
	bool exhaust_gas_sensor_test_incomplete    : 1u; // D5
	bool boost_pressure_test_incomplete        : 1u; // D3
	bool nox_scr_monitor_test_incomplete       : 1u; // D1
	bool nmhc_catalyst_test_incomplete         : 1u; // D0
};

enum class IgnitionMonitorSupport: bool {
	SparkIgnition       = false,
	CompressionIgnition = true
};

struct MonitorStatus {
	bool components_test_incomplete  : 1u; // B6
	bool fuel_system_test_incomplete : 1u; // B5
	bool misfire_test_incomplete     : 1u; // B4
	bool components_test_available   : 1u; // B2
	bool fuel_system_test_available  : 1u; // B1
	bool misfire_test_available      : 1u; // B0
	
	IgnitionMonitorSupport ignition_monitor_support : 1u; // B3

	union {
		SparkIgnitionMonitor       spark_ignition_monitor;
		CompressionIgnitionMonitor compression_ignition_monitor;
	}

	static constexpr MonitorStatus decode(unsigned char A, unsigned char B, unsigned char C, unsigned char D) noexcept {
		bool components_test_incomplete   = (B >> 6) & 0x01u; 
		bool fuel_system_test_incomplete  = (B >> 5) & 0x01u;
		bool misfire_test_incomplete      = (B >> 4) & 0x01u;
		bool components_test_available    = (B >> 2) & 0x01u;
		bool fuel_system_test_available   = (B >> 1) & 0x01u;
		bool misfire_test_available       = (B >> 0) & 0x01u;
		auto ignition_monitor_support     = static_cast<IgnitionMonitorSupport>((B >> 3) & 0x01u);

		if(result.ignition_monitor_support ==  IgnitionMonitorSupport::SparkIgnition) {
			SparkIgnitionMonitor spark;
			spark.egr_system_test_available           = (C >> 7) & 0x01u;
			spark.oxygen_sensor_heater_test_available = (C >> 6) & 0x01u;
			spark.oxygen_sensor_test_available        = (C >> 5) & 0x01u;
			spark.ac_refrigerant_test_available       = (C >> 4) & 0x01u;
			spark.secondary_air_system_test_available = (C >> 3) & 0x01u;
			spark.evaporative_system_test_available   = (C >> 2) & 0x01u;
			spark.heated_catalyst_test_available      = (C >> 1) & 0x01u;
			spark.catalyst_test_available             = (C >> 0) & 0x01u;

			spark.egr_system_test_incomplete            = (D >> 7) & 0x01u;
			spark.oxygen_sensor_heater_test_incomplete  = (D >> 6) & 0x01u;
			spark.oxygen_sensor_test_incomplete         = (D >> 5) & 0x01u;
			spark.ac_refrigerant_test_incomplete        = (D >> 4) & 0x01u;
			spark.secondary_air_system_test_incomplete  = (D >> 3) & 0x01u;
			spark.evaporative_system_test_incomplete    = (D >> 2) & 0x01u;
			spark.heated_catalyst_test_incomplete       = (D >> 1) & 0x01u;
			spark.catalyst_test_incomplete              = (D >> 0) & 0x01u;
			return MonitorStatus{
				components_test_incomplete,
				fuel_system_test_incomplete,
				misfire_test_incomplete,
				components_test_available,
				fuel_system_test_available,
				misfire_test_available,
				ignition_monitor_support,
				{ spark }
			};
		} else {
			CompressionIgnitionMonitor compression;
			compression.egr_and_or_vvt_system_test_available = (C >> 7) & 0x01u; 
			compression.pm_filter_monitoring_test_available  = (C >> 6) & 0x01u;
			compression.exhaust_gas_sensor_test_available    = (C >> 5) & 0x01u;
			compression.boost_pressure_test_available        = (C >> 3) & 0x01u;
			compression.nox_scr_monitor_test_available       = (C >> 1) & 0x01u;
			compression.nmhc_catalyst_test_available         = (C >> 0) & 0x01u;

			compression.egr_and_or_vvt_system_test_incomplete = (D >> 7) & 0x01u;
			compression.pm_filter_monitoring_test_incomplete  = (D >> 6) & 0x01u;
			compression.exhaust_gas_sensor_test_incomplete    = (D >> 5) & 0x01u;
			compression.boost_pressure_test_incomplete        = (D >> 3) & 0x01u;
			compression.nox_scr_monitor_test_incomplete       = (D >> 1) & 0x01u;
			compression.nmhc_catalyst_test_incomplete         = (D >> 0) & 0x01u;
			compression_ignition_monitor = spark;
			return MonitorStatus{
				components_test_incomplete,
				fuel_system_test_incomplete,
				misfire_test_incomplete,
				components_test_available,
				fuel_system_test_available,
				misfire_test_available,
				ignition_monitor_support,
				{ compression }	
			};
		}
	}
};

template <>
struct pid_bitwise_traits<PID::MonitorStatusSinceDTCCleared> {
	struct type {
		bool          check_engine_light_on             : 1u; // A7
		unsigned char diagnostic_code_count             : 7u; // A6-A0
		MonitorStatus monitor_status;
	};
	static constexpr type decode(unsigned char A, unsigned char B, unsigned char C, unsigned char D) noexcept {
		return type{
			(A >> 7u) & 0x01u,
			A & 0b0111'1111u,
			{ MontorStatus::decode(A, B, C, D) }
		};
	}
};

enum class FuelSystemStatus: unsigned char {
	OpenLoopInsufficientEngineTemperature = 1u,
	ClosedLoopUsingOxygenSensorFeedback  = 2u,
	OpenLoopEngineLoadOrFuelCut = 4u,
	OpenLoopSystemFailure = 8u,
	CloseLoopUsingOxygenSensorWithFeedbackFault = 16u
};

template <>
struct pid_bitwise_traits<PID::FuelSystemStatus> {
	using type = std::pair<FuelSystemStatus, FuelSystemStatus>;
	
	static constexpr type decode(unsigned char A, unsigned char B) noexcept {
		return type{static_cast<FuelSystemStatus>(A), static_cast<FuelSystemStatus>(B)};
	}
};

enum class SecondaryAirStatus: unsigned char {
	Upstream = 1u,
	DownstreamOfCatalyticConverter = 2u,
	ExternalOrOff = 4u,
	PumpCommandedOnForDiagnostics = 8u
};

template <>
struct pid_bitwise_traits<PID::CommandedSecondaryAirStatus> {
	using type = SecondaryAirStatus;
	
	static constexpr type decode(unsigned char A) noexcept {
		return static_cast<type>(A);
	}
};

enum class OBDStandard: unsigned char {
	OBD_II_CARB          = 1,
	OBD_EPA              = 2,
	OBD_and_OBD_II       = 3,
	OBD_I                = 4,
	NonCompliant         = 5,
	EOBD                 = 6,
	EOBD_and_OBD_II      = 7,
	EOBD_and_OBD         = 8,
	EOBD_OBD_and_OBD_II  = 9,
	JOBD                 = 10,
	JOBD_and_OBD_II      = 11,
	JOBD_and_EOBD        = 12,
	JOBD_EOBD_and_OBD_II = 13,
	EMD                  = 17,
	EMD_Plus             = 18,
	HD_OBD_C             = 19,
	HD_OBD               = 20,
	WWH_OBD              = 21,
	HD_EOBD_I            = 23,
	HD_EOBD_I_N          = 24,
	HD_EOBD_II           = 25,
	HD_EOBD_II_N         = 26,
	OBDBr_1              = 28,
	OBDBr_2              = 29,
	KOBD                 = 30,
	IOBD_I               = 31,
	IOBD_II              = 32,
	HD_EOBD_IV           = 33
};

template <>
struct pid_bitwise_traits<PID::SupportedOBDStandards> {
	using type = OBDStandard;
	
	static constexpr type decode(unsigned char A) noexcept {
		return static_cast<type>(A);
	}
};

enum class PTOStatus: bool {
	Inactive = false,
	Active = true
};

template <>
struct pid_bitwise_traits<PID::AuxiliaryInputStatus> {
	using type = PTOStatus;
	
	static constexpr type decode(unsigned char A) noexcept {
		return static_cast<type>(static_cast<bool>(A & 0x01));
	}
};

template <>
struct pid_bitwise_traits<PID::MonitorStatusThisDriveCycle> {
	using type = MonitorStatus;
	
	static constexpr type decode(unsigned char A, unsigned char B, unsigned char C, unsigned char D) noexcept {
		return MonitorStatus::decode(A, B, C, D);
	}
};

enum class FuelType {
	Not available                            = 0,
	Gasoline                                 = 1,
	Methanol                                 = 2,
	Ethanol                                  = 3,
	Diesel                                   = 4,
	LPG                                      = 5,
	CNG                                      = 6,
	Propane                                  = 7,
	Electric                                 = 8,
	BifuelRunningGasoline                    = 9,
	BifuelRunningMethanol                    = 10,
	BifuelRunningEthanol                     = 11,
	BifuelRunningLPG                         = 12,
	BifuelRunningCNG                         = 13,
	BifuelRunningPropane                     = 14,
	BifuelRunningElectricity                 = 15,
	BifuelRunningElectricCombustionEngine    = 16,
	HybridGasoline                           = 17,
	HybridEthanol                            = 18,
	HybridDiesel                             = 19,
	HybridElectric                           = 20,
	HybridRunningElectricAndCombustionEngine = 21,
	HybridRegenerative                       = 22,
	BifuelRunningDiesel                      = 23
};

template <>
struct pid_bitwise_traits<PID::FuelType> {
	using type = FuelType;
	
	static constexpr type decode(unsigned char A) noexcept {
		return static_cast<type>(A);
	}
};

struct CompressedDTC {
	unsigned char ch1: 2u;
	unsigned char ch2: 2u;
	unsigned char ch3: 4u;
	unsigned char ch4: 4u;
	unsigned char ch5: 4u;

	constexpr std::array<char, 6> to_string() const {
		return {
			("PCBU")[ch1],
			("0123")[ch2],
			("0123456789ABCDEF")[ch3],
			("0123456789ABCDEF")[ch4],
			("0123456789ABCDEF")[ch5],
			'\0'
		};
	}
};

template <PID Pid>
struct pid_traits {
	using unit_traits    = pid_unit_traits<Pid>;
	using bitwise_traits = pid_unit_traits<Pid>;

	static constexpr bool has_unit_encoding
		= (not std::is_same_v<typename unit_traits::type, void>);

	static constexpr bool has_bitwise_encoding
		= (not std::is_same_v<typename bitwise_traits::type, void>);

	static constexpr bool has_known_encoding
		= has_unit_encoding and has_bitwise_encoding;
	
	static constexpr auto decode = []() {
		if constexpr(has_unit_encoding) {
			return &unit_traits::decode;
		} else if constexpr(has_bitwise_encoding) {
			return &bitwise_traits::decode;
		} else {
			return static_cast<void(*)() noexcept>(nullptr);
		}
	}();

	static constexpr std::optional<unsigned char> encoding_size
		= pid_encoding_sizes[static_cast<unsigned char>(Pid)];
};

} /* namespace m3 */

#endif /* M3_OBD_PID_H */
