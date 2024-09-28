# src

MesonHelperCPP = configure_file(
  input: 'MesonHelper.cpp.in',
  output: '@BASENAME@',
  configuration: {
    'PROGRAM_DESC': PROGRAM_DESC,
    'TOOLKIT_VERSION': TOOLKIT_VERSION,
    'MESON_VERSION': MESON_VERSION,
	'cero': '@0@',
	'uno': '@1@'
  }
)

SOURCE_FILES = files('main.cpp', 'MainWindow.cpp', MesonHelperCPP.full_path(), 'MyTranslator.cpp')
MOC_FILES    = files('MainWindow.h')

PROGRAM_SOURCES += [
	SOURCE_FILES,
	QT_MOD.compile_moc(headers: MOC_FILES)
]

TS_SOURCE_FILES += SOURCE_FILES

PROGRAM_INCDIRS += include_directories('.')