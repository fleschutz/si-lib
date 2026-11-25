Integrate *si-lib* in Projects
==============================

Please choose one of the 4 integration options:

### Option 1: Using `FetchContent` in CMake

Pull it at configure time — no vendored copy in your tree. Add to the `CMakeLists.txt` file:

```cmake
cmake_minimum_required(VERSION 3.11) # FetchContent requires version 3.11 or newer

include(FetchContent)

FetchContent_Declare(si-lib
  GIT_REPOSITORY https://github.com/fleschutz/si-lib.git
  GIT_TAG        v0.7)            # pin a release tag

FetchContent_MakeAvailable(si-lib)

target_link_libraries(main PRIVATE si-lib::si-lib)
```


### Option 2: Using `add_subdirectory` in CMake

Vendor the project (a submodule or a copy) and add it. Add to the `CMakeLists.txt` file:

```cmake
add_subdirectory(si-lib)

target_link_libraries(main PRIVATE si-lib::si-lib)
```

Linking the target propagates the include directory, so you do not set either yourself.


### Option 3: Using `find_package` in CMake

If `si-lib` is installed (via `cmake --install`, or a Linux package), consume it with `find_package`. Add to the `CMakeLists.txt` file:

```cmake
find_package(si-lib CONFIG REQUIRED)

target_link_libraries(main PRIVATE si-lib::si-lib)
```


### Option 4: Copy the headers (no CMake)

Put `include/si/` on your compiler's include path and build with C++17 (`-std=c++17` on GCC and Clang,
`/std:c++latest` on MSVC). Nothing else is required.


Include the Header Files
------------------------
Use the convenient *#include <si/core.h>* to include the 6 core header files (datatypes.h, units.h, literals.h, constants.h, formulas.h, conversions.h), otherwise pick the necessary ones only.

Improve Debugging
-----------------
If you might be debugging using Microsoft Visual Studio, you may find the debugger visualisation file at ../examples/visualization.natvis useful to include into your build.
