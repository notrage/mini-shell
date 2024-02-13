#include "cmd_intern.h"
#include "string.h"

int exec_cmd_intern(char **cmd) {
    if (!strcmp(cmd[0], "quit"))
    {
        quit();
    } else if (!strcmp(cmd[0], "cd"))
    {
        //chdir(cmd[1]);
    }
    
    return 0;
}

void quit() {
    exit(0);
}

