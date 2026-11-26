/// @file   examples/main.cpp
/// @brief  The main() function calling all examples.

#include <si/core.h>
#include <si/tests.h>                     // unit tests to check everything
#ifdef _WIN32
#include <Windows.h>
#endif

extern void cheat_sheet(), speed_examples(), astronomy_examples(), various_examples();

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);          // console output in UTF-8
#endif
    si::to_string_format = "%.1Lf %s";    // e.g. "1.2 m"
    si::to_equiv_format  = "%.1Lf %s";    // e.g. "1.2 ft"
    si::to_pct_format    = "%.0Lf%%";     // e.g. "100%"

    cheat_sheet();                        // in cheat_sheet.cpp

    speed_examples();                     // in speeds.cpp

    astronomy_examples();                 // in astronomy.cpp

    various_examples();                   // in various.cpp
}
