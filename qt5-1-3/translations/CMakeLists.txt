# translations

get_target_property(_SOURCES ${BIN_NAME} SOURCES)

# defined as needed
set(_TS_FILES es.ts fr.ts)

add_custom_target(create-ts
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	COMMAND lupdate ${_SOURCES} -ts ${_TS_FILES}
)

add_custom_target(create-qm)

foreach(_TS_FILE ${_TS_FILES})
	cmake_path(GET _TS_FILE STEM _FILENAME)
	add_custom_command(
		OUTPUT "${CMAKE_BINARY_DIR}/translations/${_FILENAME}.qm"
		DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${_TS_FILE}
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
		COMMAND lrelease ${CMAKE_CURRENT_SOURCE_DIR}/${_TS_FILE} -qm ${CMAKE_BINARY_DIR}/translations/${_FILENAME}.qm
		VERBATIM
	)
	add_custom_target(create-qm-${_FILENAME} DEPENDS "${CMAKE_BINARY_DIR}/translations/${_FILENAME}.qm")
	add_dependencies(create-qm create-qm-${_FILENAME})
endforeach()

add_dependencies(${BIN_NAME} create-qm)

target_compile_definitions(${BIN_NAME} PRIVATE PROGRAM_LOCALEDIR="${CMAKE_BINARY_DIR}/translations")
