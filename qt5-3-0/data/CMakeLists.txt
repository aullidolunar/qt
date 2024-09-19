# data

set(DATA_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/all.qrc)

if (WIN32)
	add_subdirectory(win)
else()
	add_subdirectory(unix)
endif()

set(DATA_SOURCES ${DATA_SOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/FormUI.ui)
target_sources(${BIN_NAME} PRIVATE ${DATA_SOURCES})

set(SOURCE_FILES ${SOURCE_FILES} ${DATA_SOURCES})
set(PROGRAM_SOURCES "${PROGRAM_SOURCES}" "${CMAKE_CURRENT_SOURCE_DIR}/FormUI.ui" PARENT_SCOPE)