# python gen_langs_qrc.py "save_qrc" "num_ts_files" "ts_files"

import sys
import subprocess
from pathlib import Path
from lxml import etree

n = 1
save_qrc = sys.argv[n]

n += 1
num_ts_files = int(sys.argv[n])

root = etree.Element("RCC", version="1.0")
qresource = etree.SubElement(root, "qresource", prefix="/translations")

for _ in range(0, int(num_ts_files)):
	n += 1
	ts_file = sys.argv[n]
	lang = Path(ts_file).stem
	qm_file = lang + '.qm'
	new_qm = etree.Element("file", alias=f"{lang}")
	new_qm.text = qm_file
	qresource.append(new_qm)
	subprocess.call(['lrelease', ts_file, '-qm', Path(save_qrc).parent / qm_file])

tree = etree.tostring(root, encoding="utf-8", pretty_print=True, doctype="<!DOCTYPE RCC>")

with open(save_qrc, "w", encoding='UTF-8') as xf:
	xf.write(tree.decode())

