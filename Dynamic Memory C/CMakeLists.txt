# CMakeList.txt : CMake project for Dynamic Memory C, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
find_path(RAPIDXML_INCLUDE_DIRS "rapidxml/rapidxml.hpp")
find_package(RapidJSON CONFIG REQUIRED)
find_package(Armadillo CONFIG REQUIRED)
# Add source to this project's executable.
add_executable (CMakeTarget "Dynamic Memory C.cpp" "Dynamic Memory C.h")
target_include_directories(CMakeTarget PRIVATE ${RAPIDXML_INCLUDE_DIRS})
target_include_directories(CMakeTarget PRIVATE ${RAPIDJSON_INCLUDE_DIRS})
    target_link_libraries(CMakeTarget PRIVATE ${ARMADILLO_LIBRARIES})

# TODO: Add tests and install targets if needed.
