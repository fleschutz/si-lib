#include <si/core.h> 

void cheat_sheet() {   using namespace si;

    // Assignments
    // -----------
    length a = 1_m;                // user-defined literal (UDL)
    auto   b = 1_m;                // with convenient auto
    length c = meters(1);          // construct from number
    length d = 5.0 * 1_m;          // multiply with a quantity
    length e = to_length("42m");   // string to length conversion
    // length bad = 1_kg;          // ERROR: incompatible dimensions

    // Calculations
    // ------------
    auto t = 1_h + 7_min + 9_s;    // time added
    area A = a * b;                // area from length by length
    volume V = A * 10_ft;          // volume from area by height
    density D = 1_kg / V;          // density from mass per volume
    velocity S = 1_km / 1_h;       // speed from distance per time
    frequency F = 100 / 1_s;       // frequency from number per time
    charge Q = 1_A * 1_h;          // electric charge from ampere-hours
    resistance R = 1_V / 1_A;      // electrical resistance from volt per ampere
    temperature T = 10_degC + 5_K; // different units
    auto DS = 5_TB / 1_s;          // data speed from data size per time
    energy E = 1_kg * square(constant::c); // with a constant
    length W = wavelength_formula(constant::c, 100_Hz); // using a formula

    // Comparisons
    // -----------
    bool good = (1_m > 2_ft);      // correct 
    // bool bad = (1_m > 1_kg);    // ERROR: incompatible dimensions

    // Angles
    // ------
    angle a1 = 180_deg;            // 180°
    angle a2 = constant::pi;       // or π
    angle a3 = 3.14_rad;           // or as radian
    angle a4 = 3'141.5_mrad;       // or as milliradian 
    angle a5 = 10800_arcmin;       // or as arcminutes
    angle a6 = 648000_arcsec;      // or as arcseconds
    angle a7 = radians(3.14);      // or constructed from number

    // Ratios
    // ------
    dimensionless r1 = 0.1;        // 1/10
    dimensionless r2 = 10_pct;     // or as percentage (%)
    dimensionless r3 = 1000_bp;    // or as basis points
    dimensionless r4 = 100'000_ppm;// or as parts per million
    dimensionless r5 = 100'000'000_ppb; // or as parts per billion
    dimensionless r6 = 100'000'000'000_ppt; // or as parts per trillion

    // Loops
    // -----
    for (auto t = 0_s; t < 5_min; t += 1_s) { } // 0 to 5min in 1s steps

    // Own Units
    // ---------
    auto smoot = unit<length, 17018, 10000>(); // Oliver R Smoot's height (https://en.wikipedia.org/wiki/Smoot)
    auto Harvard_bridge_length = smoot(364.4);

    // Exports
    // -------
    length len = 42_m;
    auto e1 = meters(len);         // cast to number (=42)
    auto e2 = len / 1_m;           // divide to a number (=42)
    auto e3 = to_string(len);      // convert to a string (="42.0m")
    auto e4 = to_equivalent(len);  // convert to an equivalent string (="45.93yd")
    auto e5 = to_percentage(len, 420_m); // convert to percentage string (="10%")
}
