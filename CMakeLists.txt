cmake_minimum_required(VERSION 3.5)

project(kmp_test)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(kmp)

aux_source_directory(./ PROJECT_SRCS)
add_executable(${PROJECT_NAME} ${PROJECT_SRCS})

target_include_directories(${PROJECT_NAME} PUBLIC
	${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/kmp/include)
#include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/class_base/include ${PROJECT_SOURCE_DIR}/class_derived/include)

target_link_libraries(${PROJECT_NAME} kmp)
#link_directories(class_base class_derived)
