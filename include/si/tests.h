/// @file      <si/tests.h>
/// @brief     Contains 300+ unit tests
/// @details   The unit tests are executed at compile-time and on each commit by GitHub actions.
///            Categories are: some features, base units, derived units, astronomical units, Imperial units, digital data units, angles, ratios, various, functions and templates, SI prefixes.

#pragma once
#include <cassert>
#include <si/literals.h>
#include <si/prefixes.h>
#define TEST(_condition)     static_assert(_condition)
#define NEARLY_EQUAL(_a, _b) static_assert((_a) * 1.000000001 >= (_b) && (_a) <= (_b) * 1.000000001)

namespace si {

  inline void check_some_features() { // just show what's possible - the serious checks follow below
	TEST( 3_m == meters(3) );
	TEST( 3_m == 3 * 1_m );
	TEST( 1_km + 1_m + 1_dm + 1_cm + 1_mm == 1001.111_m );
	TEST( 1_km / 30_min == 2_km_per_h );
	TEST( 1_m * 2_m == 2_m2 );
	TEST( 1_m * 2_m * 3_m == 6_m3 );
	TEST( (1_m * 2_m * 3_m) / 2_s == 3_m3_per_s );
	TEST( 1000 / 1_s == 1_kHz );
	TEST( 1_Mach == 330_m_per_s );
	TEST( 1_Mach * 10_pct == 33_m_per_s );
	TEST( (0_degC + 32_degF + 491.67_degR + 273.15_K) / 4 == 273.15_K );
	TEST( 1_A * 1_h == 3600_C );
	TEST( 1_Ah == 3600_C );
	TEST( 8_bit == 1_byte );
	TEST( 16_bit == 2_byte );
  }

  inline void check_SI_base_units() {
	// length in...
	TEST( 1_Pm == 1000_Tm );
	TEST( 1_Tm == 1000_Gm );
	TEST( 1_Gm == 1000_Mm );
	TEST( 1_Mm == 1000_km );
	TEST( 1_km == 1000_m  );
	TEST( 1_m  == meters(1));
	TEST( 1_m  == 10_dm   );
	TEST( 1_dm == 10_cm   );
	TEST( 1_cm == 10_mm   );
	TEST( 1_mm == 1000_um );
	NEARLY_EQUAL(1_um, 1000_nm);
	NEARLY_EQUAL(1_nm, 1000_pm);
	// time in...
	TEST( 1_d   == 24_h );
	TEST( 1_h   == 60_min );
	TEST( 1_h   == hours(1) );
	TEST( 1_min == 60_s );
	TEST( 1_s   == 1000_ms );
	TEST( 1_s   == seconds(1) );
	TEST( 1_ms  == 0.001_s );
	TEST( 1_us  == 0.001_ms );
	TEST( 1_ns  == 0.001_us );
	// mass in...
	TEST( 1_Gt == 1000_Mt );
	TEST( 1_Mt == 1000_kt );
	TEST( 1_kt == 1000_t );
	TEST( 1_t  == 1000_kg );
	TEST( 1_kg == 1000_g );
	TEST( 1_kg == kilograms(1) );
	TEST( 1_g  == 0.001_kg );
	TEST( 1_mg == 0.001_g );
	TEST( 1_ug == 0.001_mg );
	// thermodynamic temperature in...
	TEST( 1_GK == 1000_MK );
	TEST( 1_MK == 1000_kK );
	TEST( 1_kK == 1000_K );
	TEST( 1_mK == 0.001_K );
	TEST( 1_uK == 0.001_mK );
	TEST( 1_nK == 0.001_uK );
	// electric current in...
	TEST( 1_GA == 1000_MA );
	TEST( 1_MA == 1000_kA );
	TEST( 1_kA == 1000_A );
	TEST( 1_A  == 1000_mA );
	TEST( 1_A  == amperes(1) );
	TEST( 1_mA == 0.001_A );
	TEST( 1_uA == 0.001_mA );
	TEST( 1_nA == 0.001_uA );
	// amount of substance in...
	TEST( 1_Gmol == 1000_Mmol );
	TEST( 1_Mmol == 1000_kmol );
	TEST( 1_kmol == 1000_mol );
	TEST( 1_mol  == 0.001_kmol );
	TEST( 1_mol  == moles(1) );
	TEST( 1_mmol == 0.001_mol );
	TEST( 1_umol == 0.001_mmol );
	TEST( 1_nmol == 0.001_umol );
	// luminous intensity in...
	TEST( 1_kcd == 1000_cd );
	TEST( 1_cd == 0.001_kcd );
	TEST( 1_cd == candelas(1) );
  }

