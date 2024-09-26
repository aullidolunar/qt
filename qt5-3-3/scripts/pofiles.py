# python pofiles.py msginit_executable program_pot po_dir langs

import os
import sys
import subprocess

msginit_executable = sys.argv[1]
program_pot = sys.argv[2]
po_dir = sys.argv[3]
langs = sys.argv[4:]

saved_cwd = os.getcwd()
os.chdir(po_dir)

for lang in langs:
	subprocess.call([
		msginit_executable,
		'-i',
		program_pot,
		'-l',
		f'{lang}.UTF-8',
		'--no-translator',
		'-o',
		f'{lang}.po'
	])

os.chdir(saved_cwd)
