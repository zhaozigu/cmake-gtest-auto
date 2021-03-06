# 3.11 才有 FetchContent
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# 项目名称
project(cmake-gtest LANGUAGES CXX)

# C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src)
add_subdirectory(src)

option(ENABLE_UNIT_TESTS "Enable unit tests" ON)
message(STATUS "Enable testing: ${ENABLE_UNIT_TESTS}")

if (ENABLE_UNIT_TESTS)
	include(FetchContent)
	FetchContent_Declare(
  	googletest
  	GIT_REPOSITORY https://github.com/google/googletest.git
  	GIT_TAG release-1.10.0
	)
	
	FetchContent_MakeAvailable(googletest)

	add_executable(cpp_test "")
	target_sources(cpp_test
		PRIVATE
			tests/test.cpp
	)

	target_link_libraries(cpp_test
  	PRIVATE
    	sum_integers
    	gtest_main
  )

	enable_testing()
	add_test(
  	NAME google_test
  	COMMAND $<TARGET_FILE:cpp_test>
  )
endif()
