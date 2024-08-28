# .

# try not to use paths with spaces

# mkdir build
# cd build
# meson setup
# or choose qt6:
# meson setup -DWITH_QT=6 [--reconfigure]
# ninja
# ninja run

# to regenerate the build env:
# meson setup --reconfigure

# add/change strings in *.cpp and/or *.ui
# and/or
# add/remove languages in translations/meson.build:
# ninja create-ts
# edit manually the affected *.ts, then rebuild langs.qrc with the updated strings/qm files:
# ninja update-qm
# ninja [run]

# change strings in *.ts:
# ninja update-qm
# ninja [run]

project('qt', 'cpp', version : '2.0.0.0', default_options : ['cpp_std=c++17', 'warning_level=3'])

QT_VER          = get_option('WITH_QT')

MESON_VERSION   = meson.version()
PROGRAM_VERSION = meson.project_version()
version_str     = PROGRAM_VERSION.split('.')
PROGRAM_NAME    = meson.project_name() + QT_VER + '-' + version_str[0] + '-' + version_str[1]
PROGRAM_DESC    = 'Programa compilado con MESON ' + MESON_VERSION
PROGRAM_DEFS    = ['-DPROGRAM_NAME="' + PROGRAM_NAME + '"',
				   '-DPROGRAM_TITLE="' + PROGRAM_NAME + ' ' + PROGRAM_VERSION + '"'
				  ]

QT_MOD          = import('qt' + QT_VER)
qt_dep          = dependency('qt' + QT_VER, modules: ['Widgets'], required: true)
QT_FULL_VERSION = qt_dep.version()

IS_WIN32        = (build_machine.system() == 'windows') ? true : false

FS              = import('fs')

PROGRAM_SOURCES = []

subdir('src')
subdir('data')
subdir('scripts')
subdir('translations')

bin_path = executable(
	PROGRAM_NAME,
	PROGRAM_SOURCES,
	dependencies : [qt_dep],
	cpp_args: PROGRAM_DEFS,
	native: true
)

run_target('run', command : bin_path)

zip_path = find_program('7z')

build_dirname = FS.stem(meson.current_build_dir())
proyect_dirname = FS.name(meson.project_source_root())

run_target(
	'zip',
	command: [
		zip_path,
		'a',
		'-t7z',
		'-xr!' + build_dirname,
		PROGRAM_NAME + '.7z',
		'../../' + proyect_dirname
	]
)
