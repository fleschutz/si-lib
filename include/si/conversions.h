/// @file     si/conversions.h
/// @brief    Provides some conversion functions, e.g. to_string(12_m).
/// @details  Defines the operator << and the functions: from_string(), to_string(), to_equivalent(), and to_percentage().

#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <si/literals.h>
#define FUNC [[nodiscard]] inline

namespace si
{
	// Default Format Strings (Configurable)
	// -------------------------------------
	inline auto to_string_format     = "%.2Lf %s"; ///< SI standard formatting by default
	inline auto to_equivalent_format = "%.2Lf %s"; ///< SI standard formatting by default
	inline auto to_percentage_format = "%.0Lf%s"; 

	// from_string() Function Overloading
	// ----------------------------------
	/// @brief The from_string() function
	FUNC bool from_string(const std::string& str, length& result)
	{
		double value = 0.0;
		char unit[100] = "";
		if (std::sscanf(str.c_str(), "%lf%99s", &value, unit) != 2)
			return false; // not recognized

		if (!std::strcmp(unit, "Gm"))      result = 1_Gm * value;
		else if (!std::strcmp(unit, "Mm")) result = 1_Mm * value;
		else if (!std::strcmp(unit, "km")) result = 1_km * value;
		else if (!std::strcmp(unit, "m"))  result = 1_m * value;
		else if (!std::strcmp(unit, "dm")) result = 1_dm * value;
		else if (!std::strcmp(unit, "cm")) result = 1_cm * value;
		else if (!std::strcmp(unit, "mm")) result = 1_mm * value;
		else if (!std::strcmp(unit, "um")) result = 1_um * value;
		else if (!std::strcmp(unit, "nm")) result = 1_nm * value;
		else if (!std::strcmp(unit, "pm")) result = 1_pm * value;
		else
			return false; // unknown unit

		return true;
	}

	FUNC bool from_string(const std::string& str, time& result)
	{
		double value = 0.0;
		char unit[100] = "";
		if (std::sscanf(str.c_str(), "%lf%99s", &value, unit) != 2)
			return false; // not recognized

		if (!std::strcmp(unit, "d"))       result = 1_d * value;
		else if (!std::strcmp(unit, "h"))  result = 1_h * value;
		else if (!std::strcmp(unit, "m"))  result = 1_min * value;
		else if (!std::strcmp(unit, "s"))  result = 1_s * value;
		else if (!std::strcmp(unit, "ms")) result = 1_ms * value;
		else if (!std::strcmp(unit, "us")) result = 1_us * value;
		else if (!std::strcmp(unit, "ns")) result = 1_ns * value;
		else if (!std::strcmp(unit, "ps")) result = 1_ps * value;
		else
			return false; // unknown unit

		return true;
	}

	FUNC bool from_string(const std::string& str, mass& result)
	{
		double value = 0.0;
		char unit[100] = "";
		if (std::sscanf(str.c_str(), "%lf%99s", &value, unit) != 2)
			return false; // not recognized

		if (!std::strcmp(unit, "Gt"))      result = 1_Gt * value;
		else if (!std::strcmp(unit, "Mt")) result = 1_Mt * value;
		else if (!std::strcmp(unit, "kt")) result = 1_kt * value;
		else if (!std::strcmp(unit, "t"))  result = 1_t * value;
		else if (!std::strcmp(unit, "kg")) result = 1_kg * value;
		else if (!std::strcmp(unit, "g"))  result = 1_g * value;
		else if (!std::strcmp(unit, "mg")) result = 1_mg * value;
		else if (!std::strcmp(unit, "ug")) result = 1_ug * value;
		else if (!std::strcmp(unit, "ng")) result = 1_ng * value;
		else
			return false; // unknown unit

		return true;
	}

	/// @brief Internal function to format quantity and unit into a string by using a format string.
	FUNC std::string _fmt(long double quantity, const char* unit, const char* formatString)
	{
		char buf[256] = "";
		std::snprintf(buf, sizeof(buf), formatString, quantity, unit);
		return std::string(buf);
	}

