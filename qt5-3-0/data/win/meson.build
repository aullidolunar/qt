# data/win

windows = import('windows')

resource_rc = configure_file(
	input : 'resource.rc.in',
	output : 'resource.rc',
	configuration : {
		'PROGRAM_NAME': PROGRAM_NAME,
		'PROGRAM_VERSION': PROGRAM_VERSION,
		'PROGRAM_VERSION_COMMA': PROGRAM_VERSION.replace('.', ','),
		'PROGRAM_DESCRIPTION': PROGRAM_DESC,
		'BIN_NAME': PROGRAM_NAME
	}
)

PROGRAM_SOURCES += windows.compile_resources(
	resource_rc,
	include_directories: meson.current_source_dir()
)

qrc_files += files('win_resource.qrc')
