# .

# try not to use paths with spaces

# rsync -rvu -tpgo --exclude=_build/ --delete stage/ qt5-4-0/

# meson setup _build
# or choose qt6:
# meson setup -DUSE_QT_VER=6 _build

# meson compile -C _build

# to regenerate the build env:
# meson setup _build --reconfigure

# i18n:
# add/remove languages in translations/LINGUAS:
# meson setup _build --reconfigure
# meson compile -C _build translations
# edit manually the affected *.ts and *.po files then rebuild:
# meson compile -C _build [run]

project('qt', 'cpp', version : '4.0.0.0', default_options : ['cpp_std=c++17', 'warning_level=3'])

IS_WIN        = (build_machine.system() == 'windows') ? true : false

FS              = import('fs')

QT_VER          = get_option('USE_QT_VER')
QT_MOD          = import(f'qt@QT_VER@')
QT_DEP          = dependency(f'qt@QT_VER@', modules: ['Widgets'], required: true)

zip_program     = find_program('7z')

PROGRAM_VERSION = meson.project_version()
version_tokens  = PROGRAM_VERSION.split('.')
PROGRAM_NAME    = '@0@@1@-@2@-@3@'.format(meson.project_name(), QT_VER, version_tokens[0], version_tokens[1])
PROGRAM_DESC    = 'Qt@0@ application demo'.format(QT_VER)
PROGRAM_TITLE   = f'@PROGRAM_NAME@ @PROGRAM_VERSION@'
PROGRAM_DEFS    = [
  f'-DPROGRAM_NAME="@PROGRAM_NAME@"',
  f'-DPROGRAM_VERSION="@PROGRAM_VERSION@"',
  f'-DPROGRAM_TITLE="@PROGRAM_TITLE@"'
]

PROGRAM_SOURCES = []
PROGRAM_TS_SRCS = []
PROGRAM_INCDIRS = []

subdir('scripts')
subdir('src')
subdir('data')
subdir('translations')

program_executable = executable(
  PROGRAM_NAME,
  PROGRAM_SOURCES,
  dependencies: QT_DEP,
  cpp_args: PROGRAM_DEFS,
  include_directories: PROGRAM_INCDIRS,
  native: true
)

run_target(
  'run',
  command: [
    program_executable
  ]
)

project_dir = FS.parent(meson.project_build_root())

run_target(
  'zip',
  command: [
    zip_program,
    'a',
    '-t7z',
    '-xr!*_build',
    f'@PROGRAM_NAME@-@PROGRAM_VERSION@-src.7z',
    project_dir
  ]
)