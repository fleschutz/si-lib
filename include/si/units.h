/// @file     <si/units.h>
/// @brief    Defines 100+ units, e.g. si::meters
/// @details  Categories are: SI base units, SI derived, Imperial, digital data, and various.

#pragma once
#include <si/datatypes.h>
#define UNIT inline constexpr auto

namespace si {

  // SI Base Units
  // -------------
  UNIT meters         = unit<length>();
  UNIT seconds        = unit<time>();
  UNIT kilograms      = unit<mass>();
  UNIT kelvins        = unit<temperature>();
  UNIT amperes        = unit<current>();
  UNIT moles          = unit<substance>();
  UNIT candelas       = unit<luminous_intensity>();

  // Derived SI Units
  // ----------------
  UNIT kilometers     = unit<length,1000>();
  UNIT centimeters    = unit<length, 1,100>();
  UNIT millimeters    = unit<length, 1,1000>();
  UNIT per_m          = unit<per_length>();
  UNIT hours          = unit<time, 3600>();
  UNIT hertz          = unit<frequency>();
  // area in...
  UNIT kilometers2    = kilometers * kilometers;
  UNIT centimeters2   = centimeters * centimeters;
  UNIT meters2        = meters * meters;
  UNIT per_m2         = unit<per_area>();
  UNIT meter_kelvins  = meters * kelvins;
  UNIT m2_per_s       = (meters * meters) / seconds;
  UNIT m2_per_s2      = (meters * meters) / (seconds * seconds);
  UNIT kg_per_m2      = kilograms / (meters * meters);
  // volume in...
  UNIT meters3        = meters * meters * meters;
  UNIT km3            = kilometers * kilometers * kilometers;
  UNIT m3_per_s       = (meters * meters * meters) / seconds;
  UNIT m3_per_mol     = (meters * meters * meters) / moles;
  UNIT m3_per_s2      = (meters * meters * meters) / (seconds * seconds);
  UNIT m3_per_kg_per_s2 = (meters * meters * meters) / kilograms / (seconds * seconds);
  UNIT kg_per_m3      = kilograms / (meters * meters * meters);
  // velocity in...
  UNIT m_per_s        = meters / seconds;
  UNIT m_per_h        = meters / hours;
  // acceleration in...
  UNIT m_per_s2       = meters / (seconds * seconds);
  // force in...
  UNIT newtons        = unit<force>();
  UNIT newtonmeters   = newtons * meters;
  UNIT newtonseconds  = newtons * seconds;
  UNIT newtons_per_A2 = newtons / (amperes * amperes);
  // energy in...
  UNIT joules         = kilograms * (meters * meters) / (seconds * seconds);
  UNIT jouleseconds   = joules * seconds;
  UNIT joules_per_s   = joules / seconds;
  UNIT joules_per_K   = joules / kelvins;
  UNIT joules_per_s_per_kg = joules / seconds / kilograms;
  UNIT joules_per_kg_per_K = joules / kilograms / kelvins;
  UNIT joules_per_mol = unit<energy_per_mol>();
  UNIT joules_per_K_per_mol = joules / kelvins / moles;
  // pressure in...
  UNIT pascals        = kilograms / meters / (seconds * seconds);
  // absorbed dose in...
  UNIT grays          = joules / kilograms;
  UNIT sieverts       = joules / kilograms;

  UNIT watts          = unit<power>();
  UNIT wattmeters2    = watts * meters * meters;
  UNIT watts_per_m2   = watts / (meters * meters);

  UNIT amperes_per_m  = amperes / meters;
  UNIT amperes_per_m2 = amperes / (meters * meters);
  UNIT ampere_hours   = amperes * hours;

  UNIT coulombs       = unit<charge>();
  UNIT coulombs_per_mol = coulombs / moles;

  UNIT volts          = unit<potential>();
  UNIT farads         = coulombs / volts;
  UNIT hertz_per_volt = hertz / volts;
  UNIT farads_per_m   = farads / meters;
  UNIT ohms           = volts / amperes;
  UNIT ohm_meters     = ohms * meters;
  UNIT siemens        = amperes / volts;
  UNIT siemens_per_m  = siemens / meters;
  UNIT henrys         = volts * seconds / amperes;
  UNIT webers         = volts * seconds;
  UNIT teslas         = kilograms / (amperes * seconds * seconds);
  UNIT joules_per_tesla = joules / teslas;

