# src

MesonHelper_h = configure_file(
  input: files('MesonHelper.h.in'),
  output: '@BASENAME@',
  configuration: {
    'PROGRAM_NAME': PROGRAM_NAME,
    'PROGRAM_DESC': PROGRAM_DESC
  }
)

SOURCE_FILES = files('main.cpp', 'MainWindow.cpp', 'MyTranslator.cpp')
MOC_FILES    = files('MainWindow.h')

PROGRAM_SOURCES += [
  SOURCE_FILES,
  QT_MOD.compile_moc(headers: MOC_FILES)
]

PROGRAM_TS_SRCS += [SOURCE_FILES, MesonHelper_h]

PROGRAM_INCDIRS += include_directories('.')