	// to_string() Function Overloading
	// --------------------------------

	/// @brief Returns the given length as string using SI units.
	FUNC std::string to_string(length d, const char* fmtStr = to_string_format)
	{
		if (d <= -1_Gpc || d >= 1_Gpc)         return _fmt(d / 1_Gpc, "Gpc", fmtStr); // gigaparsec
		if (d <= -1_Mpc || d >= 1_Mpc)         return _fmt(d / 1_Mpc, "Mpc", fmtStr); // megaparsec
		if (d <= -1_kpc || d >= 1_kpc)         return _fmt(d / 1_kpc, "kpc", fmtStr); // kiloparsec
		if (d <= -1_pc || d >= 1_pc)           return _fmt(d / 1_pc, "pc", fmtStr);   // parsec
		if (d <= -1_ly || d >= 1_ly)           return _fmt(d / 1_ly, "ly", fmtStr);   // light-year
		if (d <= -0.1_au || d >= 0.1_au)       return _fmt(d / 1_au, "au", fmtStr);   // astronomical unit
		if (d <= -1_km || d >= 1_km)           return _fmt(d / 1_km, "km", fmtStr);   // kilometer
		if (d <= -1_m || d >= 1_m || d == 0_m) return _fmt(d / 1_m, "m", fmtStr);     // meter
		if (d <= -1_cm || d >= 1_cm)           return _fmt(d / 1_cm, "cm", fmtStr);   // centimeter
		if (d <= -1_mm || d >= 1_mm)           return _fmt(d / 1_mm, "mm", fmtStr);   // millimeter
		if (d <= -1_um || d >= 1_um)           return _fmt(d / 1_um, "µm", fmtStr);   // micrometer
		if (d <= -1_nm || d >= 1_nm)           return _fmt(d / 1_nm, "nm", fmtStr);   // nanometer
		return _fmt(d / 1_pm, "pm", fmtStr);
	}

	FUNC std::ostream& operator<<(std::ostream& os, length d)
	{
		return (os << to_string(d));
	}

	/// @brief Returns the given time as string using SI units.
	FUNC std::string to_string(time t, const char* fmtStr = to_string_format)
	{
		if (t <= -365.25_d || t >= 365.25_d)   return _fmt(t / 365.25_d, "y", fmtStr);
		if (t <= -1_w || t >= 1_w)             return _fmt(t / 1_w, "w", fmtStr);
		if (t <= -2_d || t >= 2_d)             return _fmt(t / 1_d, "d", fmtStr);
		if (t <= -2_h || t >= 2_h)             return _fmt(t / 1_h, "h", fmtStr);
		if (t <= -2_min || t >= 2_min)         return _fmt(t / 1_min, "min", fmtStr);
		if (t <= -1_s || t >= 1_s || t == 0_s) return _fmt(t / 1_s, "s", fmtStr);
		if (t <= -1_ms || t >= 1_ms)           return _fmt(t / 1_ms, "ms", fmtStr);
		if (t <= -1_us || t >= 1_us)           return _fmt(t / 1_us, "µs", fmtStr);
		if (t <= -1_ns || t >= 1_ns)           return _fmt(t / 1_ns, "ns", fmtStr);
		return _fmt(t / 1_ps, "ps", fmtStr);
	}

	FUNC std::ostream& operator<<(std::ostream& os, time t)
	{
		return (os << to_string(t));
	}

