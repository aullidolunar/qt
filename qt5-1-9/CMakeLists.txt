# .

# cmake -DCMAKE_BUILD_TYPE=Debug -DWITH_QT=[5/6] -GNinja ..

cmake_minimum_required(VERSION 3.20)

project(qt VERSION 1.9.0.1 DESCRIPTION "Programa hecho en QT" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(NOT WITH_QT)
	set(WITH_QT 5)
endif()

if(WITH_QT LESS 5)
	message(FATAL_ERROR "I don't have support for qt ${WITH_QT}.x, please choose for WITH_QT 5 or 6.")
elseif(WITH_QT EQUAL 5)
	set(QMAKE_NAME qmake)
elseif(WITH_QT EQUAL 6)
	set(QMAKE_NAME qmake6)
else()
	message(FATAL_ERROR "I don't have YET support for qt ${WITH_QT}.x, please choose for WITH_QT 5 or 6.")
endif()

find_program(QMAKE_PATH names ${QMAKE_NAME} NO_CACHE REQUIRED)
execute_process(COMMAND ${QMAKE_PATH} -query QT_VERSION OUTPUT_VARIABLE QT_VERSION OUTPUT_STRIP_TRAILING_WHITESPACE)

message(STATUS "WITH_QT=${WITH_QT}")
message(STATUS "QMAKE_NAME=${QMAKE_NAME}")
message(STATUS "QMAKE_PATH=${QMAKE_PATH}")
message(STATUS "QT_VERSION=${QT_VERSION}")

set(BIN_NAME "${PROJECT_NAME}${WITH_QT}-${PROJECT_VERSION_MAJOR}-${PROJECT_VERSION_MINOR}")

find_package(Qt${WITH_QT} COMPONENTS Widgets REQUIRED)

set(CMAKE_AUTOUIC_SEARCH_PATHS "${PROJECT_SOURCE_DIR}/data")

add_executable(${BIN_NAME})

add_subdirectory(src)
add_subdirectory(data)
add_subdirectory(translations)
add_subdirectory(scripts)

target_compile_definitions (${BIN_NAME} PRIVATE PROGRAM_TITLE="${BIN_NAME} ${PROJECT_VERSION}")
target_link_libraries(${BIN_NAME} PRIVATE Qt::Widgets)

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
