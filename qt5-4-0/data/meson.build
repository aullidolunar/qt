# data

qrc_files = files('all.qrc')
ui_files  = files('FormUI.ui')

PROGRAM_TS_SRCS += ui_files

PROGRAM_SOURCES += [
  QT_MOD.compile_ui(sources: ui_files),
  QT_MOD.compile_resources(sources: qrc_files)
]

if IS_WIN
windows = import('windows')

resource = configure_file(
  input: files('resource.rc.in'),
  output: '@BASENAME@',
  configuration: {
    'PROGRAM_VERSION': PROGRAM_VERSION,
    'PROGRAM_VERSION_COMMA': PROGRAM_VERSION.replace('.', ','),
    'BIN_NAME': PROGRAM_NAME, 
    'PROGRAM_DESCRIPTION': PROGRAM_DESC 
  }
)
	
PROGRAM_SOURCES += windows.compile_resources(
  resource,
  include_directories: meson.current_source_dir()
)
endif