	/// @brief Returns the given mass as string using SI units.
	FUNC std::string to_string(mass m, const char* fmtStr = to_string_format)
	{
		if (m <= -1_Pt || m >= 1_Pt)              return _fmt(m / 1_Pt, "Pt", fmtStr);
		if (m <= -1_Tt || m >= 1_Tt)              return _fmt(m / 1_Tt, "Tt", fmtStr);
		if (m <= -1_Gt || m >= 1_Gt)              return _fmt(m / 1_Gt, "Gt", fmtStr);
		if (m <= -1_Mt || m >= 1_Mt)              return _fmt(m / 1_Mt, "Mt", fmtStr);
		if (m <= -1_kt || m >= 1_kt)              return _fmt(m / 1_kt, "kt", fmtStr);
		if (m <= -1_t || m >= 1_t)                return _fmt(m / 1_t, "t", fmtStr);
		if (m <= -1_kg || m >= 1_kg || m == 0_kg) return _fmt(m / 1_kg, "kg", fmtStr);
		if (m <= -1_g || m >= 1_g)                return _fmt(m / 1_g, "g", fmtStr);
		if (m <= -1_mg || m >= 1_mg)              return _fmt(m / 1_mg, "mg", fmtStr);
		if (m <= -1_ug || m >= 1_ug)              return _fmt(m / 1_ug, "µg", fmtStr);
		return _fmt(m / 1_ng, "ng", fmtStr);
	}

	FUNC std::ostream& operator<<(std::ostream& os, mass m)
	{
		return (os << to_string(m));
	}

	/// @brief Returns the given temperature as string using SI units.
	FUNC std::string to_string(temperature T, const char* fmtStr = to_string_format)
	{
		if (T >= 1_GK)                       return _fmt(T / 1_GK, "GK", fmtStr);
		if (T >= 1_MK)                       return _fmt(T / 1_MK, "MK", fmtStr);
		if (T >= -150_degC && T <= 150_degC) return _fmt(celsius(T), "°C", fmtStr); // human temperature range
		if (T >= 1_K || T == 0.0_K)          return _fmt(T / 1_K, "K", fmtStr);
		if (T >= 1_mK)                       return _fmt(T / 1_mK, "mK", fmtStr);
		if (T >= 1_uK)                       return _fmt(T / 1_uK, "µK", fmtStr);
		return _fmt(T / 1_nK, "nK", fmtStr);
	}

	FUNC std::ostream& operator<<(std::ostream& os, temperature T)
	{
		return (os << to_string(T));
	}

	/// @brief Returns the electric current as string using SI units.
	inline std::string to_string(current I, const char* fmtStr = to_string_format)
	{
		if (I <= -1_GA || I >= 1_GA)           return _fmt(I / 1_GA, "GA", fmtStr);
		if (I <= -1_MA || I >= 1_MA)           return _fmt(I / 1_MA, "MA", fmtStr);
		if (I <= -1_kA || I >= 1_kA)           return _fmt(I / 1_kA, "kA", fmtStr);
		if (I <= -1_A || I >= 1_A || I == 0_A) return _fmt(I / 1_A, "A", fmtStr);
		if (I <= -1_mA || I >= 1_mA)           return _fmt(I / 1_mA, "mA", fmtStr);
		if (I <= -1_uA || I >= 1_uA)           return _fmt(I / 1_uA, "µA", fmtStr);
		if (I <= -1_nA || I >= 1_nA)           return _fmt(I / 1_nA, "nA", fmtStr);
		return _fmt(I / 1_pA, "pA", fmtStr);
	}

	FUNC std::ostream& operator<<(std::ostream& os, current I)
	{
		return (os << to_string(I));
	}

	// Convert the 22 derived SI units:

	/// @brief Returns the given area as string using SI units.
	FUNC std::string to_string(area a, const char* fmtStr = to_string_format)
	{
		if (a <= -1_km² || a >= 1_km²)            return _fmt(a / 1_km², "km²", fmtStr);
		if (a <= -1_hm² || a >= 1_hm²)            return _fmt(a / 1_hm², "hm²", fmtStr);
		if (a <= -1_m² || a >= 1_m² || a == 0_m²) return _fmt(a / 1_m², "m²", fmtStr);
		if (a <= -1_cm² || a >= 1_cm²)            return _fmt(a / 1_cm², "cm²", fmtStr);
		if (a <= -1_mm² || a >= 1_mm²)            return _fmt(a / 1_mm², "mm²", fmtStr);
		return _fmt(a / 1_um², "µm²", fmtStr);
	}

	FUNC std::ostream& operator<<(std::ostream& os, area a)
	{
		return (os << to_string(a));
	}

