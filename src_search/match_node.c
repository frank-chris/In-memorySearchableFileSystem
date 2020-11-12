#include <fuse.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include "tree.h"
#include "search_use_query.h"

int match_node(imsfs_tree_node *node, imsfs_searchobj *searcher){
    
    int match = 1; //indicated whether current node is a successfull match, need to check all constraints

    //prefix matching
    if (searcher->prefix != NULL){
        
        if (strlen(node->name) < strlen(searcher->prefix)) return 0;
        
        for (int i=0; i<strlen(searcher->prefix); i++){
            if (node->name[i] != searcher->prefix[i]) return 0;
        }
    }

    return match;
}

