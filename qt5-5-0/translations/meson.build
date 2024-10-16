# translations

# Note:
# In most cases you don't need to edit this meson.build file.
# If you need to add/remove languages, edit LINGUAS located in this directory

i18n = import('i18n')

lupdate_executable = find_program('lupdate', required: true)

translations_file = files('LINGUAS')

langs = FS.read(translations_file).strip().split('\n')

ts_list  = []
ts_paths = []
po_paths = []
qm_list  = ''
foreach lang: langs
  ts_file = '@0@.ts'.format(lang)
  ts_list += ts_file
  ts_paths += meson.current_source_dir() / ts_file
  po_file = meson.current_source_dir() / '@0@.po'.format(lang)
  if not FS.exists(po_file)
    run_command(
      TOUCH_CMD,
      po_file,
      check: true
    )
  endif
  po_paths += po_file
  qm_list += f'\n\t\t<file alias="@lang@">@lang@.qm</file>'
endforeach

qm_qrc = configure_file(
  input: files('linguas.qrc.in'),
  output: '@BASENAME0@',
  configuration: {
    'list': qm_list
  }
)

run_target(
  'potfiles',
  command: [
    SH_CMD,
    'echo -n "@0@" > "@1@"'.format(DESKTOP_FILE_PATH, meson.current_source_dir() / 'POTFILES')
  ]
)

gettext = i18n.gettext(
  PROGRAM_NAME,
  preset: 'glib',
  args: [
    '--msgid-bugs-address="aullidolunar@gmail.com"',
    f'--package-name="@PROGRAM_NAME@"',
    f'--package-version="@PROGRAM_VERSION@"'
  ]
)

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

PROGRAM_I18NDEP += custom_target(
  input: [DESKTOP_FILE_IN, po_paths],
  output: '@BASENAME0@',
  command: [
    'msgfmt',
    '--desktop',
    '--template=@INPUT0@',
    '-d',
    '@CURRENT_SOURCE_DIR@',
    '-o',
    '@OUTPUT0@'
  ]
)

qt_translations = QT_MOD.compile_translations(ts_files: ts_list)

PROGRAM_SOURCES += custom_target(
  input: qm_qrc,
  output: '@BASENAME0@.cpp',
  depends: qt_translations,
  command: [
    'rcc',
    '-o',
    '@OUTPUT@',
    '@INPUT@'
  ]
)