	/// @brief Returns the per area as string using SI units.
	FUNC std::string to_string(per_area a, const char* fmtStr = to_string_format)
	{
		if (a <= -1_per_km² || a >= 1_per_km²)                return _fmt(a / 1_per_km², "/km²", fmtStr);
		if (a <= -1_per_hm² || a >= 1_per_hm²)                return _fmt(a / 1_per_hm², "/hm²", fmtStr);
		if (a <= -1_per_m² || a >= 1_per_m² || a == 0_per_m²) return _fmt(a / 1_per_m², "/m²", fmtStr);
		if (a <= -1_per_cm² || a >= 1_per_cm²)                return _fmt(a / 1_per_cm², "/cm²", fmtStr);
		if (a <= -1_per_mm² || a >= 1_per_mm²)                return _fmt(a / 1_per_mm², "/mm²", fmtStr);
		return _fmt(a / 1_per_μm², "/μm²", fmtStr);
	}

	FUNC std::ostream& operator<<(std::ostream& os, per_area a)
	{
		return (os << to_string(a));
	}

	/// @brief Returns the given volume as string using SI units.
	FUNC std::string to_string(volume v, const char* fmtStr = to_string_format)
	{
		if (v <= -1_km³ || v >= 1_km³)         return _fmt(v / 1_km³, "km³", fmtStr);
		if (v <= -1_m³ || v >= 1_m³)           return _fmt(v / 1_m³, "m³", fmtStr);
		if (v <= -1_l || v >= 1_l || v == 0_l) return _fmt(v / 1_l, "l", fmtStr);
		if (v <= -1_ml || v >= 1_ml)           return _fmt(v / 1_ml, "ml", fmtStr);
		if (v <= -1_ul || v >= 1_ul)           return _fmt(v / 1_ul, "µl", fmtStr);
		if (v <= -1_nl || v >= 1_nl)           return _fmt(v / 1_nl, "nl", fmtStr);
		return _fmt(v / 1_pl, "pl", fmtStr);
	}

	FUNC std::ostream& operator<<(std::ostream& os, volume v)
	{
		return (os << to_string(v));
	}

	/// @brief Returns velocity as string using SI units.
	FUNC std::string to_string(velocity v, const char* fmtStr = to_string_format)
	{
		if (v <= -1_km_per_s || v >= 1_km_per_s)                 return _fmt(v / 1_km_per_s, "km/s", fmtStr);
		if (v <= -1_km_per_h || v >= 1_km_per_h)                 return _fmt(v / 1_km_per_h, "km/h", fmtStr);
		if (v <= -1_m_per_s || v >= 1_m_per_s || v == 0_m_per_s) return _fmt(v / 1_m_per_s, "m/s", fmtStr);
		return _fmt(v / 1_mm_per_h, "mm/h", fmtStr);
	}

	FUNC std::ostream& operator<<(std::ostream& os, velocity v)
	{
		return (os << to_string(v));
	}

	/// @brief Returns the acceleration as string using SI units.
	FUNC std::string to_string(acceleration a, const char* fmtStr = to_string_format)
	{
		if (a <= -1_km_per_s² || a >= 1_km_per_s²) return _fmt(a / 1_km_per_s², "km/s²", fmtStr);
		return _fmt(a / 1_m_per_s², "m/s²", fmtStr);
	}

	FUNC std::ostream& operator<<(std::ostream& os, acceleration a)
	{
		return (os << to_string(a));
	}

	/// @brief Returns the frequency as string using SI units.
	FUNC std::string to_string(frequency f, const char* fmtStr = to_string_format)
	{
		if (f <= -1_THz || f >= 1_THz)            return _fmt(f / 1_THz, "THz", fmtStr);
		if (f <= -1_GHz || f >= 1_GHz)            return _fmt(f / 1_GHz, "GHz", fmtStr);
		if (f <= -1_MHz || f >= 1_MHz)            return _fmt(f / 1_MHz, "MHz", fmtStr);
		if (f <= -1_kHz || f >= 1_kHz)            return _fmt(f / 1_kHz, "kHz", fmtStr);
		if (f <= -1_Hz || f >= 1_Hz || f == 0_Hz) return _fmt(f / 1_Hz, "Hz", fmtStr);
		if (f <= -1_mHz || f >= 1_mHz)            return _fmt(f / 1_mHz, "mHz", fmtStr);
		return _fmt(f / 1_uHz, "µHz", fmtStr);
	}

