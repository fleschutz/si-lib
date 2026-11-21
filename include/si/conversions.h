/// @file     <si/conversions.h>
/// @brief    Provides conversion functions, e.g. to_string()
/// @details  Defines from_string(), to_string(), to_equivalent(), to_percentage(), and the operator <<.

#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <si/literals.h>
#define FUNC [[nodiscard]] inline

namespace si {

	// Default Format Strings (Configurable)
	// -------------------------------------
	inline auto to_string_format     = "%.2Lf %s"; ///< SI standard formatting by default
	inline auto to_equivalent_format = "%.2Lf %s"; ///< SI standard formatting by default
	inline auto to_percentage_format = "%.0Lf%s"; 

	static bool _parse(const std::string& str, double& number, char* unit) {
#ifdef _WIN32
		return sscanf_s(str.c_str(), "%lf%99s", &number, unit, 100) == 2;
#else
		return std::sscanf(str.c_str(), "%lf%99s", &number, unit) == 2;
#endif
	}

	/// @brief Returns the length from the given string, or NaN on error.
	FUNC length to_length(const std::string& str) {
		double num = 0.0;
		char unit[100] = "";
		if (!_parse(str, num, unit))  return meters(std::nan("1")); // not recognized
		if (!std::strcmp(unit, "Gm")) return num * 1_Gm;
		if (!std::strcmp(unit, "Mm")) return num * 1_Mm;
		if (!std::strcmp(unit, "km")) return num * 1_km;
		if (!std::strcmp(unit, "m"))  return num * 1_m;
		if (!std::strcmp(unit, "dm")) return num * 1_dm;
		if (!std::strcmp(unit, "cm")) return num * 1_cm;
		if (!std::strcmp(unit, "mm")) return num * 1_mm;
		if (!std::strcmp(unit, "um")) return num * 1_um;
		if (!std::strcmp(unit, "nm")) return num * 1_nm;
		if (!std::strcmp(unit, "pm")) return num * 1_pm;
		return meters(std::nan("2")); // unknown unit
	}

	/// @brief Returns the time from the given string, or NaN on error.
	FUNC time to_time(const std::string& str) {
		double num = 0.0;
		char unit[100] = "";
		if (!_parse(str, num, unit))  return seconds(std::nan("1")); // not recognized
		if (!std::strcmp(unit, "d"))  return num * 1_d;
		if (!std::strcmp(unit, "h"))  return num * 1_h;
		if (!std::strcmp(unit, "m"))  return num * 1_min;
		if (!std::strcmp(unit, "s"))  return num * 1_s;
		if (!std::strcmp(unit, "ms")) return num * 1_ms;
		if (!std::strcmp(unit, "us")) return num * 1_us;
		if (!std::strcmp(unit, "ns")) return num * 1_ns;
		if (!std::strcmp(unit, "ps")) return num * 1_ps;
		return seconds(std::nan("2")); // unknown unit
	}

	/// @brief Returns the mass from the given string, or NaN on error.
	FUNC mass to_mass(const std::string& str) {
		double num = 0.0;
		char unit[100] = "";
		if (!_parse(str, num, unit))  return kilograms(std::nan("1")); // not recognized
		if (!std::strcmp(unit, "Gt")) return num * 1_Gt;
		if (!std::strcmp(unit, "Mt")) return num * 1_Mt;
		if (!std::strcmp(unit, "kt")) return num * 1_kt;
		if (!std::strcmp(unit, "t"))  return num * 1_t;
		if (!std::strcmp(unit, "kg")) return num * 1_kg;
		if (!std::strcmp(unit, "g"))  return num * 1_g;
		if (!std::strcmp(unit, "mg")) return num * 1_mg;
		if (!std::strcmp(unit, "ug")) return num * 1_ug;
		if (!std::strcmp(unit, "ng")) return num * 1_ng;
		return kilograms(std::nan("2")); // unknown unit
	}

	/// @brief Internal function to format a number and a unit into a string by using a format string.
	FUNC std::string _fmt(long double number, const char* unit, const char* formatString) {
		char buf[256] = "";
		std::snprintf(buf, sizeof(buf), formatString, number, unit);
		return std::string(buf);
	}

	// to_string() Function Overloading
	// --------------------------------

