cmake_minimum_required(VERSION 3.0)
project(CarRentalSystem)

###############################################################################
## file globbing ##############################################################
###############################################################################
 
# these instructions search the directory tree when CMake is
# invoked and put all files that match the pattern in the variables
# `sources` and `data`
file(GLOB sources_view       view/*)
file(GLOB sources_controller controller/*h)
file(GLOB sources_model      sources_model/*)
file(GLOB sources_main       src/*.cpp src/*.h)
file(GLOB_RECURSE sources_test test/*.cpp test/*.h)
file(GLOB_RECURSE data resources/*)

set(CMAKE_CXX_FLAGS "-g -Wall -Wextra -Wpedantic")
#set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra -Wpedantic")
# you can use set(sources src/main.cpp) etc if you don't want to
# use globbing to find files automatically

###############################################################################
## target definitions #########################################################
###############################################################################

# add the data to the target, so it becomes visible in some IDE
add_executable(CarRentalSystem ${sources_main} ${sources_model} ${sources_controller} ${sources_view} ${data})


set_target_properties(CarRentalSystem PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
# just for example add some compiler flags
target_compile_options(CarRentalSystem PUBLIC -std=c++17 -Wall -Wfloat-conversion)

# this lets me include files relative to the root source directory with a <> pair
target_include_directories(CarRentalSystem PUBLIC src/main)

add_executable(test ${sources_test} ${sources_model} ${sources_controller} ${sources_view} ${data})