	FUNC std::ostream& operator<<(std::ostream& os, frequency f)
	{
		return (os << to_string(f));
	}

	/// @brief Returns the force as string using SI units.
	FUNC std::string to_string(force F, const char* fmtStr = to_string_format)
	{
		if (F <= -1_ZN || F >= 1_ZN)           return _fmt(F / 1_ZN, "ZN", fmtStr);
		if (F <= -1_EN || F >= 1_EN)           return _fmt(F / 1_EN, "EN", fmtStr);
		if (F <= -1_PN || F >= 1_PN)           return _fmt(F / 1_PN, "PN", fmtStr);
		if (F <= -1_TN || F >= 1_TN)           return _fmt(F / 1_TN, "TN", fmtStr);
		if (F <= -1_GN || F >= 1_GN)           return _fmt(F / 1_GN, "GN", fmtStr);
		if (F <= -1_MN || F >= 1_MN)           return _fmt(F / 1_MN, "MN", fmtStr);
		if (F <= -1_kN || F >= 1_kN)           return _fmt(F / 1_kN, "kN", fmtStr);
		if (F <= -1_N || F >= 1_N || F == 0_N) return _fmt(F / 1_N, "N", fmtStr);
		if (F <= -1_mN || F >= 1_mN)           return _fmt(F / 1_mN, "mN", fmtStr);
		if (F <= -1_uN || F >= 1_uN)           return _fmt(F / 1_uN, "µN", fmtStr);
		if (F <= -1_nN || F >= 1_nN)           return _fmt(F / 1_nN, "nN", fmtStr);
		return _fmt(F / 1_pN, "pN", fmtStr);
	}

	FUNC std::ostream& operator<<(std::ostream& os, force F)
	{
		return (os << to_string(F));
	}

	/// @brief Returns the energy as string using SI units.
	FUNC std::string to_string(energy E, const char* fmtStr = to_string_format)
	{
		if (E <= -1_PJ || E >= 1_PJ)           return _fmt(E / 1_PJ, "PJ", fmtStr);
		if (E <= -1_TJ || E >= 1_TJ)           return _fmt(E / 1_TJ, "TJ", fmtStr);
		if (E <= -1_GJ || E >= 1_GJ)           return _fmt(E / 1_GJ, "GJ", fmtStr);
		if (E <= -1_MJ || E >= 1_MJ)           return _fmt(E / 1_MJ, "MJ", fmtStr);
		if (E <= -1_kJ || E >= 1_kJ)           return _fmt(E / 1_kJ, "kJ", fmtStr);
		if (E <= -1_J || E >= 1_J || E == 0_J) return _fmt(E / 1_J, "J", fmtStr);
		return _fmt(E / 1_mJ, "mJ", fmtStr);
	}

	FUNC std::ostream& operator<<(std::ostream& os, energy E)
	{
		return (os << to_string(E));
	}

	/// @brief Returns the power as string using SI units.
	FUNC std::string to_string(power P, const char* fmtStr = to_string_format)
	{
		if (P <= -1_TW || P >= 1_TW)           return _fmt(P / 1_TW, "TW", fmtStr);
		if (P <= -1_GW || P >= 1_GW)           return _fmt(P / 1_GW, "GW", fmtStr);
		if (P <= -1_MW || P >= 1_MW)           return _fmt(P / 1_MW, "MW", fmtStr);
		if (P <= -1_kW || P >= 1_kW)           return _fmt(P / 1_kW, "kW", fmtStr);
		if (P <= -1_W || P >= 1_W || P == 0_W) return _fmt(P / 1_W, "W", fmtStr);
		if (P <= -1_mW || P >= 1_mW)           return _fmt(P / 1_mW, "mW", fmtStr);
		return _fmt(P / 1_uW, "µW", fmtStr);
	}

