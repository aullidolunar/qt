# data

qrc_files = files('all.qrc')

subdir(IS_WIN32 ? 'win' : 'unix')

ui_files = files('FormUI.ui')

TS_SOURCE_FILES += ui_files

PROGRAM_SOURCES += [
  QT_MOD.compile_ui(sources: ui_files),
  QT_MOD.compile_resources(sources: qrc_files)
]

DESKTOP_FILE_IN = configure_file(
  input: files('desktop.in.in'),
  output: 'template.@BASENAME@',
  configuration: {
    'PROGRAM_NAME': PROGRAM_NAME,
    'PROGRAM_DESC': PROGRAM_DESC,
    'PROGRAM_ICON': meson.current_source_dir() / 'tux-logo-24.png'
  }
)

DESKTOP_FILE = FS.relative_to(DESKTOP_FILE_IN, meson.project_source_root())
