# src

set(SOURCE_FILES main.cpp MainWindow.cpp MyTranslator.cpp)

target_sources(${BIN_NAME} PRIVATE ${SOURCE_FILES})

set(SCS)
foreach(SRC ${SOURCE_FILES})
	set(SCS "${SCS}" "${CMAKE_CURRENT_SOURCE_DIR}/${SRC}")
endforeach()

set(PROGRAM_SOURCES "${PROGRAM_SOURCES}" "${SCS}" PARENT_SCOPE)

