#!/usr/bin/python3


import subprocess
import os
import shutil
import sys


curr_folder = os.path.basename(os.getcwd())
if curr_folder != 'rpg2':
    print("please run this script from rpg2 directory")
    print("current directory: ", (curr_folder))
    sys.exit()

#make a build directory for CMake
if os.path.exists('build'):
    shutil.rmtree('build')
os.mkdir('build')
os.chdir('build')
res = subprocess.run(['cmake', '..'], check=True)
res = subprocess.run(['cmake', '--build', '.'], check=False)

if res.returncode == 0:
    os.remove('../rpg2')
    shutil.move('src/rpg2', '..')