	FUNC std::ostream& operator<<(std::ostream& os, power P)
	{
		return (os << to_string(P));
	}

	/// @brief Returns the power intensity as string using SI units.
	FUNC std::string to_string(power_intensity I, const char* fmtStr = to_string_format)
	{
		if (I <= -1_MW_per_m² || I >= 1_MW_per_m²)                  return _fmt(I / 1_MW_per_m², "MW/m²", fmtStr);
		if (I <= -1_kW_per_m² || I >= 1_kW_per_m²)                  return _fmt(I / 1_kW_per_m², "kW/m²", fmtStr);
		if (I <= -1_W_per_m² || I >= 1_W_per_m² || I == 0_W_per_m²) return _fmt(I / 1_W_per_m², "W/m²", fmtStr);
		return _fmt(I / 1_mW_per_m², "mW/m²", fmtStr);
	}

	FUNC std::ostream& operator<<(std::ostream& os, const power_intensity I)
	{
		return (os << to_string(I));
	}

	/// @brief Returns the pressure as string using SI units.
	FUNC std::string to_string(pressure p, const char* fmtStr = to_string_format)
	{
		if (p <= -1_MPa || p >= 1_MPa)            return _fmt(p / 1_MPa, "MPa", fmtStr);
		if (p <= -1_kPa || p >= 1_kPa)            return _fmt(p / 1_kPa, "kPa", fmtStr);
		if (p <= -1_hPa || p >= 1_hPa)            return _fmt(p / 1_hPa, "hPa", fmtStr);
		if (p <= -1_Pa || p >= 1_Pa || p == 0_Pa) return _fmt(p / 1_Pa, "Pa", fmtStr);
		if (p <= -1_mPa || p >= 1_mPa)            return _fmt(p / 1_mPa, "mPa", fmtStr);
		return _fmt(p / 1_uPa, "µPa", fmtStr);
	}

	FUNC std::ostream& operator<<(std::ostream& os, pressure p)
	{
		return (os << to_string(p));
	}

	/// @brief Returns the electric potential as string using SI units.
	FUNC std::string to_string(electric_potential U, const char* fmtStr = to_string_format)
	{
		if (U <= -1_GV || U >= 1_GV)           return _fmt(U / 1_GV, "GV", fmtStr);
		if (U <= -1_MV || U >= 1_MV)           return _fmt(U / 1_MV, "MV", fmtStr);
		if (U <= -1_kV || U >= 1_kV)           return _fmt(U / 1_kV, "kV", fmtStr);
		if (U <= -1_V || U >= 1_V || U == 0_V) return _fmt(U / 1_V, "V", fmtStr);
		if (U <= -1_mV || U >= 1_mV)           return _fmt(U / 1_mV, "mV", fmtStr);
		if (U <= -1_uV || U >= 1_uV)           return _fmt(U / 1_uV, "µV", fmtStr);
		if (U <= -1_nV || U >= 1_nV)           return _fmt(U / 1_nV, "nV", fmtStr);
		return _fmt(U / 1_pV, "pV", fmtStr);
	}

	FUNC std::ostream& operator<<(std::ostream& os, electric_potential U)
	{
		return (os << to_string(U));
	}

	/// @brief Returns the electric charge as string using SI units.
	FUNC std::string to_string(electric_charge Q, const char* fmtStr = to_string_format)
	{
		if (Q <= -1_GAh || Q >= 1_GAh)            return _fmt(Q / 1_GAh, "GAh", fmtStr);
		if (Q <= -1_MAh || Q >= 1_MAh)            return _fmt(Q / 1_MAh, "MAh", fmtStr);
		if (Q <= -1_kAh || Q >= 1_kAh)            return _fmt(Q / 1_kAh, "kAh", fmtStr);
		if (Q <= -1_Ah || Q >= 1_Ah || Q == 0_Ah) return _fmt(Q / 1_Ah, "Ah", fmtStr);
		if (Q <= -1_mAh || Q >= 1_mAh)            return _fmt(Q / 1_mAh, "mAh", fmtStr);
		return _fmt(Q / 1_uAh, "µAh", fmtStr);
	}

