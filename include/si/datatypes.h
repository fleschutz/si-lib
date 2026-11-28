/// @file     <si/datatypes.h>
/// @brief    Defines the fundamental datatypes, e.g. si::length
/// @details  Categories are: base datatypes, derived datatypes, and dimensionless.

#pragma once
#include <si/internal.h>
#define TYPE(_name, _lenExp, _massExp, _timeExp, _tempExp, _currExp, _substExp, _lumExp, _dataExp)    \
  namespace detail { using _name ## _dimension = dimension<_lenExp, _massExp, _timeExp, _tempExp,     \
                                                           _currExp, _substExp, _lumExp, _dataExp>; } \
  template <class T> using _name ## _t = detail::quantity<detail:: _name ## _dimension, T>;           \
  using _name = _name ## _t<SIdouble>;                                                                \
  using _name ## 2 = _name ## _t<detail::vec2<SIdouble>>;                                             \
  using _name ## 3 = _name ## _t<detail::vec3<SIdouble>>

namespace si {

  // Base Datatypes
  // --------------
  //       NAME                      EXPONENTS             BASE UNIT
  //                           l  m  t  T  c  s  i  d
  TYPE(length,                 1, 0, 0, 0, 0, 0, 0, 0); // in meters
  TYPE(mass,                   0, 1, 0, 0, 0, 0, 0, 0); // in kilograms
  TYPE(time,                   0, 0, 1, 0, 0, 0, 0, 0); // in seconds
  TYPE(temperature,            0, 0, 0, 1, 0, 0, 0, 0); // in kelvins
  TYPE(current,                0, 0, 0, 0, 1, 0, 0, 0); // in amperes
  TYPE(substance,              0, 0, 0, 0, 0, 1, 0, 0); // in moles
  TYPE(luminous_intensity,     0, 0, 0, 0, 0, 0, 1, 0); // in candelas
  TYPE(data_size,              0, 0, 0, 0, 0, 0, 0, 1); // in bits

  // Derived Datatypes
  // -----------------
  TYPE(area,                   2, 0, 0, 0, 0, 0, 0, 0); // in square meters
  TYPE(volume,                 3, 0, 0, 0, 0, 0, 0, 0); // in cubic meters
  TYPE(velocity,               1, 0,-1, 0, 0, 0, 0, 0); // in meters per second
  TYPE(acceleration,           1, 0,-2, 0, 0, 0, 0, 0); // in meters per square second
  TYPE(jerk,                   1, 0,-3, 0, 0, 0, 0, 0); // in meters per cubic second
  TYPE(force,                  1, 1,-2, 0, 0, 0, 0, 0); // in newtons
  TYPE(energy,                 2, 1,-2, 0, 0, 0, 0, 0); // in newtonmeters
  TYPE(impulse,                1, 1,-1, 0, 0, 0, 0, 0); // in kilogram meters per second
  TYPE(torque,                 2, 1,-2, 0, 0, 0, 0, 0); // in kilogram square meters per square second
  TYPE(pressure,              -1, 1,-2, 0, 0, 0, 0, 0); // in pascals
  TYPE(power,                  2, 1,-3, 0, 0, 0, 0, 0); // in watts
  TYPE(power_intensity,        0, 1,-3, 0, 0, 0, 0, 0); // in watts per square meter
  TYPE(density,               -3, 1, 0, 0, 0, 0, 0, 0); // in kilograms per cubic meter
  TYPE(potential,              2, 1,-3, 0,-1, 0, 0, 0); // in volts
  TYPE(resistance,             2, 1,-3, 0,-2, 0, 0, 0); // in ohms
  TYPE(charge,                 0, 0, 1, 0, 1, 0, 0, 0); // in ampere-seconds
  TYPE(mass_per_area,         -2, 1, 0, 0, 0, 0, 0, 0); // in kilograms per square meter
  TYPE(mass_per_power,        -2, 0, 3, 0, 0, 0, 0, 0); // in kilograms per watt
  TYPE(specific_energy,        2, 0,-2, 0, 0, 0, 0, 0); // in joules per kilogram
  TYPE(energy_per_mol,         2, 1,-2, 0, 0, 1, 0, 0); // in joules per mol
  TYPE(volume_per_time_squared,3, 0,-2, 0, 0, 0, 0, 0); // in cubic meters per square second
  TYPE(per_length,            -1, 0, 0, 0, 0, 0, 0, 0); // per meter (reciprocal)
  TYPE(per_area,              -2, 0, 0, 0, 0, 0, 0, 0); // per square meter (reciprocal)
  TYPE(frequency,              0, 0,-1, 0, 0, 0, 0, 0); // per second (reciprocal)
  TYPE(per_substance,          0, 0, 0, 0, 0,-1, 0, 0); // per mol (reciprocal)
  TYPE(data_speed,             0, 0,-1, 0, 0, 0, 0, 1); // in bits per second
  TYPE(data_per_area,         -2, 0, 0, 0, 0, 0, 0, 1); // in bits per square meter
  TYPE(data_per_volume,       -3, 0, 0, 0, 0, 0, 0, 1); // in bits per cubic meter

  // Dimensionless Datatypes
  // -----------------------
  typedef long double angle;                            // in radians with high precision
  typedef double dimensionless;                         // for dimensionless numbers

} // end of namespace

#undef TYPE
