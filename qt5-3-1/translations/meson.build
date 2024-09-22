# translations

# Note:
# In most cases you don't need to edit this meson.build file.
# If you need to add/remove languages, edit TRANSLATIONS located in this directory

translations_file = files('LINGUAS')

lupdate_executable = find_program('lupdate', required: true)

langs = FS.read(translations_file).strip().split('\n')

ts_list = []
ts_paths = []
po_paths = []
foreach lang: langs
	
	ts_file = lang + '.ts'
	ts_list += ts_file
	ts_paths += meson.current_source_dir() / ts_file
	if not IS_WIN32
		po_paths += meson.current_source_dir() / lang + '.po'
	endif
	
endforeach

run_target(
	'translations',
	command: [
		lupdate_executable,
		'-no-obsolete',
		TS_SOURCE_FILES,
		'-ts',
		ts_paths
	]
)

PROGRAM_SOURCES += QT_MOD.compile_translations(ts_files: ts_list)

if not IS_WIN32

	run_target(
		'desktop-po',
		command: [
			PYTHON_EXECUTABLE,
			PY_SCRIPTS[0], # desktop.py
			PROGRAM_NAME,
			PROGRAM_DESC,
			meson.current_source_dir(),
			langs
		]
	)
	
	PROGRAM_SOURCES += custom_target(
		input: [DESKTOP_IN, po_paths],
		output: PROGRAM_NAME + '.desktop',
		command: [
			msgfmt_executable,
			'--desktop',
			'--template=@INPUT0@',
			'-d',
			meson.current_source_dir(),
			'-o',
			'@OUTPUT@'
		]
	)

endif