	/// @brief Returns the given length as string using SI units.
	FUNC std::string to_string(length d, const char* fmtStr = to_string_format) {
		if (d <= -1_Gpc || d >= 1_Gpc)     return _fmt(d / 1_Gpc, "Gpc", fmtStr); // gigaparsec
		if (d <= -1_Mpc || d >= 1_Mpc)     return _fmt(d / 1_Mpc, "Mpc", fmtStr); // megaparsec
		if (d <= -1_kpc || d >= 1_kpc)     return _fmt(d / 1_kpc, "kpc", fmtStr); // kiloparsec
		if (d <= -1_pc  || d >= 1_pc)      return _fmt(d / 1_pc, "pc", fmtStr);   // parsec
		if (d <= -1_ly  || d >= 1_ly)      return _fmt(d / 1_ly, "ly", fmtStr);   // light-year
		if (d <= -0.1_au|| d >= 0.1_au)    return _fmt(d / 1_au, "au", fmtStr);   // astronomical unit
		if (d <= -1_km  || d >= 1_km)      return _fmt(d / 1_km, "km", fmtStr);   // kilometer
		if (d <= -1_m   || d >= 1_m || !d) return _fmt(d / 1_m, "m", fmtStr);     // meter
		if (d <= -1_cm  || d >= 1_cm)      return _fmt(d / 1_cm, "cm", fmtStr);   // centimeter
		if (d <= -1_mm  || d >= 1_mm)      return _fmt(d / 1_mm, "mm", fmtStr);   // millimeter
		if (d <= -1_um  || d >= 1_um)      return _fmt(d / 1_um, "µm", fmtStr);   // micrometer
		if (d <= -1_nm  || d >= 1_nm)      return _fmt(d / 1_nm, "nm", fmtStr);   // nanometer
		return _fmt(d / 1_pm, "pm", fmtStr);
	}

	/// @brief Returns the given time as string using SI units.
	FUNC std::string to_string(time t, const char* fmtStr = to_string_format) {
		if (t <= -365.25_d || t >= 365.25_d) return _fmt(t / 365.25_d, "y", fmtStr);
		if (t <= -1_w || t >= 1_w)           return _fmt(t / 1_w, "w", fmtStr);
		if (t <= -2_d || t >= 2_d)           return _fmt(t / 1_d, "d", fmtStr);
		if (t <= -2_h || t >= 2_h)           return _fmt(t / 1_h, "h", fmtStr);
		if (t <= -2_min || t >= 2_min)       return _fmt(t / 1_min, "min", fmtStr);
		if (t <= -1_s || t >= 1_s || !t)     return _fmt(t / 1_s, "s", fmtStr);
		if (t <= -1_ms || t >= 1_ms)         return _fmt(t / 1_ms, "ms", fmtStr);
		if (t <= -1_us || t >= 1_us)         return _fmt(t / 1_us, "µs", fmtStr);
		if (t <= -1_ns || t >= 1_ns)         return _fmt(t / 1_ns, "ns", fmtStr);
		return _fmt(t / 1_ps, "ps", fmtStr);
	}

	/// @brief Returns the given mass as string using SI units.
	FUNC std::string to_string(mass m, const char* fmtStr = to_string_format) {
		if (m <= -1_Pt || m >= 1_Pt)       return _fmt(m / 1_Pt, "Pt", fmtStr);
		if (m <= -1_Tt || m >= 1_Tt)       return _fmt(m / 1_Tt, "Tt", fmtStr);
		if (m <= -1_Gt || m >= 1_Gt)       return _fmt(m / 1_Gt, "Gt", fmtStr);
		if (m <= -1_Mt || m >= 1_Mt)       return _fmt(m / 1_Mt, "Mt", fmtStr);
		if (m <= -1_kt || m >= 1_kt)       return _fmt(m / 1_kt, "kt", fmtStr);
		if (m <= -1_t  || m >= 1_t)        return _fmt(m / 1_t, "t", fmtStr);
		if (m <= -1_kg || m >= 1_kg)       return _fmt(m / 1_kg, "kg", fmtStr);
		if (m <= -1_g  || m >= 1_g || !m)  return _fmt(m / 1_g, "g", fmtStr);
		if (m <= -1_mg || m >= 1_mg)       return _fmt(m / 1_mg, "mg", fmtStr);
		if (m <= -1_ug || m >= 1_ug)       return _fmt(m / 1_ug, "µg", fmtStr);
		return _fmt(m / 1_ng, "ng", fmtStr);
	}

