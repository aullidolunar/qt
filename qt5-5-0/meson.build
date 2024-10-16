# .

# rsync -arvu --delete --delete-excluded --exclude=build/ unzipped/ unstable/
# rsync -arvu --delete --delete-excluded --exclude=build/ unstable/ stage/
# rsync -arvu --delete --delete-excluded --exclude=build/ stage/ qt5-5-0/

# meson setup _build
# or choose qt6:
# meson setup -DUSE_QT_VER=6 build

# meson compile -C build

# to regenerate the build env:
# meson setup build --reconfigure

# i18n:
# add/remove languages in translations/LINGUAS:
# meson setup build --reconfigure
# meson compile -C build translations potfiles qt5-5-0-update-po
# edit manually the affected *.ts and *.po files then rebuild:
# meson compile -C build [run]

project('qt', 'cpp', version : '5.0.0.3', default_options : ['cpp_std=c++17', 'warning_level=3'])

IS_WIN          = (build_machine.system() == 'windows') ? true : false
touch_bin       = find_program('touch', required: false)
if touch_bin.found()
  TOUCH_CMD     = touch_bin
  SH_CMD      = ['sh', '-c']
else
  TOUCH_CMD     = 'echo. >'
  SH_CMD      = ['cmd', '/C']
endif

FS              = import('fs')

QT_VER          = get_option('USE_QT_VER')
QT_MOD          = import(f'qt@QT_VER@')
QT_DEPS         = dependency(f'qt@QT_VER@', modules: ['Widgets'], required: true)
PROGRAM_VERSION = meson.project_version()
version_tokens  = PROGRAM_VERSION.split('.')
PROGRAM_NAME    = '@0@@1@-@2@-@3@'.format(meson.project_name(), QT_VER, version_tokens[0], version_tokens[1])
PROGRAM_DESC    = 'Qt application demo'
PROGRAM_DEFS    = [
  f'-DPROGRAM_VERSION="@PROGRAM_VERSION@"',
  f'-DPROGRAM_TITLE="@PROGRAM_NAME@ @PROGRAM_VERSION@"'
]

PROGRAM_SOURCES = []
PROGRAM_TS_SRCS = []
PROGRAM_INCDIRS = []
PROGRAM_I18NDEP = []

subdir('src')
subdir('data')
subdir('translations')

program_executable = executable(
  PROGRAM_NAME,
  PROGRAM_SOURCES,
  PROGRAM_I18NDEP,
  dependencies: QT_DEPS,
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

zip_path = find_program('7z', required: false)

if zip_path.found()
  project_dir = FS.parent(meson.project_build_root())
  build_dir = FS.name(meson.current_build_dir())
  run_target(
    'zip',
    command: [
      zip_path,
      'a',
      '-t7z',
      '-xr!@0@'.format(build_dir),
      f'@PROGRAM_NAME@-@PROGRAM_VERSION@-src.7z',
      project_dir
    ]
  )
endif