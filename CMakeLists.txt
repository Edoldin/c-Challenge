cmake_minimum_required(VERSION 3.0)
project(CarRentalSystem)

# Set C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable compile_commands.json generation
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/test)
include_directories(${PROJECT_SOURCE_DIR}/3rdParty/cpp-httplib/)

# File globbing (if needed)
file(GLOB_RECURSE sources_view ${PROJECT_SOURCE_DIR}/src/view/*.cpp)
file(GLOB sources_controller ${PROJECT_SOURCE_DIR}/src/controller/*.cpp)
file(GLOB sources_model ${PROJECT_SOURCE_DIR}/src/model/*.cpp)
file(GLOB sources_main ${PROJECT_SOURCE_DIR}/src/main.cpp) # Only main.cpp
file(GLOB_RECURSE sources_test test/*.cpp)
message("wasd")
# Add CarRentalSystem executable
add_executable(CarRentalSystem ${sources_main} ${sources_model} ${sources_controller} ${sources_view})

set_target_properties(CarRentalSystem PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
) 
message("Sources for view/client: ${sources_view}")
# Compiler options for CarRentalSystem
target_compile_options(CarRentalSystem PUBLIC -Wall -Wextra -Wpedantic -Wfloat-conversion)

# Add test executable
add_executable(CarRentalSystemTest ${sources_test} ${sources_model} ${sources_controller} ${sources_view})

# Compiler options for CarRentalSystemTest
target_compile_options(CarRentalSystemTest PUBLIC -Wall -Wextra -Wpedantic)

set_target_properties(CarRentalSystemTest PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)