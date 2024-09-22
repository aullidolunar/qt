# data/win

windows = import('windows')
	
resource = configure_file(
	input: 'resource.rc.in',
	output: '@BASENAME@',
	configuration: {
		'PROGRAM_VERSION': PROGRAM_VERSION,
		'PROGRAM_VERSION_COMMA': PROGRAM_VERSION.replace('.', ','),
		'BIN_NAME': BIN_NAME, 
		'PROGRAM_DESCRIPTION': PROGRAM_DESC 
	}
)
	
PROGRAM_SOURCES += windows.compile_resources(
	resource,
	include_directories: meson.current_source_dir()
)

qrc_files += files('win_resource.qrc')