	/// @brief Returns the given temperature as string using SI units.
	FUNC std::string to_string(temperature T, const char* fmtStr = to_string_format) {
		if (T <= -1_GK || T >= 1_GK)         return _fmt(T / 1_GK, "GK", fmtStr);
		if (T <= -1_MK || T >= 1_MK)         return _fmt(T / 1_MK, "MK", fmtStr);
		if (T >= -150_degC && T <= 150_degC) return _fmt(celsius(T), "°C", fmtStr); // human temperature range
		if (T <= -1_K || T >= 1_K || !T)     return _fmt(T / 1_K, "K", fmtStr);
		if (T <= -1_mK || T >= 1_mK)         return _fmt(T / 1_mK, "mK", fmtStr);
		if (T <= -1_uK || T >= 1_uK)         return _fmt(T / 1_uK, "µK", fmtStr);
		return _fmt(T / 1_nK, "nK", fmtStr);
	}

	/// @brief Returns the electric current as string using SI units.
	inline std::string to_string(current I, const char* fmtStr = to_string_format) {
		if (I <= -1_GA || I >= 1_GA)      return _fmt(I / 1_GA, "GA", fmtStr);
		if (I <= -1_MA || I >= 1_MA)      return _fmt(I / 1_MA, "MA", fmtStr);
		if (I <= -1_kA || I >= 1_kA)      return _fmt(I / 1_kA, "kA", fmtStr);
		if (I <= -1_A  || I >= 1_A || !I) return _fmt(I / 1_A, "A", fmtStr);
		if (I <= -1_mA || I >= 1_mA)      return _fmt(I / 1_mA, "mA", fmtStr);
		if (I <= -1_uA || I >= 1_uA)      return _fmt(I / 1_uA, "µA", fmtStr);
		if (I <= -1_nA || I >= 1_nA)      return _fmt(I / 1_nA, "nA", fmtStr);
		return _fmt(I / 1_pA, "pA", fmtStr);
	}

	// Derived SI Units
	// ----------------

	/// @brief Returns the given area as string using SI units.
	FUNC std::string to_string(area a, const char* fmtStr = to_string_format) {
		if (a <= -1_km2 || a >= 1_km2)      return _fmt(a / 1_km2, "km²", fmtStr);
		if (a <= -1_hm2 || a >= 1_hm2)      return _fmt(a / 1_hm2, "hm²", fmtStr);
		if (a <= -1_m2  || a >= 1_m2 || !a) return _fmt(a / 1_m2, "m²", fmtStr);
		if (a <= -1_cm2 || a >= 1_cm2)      return _fmt(a / 1_cm2, "cm²", fmtStr);
		if (a <= -1_mm2 || a >= 1_mm2)      return _fmt(a / 1_mm2, "mm²", fmtStr);
		return _fmt(a / 1_um2, "µm²", fmtStr);
	}

	/// @brief Returns the per area as string using SI units.
	FUNC std::string to_string(per_area a, const char* fmtStr = to_string_format) {
		if (a <= -1_per_km2 || a >= 1_per_km2)      return _fmt(a / 1_per_km2, "/km²", fmtStr);
		if (a <= -1_per_hm2 || a >= 1_per_hm2)      return _fmt(a / 1_per_hm2, "/hm²", fmtStr);
		if (a <= -1_per_m2  || a >= 1_per_m2 || !a) return _fmt(a / 1_per_m2, "/m²", fmtStr);
		if (a <= -1_per_cm2 || a >= 1_per_cm2)      return _fmt(a / 1_per_cm2, "/cm²", fmtStr);
		if (a <= -1_per_mm2 || a >= 1_per_mm2)      return _fmt(a / 1_per_mm2, "/mm²", fmtStr);
		return _fmt(a / 1_per_μm2, "/μm²", fmtStr);
	}

