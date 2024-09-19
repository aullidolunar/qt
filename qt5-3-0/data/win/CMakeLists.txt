# data/win

string(REPLACE "." "," PROGRAM_VERSION_COMMA ${PROGRAM_VERSION})

configure_file(
	"resource.rc.in"
	"resource.rc"
)

target_include_directories(${BIN_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(${BIN_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/resource.rc)

set(DATA_SOURCES ${DATA_SOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/win_resource.qrc PARENT_SCOPE)
