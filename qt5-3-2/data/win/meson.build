# data/win

windows = import('windows')

new_desc = PROGRAM_DESC

resource = configure_file(
	input: 'resource.rc.in',
	output: '@BASENAME@',
	configuration: {
		'PROGRAM_VERSION': PROGRAM_VERSION,
		'PROGRAM_VERSION_COMMA': PROGRAM_VERSION.replace('.', ','),
		'BIN_NAME': PROGRAM_NAME, 
		'PROGRAM_DESCRIPTION': new_desc.format(QT_FULL_VERSION, meson.version()) 
	}
)
	
PROGRAM_SOURCES += windows.compile_resources(
	resource,
	include_directories: meson.current_source_dir()
)

qrc_files += files('win_resource.qrc')