	/// @brief Returns the given volume as string using SI units.
	FUNC std::string to_string(volume v, const char* fmtStr = to_string_format) {
		if (v <= -1_km3|| v >= 1_km3)     return _fmt(v / 1_km3, "km³", fmtStr);
		if (v <= -1_m3 || v >= 1_m3)      return _fmt(v / 1_m3, "m³", fmtStr);
		if (v <= -1_l  || v >= 1_l || !v) return _fmt(v / 1_l, "l", fmtStr);
		if (v <= -1_ml || v >= 1_ml)      return _fmt(v / 1_ml, "ml", fmtStr);
		if (v <= -1_ul || v >= 1_ul)      return _fmt(v / 1_ul, "µl", fmtStr);
		if (v <= -1_nl || v >= 1_nl)      return _fmt(v / 1_nl, "nl", fmtStr);
		return _fmt(v / 1_pl, "pl", fmtStr);
	}

	/// @brief Returns velocity as string using SI units.
	FUNC std::string to_string(velocity v, const char* fmtStr = to_string_format) {
		if (v <= -1_km_per_s || v >= 1_km_per_s)      return _fmt(v / 1_km_per_s, "km/s", fmtStr);
		if (v <= -1_km_per_h || v >= 1_km_per_h)      return _fmt(v / 1_km_per_h, "km/h", fmtStr);
		if (v <= -1_m_per_s  || v >= 1_m_per_s || !v) return _fmt(v / 1_m_per_s, "m/s", fmtStr);
		return _fmt(v / 1_mm_per_h, "mm/h", fmtStr);
	}

	/// @brief Returns the acceleration as string using SI units.
	FUNC std::string to_string(acceleration a, const char* fmtStr = to_string_format) {
		if (a <= -1_km_per_s2 || a >= 1_km_per_s2) return _fmt(a / 1_km_per_s2, "km/s²", fmtStr);
		return _fmt(a / 1_m_per_s2, "m/s²", fmtStr);
	}

	/// @brief Returns the frequency as string using SI units.
	FUNC std::string to_string(frequency f, const char* fmtStr = to_string_format) {
		if (f <= -1_THz || f >= 1_THz)      return _fmt(f / 1_THz, "THz", fmtStr);
		if (f <= -1_GHz || f >= 1_GHz)      return _fmt(f / 1_GHz, "GHz", fmtStr);
		if (f <= -1_MHz || f >= 1_MHz)      return _fmt(f / 1_MHz, "MHz", fmtStr);
		if (f <= -1_kHz || f >= 1_kHz)      return _fmt(f / 1_kHz, "kHz", fmtStr);
		if (f <= -1_Hz  || f >= 1_Hz || !f) return _fmt(f / 1_Hz, "Hz", fmtStr);
		if (f <= -1_mHz || f >= 1_mHz)      return _fmt(f / 1_mHz, "mHz", fmtStr);
		return _fmt(f / 1_uHz, "µHz", fmtStr);
	}

	/// @brief Returns the force as string using SI units.
	FUNC std::string to_string(force F, const char* fmtStr = to_string_format) {
		if (F <= -1_ZN || F >= 1_ZN)      return _fmt(F / 1_ZN, "ZN", fmtStr);
		if (F <= -1_EN || F >= 1_EN)      return _fmt(F / 1_EN, "EN", fmtStr);
		if (F <= -1_PN || F >= 1_PN)      return _fmt(F / 1_PN, "PN", fmtStr);
		if (F <= -1_TN || F >= 1_TN)      return _fmt(F / 1_TN, "TN", fmtStr);
		if (F <= -1_GN || F >= 1_GN)      return _fmt(F / 1_GN, "GN", fmtStr);
		if (F <= -1_MN || F >= 1_MN)      return _fmt(F / 1_MN, "MN", fmtStr);
		if (F <= -1_kN || F >= 1_kN)      return _fmt(F / 1_kN, "kN", fmtStr);
		if (F <= -1_N  || F >= 1_N || !F) return _fmt(F / 1_N, "N", fmtStr);
		if (F <= -1_mN || F >= 1_mN)      return _fmt(F / 1_mN, "mN", fmtStr);
		if (F <= -1_uN || F >= 1_uN)      return _fmt(F / 1_uN, "µN", fmtStr);
		if (F <= -1_nN || F >= 1_nN)      return _fmt(F / 1_nN, "nN", fmtStr);
		return _fmt(F / 1_pN, "pN", fmtStr);
	}

