# .

# try not to use paths with spaces

# meson setup _build

# or choose qt6:
# meson setup -DWITH_QT=6  _build
# ninja|samu -C _build [run]

# to regenerate the build env:
# meson setup _build

# add/change strings in *.cpp and/or *.ui
# and/or
# add/remove languages in translations/LINGUAS:
# meson setup _build --reconfigure
# meson compile -C _build translations update-po
# edit manually the affected *.ts and *.po files then rebuild:
# meson compile -C _build [run]

project('qt', 'cpp', version : '3.3.0.1', default_options : ['cpp_std=c++17', 'warning_level=3'])

QT_VER          = get_option('WITH_QT')

PROGRAM_VERSION = meson.project_version()
version_str     = PROGRAM_VERSION.split('.')
PROGRAM_NAME    = meson.project_name() + QT_VER + '-' + version_str[0] + '-' + version_str[1]
PROGRAM_DEFS    = ['-DPROGRAM_NAME="' + PROGRAM_NAME + '"',
				   '-DPROGRAM_TITLE="' + PROGRAM_NAME + ' release ' + PROGRAM_VERSION + '"'
				  ]

QT_MOD          = import('qt' + QT_VER)
qt_dep          = dependency('qt' + QT_VER, modules: ['Widgets'], required: true)
MESON_VERSION   = meson.version()
TOOLKIT_VERSION = qt_dep.version()
PROGRAM_DESC    = 'Compile with Qt @0@ and with Meson @1@'

IS_WIN32        = (build_machine.system() == 'windows') ? true : false

FS              = import('fs')

PROGRAM_SOURCES = []
TS_SOURCE_FILES = []
PROGRAM_INCDIRS = []

subdir('scripts')
subdir('src')
subdir('data')
subdir('translations')

bin_path = executable(
	PROGRAM_NAME,
	PROGRAM_SOURCES,
	dependencies : [qt_dep],
	cpp_args: PROGRAM_DEFS,
	include_directories: PROGRAM_INCDIRS,
	native: true
)

run_target('run', command: bin_path)

zip_path = find_program('7z')

project_dir = FS.parent(meson.project_build_root())
project_channel = FS.stem(project_dir)

run_target(
	'zip',
	command: [
		zip_path,
		'a',
		'-t7z',
		'-xr!*_build',
		project_channel + '.7z',
		project_dir
	]
)