# IMSFS: In-Memory Searchable FileSystem


## Motivation behind the project
* Filesystems are very fundamental, but also very slow since they are stored on the disk. These file systems may suffer from high latencies on IO heavy tasks.
* An In-Memory File System can resolve this issue by storing the files and folders inside the RAM. As memory accesses are significantly faster than disk accesses, the In-Memory File System can substantially improve performance for IO intensive tasks.
* In-Memory File systems can serve as a fast non-persistent storage medium. They can be useful for caches, temporary data stores, etc.

## Our Work
* We have created a file system names IMSFS which completely resides in memory. 
* The file system also supports search based on metadata
* There is nothing like this on Github! We are the first to create such a filesystem using the FUSE library. 😀

## Using IMSFS

1. Clone the repository. 
2. Type `make` in the terminal. A directory named **mountpoint** will be created in the main folder. This is the root-directory/mountpoint for IMSFS.
3. Open another terminal. Navigate into the created directory called **mountpoint**. All operations done inside this directory will be stored inside the RAM itself and not get written onto the disk. Beware, all files and folders created here will be temporary, you will lose them once you clean close the filesystem.
4. Once inside the filesystem, you can perform all of the basic Bash commands such as `ls`, `mkdir`, `cp`, `stat`, `cat`, `touch`, `mv` and many more.
5. To exit the file system use the `Ctrl+C` combination on the terminal running the program. Then type the command `make clean` to unmount the file system, remove the mountpoint directory, and remove the executables.

## Searchability
A special feature of this file system is that it supports both prefix and substring searchability. This functionality is exposed as a filesystem API
1. Prefix Matching - <br>
Type in the command `ls ./FIND/PREFIX/<prefixname>` to search all files in the entire file system that have the prefix as **prefixname**. For example, if you want to search all the files that have the prefix **_abc_**, you have to type command `ls ./FIND/PREFIX/abc`. You will get results such as **_abc.txt_**, **_abcd.py_**, etc
2. Substring Matching - <br>
 Type in the command `ls ./FIND/SUBSTR/<substringname>` to search all files in the entire file system that have the prefix as **substringname**. For example, if you want to search all the files that have the substring **_bcd_**, you have to type command `ls ./FIND/SUBSTR/bcd`. You will get results such as **_bcd.mp4_**, **_abcd.py_**, etc.
3. You may type a combination of the two to get more specific results, such as `ls ./FIND/PREFIX/<prefixname>/SUBSTR/<substringname>` will search the file system for names beginning with **prefixname** AND containing the **substringname**.

## Note
* All the directories in this repository have separate READMES which provide information about the 
* The source files are well commented as well
* Link to presentation: [Presentation](https://docs.google.com/presentation/d/1e-mg9RtKudUxI7enxK1pMCTCyFjADkYlf7XBl0A94Uk/edit?usp=sharing) 











