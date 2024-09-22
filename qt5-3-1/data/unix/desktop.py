# python desktop.py program_name program_desc po_dir langs_list

import os
import sys

program_name = sys.argv[1]
program_desc = sys.argv[2]
po_dir = sys.argv[3]
langs_list = sys.argv[4:]

save_cwd = os.getcwd()
os.chdir(po_dir)

for lang in langs_list:
	with open(lang + '.po', 'w') as pf:
		pf.write(f'msgid "{program_name}"\n')
		pf.write(f'msgstr ""\n\n')
		pf.write(f'msgid "{program_desc}"\n')
		pf.write(f'msgstr ""\n')

os.chdir(save_cwd)
