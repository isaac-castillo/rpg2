#!/usr/bin/python3


import subprocess
import os
import shutil
import sys
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('--cmake', action='store_true')
args = parser.parse_args()

curr_folder = os.path.basename(os.getcwd())
if curr_folder != 'rpg2':
    print("please run this script from rpg2 directory")
    print("current directory: ", (curr_folder))
    sys.exit()

#make a build directory for CMake
if not args.cmake and os.path.exists('build'):
    os.chdir('build')

else:
    if os.path.exists('build'):
        shutil.rmtree('build')
    os.mkdir('build')
    os.chdir('build')
    res = subprocess.run(['cmake', '..'], check=True)
res = subprocess.run(['cmake', '--build', '.'], check=True)




tests = ['ui', 'world']

if res.returncode == 0:
    if os.path.exists('../rpg2'):
        os.remove('../rpg2')
    shutil.move('src/rpg2', '..')


    # for test in tests:
    #     print(test)
    #     if os.path.exists('../{}_tests'.format(test)):
    #         os.remove('../{}_tests'.format(test))
    #     shutil.move('tests/{}/{}_tests'.format(test, test), '..')


print("done")