	FUNC std::ostream& operator<<(std::ostream& os, electric_charge Q)
	{
		return (os << to_string(Q));
	}

	/// @brief Returns the mass per area as string using SI units.
	FUNC std::string to_string(mass_per_area m, const char* fmtStr = to_string_format)
	{
		if (m <= -1_t_per_m² || m >= 1_t_per_m²) return _fmt(m / 1_t_per_m², "t/m²", fmtStr);
		return _fmt(m / 1_kg_per_m², "kg/m²", fmtStr);
	}

	FUNC std::ostream& operator<<(std::ostream& os, mass_per_area m)
	{
		return (os << to_string(m));
	}

	/// @brief Returns the mass per power as string using SI units.
	FUNC std::string to_string(mass_per_power m, const char* fmtStr = to_string_format)
	{
		if (m <= -1_kg_per_kW || m >= 1_kg_per_kW) return _fmt(m / 1_kg_per_kW, "kg/kW", fmtStr);
		return _fmt(m / 1_kg_per_W, "kg/W", fmtStr);
	}

	FUNC std::ostream& operator<<(std::ostream& os, mass_per_power m)
	{
		return (os << to_string(m));
	}

	/// @brief Returns density as string using SI units.
	FUNC std::string to_string(density d, const char* fmtStr = to_string_format)
	{
		if (d <= -1_t_per_m³ || d >= 1_t_per_m³) return _fmt(d / 1_t_per_m³, "t/m³", fmtStr);
		return _fmt(d / 1_kg_per_m³, "kg/m³", fmtStr);
	}

	FUNC std::ostream& operator<<(std::ostream& os, density d)
	{
		return (os << to_string(d));
	}

	/// @brief Returns the digital size as string in bits and bytes.
	FUNC std::string to_string(digital_size n, const char* fmtStr = to_string_format)
	{
		if (n >= 1_EB)  return _fmt(n / 1_EB, "EB", fmtStr);
		if (n >= 1_PB)  return _fmt(n / 1_PB, "PB", fmtStr);
		if (n >= 1_TB)  return _fmt(n / 1_TB, "TB", fmtStr);
		if (n >= 1_GB)  return _fmt(n / 1_GB, "GB", fmtStr);
		if (n >= 1_MB)  return _fmt(n / 1_MB, "MB", fmtStr);
		if (n >= 1_kB)  return _fmt(n / 1_kB, "kB", fmtStr);
		if (n >= 8_bit) return _fmt(n / 8_bit, "bytes", fmtStr);
		if (n > 1_bit)  return _fmt(n / 1_bit, "bits", fmtStr);
		return _fmt(n / 1_bit, "bit", fmtStr);
	}

	FUNC std::ostream& operator<<(std::ostream& os, digital_size n)
	{
		return (os << to_string(n));
	}

	/// @brief Returns the angle as string in degree.
	FUNC std::string to_string(const angle a, const char* fmtStr = to_string_format)
	{
		return _fmt(a / 1_deg, "°", fmtStr);
	}

	// to_equivalent() Function Overloading
	// ------------------------------------

	/// @brief Returns a length equivalent as string, e.g. in Imperial units.
	FUNC std::string to_equivalent(length d, const char* fmtStr = to_equivalent_format)
	{
		if (d <= -1_ly || d >= 1_ly) return _fmt(d / 1_ly, "light-years", fmtStr);
		if (d <= -1_ls || d >= 1_ls) return _fmt(d / 1_ls, "light-seconds", fmtStr);
		if (d <= -1_mi || d >= 1_mi) return _fmt(d / 1_mi, "mi", fmtStr);
		if (d <= -1_yd || d >= 1_yd) return _fmt(d / 1_yd, "yd", fmtStr);
		if (d <= -1_ft || d >= 1_ft) return _fmt(d / 1_ft, "ft", fmtStr);
		return _fmt(d / 1_in, "in", fmtStr);
	}

