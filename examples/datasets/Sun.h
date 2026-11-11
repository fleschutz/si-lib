/// @file     examples/datasets/Sun.h
/// @brief    Contains data of our sun, e.g. Sun.mass
/// @details  Categories are: orbital characteristics, physical characteristics, photosphere, and various.

#pragma once
#include <si/literals.h>

namespace {
  using namespace si;

  constexpr struct {

    // Orbital Characteristics 
    // ----------------------- (source: https://en.wikipedia.org/wiki/Sun as of 2026)
    length        mean_distance_from_Earth = 149'600'00_km; // (=1 AU)
    velocity      equatorial_rotation_velocity = 1.997_km_per_s;

    // Physical Characteristics 
    // ------------------------ (source: https://en.wikipedia.org/wiki/Sun as of 2026)
    length        equatorial_radius =   695'500_km;
    si::mass      mass              = 1.988475e30_kg;

    // Photosphere
    // ----------- (source: https://en.wikipedia.org/wiki/Sun as of 2026)
    dimensionless hydrogen =             73.46_percent;
    dimensionless helium =               24.85_percent;
    dimensionless oxygen =                0.77_percent;
    dimensionless carbon =                0.29_percent;
    dimensionless iron =                  0.16_percent;
    dimensionless neon =                  0.12_percent;
    dimensionless nitrogen =              0.09_percent;
    dimensionless silicon =               0.07_percent;
    dimensionless magnesium =             0.05_percent;
    dimensionless sulfur =                0.04_percent;

  } Sun;

} // end of namespace

