# python touch.py file_path

import os
import sys

def touch(_file):
	with open(_file, 'a') as tf:
		pass

touch(sys.argv[1])
