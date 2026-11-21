/// @file     <si/constants.h>
/// @brief    Defines 70+ type-safe constants, e.g. si::constant::c
/// @details  Categories are: defined constants, universal constants, electromagnetic constants, atomic & nuclear constants, physico-chemical constants, physical constants, mathematical constants, astronomical constants, various constants, and references.

#pragma once
#include <si/units.h>
#define SET(_name, _number, _unit) inline constexpr auto _name = _unit(_number)

namespace si { namespace constant {                             // singular for better code readability

  // Defined Constants
  // -----------------                                          // CODATA 2022 constants (source: https://codata.org)
  SET(caesium_frequency,     9'192'631'770, hertz);             // the unperturbed ground state hyperfine transition frequency of the ceesium-133 atom
  SET(c,                     299'792'458.0, m_per_s);           // the speed of light in vacuum (symbol: c)
  SET(c²,           89'875'517'873'681'764, m2_per_s2);         // the speed of light in vacuum squared 
  SET(h,                  6.626'070'15e-34, jouleseconds);      // Planck constant (symbol: h)
  SET(e,                 1.602'176'634e-19, coulombs);          // the elementary charge (symbol: e)
  SET(k_B,                   1.380'649e-23, joules_per_kelvin); // Boltzmann constant (symbol: k)
  SET(N_A,                   6.02214076e23, per_mol);           // Avogadro constant (symbol: N_A)
  SET(K_cd,                            683, lumens_per_watt);   // the luminous efficacy of monochromatic radiation of frequency 540 THz
  SET(g_n,                        9.806'65, m_per_s2);          // standard acceleration of gravity
  SET(atm,                         101'325, pascals);           // standard atmosphere
  SET(ssp,                         100'000, pascals);           // standard-state pressure

  // Universal Constants
  // -------------------                                        // CODATA 2022 constants (source: https://codata.org)
  SET(G,                       6.67430e-11, m3_per_kg_per_s2);  // Newtonian constant of gravitation (symbol: G)
  SET(Z_0,                 376.730'313'412, ohms);              // characteristic impedance of vacuum
  SET(epsilon_0,        8.854'187'8188e-12, farads_per_m);      // vacuum electric permittivity, symbol: ε_0
  SET(l_P,                    1.616255e-35, meters);            // Planck length
  SET(m_P,                     2.176434e-8, kilograms);         // Planck mass
  SET(T_P,                     1.416784e32, kelvins);           // Planck temperature
  SET(t_P,                    5.391247e-44, seconds);           // Planck time
  SET(h_bar,             1.054'571'817e-34, jouleseconds);      // reduced Planck constant
  SET(mu_0,            1.256'637'061'27e-6, newtons_per_ampere2);// vacuum magnetic permeability

  // Electromagnetic Constants
  // -------------------------                                  // CODATA 2022 constants (source: https://codata.org)
  SET(G_0,                7.748'091'729e-5, siemens);           // conductance quantum
  SET(G_0_inv,                 12906.40372, ohms);              // inverse conductance quantum
  SET(K_J,                 483'597.848'4e9, hertz_per_volt);    // Josephson constant
  SET(mu_B,             9.274'010'0657e-24, joules_per_tesla);  // Bohr magneton (symbol: µB)
  SET(mu_N,             5.050'783'7393e-27, joules_per_tesla);  // nuclear magneton (symbol: μ_N)
  SET(Phi_0,               2.067833848e-15, webers);            // magnetic flux quantum (symbol: Φ_0)
  SET(R_K,                   25'812.807'45, ohms);              // von Klitzing constant
  SET(R_Km90,                    25812.807, ohms);              // conventional value of von Klitzing constant

  // Physico-chemical Constants
  // --------------------------                                 // CODATA 2022 constants (source: https://codata.org)
  SET(R,                     8.314'462'618, joules_per_kelvin_per_mol); // molar gas constant
  SET(R_dry_air,              287.050'0676, joules_per_kg_per_kelvin); // specific gas constant for dry air
  SET(b,                    2.897771955e-3, meter_kelvins);     // Wien wavelength displacement law constant
  SET(c_1,                 3.741771852e-16, wattmeters2);       // first radiation constant
  SET(c_1L,                1.191042972e-16, watts_per_m2);      // first radiation constant for spectral radiance
  SET(F,                     96'485.332'12, coulombs_per_mol);  // Faraday constant
  SET(m_u,          1.660'539'068'9252e-27, kilograms);         // atomic mass constant
  SET(M_u,             1.000'000'001'05e-3, kg_per_mol);        // molar mass constant
  SET(S_0_by_R,             -1.15170753706, dimensionless);     // Sackur–Tetrode constant
  SET(V_m,                22.710'954'64e-3, m3_per_mol);        // molar volume of ideal gas (273.15K, 100kPa)

  // Atomic & Nuclear Constants
  // --------------------------                                 // CODATA 2022 constants (source: https://codata.org)
  SET(a_0,            5.291'772'105'44e-11, meters);            // Bohr radius
  SET(alpha,                  7.2973525e-3, dimensionless);     // fine-structure constant
  SET(alpha_inv,           137.035'999'177, dimensionless);     // inverse fine-structure constant
  SET(E_h,                4.3597447222e-18, joules);            // Hartree energy
  SET(g_e,               -2.00231930436256, dimensionless);     // electron g-factor
  SET(m_e,              9.109'383'7139e-31, kilograms);         // electron mass
  SET(m_d,              3.343'583'7768e-27, kilograms);         // deuteron mass
  SET(m_h,              5.006'412'7862e-27, kilograms);         // helion mass
  SET(m_mu,              1.883'531'627e-28, kilograms);         // muon mass
  SET(m_n,            1.674'927'500'56e-27, kilograms);         // neutron mass
  SET(m_p,            1.672'621'925'95e-27, kilograms);         // proton mass
  SET(m_tau,                  3.167'54e-27, kilograms);         // tau mass
  SET(m_t,              5.007'356'7512e-27, kilograms);         // triton mass
  SET(r_e,              2.817'940'3205e-15, meters);            // classical electron radius
  SET(sin2Theta_W,                 0.22290, dimensionless);     // weak mixing angle
  SET(sigma_e,               6.6524587e-29, meters2);           // Thomson cross section (symbol: σ_e)

  // Mathematical Constants 
  // ----------------------        (source: https://en.wikipedia.org/wiki/Mathematical_constant as of 2026)
  SET(euler,        2.71828182845904523536, dimensionless);     // Euler's number (symbol: e)
  SET(ln_2,         0.69314718055994530941, dimensionless);     // natural logarithm of 2
  SET(pi,           3.14159265358979323846L,radians);           // Archimedes' constant (symbol: π)
  SET(half_pi,      1.57079632679489661923L,radians);           // π / 2
  SET(quarter_pi,   0.78539816339744830961L,radians);           // π / 4
  SET(phi,          1.61803398874989484820, dimensionless);     // The golden ratio (symbol: φ)
  SET(sqrt_2,       1.41421356237309504880, dimensionless);     // Pythagoras' constant (square root of 2)
  SET(sqrt_3,       1.73205080756887729352, dimensionless);     // Theodorus's constant (square root of 3)
  SET(sqrt_5,       2.23606797749978969640, dimensionless);     // square root of 5
  SET(tau,          6.28318530717958647692L,radians);           // The full circle constant (symbol: τ)

  // Astronomical Constants
  // ----------------------        (source: https://en.wikipedia.org/wiki/Astronomical_constant as of 2026)
  SET(AU,                  149'597'870'700, meters);            // one astronomical unit (symbol: au, IAU 2009)
  SET(parsec,       30'856'775'814'913'673, meters);            // one Parsec (symbol: pc, IAU 2015)
  SET(lightyear,     9'460'730'472'580'800, meters);            // one light-year (symbol: ly, IAU 2009)
  SET(H0,                           70'100, m_per_s);           // per megaparsec, Hubble constant (symbol: H0)
  SET(Lsun,                       3.828e26, watts);             // Solar luminosity, IAU nominal value (symbol: L☉)
  SET(F1AU,                         1366.1, watts_per_m2);      // total solar irradiance at 1 AU (solar constant)

  // Various Constants
  // -----------------
  SET(T0,                                0, kelvins);           // absolute zero (0K, the lowest possible temperature)
  SET(speed_of_sound,                  343, m_per_s);           // speed of sound in dry air at 20°C (68°F)
  SET(speed_of_sound_in_fresh_water,  1481, m_per_s);           // at 20°C (68°F)
  SET(speed_of_sound_in_iron,         5120, m_per_s);
  SET(speed_of_sound_in_diamonds,   12'000, m_per_s);

} } // end of namespaces

#undef SET
