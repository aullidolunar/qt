# data

qrc_files = []

qrc_files += files('all.qrc')

if IS_WIN32
	
	windows = import('windows')

	rc_data = configuration_data()
	rc_data.set('PROGRAM_NAME', meson.project_name())
	rc_data.set('PROGRAM_VERSION', meson.project_version())
	rc_data.set('PROGRAM_VERSION_COMMA', meson.project_version().replace('.', ','))
	rc_data.set('PROGRAM_DESCRIPTION', PROGRAM_DESC)
	rc_data.set('BIN_NAME', PROGRAM_NAME)

	resource_rc = configure_file(
		input : 'resource.rc.in',
		output : 'resource.rc',
		configuration : rc_data
	)
	
	PROGRAM_SOURCES += windows.compile_resources(
		resource_rc,
		include_directories: meson.current_source_dir()
	)
	
	qrc_files += files('win_resource.qrc')

else
	
	qrc_files += files('unix_resource.qrc')

endif

ui_files = files('FormUI.ui')

SOURCE_FILES += ui_files

PROGRAM_SOURCES += QT_MOD.compile_ui(sources: ui_files)

PROGRAM_SOURCES += QT_MOD.compile_resources(sources: qrc_files)
