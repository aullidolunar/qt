# translations

# Note:
# In most cases you don't need to edit this meson.build file.
# If you need to add/remove languages, edit TRANSLATIONS locates in this directory

translations_file = files('TRANSLATIONS')

lupdate_executable = find_program('lupdate', required: true)

langs = FS.read(translations_file).strip().split(' ')

ts_files = []
foreach lang: langs
	ts_files += meson.current_source_dir() / lang + '.ts'
endforeach

run_target(
	'create-ts',
	command: [
		lupdate_executable,
		'-no-obsolete',
		SOURCE_FILES,
		'-ts',
		ts_files
	]
)

langs_qrc = custom_target(
	'create-qm',
	input: ts_files,
	output: 'langs.qrc',
	command: [
		PYTHON_EXECUTABLE,
		GEN_LANGS_QRC, # gen_langs_qrc.py
		'@OUTPUT@', # name of qresource with qms to be embeded
		ts_files.length().to_string(), # number of ts files
		'@INPUT@'  # list of ts files
	]
)

langs_cpp = custom_target(
		'langs_cpp',
		input: langs_qrc,
		output: 'langs.cpp',
		command: [
			'rcc',
			'-o',
			'@OUTPUT@',
			'-g',
			'cpp',
			'@INPUT@'
		]
	)

PROGRAM_SOURCES += langs_cpp

run_target(
	'update-qm',
	command: [
		'rm',
		langs_cpp,
		langs_qrc
	]
)
