# translations

# Note:
# In most cases you don't need to edit this meson.build file.
# If you need to add/remove languages, edit LINGUAS located in this directory

i18n = import('i18n')

translations_file = files('LINGUAS')

lupdate_executable = find_program('lupdate', required: true)

langs = FS.read(translations_file).strip().split('\n')

ts_list = []
ts_paths = []
po_paths = []
foreach lang: langs
	
	ts_file = lang + '.ts'
	po_file = lang + '.po'
	
	ts_list += ts_file
	
	ts_paths += meson.current_source_dir() / ts_file
	po_path = meson.current_source_dir() / po_file

	if not FS.exists(po_path)
		
		run_command(
			PYTHON_EXECUTABLE,
			PY_SCRIPTS[0], # touch.py
			po_file,
			check: false
		)

	endif
	
	po_paths += po_path
	
endforeach

# creates <meson.project_name()>-update-po
gettext = i18n.gettext(
	meson.project_name(),
	args: [
		'--msgid-bugs-address="aullidolunar@gmail.com"',
		'--package-version="' + PROGRAM_VERSION + '"'
	]
)

# Save current source files with translatable strings in POTFILES:
run_command(
	PYTHON_EXECUTABLE,
	PY_SCRIPTS[1], # potfiles.py
	meson.current_source_dir(),
	DESKTOP_FILE,
	check: false
)

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

desktopfile_in = custom_target(
	input: [DESKTOP_FILE_IN, po_paths],
	output: PROGRAM_NAME + '.desktop.in',
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

desktopfile = custom_target(
	input: desktopfile_in,
	output: '@BASENAME@',
	command: [
		PYTHON_EXECUTABLE,
		PY_SCRIPTS[2], # desktop.py
		'@INPUT@',
		qt_dep.version(),
		meson.version(),
		'@OUTPUT@'
	]
)

PROGRAM_SOURCES += [
	QT_MOD.compile_translations(ts_files: ts_list),
	desktopfile
]