  UNIT steradians     = unit<detail::dimensionless>();
  UNIT lumens         = candelas * steradians;
  UNIT lumenseconds   = lumens * seconds;
  UNIT lumens_per_watt = lumens / watts;
  UNIT lux            = lumens / (meters * meters);

  UNIT kg_per_mol     = kilograms / moles;
  UNIT mols_per_m3    = moles / (meters * meters * meters);
  UNIT mols_per_kg    = moles / kilograms;
  UNIT mols_per_s     = moles / seconds;
  UNIT per_mol        = unit<per_substance>();

  UNIT kg_per_watt    = kilograms / watts;

  // Imperial Units
  // --------------
  UNIT pounds          = unit<mass, 45359237,100000000>();
  UNIT ounces          = unit<mass, 45359237,1600000000>();
  UNIT feet            = unit<length, 3048,10000>();
  UNIT nautical_miles  = unit<length, 1852>();
  UNIT inches          = unit<length, 254,10000>();
  UNIT statute_miles   = unit<length, 1609344,1000>();
  UNIT fahrenheit      = detail::unit<detail::temperature_dimension, detail::tag_fahrenheit>();
  UNIT miles_per_h     = statute_miles / hours;
  UNIT knots           = nautical_miles / hours;

  // Digital Data Units
  // ------------------
  UNIT bits              = unit<data_size>();
  UNIT bits_per_s        = bits / seconds;
  UNIT bits_per_m2       = bits / (meters * meters);
  UNIT bits_per_m3       = bits / (meters * meters * meters);
  UNIT bytes             = unit<data_size, 8>();
  UNIT bytes_per_s       = bytes / seconds;
  UNIT bytes_per_cm2     = bytes / (centimeters * centimeters);
  UNIT bytes_per_cm3     = bytes / (centimeters * centimeters * centimeters);

  // Various Units
  // -------------
  UNIT celsius           = detail::unit<detail::temperature_dimension, detail::tag_celsius>();
  typedef angle radians;

  // Helper Functions and Templates
  // -----------------------------
 
  /// @brief Calculates sin(), cos(), or tan() of an angle.
  [[nodiscard]] inline dimensionless sin(angle a) { return std::sinl(a); }
  [[nodiscard]] inline dimensionless cos(angle a) { return std::cosl(a); }
  [[nodiscard]] inline dimensionless tan(angle a) { return std::tanl(a); }

  /// @brief Calculates arcsin(), arccos(), or arctan() to an angle.
  [[nodiscard]] inline angle arcsin(dimensionless a) { return std::asinl(a); }
  [[nodiscard]] inline angle arccos(dimensionless a) { return std::acosl(a); }
  [[nodiscard]] inline angle arctan(dimensionless a) { return std::atanl(a); }

  /// @brief Calculates the atangens of two angles.
  [[nodiscard]] inline angle atan2(angle y, angle x) { return std::atan2l(y, x); }

  /// @brief Calculates the angle between the positive x-axis and a point (x, y).
  [[nodiscard]] inline angle atan2(length y, length x) { return std::atan2(meters(y), meters(x)); }

  /// @brief Calculates sin²x or cos²x.
  [[nodiscard]] inline angle sin2(angle x) { return 0.5 * (1. - std::cosl(2. * x)); }
  [[nodiscard]] inline angle cos2(angle x) { return 0.5 * (1. + std::cosl(2. * x)); }

  /// @brief Raise any number <x> to power of 2 (x² or x*x).
  template <typename T>
  [[nodiscard]] inline constexpr auto square(T x) { return x * x; }

  /// @brief Raise any number <x> to power of 3 (x³ or x*x*x).
  template <typename T>
  [[nodiscard]] inline constexpr auto cube(T x) { return x * x * x; }

  /// @brief Calculates the square root of an angle (a).
  [[nodiscard]] inline angle sqrt(angle a) { return std::sqrtl(a); }

  /// @brief Clamp any number <x> between <min> and <max> value.
  template <typename T>
  [[nodiscard]] inline constexpr auto clamp(T x, T min, T max) {
      if (x < min) return min;
      if (x > max) return max;
      return x;
  }

} // end of namespace

#undef UNIT
