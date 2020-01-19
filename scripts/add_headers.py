#!/usr/bin/python3

import glob
import os
#get the hpp_files
files = glob.glob('src/**/*.hpp', recursive=True)

modified_files = []
for file in files:
    with open(file, "r+") as f:       
        filename = os.path.basename(file).split(".")[0]
        old = f.read()
        f.seek(0)
        first_line = f.readline()
        if filename in first_line and '#ifndef' in first_line:
            continue
        modified_files.append(file)
        filename = "__" + filename + "__"
        f.seek(0)
        first_line = "#ifndef " + filename  + "\n" + "#define " + filename + "\n"
        last_line = "\n#endif"
        f.write(first_line + old + last_line)

if modified_files:
    print("modified the following files:", modified_files)
else:
    print("no files modified")
    