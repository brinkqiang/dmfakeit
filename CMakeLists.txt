# ARCH_INDEPENDENT option at write_basic_package_version_file requires 3.14 version of CMake.
cmake_minimum_required(VERSION 3.14)

PROJECT(dmfakeit VERSION 2.4.0 LANGUAGES CXX)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
INCLUDE(cmake/ModuleImport.cmake)
INCLUDE(cmake/ModuleCompileOptions.cmake)
ModuleSetCompileOptions()
ModuleSetWinCompilerFlags()

option(ENABLE_TESTING "Enable build of tests." ON)
option(OVERRIDE_CXX_STANDARD_FOR_TESTS "Override the C++ standard used for building tests." "")
option(ENABLE_SANITIZERS_IN_TESTS "Enable address / undefined sanitizers in tests." OFF)
option(ENABLE_COVERAGE "Enable coverage reporting for gcc/clang." OFF)

# Directory containing main targets of FakeIt.
add_subdirectory(include)

# Directory containing config targets of FakeIt.
add_subdirectory(config)

if(ENABLE_TESTING)
    # Directory containing test targets of FakeIt.
    add_subdirectory(tests)
endif()

# Directory containing single header targets of FakeIt.
add_subdirectory(single_header)