	/// @brief Returns a mass equivalent as string, e.g. in Imperial units.
	FUNC std::string to_equivalent(mass m, const char* fmtStr = to_equivalent_format)
	{
		if (m <= -1_Msun || m >= 1_Msun)     return _fmt(m / 1_Msun, "solar masses", fmtStr);
		if (m <= -1_Mjup || m >= 1_Mjup)     return _fmt(m / 1_Mjup, "Jupiter masses", fmtStr);
		if (m <= -1_Mearth || m >= 1_Mearth) return _fmt(m / 1_Mearth, "Earth masses", fmtStr);
		if (m <= -1_Mmoon || m >= 1_Mmoon)   return _fmt(m / 1_Mmoon, "Moon masses", fmtStr);
		if (m <= -1_lb || m >= 1_lb)         return _fmt(m / 1_lb, "lb", fmtStr);
		return _fmt(m / 1_oz, "oz", fmtStr);
	}

	/// @brief Returns a temperature equivalent as string, e.g. in Fahrenheit.
	FUNC std::string to_equivalent(temperature T, const char* fmtStr = to_equivalent_format)
	{
		return _fmt(fahrenheit(T), "°F", fmtStr);
	}

	/// @brief Returns a velocity equivalent as string, e.g. in Imperial units.
	FUNC std::string to_equivalent(velocity V, const char* fmtStr = to_equivalent_format)
	{
		if (V <= -1_Mach || V >= 1_Mach) return _fmt(V / 1_Mach, "Mach", fmtStr);
		return _fmt(V / 1_mph, "mph", fmtStr);
	}

	/// @brief Returns a power intensity equivalent as string, e.g. in dB.
	FUNC std::string to_equivalent(power_intensity I, const char* fmtStr = to_equivalent_format)
	{
		return _fmt(10.0 * std::log10((I / 1_W_per_m²) / 1e-12), "dB", fmtStr);
	}

	/// @brief Returns an energy equivalent as string, e.g. kg TNT.
	FUNC std::string to_equivalent(energy E, const char* fmtStr = to_equivalent_format)
	{
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
	FUNC std::string to_equivalent(digital_size n, const char* fmtStr = to_equivalent_format)
	{
		if (n >= 1_PiB)  return _fmt(n / 1_PiB, "PiB", fmtStr);
		if (n >= 1_TiB)  return _fmt(n / 1_TiB, "TiB", fmtStr);
		if (n >= 1_GiB)  return _fmt(n / 1_GiB, "GiB", fmtStr);
		if (n >= 1_MiB)  return _fmt(n / 1_MiB, "MiB", fmtStr);
		if (n >= 1_KiB)  return _fmt(n / 1_KiB, "KiB", fmtStr);
		if (n >= 8_bit)  return _fmt(n / 8_bit, "bytes", fmtStr);
		if (n > 1_bit)   return _fmt(n / 1_bit, "bits", fmtStr);
		return _fmt(n / 1_bit, "bit", fmtStr);
	}

	// to_percentage() Function Overloading
	// ------------------------------------

	/// @brief Returns the percentage as string, e.g. "50.0%"
	FUNC std::string to_percentage(length part, length total, const char* fmtStr = to_percentage_format)
	{
		return _fmt((part / total) * 100.0, "%", fmtStr);
	}

	/// @brief Returns the percentage as string, e.g. "50.0%"
	FUNC std::string to_percentage(mass part, mass total, const char* fmtStr = to_percentage_format)
	{
		return _fmt((part / total) * 100.0, "%", fmtStr);
	}

	/// @brief Returns the percentage as string, e.g. "50.0%"
	FUNC std::string to_percentage(velocity part, velocity total, const char* fmtStr = to_percentage_format)
	{
		return _fmt((part / total) * 100.0, "%", fmtStr);
	}

	/// @brief Returns the percentage as string, e.g. "50.0%"
	FUNC std::string to_percentage(digital_size part, digital_size total, const char* fmtStr = to_percentage_format)
	{
		return _fmt((part / total) * 100.0, "%", fmtStr);
	}

	// References
	// ----------
	// 1. https://en.wikipedia.org/wiki/International_System_of_Units

} // end of namespace

#undef FUNC
