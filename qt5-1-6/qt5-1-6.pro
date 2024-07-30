# you can build out-of-source
# create folder: build
# cd build
# for qt5: qmake ..
# for qt6: qmake6 ..
# then: make
# to test the binary: make run

PROGRAM_NAME = $$basename(_PRO_FILE_PWD_)

TARGET = $${PROGRAM_NAME}
VERSION = 1.0.0.5

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

DEFINES += PACKAGE_TITLE='"\\\"$$TARGET $$VERSION\\\""'

SOURCES += MyWindow.cpp main.cpp
HEADERS += MyWindow.h

RESOURCES += resources.qrc

QMAKE_EXTRA_TARGETS += run zip

win32 {
	release: BIN_PATH = ./$$DESTDIR/$${TARGET}.exe
	debug: BIN_PATH = ./$$DESTDIR/$${TARGET}.exe
	RC_ICONS = main.ico
	QMAKE_TARGET_COMPANY = "aullidolunar"
	QMAKE_TARGET_COPYRIGHT = "Copyleft"
	QMAKE_TARGET_DESCRIPTION = "Programa hecho en QT-$${QT_VERSION}"
	RC_LANG = 0x080A
	RESOURCES += resource_win.qrc
} else {
	BIN_PATH = ./$$DESTDIR/$$TARGET
	RESOURCES += resource_nix.qrc
}

run.commands = $${BIN_PATH}
run.depends = $${BIN_PATH}

PROJECT_DIR = $$clean_path($$PWD/../)

zip.commands = cd $${PROJECT_DIR} && 7z a -t7z $${PROGRAM_NAME}/build/$${PROGRAM_NAME}.7z $${PROGRAM_NAME}/*.{cpp,h,pro,qrc,png,ico,xpm}
