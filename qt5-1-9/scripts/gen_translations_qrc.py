# python gen_translations_qrc.py "dir_with_qms" "save_qrc"

import sys
import glob
from pathlib import Path
from lxml import etree

dir_with_qms = sys.argv[1]
save_qrc = sys.argv[2]

root = etree.Element("RCC", version="1.0")
qresource = etree.SubElement(root, "qresource", prefix="/translations")

qm_files = glob.glob(dir_with_qms + '/*.qm')

for qm_file in qm_files:
	lang = Path(qm_file).stem
	new_qm = etree.Element("file", alias=f"{lang}")
	new_qm.text = qm_file
	qresource.append(new_qm)

tree = etree.tostring(root, encoding="utf-8", pretty_print=True, doctype="<!DOCTYPE RCC>")

with open(save_qrc, "w", encoding='UTF-8') as xf:
	xf.write(tree.decode())
