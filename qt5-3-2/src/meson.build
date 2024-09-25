# src

SOURCE_FILES = files('main.cpp', 'MainWindow.cpp', 'MyTranslator.cpp')
MOC_FILES    = files('MainWindow.h')

PROGRAM_SOURCES += [
	SOURCE_FILES,
	QT_MOD.compile_moc(headers: MOC_FILES)
]

TS_SOURCE_FILES += SOURCE_FILES
