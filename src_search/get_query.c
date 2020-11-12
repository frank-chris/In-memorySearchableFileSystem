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


//Assuming only search queries passed 
char* get_query(const char *request){
    
    int request_len = strlen(request);
    int prefix_len = strlen("/FIND");

    int curptr = 0;
    for (int i=0; i<prefix_len; i++) curptr++;

    curptr++;
    int nxtptr = curptr;

    while(nxtptr<=request_len && nxtptr!='/'){
        nxtptr++;
    }

    int query_len = nxtptr-curptr;

    if (query_len<=0) return NULL;

    char* query = (char*)malloc(sizeof(char)*query_len+1);
    for (int i=curptr; i<nxtptr; i++){
        query[i] = request[i];
    }
    query[query_len]='\0';

    return NULL;
}

