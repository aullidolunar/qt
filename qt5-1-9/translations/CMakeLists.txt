# translations

get_target_property(_SOURCES ${BIN_NAME} SOURCES)

# defined as needed
set(TS_FILES es.ts fr.ts de.ts)

add_custom_target(create-ts
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	COMMAND lupdate ${_SOURCES} -no-obsolete -ts ${TS_FILES}
	VERBATIM
)

add_custom_target(create-qm)

string(REPLACE ".ts"  "" LANGS "${TS_FILES}")

foreach(LANG ${LANGS})
	add_custom_command(
		OUTPUT "${CMAKE_BINARY_DIR}/translations/${LANG}.qm"
		DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/${LANG}.ts"
		COMMAND lrelease "${CMAKE_CURRENT_SOURCE_DIR}/${LANG}.ts" -qm "${CMAKE_BINARY_DIR}/translations/${LANG}.qm"
		VERBATIM
	)
	add_custom_target(create-qm-${LANG} DEPENDS "${CMAKE_BINARY_DIR}/translations/${LANG}.qm")
	add_dependencies(create-qm create-qm-${LANG})
endforeach()

add_dependencies(${BIN_NAME} create-qm)

string(REPLACE ";"  " " PROGRAM_LANGS "${LANGS}")
target_compile_definitions(${BIN_NAME} PRIVATE PROGRAM_TRANSLATIONS="${PROGRAM_LANGS}" PROGRAM_QMDIR="${CMAKE_BINARY_DIR}/translations")
