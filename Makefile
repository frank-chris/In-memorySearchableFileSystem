CC=gcc #compiler name
TARGET=execute #executable's name
compileflags = -D_FILE_OFFSET_BITS=64
all:
	$(CC) initialise_imsfs.c add_dir_node.c add_file_node.c error_msg.c get_node.c name_from_path.c parent_from_path.c parent_node_from_path.c  print_node_data.c get_file_node.c get_dir_node.c dummy.c -o $(TARGET) $(compileflags)

#to compile together


clean:
	rm $(TARGET)

#to clean up the executable
