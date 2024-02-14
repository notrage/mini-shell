#include "execution.h"
#include "error.h"

void quit() {
    exit(0);
}

void internal_cmd(char **cmd) {
    if (!strcmp(cmd[0], "quit"))
        quit();
    else if (!strcmp(cmd[0], "exit"))
        quit();
    else if (!strcmp(cmd[0], "cd"))
    {
        //chdir(cmd[1]);
    }
    return;
}

void external_cmd(char **cmd, char *in, char *out) {
    
    pid_t pid;

    switch (pid = fork())
    {
    case -1: // error
        fork_error(cmd[0]);
        break;
    case 0: // child

        if (in)
        {
            int fd = open(in, O_RDONLY);
            if (fd < 0) open_error(in);
            dup2(fd, 0);
            close(fd);
        }
        if (out)
        {
            int fd = open(out, O_WRONLY | O_CREAT, 0644);
            if (fd < 0) open_error(out);
            dup2(fd, 1);
            close(fd);
        }
        execvp(cmd[0], cmd);
        // if execvp returns, it must have failed
        exec_error(cmd[0]);
        break;
    default: // parent
        wait(NULL);
        break;
    }   
    return;
}