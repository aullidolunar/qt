# scripts

find_package(Python3 COMPONENTS Interpreter REQUIRED)

add_custom_command(
	OUTPUT "${CMAKE_BINARY_DIR}/translations.qrc"
	DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/gen_translations_qrc.py"
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	COMMAND Python3::Interpreter gen_translations_qrc.py "${CMAKE_BINARY_DIR}/translations" "${CMAKE_BINARY_DIR}/translations.qrc"
	VERBATIM
)

add_custom_target(create-translations-qrc DEPENDS "${CMAKE_BINARY_DIR}/translations.qrc" VERBATIM)
add_dependencies(create-qm create-translations-qrc)
# add_dependencies(${BIN_NAME} create-translations-qrc)

target_sources(${BIN_NAME} PRIVATE "${CMAKE_BINARY_DIR}/translations.qrc")