# .

# cmake -B cmake_build -DWITH_QT=[5/6] -GNinja
# ninja/samu -C cmake_build [run]

cmake_minimum_required(VERSION 3.20)

project(qt VERSION 5.3.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(NOT DEFINED WITH_QT)
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
set(PROGRAM_NAME "${PROJECT_NAME}")
set(PROGRAM_VERSION "${PROJECT_VERSION_MAJOR}")
set(PROGRAM_DESCRIPTION "Compile with QT ${QT_VERSION} with CMake ${CMAKE_VERSION}")

find_package(Qt${WITH_QT} COMPONENTS Widgets LinguistTools REQUIRED)

set(CMAKE_AUTOUIC_SEARCH_PATHS "${PROJECT_SOURCE_DIR}/data")

add_executable(${BIN_NAME})

set(PROGRAM_SOURCES)
add_subdirectory(src)
add_subdirectory(data)
add_subdirectory(translations)

target_compile_definitions (${BIN_NAME} PRIVATE PROGRAM_TITLE="${BIN_NAME} release ${PROJECT_VERSION}")
target_link_libraries(${BIN_NAME} PRIVATE Qt::Widgets)

add_custom_target(
	run
    COMMAND
		${BIN_NAME}
	VERBATIM
)

find_program(ZIP_EXECUTABLE "7z")

if (ZIP_EXECUTABLE)

	cmake_path(GET PROJECT_SOURCE_DIR PARENT_PATH rootName)
	cmake_path(GET PROJECT_SOURCE_DIR FILENAME channel)

	add_custom_target(
		zip
		WORKING_DIRECTORY
			${rootName}
		COMMAND
			${ZIP_EXECUTABLE}
			a
			-t7z
			-xr!*_build
			${CMAKE_CURRENT_BINARY_DIR}/${channel}.7z
			${channel}
		VERBATIM
	)

endif()