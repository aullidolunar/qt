# data

qrc_files = []
qrc_files += files('all.qrc')

subdir(IS_WIN32 ? 'win' : 'unix')

ui_files = files('FormUI.ui')

SOURCE_FILES += ui_files

PROGRAM_SOURCES += [
	QT_MOD.compile_ui(sources: ui_files),
	QT_MOD.compile_resources(sources: qrc_files)
]
