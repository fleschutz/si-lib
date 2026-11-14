/// @file   examples/main.cpp
/// @brief  The main() function calling all examples.

#include <si/core.h>
#include <si/tests.h>                     // unit tests to check everything
#ifdef _WIN32
#include <Windows.h>
#endif

extern void cheat_sheet_examples(), speed_examples(), astronomy_examples(), various_examples();

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);          // switches to UTF-8 console output
#endif
    si::to_string_format = "%.1Lf %s";    // one decimal place and space between quantity and unit
    si::to_equivalent_format = "%.1Lf %s";// one decimal place and space between quantity and unit

    cheat_sheet_examples();               // calls examples in cheat_sheet.cpp

    speed_examples();                     // calls examples in speeds.cpp

    astronomy_examples();                 // calls examples in astronomy.cpp

    various_examples();                   // calls examples in various.cpp
}