	/// @brief Returns the energy as string using SI units.
	FUNC std::string to_string(energy E, const char* fmtStr = to_string_format) {
		if (E <= -1_PJ || E >= 1_PJ)      return _fmt(E / 1_PJ, "PJ", fmtStr);
		if (E <= -1_TJ || E >= 1_TJ)      return _fmt(E / 1_TJ, "TJ", fmtStr);
		if (E <= -1_GJ || E >= 1_GJ)      return _fmt(E / 1_GJ, "GJ", fmtStr);
		if (E <= -1_MJ || E >= 1_MJ)      return _fmt(E / 1_MJ, "MJ", fmtStr);
		if (E <= -1_kJ || E >= 1_kJ)      return _fmt(E / 1_kJ, "kJ", fmtStr);
		if (E <= -1_J  || E >= 1_J || !E) return _fmt(E / 1_J, "J", fmtStr);
		return _fmt(E / 1_mJ, "mJ", fmtStr);
	}

	/// @brief Returns the power as string using SI units.
	FUNC std::string to_string(power P, const char* fmtStr = to_string_format) {
		if (P <= -1_TW || P >= 1_TW)      return _fmt(P / 1_TW, "TW", fmtStr);
		if (P <= -1_GW || P >= 1_GW)      return _fmt(P / 1_GW, "GW", fmtStr);
		if (P <= -1_MW || P >= 1_MW)      return _fmt(P / 1_MW, "MW", fmtStr);
		if (P <= -1_kW || P >= 1_kW)      return _fmt(P / 1_kW, "kW", fmtStr);
		if (P <= -1_W  || P >= 1_W || !P) return _fmt(P / 1_W, "W", fmtStr);
		if (P <= -1_mW || P >= 1_mW)      return _fmt(P / 1_mW, "mW", fmtStr);
		return _fmt(P / 1_uW, "µW", fmtStr);
	}

	/// @brief Returns the power intensity as string using SI units.
	FUNC std::string to_string(power_intensity I, const char* fmtStr = to_string_format) {
		if (I <= -1_MW_per_m2 || I >= 1_MW_per_m2)      return _fmt(I / 1_MW_per_m2, "MW/m²", fmtStr);
		if (I <= -1_kW_per_m2 || I >= 1_kW_per_m2)      return _fmt(I / 1_kW_per_m2, "kW/m²", fmtStr);
		if (I <= -1_W_per_m2  || I >= 1_W_per_m2 || !I) return _fmt(I / 1_W_per_m2, "W/m²", fmtStr);
		return _fmt(I / 1_mW_per_m2, "mW/m²", fmtStr);
	}

	/// @brief Returns the pressure as string using SI units.
	FUNC std::string to_string(pressure p, const char* fmtStr = to_string_format) {
		if (p <= -1_MPa || p >= 1_MPa)      return _fmt(p / 1_MPa, "MPa", fmtStr);
		if (p <= -1_kPa || p >= 1_kPa)      return _fmt(p / 1_kPa, "kPa", fmtStr);
		if (p <= -1_hPa || p >= 1_hPa)      return _fmt(p / 1_hPa, "hPa", fmtStr);
		if (p <= -1_Pa  || p >= 1_Pa || !p) return _fmt(p / 1_Pa, "Pa", fmtStr);
		if (p <= -1_mPa || p >= 1_mPa)      return _fmt(p / 1_mPa, "mPa", fmtStr);
		return _fmt(p / 1_uPa, "µPa", fmtStr);
	}

	/// @brief Returns the electric potential as string using SI units.
	FUNC std::string to_string(potential U, const char* fmtStr = to_string_format) {
		if (U <= -1_TV || U >= 1_TV)      return _fmt(U / 1_TV, "TV", fmtStr);
		if (U <= -1_GV || U >= 1_GV)      return _fmt(U / 1_GV, "GV", fmtStr);
		if (U <= -1_MV || U >= 1_MV)      return _fmt(U / 1_MV, "MV", fmtStr);
		if (U <= -1_kV || U >= 1_kV)      return _fmt(U / 1_kV, "kV", fmtStr);
		if (U <= -1_V  || U >= 1_V || !U) return _fmt(U / 1_V, "V", fmtStr);
		if (U <= -1_mV || U >= 1_mV)      return _fmt(U / 1_mV, "mV", fmtStr);
		if (U <= -1_uV || U >= 1_uV)      return _fmt(U / 1_uV, "µV", fmtStr);
		if (U <= -1_nV || U >= 1_nV)      return _fmt(U / 1_nV, "nV", fmtStr);
		return _fmt(U / 1_pV, "pV", fmtStr);
	}

