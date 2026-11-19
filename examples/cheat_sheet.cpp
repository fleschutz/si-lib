#include <si/core.h> 
using namespace si;

void cheat_sheet() {

    // Assign a Quantity
    // -----------------
    length a = 1_m;                // user-defined literal (UDL)
    auto   b = 1_m;                // with convenient auto
    length c = meters(1);          // construct from number
    length d = 5.0 * 1_m;          // multiply with a quantity
    length e = to_length("42m");   // string to length conversion
    // length bad = 1_kg;          // ERROR: incompatible dimensions

    // Calculate with Quantities
    // -------------------------
    area A = a * b;                // area from length by length
    volume V = A * 10_ft;          // volume from area by height
    density D = 1_kg / V;          // density from mass per volume
    velocity S = 1_km / 1_h;       // speed from distance per time
    frequency F = 100 / 1_s;       // frequency from number per time
    charge Q = 1_A * 1_h;          // electric charge from ampere-hours
    resistance R = 1_V / 1_A;      // electrical resistance from volt per ampere
    temperature T = 10_degC + 5_K; // different units
    data_speed DS = 5_TB / 1_s;    // data speed from data size per time
    energy E = 1_kg * square(constant::c); // with a constant
    length W = wavelength_formula(constant::c, 100_Hz); // with a formula

    // Compare Quantities
    // ------------------
    bool good = (1_m < 2_ft);      // correct 
    // bool bad = (1_m < 1_kg);    // ERROR: incompatible dimensions
    for (auto t = 0_s; t < 5_min; t += 1_s) { } // time loop

    // Angles
    // ------
    angle alpha   = 180_deg;       // 180°
    angle beta    = constant::pi;  // or π
    angle gamma   = 3.14_rad;      // or in radian
    angle delta   = 3'141.5_mrad;  // or in milliradian 
    angle epsilon = radians(3.14); // or constructed from number
    angle zeta    = 10800_arcmin;  // or in arcminutes
    angle eta     = 648000_arcsec; // or in arcseconds

    // Dimensionless Numbers
    // ---------------------
    dimensionless ratio = 0.25;
    dimensionless share = 50_percent * 50'000;
    dimensionless CO2   = 429.12_ppm;

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
