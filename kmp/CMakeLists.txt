project(kmp)

aux_source_directory(./src PROJECT_SRCS)
#add_executable(${PROJECT_NAME} ${PROJECT_SRCS})
add_library(${PROJECT_NAME} ${PROJECT_SRCS})

target_include_directories(${PROJECT_NAME} PRIVATE
	${PROJECT_SOURCE_DIR}/include)
