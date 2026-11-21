/// @file     <si/units.h>
/// @brief    Defines 100+ units, e.g. si::meters
/// @details  Categories are: SI base units, SI derived, Imperial, digital data, various, and references.

#pragma once
#include <si/datatypes.h>
#define DEF(_name, _symbol, _value)     \
  inline constexpr auto _name = _value; \
  inline const char* to_str(decltype(_name) n) { return "0 " _symbol; }
#define UNIT inline constexpr auto

namespace si {

  // SI Base Units
  // -------------
  DEF(meters,       "m",   unit<length>());
  DEF(seconds,      "s",   unit<time>());
  DEF(kilograms,    "kg",  unit<mass>());
  DEF(kelvins,      "K",   unit<temperature>());
  DEF(amperes,      "A",   unit<current>());
  DEF(moles,        "mol", unit<substance>());
  DEF(candelas,     "cd",  unit<luminous_intensity>());

  // Derived SI Units
  // ----------------
  DEF(kilometers,   "km",  (unit<length,1000>()));
  DEF(centimeters,  "cm",  (unit<length, 1,100>()));
  DEF(millimeters,  "mm",  (unit<length, 1,1000>()));
  DEF(per_m,        "/m",  unit<per_length>());
  DEF(minutes,      "min", (unit<time, 60>()));
  DEF(hours,        "h",   (unit<time, 3600>()));
  DEF(hertz,        "Hz",  unit<frequency>());
  // area in...
  DEF(kilometers2,  "km²", kilometers * kilometers);
  DEF(centimeters2, "cm²", centimeters * centimeters);
  DEF(meters2,      "m²",  meters * meters);
  DEF(per_m2,       "/m²", unit<per_area>());
  DEF(meter_kelvins,"mK",  meters * kelvins);
  DEF(m2_per_s,     "m²/s",(meters * meters) / seconds);
  DEF(m2_per_s2,    "m²/s²",(meters * meters) / (seconds * seconds));
  DEF(kg_per_m2,    "kg/m²",kilograms / (meters * meters));
  // volume in...
  DEF(meters3,      "m³",  meters * meters * meters); 
  DEF(km3,          "km³", kilometers * kilometers * kilometers);
  DEF(m3_per_s,     "m³/s",(meters * meters * meters) / seconds);
  DEF(m3_per_mol,   "m³/mol",(meters * meters * meters) / moles);
  DEF(m3_per_s2,    "m³/s²",(meters * meters * meters) / (seconds * seconds));
  DEF(m3_per_kg_per_s2,"m³/kg/s²",(meters * meters * meters) / kilograms / (seconds * seconds));
  DEF(kg_per_m3,    "kg/m³",kilograms / (meters * meters * meters));
  // velocity in...
  DEF(m_per_s,      "m/s", meters / seconds);
  DEF(m_per_h,      "m/h", meters / hours);
  // acceleration in...
  DEF(m_per_s2,     "m/s²",meters / (seconds * seconds));
  // force in...
  DEF(newtons,      "N",   unit<force>());
  DEF(newtonmeters, "Nm",  newtons * meters);
  DEF(newtonseconds,"Ns",  newtons * seconds);
  DEF(newtons_per_A2,"N/A²", newtons / (amperes * amperes));
  // energy in...
  DEF(joules,       "J",  kilograms * (meters * meters) / (seconds * seconds));
  DEF(jouleseconds, "Js", joules * seconds);
  DEF(joules_per_s, "J/s",joules / seconds);
  DEF(joules_per_K, "J/K",joules / kelvins);
  DEF(joules_per_s_per_kg,"J/s/kg",joules / seconds / kilograms);
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
  UNIT lux            = lumens / meters2;

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
  /// @brief Calculates the sinus of an angle (a).
  [[nodiscard]] inline angle sin(angle a) {
      return std::sinl(a);
  }

  /// @brief Calculates the cosinus of an angle (a).
  [[nodiscard]] inline angle cos(angle a) {
      return std::cosl(a);
  }

  /// @brief Calculates the tangens of an angle (a).
  [[nodiscard]] inline angle tan(angle a) {
      return std::tanl(a);
  }

  /// @brief Calculates the square root of an angle (a).
  [[nodiscard]] inline angle sqrt(angle a) {
      return std::sqrtl(a);
  }

  /// @brief Calculates sin²x
  [[nodiscard]] inline angle sin2(angle x) {
      return 0.5 * (1. - std::cosl(2. * x));
  }

  /// @brief Calculates cos²x
  [[nodiscard]] inline angle cos2(angle x) {
      return 0.5 * (1. + std::cosl(2. * x));
  }

  /// @brief Calculates the atangens of two angles.
  [[nodiscard]] inline angle atan2(angle y, angle x) {
      return std::atan2l(y, x);
  }

  /// @brief Calculates the angle between the positive x-axis and a point (x, y).
  [[nodiscard]] inline angle atan2(length y, length x) {
      return std::atan2(meters(y), meters(x));
  }

  /// @brief Raise any number <x> to power of 2 (x² or x*x).
  template <typename T>
  [[nodiscard]] inline constexpr auto square(T x) { return x * x; }

  /// @brief Raise any number <x> to power of 3 (x³ or x*x*x).
  template <typename T>
  [[nodiscard]] inline constexpr auto cube(T x) { return x * x * x; }

  /// @brief Clamp any number <x> between <min> and <max> value.
  template <typename T>
  [[nodiscard]] inline constexpr auto clamp(T x, T min, T max) {
      if (x < min) return min;
      if (x > max) return max;
      return x;
  }

  // References
  // ----------
  // 1. https://en.wikipedia.org/wiki/International_System_of_Units

} // end of namespace

#undef DEF
#undef UNIT
