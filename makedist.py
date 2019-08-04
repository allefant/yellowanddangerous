#!/usr/bin/env python3
import os
import shutil
import glob
import subprocess
import re

def get_version():
    for row in open("src/config.py"):
        if row.startswith("global char const *VERSION"):
            return row.split("=")[1].strip(' "\n')

version = get_version()
dirname = "Yellow Danger " + version
folder = "dist/" + dirname

def make_zip():
    os.makedirs(folder, exist_ok = True)
    try: shutil.copytree("data", folder + "/data")
    except FileExistsError: pass
    shutil.copy2("yellowanddangerous.exe", folder)
    for dll in glob.glob("/home/elias/prog/allegro/git/build_mingw/examples/*.dll"):
        shutil.copy(dll, folder)
    shutil.copy("/home/elias/prog/land/land/bwin/libland.dll", folder)
    try: os.remove(folder + ".zip")
    except FileNotFoundError: pass
    os.chdir("dist")
    subprocess.run(["zip", "-r", dirname + ".zip", dirname])
    os.chdir("..")

def upload():
    subprocess.run(["scp", folder + ".zip", "allefant.com:/var/www/yellowdanger.com/"])

def update_website():
    subprocess.run(["scp", "allefant.com:/var/www/yellowdanger.com/index.html", "."])
    html = open("index.html").read()
    html = re.sub(r"Yellow Danger .*?\.zip", dirname + ".zip", html)
    open("index.html", "w").write(html)
    subprocess.run(["scp", "index.html", "allefant.com:/var/www/yellowdanger.com/"])

make_zip()
upload()
update_website()