	/// @brief Returns the electric charge as string using SI units.
	FUNC std::string to_string(charge Q, const char* fmtStr = to_string_format) {
		if (Q <= -1_GAh || Q >= 1_GAh)      return _fmt(Q / 1_GAh, "GAh", fmtStr);
		if (Q <= -1_MAh || Q >= 1_MAh)      return _fmt(Q / 1_MAh, "MAh", fmtStr);
		if (Q <= -1_kAh || Q >= 1_kAh)      return _fmt(Q / 1_kAh, "kAh", fmtStr);
		if (Q <= -1_Ah  || Q >= 1_Ah || !Q) return _fmt(Q / 1_Ah, "Ah", fmtStr);
		if (Q <= -1_mAh || Q >= 1_mAh)      return _fmt(Q / 1_mAh, "mAh", fmtStr);
		return _fmt(Q / 1_uAh, "µAh", fmtStr);
	}

	/// @brief Returns the mass per area as string using SI units.
	FUNC std::string to_string(mass_per_area m, const char* fmtStr = to_string_format) {
		if (m <= -1_t_per_m2 || m >= 1_t_per_m2) return _fmt(m / 1_t_per_m2, "t/m²", fmtStr);
		return _fmt(m / 1_kg_per_m2, "kg/m²", fmtStr);
	}

	/// @brief Returns the mass per power as string using SI units.
	FUNC std::string to_string(mass_per_power m, const char* fmtStr = to_string_format) {
		if (m <= -1_kg_per_kW || m >= 1_kg_per_kW) return _fmt(m / 1_kg_per_kW, "kg/kW", fmtStr);
		return _fmt(m / 1_kg_per_W, "kg/W", fmtStr);
	}

	/// @brief Returns density as string using SI units.
	FUNC std::string to_string(density d, const char* fmtStr = to_string_format) {
		if (d <= -1_t_per_m3 || d >= 1_t_per_m3) return _fmt(d / 1_t_per_m3, "t/m³", fmtStr);
		return _fmt(d / 1_kg_per_m3, "kg/m³", fmtStr);
	}

	/// @brief Returns the digital size as string in bits and bytes.
	FUNC std::string to_string(data_size n, const char* fmtStr = to_string_format) {
		if (n <= -1_QB || n >= 1_QB)        return _fmt(n / 1_QB, "QB", fmtStr);
		if (n <= -1_RB || n >= 1_RB)        return _fmt(n / 1_RB, "RB", fmtStr);
		if (n <= -1_YB || n >= 1_YB)        return _fmt(n / 1_YB, "YB", fmtStr);
		if (n <= -1_ZB || n >= 1_ZB)        return _fmt(n / 1_ZB, "ZB", fmtStr);
		if (n <= -1_EB || n >= 1_EB)        return _fmt(n / 1_EB, "EB", fmtStr);
		if (n <= -1_PB || n >= 1_PB)        return _fmt(n / 1_PB, "PB", fmtStr);
		if (n <= -1_TB || n >= 1_TB)        return _fmt(n / 1_TB, "TB", fmtStr);
		if (n <= -1_GB || n >= 1_GB)        return _fmt(n / 1_GB, "GB", fmtStr);
		if (n <= -1_MB || n >= 1_MB)        return _fmt(n / 1_MB, "MB", fmtStr);
		if (n <= -1_kB || n >= 1_kB)        return _fmt(n / 1_kB, "kB", fmtStr);
		if (n <= -8_bit|| n >= 8_bit || !n) return _fmt(n / 8_bit, "bytes", fmtStr);
		return _fmt(n / 1_bit, "bit", fmtStr);
	}

	FUNC std::string to_string(data_per_time n, const char* fmtStr = to_string_format) {
		return _fmt(n / 1_MB_per_s, "MB/s", fmtStr);
	}

	FUNC std::string to_string(data_per_area n, const char* fmtStr = to_string_format) {
		return _fmt(n / 1_MB_per_cm2, "MB/cm²", fmtStr);
	}

	FUNC std::string to_string(data_per_volume n, const char* fmtStr = to_string_format) {
		return _fmt(n / 1_MB_per_cm3, "MB/cm³", fmtStr);
	}

