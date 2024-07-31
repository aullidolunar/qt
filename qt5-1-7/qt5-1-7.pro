# you can build out-of-source
# create folder: build
# cd build
# for qt5: qmake ..
# for qt6: qmake6 ..
# then: make
# to test the binary: make run

PROGRAM_NAME = $$basename(_PRO_FILE_PWD_)

TEMPLATE = app
TARGET = $${PROGRAM_NAME}
VERSION = 1.0.0.1

CONFIG += debug

QT += core

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += widgets
	CONFIG += c++14
}

OBJECTS_DIR = qt$${QT_VERSION}_objs
RCC_DIR = $$OBJECTS_DIR
UI_DIR = $$OBJECTS_DIR
MOC_DIR = $$OBJECTS_DIR
PRECOMPILED_DIR = $$OBJECTS_DIR
DESTDIR = $$OBJECTS_DIR

DEFINES += PROGRAM_TITLE='"\\\"$$TARGET $$VERSION\\\""'

FORMS += data/MainWindowUI.ui
SOURCES += src/MyWindow.cpp src/main.cpp
HEADERS += src/MyWindow.h

RESOURCES += data/resources.qrc

QMAKE_EXTRA_TARGETS += run zip

win32 {
	release: BIN_PATH = ./$$DESTDIR/$${TARGET}.exe
	debug: BIN_PATH = ./$$DESTDIR/$${TARGET}.exe
	RC_ICONS = data/main.ico
	QMAKE_TARGET_COMPANY = "aullidolunar"
	QMAKE_TARGET_COPYRIGHT = "Copyleft"
	QMAKE_TARGET_DESCRIPTION = "Programa hecho en QT-$${QT_VERSION}"
	RC_LANG = 0x080A
	RESOURCES += data/resource_win.qrc
} else {
	BIN_PATH = ./$$DESTDIR/$$TARGET
	RESOURCES += data/resource_nix.qrc
}

run.commands = $${BIN_PATH}
run.depends = $${BIN_PATH}

PROJECT_DIR = $$clean_path($$PWD/../)

zip.commands = cd $${PROJECT_DIR} && 7z a -t7z $${PROGRAM_NAME}/build/$${PROGRAM_NAME}.7z $${PROGRAM_NAME}/$${PROGRAM_NAME}.pro $${PROGRAM_NAME}/data $${PROGRAM_NAME}/src
