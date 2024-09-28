# python pofiles.py msgmerge_executable program_pot po_dir langs

import os
import sys
import subprocess

msgmerge_executable = sys.argv[1]
program_pot = sys.argv[2]
po_dir = sys.argv[3]
langs = sys.argv[4:]

saved_cwd = os.getcwd()
os.chdir(po_dir)

for lang in langs:
	subprocess.call([
		msgmerge_executable,
		'-U',
		'--backup=none',
		f'{lang}.po',
		program_pot,
	])

os.chdir(saved_cwd)
