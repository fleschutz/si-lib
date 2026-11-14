/// @file   examples/cheat_sheet.cpp

#include <si/core.h> 
using namespace si;

void cheat_sheet_examples() {

    // Generate a Quantity
    // -------------------
    length a = 1_m;           // user-defined literal (UDL)
    auto   b = 1_m;           // with auto
    length c = meters(1);     // construct from dimensionless number
    length d = 5.0 * 1_m;     // multiply with a quantity - doesn't work for celsius/fahrenheit due to the offset!
    length distance = 42_m;
    bool is_valid = from_string("42m", distance); // <- string to length conversion
    // length bad = 1_kg;     // ERROR: incompatible dimensions

    // Calculate on Quantities
    // -----------------------
    area field = a * b;
    volume cube = a * b * c;
    velocity speed = 1_km / 1_h;

    // Compare Quantities
    // ------------------
    bool good = (1_m < 2_ft);
    // bool bad = (1_m < 1_kg); // ERROR: incompatible dimensions

    // Work with Angles
    // ----------------
    angle alpha = 90_deg;
    angle beta  = 3_rad;
    angle delta = radians(3);
    angle gamma = si::sin(delta);

    // Dimensionless Numbers
    // ---------------------
    dimensionless ratio = 0.25;
    dimensionless part = ratio * 10_percent;

    // Export a Quantity
    // -----------------
    double x = meters(distance); // <- cast to a unit (=42)
    double y = distance / 1_m;   // <- divide to a dimensionless number (=42) - doesn't work for celsius/fahrenheit due to the offset!
    std::string str = to_string(distance); // <- length to string conversion (="42.0m")
    std::string equiv = to_equivalent(distance); // <- length to an equivalent string conversion (="45.93yd")
    std::string progress = to_percentage(distance, 420_m); // <- length to percentage string conversion (="10%")
}
