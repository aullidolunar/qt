# .

cmake_minimum_required(VERSION 3.20)

project(qt5 VERSION 1.5.0.0 DESCRIPTION "Programa prueba de QT5" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(BIN_NAME "${PROJECT_NAME}-${PROJECT_VERSION_MAJOR}-${PROJECT_VERSION_MINOR}")

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(CMAKE_AUTOUIC_SEARCH_PATHS "${PROJECT_SOURCE_DIR}/data")

if (WIN32)
	find_package(Qt5WinExtras REQUIRED)	
endif()

add_executable(${BIN_NAME})

add_subdirectory(src)
add_subdirectory(data)
add_subdirectory(translations)
add_subdirectory(scripts)

target_compile_definitions (${BIN_NAME} PRIVATE PROGRAM_NAME="${BIN_NAME} ${PROJECT_VERSION}")
target_link_libraries(${BIN_NAME} PRIVATE Qt::Widgets)
if (WIN32)
	target_link_libraries(${BIN_NAME} PRIVATE Qt::WinExtras)	
endif()

add_custom_target(run
    COMMAND ${BIN_NAME}
    DEPENDS ${BIN_NAME}
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)

cmake_path(GET PROJECT_SOURCE_DIR PARENT_PATH MY_PROJECT_DIR)
cmake_path(GET PROJECT_SOURCE_DIR STEM MY_PROJECT_NAME)

add_custom_target(dist
	WORKING_DIRECTORY "${MY_PROJECT_DIR}"
	COMMAND ${CMAKE_COMMAND} -E tar cvf "${CMAKE_CURRENT_BINARY_DIR}/${BIN_NAME}.7z" --format=7zip "${MY_PROJECT_NAME}/data" "${MY_PROJECT_NAME}/scripts" "${MY_PROJECT_NAME}/translations" "${MY_PROJECT_NAME}/src" "${MY_PROJECT_NAME}/CMakeLists.txt"
)

