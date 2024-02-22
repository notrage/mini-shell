#include "internal_cmd.h"

void quit() {
    fprintf(stdout, "Goodbye, have a nice day!\n");
    kill(SIGTERM);
    return;
}

// void chdir(char * path) {
    
//     return;
// }
