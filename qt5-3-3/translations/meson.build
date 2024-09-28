# translations

# Note:
# In most cases you don't need to edit this meson.build file.
# If you need to add/remove languages, edit LINGUAS located in this directory

lupdate_executable = find_program('lupdate', required: true)
xgettext_executable = find_program('xgettext', required: true)
msgmerge_executable = find_program('msgmerge', required: true)
msgfmt_executable = find_program('msgfmt', required: true)

translations_file = files('LINGUAS')

program_pot = custom_target(
  input: DESKTOP_FILE_IN,
  output: PROGRAM_NAME + '.pot',
  command: [
    xgettext_executable,
	'-d',
	PROGRAM_NAME,
	'--from-code=UTF-8',
	'--package-name="' + PROGRAM_NAME + '"',
	'--package-version="' + PROGRAM_VERSION + '"',
	'--msgid-bugs-address="aullidolunar@gmail.com"',
	'--language=Desktop',
	'-o',
	'@OUTPUT@',
	'@INPUT@'
  ]
)

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
			check: true
		)

	endif
	
	po_paths += po_path
	
endforeach

run_target(
  'update-po',
  depends: program_pot,
  command: [
    PYTHON_EXECUTABLE,
    PY_SCRIPTS[1], # pofiles.py
    msgmerge_executable,
    program_pot.full_path(),  
    meson.current_source_dir(),
    langs
  ]
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
	output: '@BASENAME0@',
	command: [
		PYTHON_EXECUTABLE,
		PY_SCRIPTS[2], # desktop.py
		'@INPUT@',
		TOOLKIT_VERSION,
		MESON_VERSION,
		'@OUTPUT@'
	]
)

PROGRAM_SOURCES += [
	QT_MOD.compile_translations(ts_files: ts_list),
	desktopfile
]
