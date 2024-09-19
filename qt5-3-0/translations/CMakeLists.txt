# translations

# Note:
# In most cases you don't need to edit this CMakeLists.txt file.
# If you need to add/remove languages, edit TRANSLATIONS located in this directory

file(READ "TRANSLATIONS" TRANSLATIONS)
string(STRIP ${TRANSLATIONS} TRANSLATIONS_STRIPED)
string(REGEX REPLACE "\r?\n" ";" LANGS ${TRANSLATIONS_STRIPED})

set(TS_LIST)
set(TRANSLATION_FILES)
foreach (lang ${LANGS})
	set(TRANSLATION_FILES ${TRANSLATION_FILES} "${lang}.ts")
	set(TS_LIST ${TS_LIST} "${CMAKE_CURRENT_SOURCE_DIR}/${lang}.ts")
endforeach()

add_custom_target(
	translations
    COMMAND
		${Qt${WITH_QT}_LUPDATE_EXECUTABLE}
		${PROGRAM_SOURCES}
		-ts
		${TS_LIST}
    VERBATIM
)

qt5_create_translation(QM_FILES ${PROGRAM_SOURCES} ${TRANSLATION_FILES})

add_custom_target(mo-files ALL DEPENDS ${QM_FILES})
add_dependencies(${BIN_NAME} mo-files)
