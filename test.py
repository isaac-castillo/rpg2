#!/usr/bin/python3


import subprocess
import os
import sys

curr_folder = os.path.basename(os.getcwd())
if curr_folder != 'rpg2':
    print("please run this script from rpg2 directory")
    print("current directory: ", (curr_folder))
    sys.exit()

#make a build directory for CMake
if not os.path.exists('build'):
    print("please run this script after building rpg2. Run ./build.py from the rpg2 directory")
    sys.exit()

else:
    os.chdir('build')
    res = subprocess.run(['ctest'], check=True)


print("done")
