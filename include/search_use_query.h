#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#include <fuse.h>
#include "tree.h"


/**
 * ls ./FIND/PREFIX/abc/SUBSTR/txt
 * 
*/


/** Checks if the path contains FIND/ at the beginning indicating a search query
 * 0 if not a search query
 * else 1
*/

#define MAX_TAG_LENGTH 10
#define NUM_SUPPORTED_TAGS 2


typedef struct imsfs_searchobj{
    char* prefix;
    char *substr;
} imsfs_searchobj;

char* SEARCH_KEYWORD;
char* USE_KEYWORD;

char** supported_tags;

imsfs_tree_node** search_buffer;
int num_search_buffer_entries; //actually end of buffer, there may be null values in between

//Functions

//src search
int check_tag(char* tag);
imsfs_searchobj* create_search_object();
void free_search_object(imsfs_searchobj* searcher);
// char* get_query(const char *request);
imsfs_searchobj* get_search_object(const char *path);
char** get_tag_ptr(imsfs_searchobj* searcher, const char* tag);
void initialise_search();
int is_search_query(const char *path);
int match_node(imsfs_tree_node *node, imsfs_searchobj *searcher, int m, int lps[]);
void tree_search_fill(fuse_fill_dir_t filler, void *buffer, imsfs_searchobj* searcher);

//src use
void add_to_search_buffer(imsfs_tree_node* node);
void free_search_buffer();
char* get_file_name_use(const char* path);
imsfs_tree_node* get_node_from_search_buffer(char* file);
int is_use_query(const char *path);
void remove_node_from_search_buffer(imsfs_tree_node* file_node);
