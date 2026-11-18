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
    velocity s = 1_km / 1_h;       // speed from distance per time
    frequency f = 100 / 1_s;       // frequency from number per time
    charge Q = 1_A * 1_h;          // electric charge from ampere-hours
    temperature T = 10_degC + 5_K; // different units
    energy E = 1_kg * square(constant::c); // with constant
    length w = wavelength_formula(constant::c, 100_Hz); // with formula

    // Compare Quantities
    // ------------------
    bool good = (1_m < 2_ft);      // correct 
    // bool bad = (1_m < 1_kg);    // ERROR: incompatible dimensions
    for (auto t = 0_s; t < 5_min; t += 1_s) { } // time loop

    // Angles
    // ------
    angle alpha   = 90_deg;        // degree literal
    angle beta    = 1.57_rad;      // radian literal
    angle gamma   = 1'570.79_mrad; // milliradian literal
    angle delta   = radians(1.57); // construct from number
    angle epsilon = si::sin(delta);

    // Dimensionless Numbers
    // ---------------------
    dimensionless ratio = 0.25;
    dimensionless part = ratio * 10_percent;

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