	/// @brief Returns the angle as string in degree.
	FUNC std::string to_string(angle a, const char* fmtStr = to_string_format) {
		return _fmt(a / 1_deg, "°", fmtStr);
	}

	// to_equivalent() Function Overloading
	// ------------------------------------

	/// @brief Returns a length equivalent as string, e.g. in Imperial units.
	FUNC std::string to_equivalent(length d, const char* fmtStr = to_equivalent_format) {
		if (d <= -1_ly || d >= 1_ly) return _fmt(d / 1_ly, "light-years", fmtStr);
		if (d <= -1_ls || d >= 1_ls) return _fmt(d / 1_ls, "light-seconds", fmtStr);
		if (d <= -1_mi || d >= 1_mi) return _fmt(d / 1_mi, "mi", fmtStr);
		if (d <= -1_yd || d >= 1_yd) return _fmt(d / 1_yd, "yd", fmtStr);
		if (d <= -1_ft || d >= 1_ft) return _fmt(d / 1_ft, "ft", fmtStr);
		return _fmt(d / 1_in, "in", fmtStr);
	}

	/// @brief Returns a mass equivalent as string, e.g. in Imperial units.
	FUNC std::string to_equivalent(mass m, const char* fmtStr = to_equivalent_format) {
		if (m <= -1_Msun || m >= 1_Msun)     return _fmt(m / 1_Msun, "solar masses", fmtStr);
		if (m <= -1_Mjup || m >= 1_Mjup)     return _fmt(m / 1_Mjup, "Jupiter masses", fmtStr);
		if (m <= -1_Mearth || m >= 1_Mearth) return _fmt(m / 1_Mearth, "Earth masses", fmtStr);
		if (m <= -1_Mmoon || m >= 1_Mmoon)   return _fmt(m / 1_Mmoon, "Moon masses", fmtStr);
		if (m <= -1_lb || m >= 1_lb)         return _fmt(m / 1_lb, "lb", fmtStr);
		return _fmt(m / 1_oz, "oz", fmtStr);
	}

	/// @brief Returns a temperature equivalent as string, e.g. in Fahrenheit.
	FUNC std::string to_equivalent(temperature T, const char* fmtStr = to_equivalent_format) {
		return _fmt(fahrenheit(T), "°F", fmtStr);
	}

	/// @brief Returns a velocity equivalent as string, e.g. in Imperial units.
	FUNC std::string to_equivalent(velocity V, const char* fmtStr = to_equivalent_format) {
		if (V <= -1_Mach || V >= 1_Mach) return _fmt(V / 1_Mach, "Mach", fmtStr);
		return _fmt(V / 1_mi_per_h, "mph", fmtStr);
	}

	/// @brief Returns a power intensity equivalent as string, e.g. in dB.
	FUNC std::string to_equivalent(power_intensity I, const char* fmtStr = to_equivalent_format) {
		return _fmt(10.0 * std::log10((I / 1_W_per_m2) / 1e-12), "dB", fmtStr);
	}

	/// @brief Returns an energy equivalent as string, e.g. kg TNT.
	FUNC std::string to_equivalent(energy E, const char* fmtStr = to_equivalent_format) {
		constexpr auto Hiroshima_bomb = 62_TJ; // (explosion energy of the Hiroshima bomb)
		if (E >= Hiroshima_bomb)
			return _fmt(E / Hiroshima_bomb, "Hiroshima bombs", fmtStr);

		constexpr auto one_kg_TNT = 4.184_MJ; // (explosion energy of 1kg Trinitrotoluol)
		if (E >= one_kg_TNT)
			return _fmt(E / one_kg_TNT, "kg TNT", fmtStr);

		constexpr auto one_g_TNT = 4.184_kJ; // (explosion energy of 1g Trinitrotoluol)
		return _fmt(E / one_g_TNT, "g TNT", fmtStr);
	}

