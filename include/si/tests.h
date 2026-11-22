/// @file      <si/tests.h>
/// @brief     Contains 300+ unit tests
/// @details   The unit tests are executed at compile-time and on each commit by GitHub actions.
///            Categories are: features, datatypes, base units, derived units, astronomical units, Imperial units, digital data units, angles, ratios, various, functions and templates, SI prefixes.

#pragma once
#include <cassert>
#include <si/literals.h>
#include <si/prefixes.h>
#define EXACT(_condition) static_assert(_condition)
#define NEARLY0(_delta)   static_assert(_delta > -1e-10 && _delta < 1e-10)

namespace si {

  inline void check_features() { // shows what's possible - the serious checks follow below
	EXACT( 3_m == meters(3) );
	EXACT( 3_m == 3 * 1_m );
	EXACT( 1_km + 1_m + 1_dm + 1_cm + 1_mm == 1001.111_m );
	EXACT( 1_km / 30_min == 2_km_per_h );
	EXACT( 1_m * 2_m == 2_m2 );
	EXACT( 1_m * 2_m * 3_m == 6_m3 );
	EXACT( (1_m * 2_m * 3_m) / 2_s == 3_m3_per_s );
	EXACT( 1000 / 1_s == 1_kHz );
	EXACT( 1_Mach == 330_m_per_s );
	EXACT( 1_Mach * 10_pct == 33_m_per_s );
	EXACT( (0_degC + 32_degF + 491.67_degR + 273.15_K) / 4 == 273.15_K );
	EXACT( 1_A * 1_h == 3600_C );
	EXACT( 1_Ah == 3600_C );
	EXACT( 8_bit == 1_byte );
	EXACT( 16_bit == 2_byte );
  }

  inline void check_datatypes() {
	EXACT(sizeof(length) == sizeof(SIdouble));
	EXACT(sizeof(mass) == sizeof(SIdouble));
	EXACT(sizeof(time) == sizeof(SIdouble));
	EXACT(sizeof(temperature) == sizeof(SIdouble));
	EXACT(sizeof(current) == sizeof(SIdouble));
	EXACT(sizeof(substance) == sizeof(SIdouble));
	EXACT(sizeof(luminous_intensity) == sizeof(SIdouble));
	EXACT(sizeof(data_size) == sizeof(SIdouble));
	EXACT(sizeof(dimensionless) == sizeof(SIdouble));
  }

