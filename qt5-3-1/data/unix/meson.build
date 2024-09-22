# data/unix

python = import('python')
PYTHON_EXECUTABLE = python.find_installation().path()

msgfmt_executable = find_program('msgfmt', required: true)

PY_SCRIPTS = files('desktop.py')

qrc_files += files('unix_resource.qrc')

DESKTOP_IN = configure_file(
	input: 'desktop.in',
	output: PROGRAM_NAME + '.desktop.in',
	configuration: {
		'PROGRAM_NAME': PROGRAM_NAME,
		'PROGRAM_DESC': PROGRAM_DESC,
		'PROGRAM_ICON': meson.current_source_dir() / 'tux-logo-24.png'
	}
)
