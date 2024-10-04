# translations

# Note:
# In most cases you don't need to edit this meson.build file.
# If you need to add/remove languages, edit LINGUAS located in this directory

lupdate_executable = find_program('lupdate', required: true)

TRANSLATIONS = files('TRANSLATIONS')

langs = FS.read(TRANSLATIONS).strip().split('\n')

ts_list = []
ts_paths = []
foreach lang: langs
  ts_file = '@0@.ts'.format(lang)
  ts_list += ts_file
  ts_paths += meson.current_source_dir() / ts_file
endforeach

run_target(
  'translations',
  command: [
    lupdate_executable,
    '-no-obsolete',
    PROGRAM_TS_SRCS,
    '-ts',
    ts_paths
  ]
)


QM_FILES = QT_MOD.compile_translations(ts_files: ts_list)

qm_qrc = custom_target(
  input: QM_FILES,
  output: 'qm.qrc',
  command: [
    PYTHON_EXECUTABLE,
	PY_SCRIPTS[0], # gen_qrc.py
	meson.current_build_dir(),
	'@OUTPUT@'
  ]
)

PROGRAM_SOURCES += custom_target(
  input: qm_qrc,
  output: '@PLAINNAME@.cpp',
  command: [
    'rcc',
	'-o',
	'@OUTPUT@',
	'@INPUT@'
  ]
)