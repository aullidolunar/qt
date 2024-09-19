# translations

# Note:
# In most cases you don't need to edit this meson.build file.
# If you need to add/remove languages, edit TRANSLATIONS located in this directory

translations_file = files('TRANSLATIONS')

lupdate_executable = find_program('lupdate', required: true)

langs = FS.read(translations_file).strip().split('\n')

ts_list = []
ts_paths = []
foreach lang: langs
	ts_file = lang + '.ts'
	ts_list += ts_file
	ts_paths += meson.current_source_dir() / ts_file
endforeach

run_target(
	'translations',
	command: [
		lupdate_executable,
		'-no-obsolete',
		SOURCE_FILES,
		'-ts',
		ts_paths
	]
)

PROGRAM_SOURCES += QT_MOD.compile_translations(ts_files: ts_list)
