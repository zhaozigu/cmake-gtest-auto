# example library
add_library(sum_integers sum_integers.cpp)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)
# main code
add_executable(sum_up main.cpp)

target_link_libraries(sum_up sum_integers)