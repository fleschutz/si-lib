#include <si/core.h> 
using namespace si;

void cheat_sheet() {

    // Assignment
    // ----------
    length a = 1_m;                // user-defined literal (UDL)
    auto   b = 1_m;                // with convenient auto
    length c = meters(1);          // construct from number
    length d = 5.0 * 1_m;          // multiply with a quantity
    length e = to_length("42m");   // string to length conversion
    // length bad = 1_kg;          // ERROR: incompatible dimensions

    // Calculations
    // ------------
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
    length W = wavelength_formula(constant::c, 100_Hz); // with a formula

    // Comparison
    // ----------
    bool good = (1_m < 2_ft);      // correct 
    // bool bad = (1_m < 1_kg);    // ERROR: incompatible dimensions
    for (auto t = 0_s; t < 5_min; t += 1_s) { } // time loop

    // Angles
    // ------
    angle alpha   = 180_deg;       // 180°
    angle beta    = constant::pi;  // or π
    angle gamma   = 3.14_rad;      // or as radian
    angle delta   = 3'141.5_mrad;  // or as milliradian 
    angle eta     = 10800_arcmin;  // or as arcminutes
    angle epsilon = 648000_arcsec; // or as arcseconds
    angle zeta    = radians(3.14); // or constructed from number

    // Ratio
    // -----
    dimensionless ratio1 = 0.10; 
    dimensionless ratio2 = 10_pct; // or as percentage (%)
    dimensionless ratio3 = 1000_bp; // or as basis points
    dimensionless ratio4 = 100'000_ppm; // or as parts per million
    dimensionless ratio5 = 100'000'000_ppb; // or as parts per billion
    dimensionless ratio6 = 100'000'000'000_ppt; // or as parts per trillion

    // Export a Quantity
    // -----------------
    length len = 42_m;
    double x = meters(len);        // cast to a unit (=42)
    double y = len / 1_m;          // divide to a dimensionless number (=42) - doesn't work for celsius/fahrenheit due to the offset!
    std::string str = to_string(len); // length to string conversion (="42.0m")
    std::string equiv = to_equivalent(len); //  length to an equivalent string conversion (="45.93yd")
    std::string progress = to_percentage(len, 420_m); // length to percentage string conversion (="10%")

    // User-defined Units
    // ------------------
    auto smoot = unit<length, 17'018, 10'000>(); // Oliver R Smoot's height (https://en.wikipedia.org/wiki/Smoot)
    auto Harvard_bridge_length = smoot(364.4);
}
