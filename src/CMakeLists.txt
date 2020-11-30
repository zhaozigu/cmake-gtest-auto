# example library
add_library(sum_integers sum_integers.cpp)
# main code
add_executable(sum_up main.cpp)

target_link_libraries(sum_up sum_integers)