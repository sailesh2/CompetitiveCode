import os
from os import walk
from shutil import copyfile

mypath='C:\\Users\\srt\\Desktop'
codefiles = []

targetFilesPrefix=['cf','lc','COOK','he','LT','tc','csa']

for (dirpath, dirnames, filenames) in walk(mypath):
    for filename in filenames:
        if filename[0:2] in targetFilesPrefix or filename[0:4] in targetFilesPrefix or filename[0:3] in targetFilesPrefix:
            codefiles.append(filename)
    break
dstDirDropbox='C:\\Users\\srt\\Dropbox\\Code\\'

dstDirNewFolder=mypath+'\\New folder\\'

for codefile in codefiles:
    src=codefile
    dst=dstDirDropbox+src
    copyfile(src, dst)
    dst=dstDirNewFolder+src
    copyfile(src, dst)
    os.remove(src)
