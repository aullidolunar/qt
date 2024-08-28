# python gen_ts_files.py "lupdate_executable" "ts_outdir" "sources_size" "sources_list" "ts_files_size" "ts_filenames"

import os
import sys
import subprocess

n = 1 # arg counter
lupdate_executable = sys.argv[n]
n += 1
ts_outdir = sys.argv[n]
n += 1
sources_size = int(sys.argv[n])

sources = []
for _ in range(0, int(sources_size)):
	n += 1
	sources.append(sys.argv[n])

n += 1
ts_files_size = int(sys.argv[n])
ts_files = []
for _ in range(0, int(ts_files_size)):
	n += 1
	ts_files.append(sys.argv[n])

save_cwd = os.getcwd()
os.chdir(ts_outdir)

subprocess.call([
	lupdate_executable,
	'-no-obsolete',
	*sources,
	'-ts',
	*ts_files
])

os.chdir(save_cwd)