	/// @brief Returns a data size equivalent as string.
	FUNC std::string to_equivalent(data_size n, const char* fmtStr = to_equivalent_format) {
		if (n <= -1_PiB || n >= 1_PiB) return _fmt(n / 1_PiB, "PiB", fmtStr);
		if (n <= -1_TiB || n >= 1_TiB) return _fmt(n / 1_TiB, "TiB", fmtStr);
		if (n <= -1_GiB || n >= 1_GiB) return _fmt(n / 1_GiB, "GiB", fmtStr);
		if (n <= -1_MiB || n >= 1_MiB) return _fmt(n / 1_MiB, "MiB", fmtStr);
		if (n <= -1_KiB || n >= 1_KiB) return _fmt(n / 1_KiB, "KiB", fmtStr);
		if (n <= -8_bit || n >= 8_bit) return _fmt(n / 8_bit, "bytes", fmtStr);
		if (n < -1_bit  || n > 1_bit)  return _fmt(n / 1_bit, "bits", fmtStr);
		return _fmt(n / 1_bit, "bit", fmtStr);
	}

	// to_percentage() Function Overloading
	// ------------------------------------

	/// @brief Returns the percentage as string, e.g. "50.0%"
	FUNC std::string to_percentage(length part, length total, const char* fmtStr = to_percentage_format) {
		return _fmt((part / total) * 100.0, "%", fmtStr);
	}

	/// @brief Returns the percentage as string, e.g. "50.0%"
	FUNC std::string to_percentage(mass part, mass total, const char* fmtStr = to_percentage_format) {
		return _fmt((part / total) * 100.0, "%", fmtStr);
	}

	/// @brief Returns the percentage as string, e.g. "50.0%"
	FUNC std::string to_percentage(velocity part, velocity total, const char* fmtStr = to_percentage_format) {
		return _fmt((part / total) * 100.0, "%", fmtStr);
	}

	/// @brief Returns the percentage as string, e.g. "50.0%"
	FUNC std::string to_percentage(data_size part, data_size total, const char* fmtStr = to_percentage_format) {
		return _fmt((part / total) * 100.0, "%", fmtStr);
	}

	// Operator <<
	// -----------
	inline std::ostream& operator<<(std::ostream& o, length n) { return o << to_string(n); }
	inline std::ostream& operator<<(std::ostream& o, time n) { return o << to_string(n); }
	inline std::ostream& operator<<(std::ostream& o, mass n) { return o << to_string(n); }
	inline std::ostream& operator<<(std::ostream& o, temperature n) { return o << to_string(n); }
	inline std::ostream& operator<<(std::ostream& o, current n) { return o << to_string(n); }
	inline std::ostream& operator<<(std::ostream& o, area n) { return o << to_string(n); }
	inline std::ostream& operator<<(std::ostream& o, per_area n) { return o << to_string(n); }
	inline std::ostream& operator<<(std::ostream& o, volume n) { return o << to_string(n); }
	inline std::ostream& operator<<(std::ostream& o, velocity n) { return o << to_string(n); }
	inline std::ostream& operator<<(std::ostream& o, acceleration n) { return o << to_string(n); }
	inline std::ostream& operator<<(std::ostream& o, frequency n) { return o << to_string(n); }
	inline std::ostream& operator<<(std::ostream& o, force n) { return o << to_string(n); }
	inline std::ostream& operator<<(std::ostream& o, energy n) { return o << to_string(n); }
	inline std::ostream& operator<<(std::ostream& o, power n) { return o << to_string(n); }
	inline std::ostream& operator<<(std::ostream& o, power_intensity n) { return o << to_string(n); }
	inline std::ostream& operator<<(std::ostream& o, pressure n) { return o << to_string(n); }
	inline std::ostream& operator<<(std::ostream& o, potential n) { return o << to_string(n); }
	inline std::ostream& operator<<(std::ostream& o, charge n) { return o << to_string(n); }
	inline std::ostream& operator<<(std::ostream& o, mass_per_area n) { return o << to_string(n); }
	inline std::ostream& operator<<(std::ostream& o, mass_per_power n) { return o << to_string(n); }
	inline std::ostream& operator<<(std::ostream& o, density n) { return o << to_string(n); }
	inline std::ostream& operator<<(std::ostream& o, data_size n) { return o << to_string(n); }
	inline std::ostream& operator<<(std::ostream& o, data_per_time n) { return o << to_string(n); }
	inline std::ostream& operator<<(std::ostream& o, data_per_area n) { return o << to_string(n); }
	inline std::ostream& operator<<(std::ostream& o, data_per_volume n) { return o << to_string(n); }

	// References
	// ----------
	// 1. https://en.wikipedia.org/wiki/International_System_of_Units

} // end of namespace

#undef parse
#undef FUNC