  inline void check_SI_base_units() {
	// length in...
	EXACT(1_Pm == 1000_Tm);
	EXACT(1_Tm == 1000_Gm);
	EXACT(1_Gm == 1000_Mm);
	EXACT(1_Mm == 1000_km);
	EXACT(1_km == 1000_m);
	EXACT(1_km == kilometers(1));
	EXACT(1_m  == 10_dm);
	EXACT(1_m  == 100_cm);
	EXACT(1_m  == meters(1));
	EXACT(1_m  == 1000_mm);
	EXACT(1_m  == 0.001_km);
	EXACT(1_dm == 0.1_m);
	EXACT(1_cm == 0.01_m);
	EXACT(1_mm == 0.001_m);
	EXACT(1_mm == millimeters(1));
	EXACT(1_um == 0.001_mm);
	EXACT(1_nm == 0.001_um);
	// time in...
	EXACT(1_d   == 24_h);
	EXACT(1_h   == 60_min);
	EXACT(1_h   == hours(1));
	EXACT(1_min == 60_s);
	EXACT(1_min == minutes(1));
	EXACT(1_s   == 1000_ms);
	EXACT(1_s   == seconds(1));
	EXACT(1_ms  == 0.001_s);
	EXACT(1_us  == 0.001_ms);
	EXACT(1_ns  == 0.001_us);
	// mass in...
	EXACT(1_Gt == 1000_Mt);
	EXACT(1_Mt == 1000_kt);
	EXACT(1_kt == 1000_t);
	EXACT(1_t  == 1000_kg);
	EXACT(1_kg == 1000_g);
	EXACT(1_kg == kilograms(1));
	EXACT(1_g  == 0.001_kg);
	EXACT(1_mg == 0.001_g);
	EXACT(1_ug == 0.001_mg);
	// thermodynamic temperature in...
	EXACT(1_GK == 1000_MK);
	EXACT(1_MK == 1000_kK);
	EXACT(1_kK == 1000_K);
	EXACT(1_mK == 0.001_K);
	EXACT(1_uK == 0.001_mK);
	EXACT(1_nK == 0.001_uK);
	// electric current in...
	EXACT(1_GA == 1000_MA);
	EXACT(1_MA == 1000_kA);
	EXACT(1_kA == 1000_A);
	EXACT(1_A  == 1000_mA);
	EXACT(1_A  == amperes(1));
	EXACT(1_mA == 0.001_A);
	EXACT(1_uA == 0.001_mA);
	EXACT(1_nA == 0.001_uA);
	// amount of substance in...
	EXACT(1_Gmol == 1000_Mmol);
	EXACT(1_Mmol == 1000_kmol);
	EXACT(1_kmol == 1000_mol);
	EXACT(1_mol  == 0.001_kmol);
	EXACT(1_mol  == moles(1));
	EXACT(1_mmol == 0.001_mol);
	EXACT(1_umol == 0.001_mmol);
	EXACT(1_nmol == 0.001_umol);
	// luminous intensity in...
	EXACT(1_kcd == 1000_cd);
	EXACT(1_cd == 0.001_kcd);
	EXACT(1_cd == candelas(1));
  }