  inline void check_SI_derived_units() {
	// area in...
	TEST( 1_km2 == 1_km * 1_km );
	TEST( 1_km2 == 100_hm2 );
	TEST( 1_hm2 == 10'000_m2 );
	TEST( 1_hm2 == 100_m * 100_m );
	TEST( 1_m2  == 10'000_cm2 );
	TEST( 1_m2  == meters2(1) );
	TEST( 1_cm2 == 0.0001_m2 );
	TEST( 1_m2  == 1_m * 1_m );
	TEST( 1_cm2 == 1_cm * 1_cm );
	TEST( 1_mm2 == 1_mm * 1_mm );
	// volume in...
	TEST( 1_km3 == 1_km * 1_km * 1_km );
	TEST( 1_km3 == 1e9_m3 );
	TEST( 1_m3  == 1_m * 1_m * 1_m );
	TEST( 1_m3  == meters3(1) );
	TEST( 1_m3  == 1e6_cm3 );
	TEST( 1_cm3 == 0.000'001_m3 );
	// static_assert(1_cm3 == 1_cm * 1_cm * 1_cm);
	// velocity in...
	TEST( 1_km_per_s == 1000_m_per_s );
	TEST( 3.6_km_per_h == 1_m_per_s );
	TEST( 1_km_per_h == 1_km / 1_h );
	TEST( 1_km_per_h == 1000_m / 1_h );
	TEST( 1_km_per_h == 1_km / 60_min );
	TEST( 1_km_per_h == 1000_m / 60_min );
	TEST( 1_km_per_h == 1_km / 3600_s );
	TEST( 1_km_per_h == 1000_m / 3600_s );
	TEST( 1_km_per_h == 500_m / 1800_s );
	// acceleration in...
	TEST(1_km_per_s2 == 1000_m_per_s2);
	TEST(0.001_km_per_s2 == 1_m_per_s2);
	// frequency in...
	TEST( 1_PHz == 1000_THz );
	TEST( 1_THz == 1000_GHz );
	TEST( 1_GHz == 1000_MHz );
	TEST( 1_MHz == 1000_kHz );
	TEST( 1_kHz == 1000_Hz );
	TEST( 1_Hz  == hertz(1) );
	TEST( 1_mHz == 0.001_Hz );
	TEST( 1_uHz == 0.001_mHz );
	// radioactive activity (A) in...
	TEST(1_TBq == 1000_GBq);
	TEST(1_GBq == 1000_MBq);
	TEST(1_MBq == 1000_kBq);
	TEST(1_kBq == 1000_Bq);
	// equivalent dose (H) and effective dose (E) in...
	TEST(1_Sv  == 1000_mSv);
	TEST(1_mSv == 1000_uSv);
	// mass per area in...
	TEST(1_t_per_m2 == 1000_kg_per_m2);
	// mass per volume in...
	TEST(1_t_per_m3 == 1000_kg_per_m3);
	// electric potential (U) in...
	TEST(1_GV == 1000_MV);
	TEST(1_MV == 1000_kV);
	TEST(1_kV == 1000_V);
	TEST(1_V  == 1000_mV);
	TEST(1_V  == volts(1));
	TEST(1_mV == 1000_uV);
	// electric resistance (R) in...
	TEST(1_GOhm == 1000_MOhm);
	TEST(1_MOhm == 1000_kOhm);
	TEST(1_kOhm == 1000_Ohm);
	TEST(1_Ohm  == 1000_mOhm);
	TEST(1_Ohm  == ohms(1));
	TEST(1_mOhm == 1000_uOhm);
	// electric conductance (G) in...
	TEST(1_MS == 1000_kS);
	TEST(1_kS == 1000_S);
	TEST(1_S  == 1000_mS);
	TEST(1_mS == 1000_uS);
	// electric conductivity (σ) in...
	TEST(1_MS_per_m == 1000_kS_per_m);
	TEST(1_kS_per_m == 1000_S_per_m);
	// electric charge (Q) in...
	TEST(1_GAh == 1000_MAh);
	TEST(1_MAh == 1000_kAh);
	TEST(1_kAh == 1000_Ah);
	TEST(1_Ah  == 1000_mAh);
	TEST(1_mAh == 1000_uAh);
	// electric capacitance (C) in...
	TEST(1_F  == 1000_mF);
	TEST(1_mF == 1000_uF);
	TEST(1_nF == 1000_pF);
	// electric inductance (L) in...
	TEST(1_H   == 1000_mH);
	TEST(1_mH  == 1000_uH);
	// magnetic field (B) in...
	TEST(1_T  == 1000_mT);
	TEST(1_T  == teslas(1));
	TEST(1_mT == 1000_uT);
	// energy (E) in...
	TEST(1_PJ == 1000_TJ);
	TEST(1_TJ == 1000_GJ);
	TEST(1_GJ == 1000_MJ);
	TEST(1_MJ == 1000_kJ);
	TEST(1_kJ == 1000_J);
	TEST(1_J  == 1000_mJ);
	TEST(1_J  == joules(1));
	// active power (P) in...
	TEST(1_TW == 1000_GW);
	TEST(1_GW == 1000_MW);
	TEST(1_MW == 1000_kW);
	TEST(1_kW == 1000_W);
	TEST(1_W  == 1000_mW);
	TEST(1_W  == watts(1));
	TEST(1_mW == 1000_uW);
	// pressure (p) in...
	TEST(1_MPa == 1000_kPa);
	TEST(1_kPa == 1000_Pa);
	TEST(1_Pa  == 1000_mPa);
	TEST(1_Pa  == pascals(1));
	TEST(1_mPa == 1000_uPa);
	// force (F) in...
	TEST(1_GN == 1000_MN);
	TEST(1_MN == 1000_kN);
	TEST(1_kN == 1000_N);
	TEST(1_N  == 1000_mN);
	TEST(1_N  == newtons(1));
	TEST(1_mN == 1000_uN);
	// luminous flux per area in...
	TEST(1_klx == 1000_lx);
	TEST(1_lx  == 1000_mlx);
	TEST(1_lx  == lux(1));
	TEST(1_mlx == 1000_ulx);
  }

  inline void check_astronomical_units() {
	TEST(1_Gpc == 1000_Mpc);
	TEST(1_Mpc == 1000_kpc);
	TEST(1_kpc == 1000_pc);
  }

  inline void check_Imperial_units() {
	TEST(1_nmi == 10_cable);
	TEST(1_nmi == 1852_m);
	TEST(1_nmi == nautical_miles(1));
	TEST(1_mi  == 1760_yd);
	TEST(1_mi  == 80_ch);
	TEST(1_mi  == statute_miles(1));
	TEST(1_mi_per_h == miles_per_h(1));
	TEST(1_ft  == feet(1));
	TEST(1_in  == inches(1));
	TEST(1_lb  == 16_oz);
	TEST(1_degF== fahrenheit(1));
  }

  inline void check_digital_data_units() {
	// bits...
	TEST(1_Ebit == 1000_Pbit);
	TEST(1_Pbit == 1000_Tbit);
	TEST(1_Tbit == 1000_Gbit);
	TEST(1_Gbit == 1000_Mbit);
	TEST(1_Mbit == 1000_kbit);
	TEST(1_kbit == 1000_bit);
	TEST(1_bit  == bits(1));
	TEST(1_bit  == 0.001_kbit);
	TEST(4_bit  == 1_nibble);
	// bits per seconds...
	TEST(1_Ebit_per_s == 1000_Pbit_per_s);
	TEST(1_Pbit_per_s == 1000_Tbit_per_s);
	TEST(1_Tbit_per_s == 1000_Gbit_per_s);
	TEST(1_Gbit_per_s == 1000_Mbit_per_s);
	TEST(1_Mbit_per_s == 1000_kbit_per_s);
	TEST(1_kbit_per_s == bits_per_s(1000));
	// bytes with metric prefixes...
	TEST(1_ZB   == 1000_EB);
	TEST(1_EB   == 1000_PB);
	TEST(1_PB   == 1000_TB);
	TEST(1_TB   == 1000_GB);
	TEST(1_GB   == 1000_MB);
	TEST(1_MB   == 1000_kB);
	TEST(1_kB   == 1000_byte);
	TEST(1_byte == bytes(1));
	TEST(1_byte == 8_bit);
	// bytes with binary prefixes...
	TEST(1_TiB == 1024_GiB);
	TEST(1_GiB == 1024_MiB);
	TEST(1_MiB == 1024_KiB);
	TEST(1_KiB == 1024_byte);
	// bytes per second with metric prefixes...
	TEST(1_PB_per_s == 1000_TB_per_s);
	TEST(1_TB_per_s == 1000_GB_per_s);
	TEST(1_GB_per_s == 1000_MB_per_s);
	TEST(1_MB_per_s == 1000_KB_per_s);
	TEST(1_KB_per_s == 1000_byte_per_s);
	TEST(1_KB_per_s == bytes_per_s(1000));
	// bytes per second with binary prefixes...
	TEST(1_TiB_per_s == 1024_GiB_per_s);
	TEST(1_GiB_per_s == 1024_MiB_per_s);
	TEST(1_MiB_per_s == 1024_KiB_per_s);
	TEST(1_KiB_per_s == 1024_byte_per_s);
  }

  inline void check_angles() {
	TEST( 0_rad == 0_mrad );
	TEST( 0_rad == 0_deg );
	TEST( 0_rad == 0_arcmin );
	TEST( 0_rad == 0_arcsec );
	TEST( 0_rad == radians(0) );
	TEST( 1_rad == 1000_mrad );
	NEARLY_EQUAL( 180_deg, constant::pi );
	NEARLY_EQUAL( 180_deg, 10800_arcmin );
	NEARLY_EQUAL( 180_deg, 648000_arcsec );
  }

  inline void check_ratios() {
	TEST( 0.10 == 10_pct);
	TEST( 0.10 == 1000_bp);
	NEARLY_EQUAL(0.10, 100'000_ppm);
	NEARLY_EQUAL(0.10, 100'000'000_ppb);
	NEARLY_EQUAL(0.10, 100'000'000'000_ppt);
  }

  inline void check_various_units() {
	// pressure in...
	TEST(1_bar  == 1000_mbar);
	TEST(1_kbar == 1000_bar);
	TEST(1_Mbar == 1000_kbar);
	TEST(1_Gbar == 1000_Mbar);
	// temperature in...
	NEARLY_EQUAL(0_degC, 273.15_K);
	NEARLY_EQUAL(0_degC, 32.0_degF);
	NEARLY_EQUAL(491.67_degR, 273.15_K);
  }

  inline void check_functions_and_templates() {
	TEST(abs(-3.5_m) == 3.5_m);
	TEST(abs(-1_m)   == 1_m);
	TEST(abs(0_m)    == 0_m);
	TEST(abs(1_m)    == 1_m);
	TEST(abs(5.6_m)  == 5.6_m);

	TEST(square(-3_m) == 9_m2);
	TEST(square(-1_m) == 1_m2);
	TEST(square(-.5_m)== .25_m2);
	TEST(square(0_m)  == 0_m2);
	TEST(square(.5_m) == .25_m2);
	TEST(square(1_m)  == 1_m2);
	TEST(square(3_m)  == 9_m2);

	// static_assert(sqrt(9_m2) == 3_m);

	TEST(cube(-3_m) == -27_m3);
	TEST(cube(-1_m) == -1_m3);
	TEST(cube(-.5_m)== -0.125_m3);
	TEST(cube(0_m)  == 0_m3);
	TEST(cube(.5_m) == 0.125_m3);
	TEST(cube(1_m)  == 1_m3);
	TEST(cube(3_m)  == 27_m3);

	// static_assert(cbrt(27_m3) == 3_m);

	TEST(clamp(-2_m, -1_m,1_m) == -1_m);
	TEST(clamp(-1_m, 0_m,1_m) == 0_m);
	TEST(clamp(-1_m, 1_m,2_m) == 1_m);
	TEST(clamp(-0.5_m, 1_m,2_m) == 1_m);
	TEST(clamp(0_m, 0_m,1_m) == 0_m);
	TEST(clamp(0_m, -1_m,2_m) == 0_m);
	TEST(clamp(3_m, 4_m,5_m) == 4_m);
	TEST(clamp(3_m, 1_m,2_m) == 2_m);
  }

  inline void check_SI_prefixes() {
	TEST(quetta == 1000 * ronna);
	TEST(ronna  == 1000 * yotta);
	TEST(yotta  == 1000 * zetta);
	TEST(zetta  == 1000 * exa);
	TEST(exa    == 1000 * peta);
	TEST(peta   == 1000 * tera);
	TEST(tera   == 1000 * giga);
	TEST(giga   == 1000 * mega);
	TEST(mega   == 1000 * kilo);
	TEST(kilo   ==   10 * hecto);
	TEST(hecto  ==   10 * deca);
	TEST(deca   ==  100 * deci);
	TEST(deci   ==   10 * centi);
	TEST(centi  ==   10 * milli);
	TEST(milli  == 1000 * micro);
	NEARLY_EQUAL(micro, 1000 * nano);
	NEARLY_EQUAL(nano,  1000 * pico);
	NEARLY_EQUAL(pico,  1000 * femto);
	NEARLY_EQUAL(femto, 1000 * atto);
	NEARLY_EQUAL(atto,  1000 * zepto);
	NEARLY_EQUAL(zepto, 1000 * yocto);
	NEARLY_EQUAL(yocto, 1000 * ronto);
	NEARLY_EQUAL(ronto, 1000 * quecto);
  }
} // end of namespace

#undef TEST
#undef NEARLY_EQUAL
