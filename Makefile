#!/bin/bash

username = raghavgoyal283
mountpoint = mountpoint
includepath = -I./include/
srcprefix = ./src/
files = $(srcprefix)imsfs_operations.c $(srcprefix)tree.c $(srcprefix)utils.c 
compileflags = -D_FILE_OFFSET_BITS=64
opflag = -o imsfs
neededflag = `pkg-config fuse --libs` -DFUSE_USE_VERSION=26
	

all: run 

run: setup make_directory compile
	./imsfs -f $(mountpoint)
	
# # check_mountpoint:
# 	if [[-d "$(mountpoint)"]]; then echo "Removing existing mountpoint" rm -r "$(mountpoint)"; fi; mkdir $(mountpoint)

make_directory:
	mkdir $(mountpoint)

compile: 
	gcc -Wall $(includepath) $(srcprefix)imsfs_main.c $(files) $(compileflags) $(opflag) $(neededflag)

setup:
	if [ -d $(mountpoint) ]; then rm -r $(mountpoint); fi

cleanup:
	fusermount -u $(mountpoint)