  inline void check_SI_derived_units() {
	// area in...
	EXACT(1_km2 == 1_km * 1_km);
	EXACT(1_km2 == 100_hm2);
	EXACT(1_hm2 == 10'000_m2);
	EXACT(1_hm2 == 100_m * 100_m);
	EXACT(1_m2  == 10'000_cm2);
	EXACT(1_m2  == meters2(1));
	EXACT(1_cm2 == 0.0001_m2);
	EXACT(1_m2  == 1_m * 1_m);
	EXACT(1_cm2 == 1_cm * 1_cm);
	EXACT(1_mm2 == 1_mm * 1_mm);
	// volume in...
	EXACT(1_km3 == 1_km * 1_km * 1_km);
	EXACT(1_km3 == 1e9_m3);
	EXACT(1_m3  == 1_m * 1_m * 1_m);
	EXACT(1_m3  == meters3(1));
	EXACT(1_m3  == 1e6_cm3);
	EXACT(1_cm3 == 0.000'001_m3);
	// static_assert(1_cm3 == 1_cm * 1_cm * 1_cm);
	// velocity in...
	EXACT(1_km_per_s == 1000_m_per_s);
	EXACT(3.6_km_per_h == 1_m_per_s);
	EXACT(1_km_per_h == 1_km / 1_h);
	EXACT(1_km_per_h == 1000_m / 1_h);
	EXACT(1_km_per_h == 1_km / 60_min);
	EXACT(1_km_per_h == 1000_m / 60_min);
	EXACT(1_km_per_h == 1_km / 3600_s);
	EXACT(1_km_per_h == 1000_m / 3600_s);
	EXACT(1_km_per_h == 500_m / 1800_s);
	// acceleration in...
	EXACT(1_km_per_s2 == 1000_m_per_s2);
	EXACT(0.001_km_per_s2 == 1_m_per_s2);
	// frequency in...
	EXACT(1_PHz == 1000_THz);
	EXACT(1_THz == 1000_GHz);
	EXACT(1_GHz == 1000_MHz);
	EXACT(1_MHz == 1000_kHz);
	EXACT(1_kHz == 1000_Hz);
	EXACT(1_Hz  == 0.001_kHz);
	EXACT(1_Hz  == hertz(1));
	EXACT(1_Hz  == 0.000001_MHz);
	EXACT(1_Hz  == 0.000000001_GHz);
	EXACT(1_mHz == 0.001_Hz);
	// radioactive activity (A) in...
	EXACT(1_TBq == 1000_GBq);
	EXACT(1_GBq == 1000_MBq);
	EXACT(1_MBq == 1000_kBq);
	EXACT(1_kBq == 1000_Bq);
	// equivalent dose (H) and effective dose (E) in...
	EXACT(1_Sv  == 1000_mSv);
	EXACT(1_mSv == 1000_uSv);
	// mass per area in...
	EXACT(1_t_per_m2 == 1000_kg_per_m2);
	// mass per volume in...
	EXACT(1_t_per_m3 == 1000_kg_per_m3);
	// electric potential (U) in...
	EXACT(1_GV == 1000_MV);
	EXACT(1_MV == 1000_kV);
	EXACT(1_kV == 1000_V);
	EXACT(1_V  == 1000_mV);
	EXACT(1_V  == volts(1));
	EXACT(1_mV == 1000_uV);
	// electric resistance (R) in...
	EXACT(1_GOhm == 1000_MOhm);
	EXACT(1_MOhm == 1000_kOhm);
	EXACT(1_kOhm == 1000_Ohm);
	EXACT(1_Ohm  == 1000_mOhm);
	EXACT(1_Ohm  == ohms(1));
	EXACT(1_mOhm == 1000_uOhm);
	// electric conductance (G) in...
	EXACT(1_MS == 1000_kS);
	EXACT(1_kS == 1000_S);
	EXACT(1_S  == 1000_mS);
	EXACT(1_mS == 1000_uS);
	// electric conductivity (σ) in...
	EXACT(1_MS_per_m == 1000_kS_per_m);
	EXACT(1_kS_per_m == 1000_S_per_m);
	// electric charge (Q) in...
	EXACT(1_GAh == 1000_MAh);
	EXACT(1_MAh == 1000_kAh);
	EXACT(1_kAh == 1000_Ah);
	EXACT(1_Ah  == 1000_mAh);
	EXACT(1_mAh == 1000_uAh);
	// electric capacitance (C) in...
	EXACT(1_F  == 1000_mF);
	EXACT(1_mF == 1000_uF);
	EXACT(1_nF == 1000_pF);
	// electric inductance (L) in...
	EXACT(1_H   == 1000_mH);
	EXACT(1_mH  == 1000_uH);
	// magnetic field (B) in...
	EXACT(1_T  == 1000_mT);
	EXACT(1_T  == teslas(1));
	EXACT(1_mT == 1000_uT);
	// energy (E) in...
	EXACT(1_PJ == 1000_TJ);
	EXACT(1_TJ == 1000_GJ);
	EXACT(1_GJ == 1000_MJ);
	EXACT(1_MJ == 1000_kJ);
	EXACT(1_kJ == 1000_J);
	EXACT(1_J  == 1000_mJ);
	EXACT(1_J  == joules(1));
	// active power (P) in...
	EXACT(1_TW == 1000_GW);
	EXACT(1_GW == 1000_MW);
	EXACT(1_MW == 1000_kW);
	EXACT(1_kW == 1000_W);
	EXACT(1_W  == 1000_mW);
	EXACT(1_W  == watts(1));
	EXACT(1_mW == 1000_uW);
	// pressure (p) in...
	EXACT(1_MPa == 1000_kPa);
	EXACT(1_kPa == 1000_Pa);
	EXACT(1_Pa  == 1000_mPa);
	EXACT(1_Pa  == pascals(1));
	EXACT(1_mPa == 1000_uPa);
	// force (F) in...
	EXACT(1_GN == 1000_MN);
	EXACT(1_MN == 1000_kN);
	EXACT(1_kN == 1000_N);
	EXACT(1_N  == 1000_mN);
	EXACT(1_N  == newtons(1));
	EXACT(1_mN == 1000_uN);
	// luminous flux per area in...
	EXACT(1_klx == 1000_lx);
	EXACT(1_lx  == 1000_mlx);
	EXACT(1_lx  == lux(1));
	EXACT(1_mlx == 1000_ulx);
  }

  inline void check_astronomical_units() {
	EXACT(1_Gpc == 1000_Mpc);
	EXACT(1_Mpc == 1000_kpc);
	EXACT(1_kpc == 1000_pc);
  }

  inline void check_Imperial_units() {
	EXACT(1_nmi == 10_cable);
	EXACT(1_nmi == 1852_m);
	EXACT(1_nmi == nautical_miles(1));
	EXACT(1_mi  == 1760_yd);
	EXACT(1_mi  == 80_ch);
	EXACT(1_mi  == statute_miles(1));
	EXACT(1_mi_per_h == miles_per_h(1));
	EXACT(1_ft  == feet(1));
	EXACT(1_in  == inches(1));
	EXACT(1_lb  == 16_oz);
	EXACT(1_degF== fahrenheit(1));
  }

  inline void check_digital_data_units() {
	// bits...
	EXACT(1_Ebit == 1000_Pbit);
	EXACT(1_Pbit == 1000_Tbit);
	EXACT(1_Tbit == 1000_Gbit);
	EXACT(1_Gbit == 1000_Mbit);
	EXACT(1_Mbit == 1000_kbit);
	EXACT(1_kbit == 1000_bit);
	EXACT(1_bit  == bits(1));
	EXACT(1_bit  == 0.001_kbit);
	EXACT(4_bit  == 1_nibble);
	// bits per seconds...
	EXACT(1_Ebit_per_s == 1000_Pbit_per_s);
	EXACT(1_Pbit_per_s == 1000_Tbit_per_s);
	EXACT(1_Tbit_per_s == 1000_Gbit_per_s);
	EXACT(1_Gbit_per_s == 1000_Mbit_per_s);
	EXACT(1_Mbit_per_s == 1000_kbit_per_s);
	EXACT(1_kbit_per_s == bits_per_s(1000));
	// bytes with metric prefixes...
	EXACT(1_ZB   == 1000_EB);
	EXACT(1_EB   == 1000_PB);
	EXACT(1_PB   == 1000_TB);
	EXACT(1_TB   == 1000_GB);
	EXACT(1_GB   == 1000_MB);
	EXACT(1_MB   == 1000_kB);
	EXACT(1_kB   == 1000_byte);
	EXACT(1_byte == bytes(1));
	EXACT(1_byte == 8_bit);
	// bytes with binary prefixes...
	EXACT(1_TiB == 1024_GiB);
	EXACT(1_GiB == 1024_MiB);
	EXACT(1_MiB == 1024_KiB);
	EXACT(1_KiB == 1024_byte);
	// bytes per second with metric prefixes...
	EXACT(1_PB_per_s == 1000_TB_per_s);
	EXACT(1_TB_per_s == 1000_GB_per_s);
	EXACT(1_GB_per_s == 1000_MB_per_s);
	EXACT(1_MB_per_s == 1000_KB_per_s);
	EXACT(1_KB_per_s == 1000_byte_per_s);
	EXACT(1_KB_per_s == bytes_per_s(1000));
	// bytes per second with binary prefixes...
	EXACT(1_TiB_per_s == 1024_GiB_per_s);
	EXACT(1_GiB_per_s == 1024_MiB_per_s);
	EXACT(1_MiB_per_s == 1024_KiB_per_s);
	EXACT(1_KiB_per_s == 1024_byte_per_s);
  }

  inline void check_angles() {
	EXACT(0_rad == 0_mrad);
	EXACT(0_rad == 0_deg);
	EXACT(0_rad == 0_arcmin);
	EXACT(0_rad == 0_arcsec);
	EXACT(0_rad == radians(0));
	EXACT(1_rad == 1000_mrad);
	NEARLY0(180_deg - constant::pi);
	NEARLY0(180_deg - 10800_arcmin);
	NEARLY0(180_deg - 648000_arcsec);
  }

  inline void check_ratios() {
	EXACT( 0.10 == 10_pct);
	EXACT( 0.10 == 1000_bp);
	NEARLY0(0.10 - 100'000_ppm);
	NEARLY0(0.10 - 100'000'000_ppb);
	NEARLY0(0.10 - 100'000'000'000_ppt);
  }

  inline void check_various_units() {
	// pressure in...
	EXACT(1_bar  == 1000_mbar);
	EXACT(1_kbar == 1000_bar);
	EXACT(1_Mbar == 1000_kbar);
	EXACT(1_Gbar == 1000_Mbar);
	// temperature in...
	EXACT(0_degC == 273.15_K);
	//NEARLY0(491.67_degR - 273.15_K);
  }

  inline void check_functions_and_templates() {
	EXACT(abs(-3.5_m) == 3.5_m);
	EXACT(abs(-1_m)   == 1_m);
	EXACT(abs(0_m)    == 0_m);
	EXACT(abs(1_m)    == 1_m);
	EXACT(abs(5.6_m)  == 5.6_m);

	EXACT(square(-3_m) == 9_m2);
	EXACT(square(-1_m) == 1_m2);
	EXACT(square(-.5_m)== .25_m2);
	EXACT(square(0_m)  == 0_m2);
	EXACT(square(.5_m) == .25_m2);
	EXACT(square(1_m)  == 1_m2);
	EXACT(square(3_m)  == 9_m2);

	// static_assert(sqrt(9_m2) == 3_m); (TODO)

	EXACT(cube(-3_m) == -27_m3);
	EXACT(cube(-1_m) == -1_m3);
	EXACT(cube(-.5_m)== -0.125_m3);
	EXACT(cube(0_m)  == 0_m3);
	EXACT(cube(.5_m) == 0.125_m3);
	EXACT(cube(1_m)  == 1_m3);
	EXACT(cube(3_m)  == 27_m3);

	// static_assert(cbrt(27_m3) == 3_m); (TODO)

	EXACT(clamp(-2_m, -1_m,1_m) == -1_m);
	EXACT(clamp(-1_m, 0_m,1_m) == 0_m);
	EXACT(clamp(-1_m, 1_m,2_m) == 1_m);
	EXACT(clamp(-0.5_m, 1_m,2_m) == 1_m);
	EXACT(clamp(0_m, 0_m,1_m) == 0_m);
	EXACT(clamp(0_m, -1_m,2_m) == 0_m);
	EXACT(clamp(3_m, 4_m,5_m) == 4_m);
	EXACT(clamp(3_m, 1_m,2_m) == 2_m);
  }

  inline void check_SI_prefixes() {
        EXACT(quetta == 1000 * ronna);
        EXACT(ronna  == 1000 * yotta);
        EXACT(yotta  == 1000 * zetta);
        EXACT(zetta  == 1000 * exa);
        EXACT(exa    == 1000 * peta);
        EXACT(peta   == 1000 * tera);
        EXACT(tera   == 1000 * giga);
        EXACT(giga   == 1000 * mega);
        EXACT(mega   == 1000 * kilo);
        EXACT(kilo   ==   10 * hecto);
        EXACT(hecto  ==   10 * deca);
        EXACT(deca   ==  100 * deci);
        EXACT(deci   ==   10 * centi);
        EXACT(centi  ==   10 * milli);
        EXACT(milli  == 1000 * micro);
        NEARLY0(micro - 1000 * nano);
        NEARLY0(nano  - 1000 * pico);
        NEARLY0(pico  - 1000 * femto);
        NEARLY0(femto - 1000 * atto);
        NEARLY0(atto  - 1000 * zepto);
        NEARLY0(zepto - 1000 * yocto);
        NEARLY0(yocto - 1000 * ronto);
        NEARLY0(ronto - 1000 * quecto);
  }

} // end of namespace

#undef EXACT
#undef NEARLY0
