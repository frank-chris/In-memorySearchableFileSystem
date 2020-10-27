mountpoint = mountpoint
includepath = -I./include/
srcprefix = ./src/
files = $(srcprefix)imsfs_main.c $(srcprefix)tree.c $(srcprefix)imsfs_getattr.c
compileflags = -D_FILE_OFFSET_BITS=64
opflag = -o imsfs
neededflag = `pkg-config fuse --libs` -DFUSE_USE_VERSION=30 -lm

all: make_dir run
	./imsfs -f $(mountpoint)

make_dir:
	mkdir $(mountpoint)

run:
	gcc -Wall $(includepath) $(files) $(compileflags) $(opflag) $(neededflag)

clean:
	fusermount -u $(mountpoint)
	rm -r $(mountpoint)

