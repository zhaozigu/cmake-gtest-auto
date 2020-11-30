# 3.11 才有 FetchContent
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# 项目名称
project(cmake-gtest LANGUAGES CXX)

# C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

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
	FetchContent_GetProperties(googletest)

	if(NOT googletest_POPULATED)
  	FetchContent_Populate(googletest)
		set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
		set(gtest_disable_pthreads ON CACHE BOOL "" FORCE)
		# add the targets: gtest、gtest_main、gmock、gmock_main
		add_subdirectory(
			${googletest_SOURCE_DIR}
			${googletest_BINARY_DIR}
		)

		if(MSVC)
			foreach(_tgt gtest gtest_main gmock gmock_main)
				target_compile_definitions(${_tgt}
					PRIVATE
						"_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING"
        )
    	endforeach()
		endif()
  endif()

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
