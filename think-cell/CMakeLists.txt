cmake_minimum_required(VERSION 3.0)
project(HelloBoost)

# Set the path to your Boost installation directory
set(BOOST_ROOT "/opt/homebrew/Cellar/boost")

# Find Boost components
find_package(Boost REQUIRED COMPONENTS system geometry)

# Include Boost headers
include_directories(${Boost_INCLUDE_DIRS})

# Add executable
add_executable(hello_boost hello_boost.cpp)

# Link against Boost libraries
target_link_libraries(hello_boost ${Boost_LIBRARIES})