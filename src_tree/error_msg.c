#include "tree.h"


void error_msg(const char * msg, const char * reason){
    fputs(msg, stderr);
    fputs(": ", stderr);
    fputs(reason, stderr);
    fputs("\n", stderr);
    // exit(1);
}
