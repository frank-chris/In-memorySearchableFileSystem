mountpoint = mountpoint
includepath = -I./include/
srcprefix = ./src/
# files = $(srcprefix)imsfs_main.c $(srcprefix)tree.c $(srcprefix)imsfs_getattr.c
files = $(wildcard ./src_*/*.c)
# files_fuse = $(wildcard ./src_fuse/*.c)
# files_tree = $(wildcard ./src_tree/*.c)
compileflags = -D_FILE_OFFSET_BITS=64
opflag = -o imsfs
neededflag = `pkg-config fuse --libs` -DFUSE_USE_VERSION=26 -lm

all: make_dir run
	./imsfs -f $(mountpoint)

make_dir:
	mkdir $(mountpoint)

run:
	# gcc -Wall $(includepath) $(files_fuse) $(files_tree) $(compileflags) $(opflag) $(neededflag)
	gcc -Wall $(includepath) $(files) $(compileflags) $(opflag) $(neededflag)

clean:
	fusermount -u $(mountpoint)
	rm -r $(mountpoint)
	rm imsfs

cleanup: 
	rm -r $(mountpoint)
	rm imsfs
	rm -rvf comparison/disk comparison/*.csv comparison/imsfs_bin comparison/ondisk_bin

compare_imsfs:
	./comparison/imsfs.sh 
	gcc -o comparison/imsfs_bin comparison/imsfs.c
	./comparison/imsfs_bin

compare_ondisk:
	mkdir comparison/disk
	./comparison/ondisk.sh
	gcc -o comparison/ondisk_bin comparison/ondisk.c
	./comparison/ondisk_bin


