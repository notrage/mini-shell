#include "cmd_extern.h"
#include "csapp.h"

void fork_error() {
    printf("fork error\n");
    exit(1);
}

int exec_cmd_extern(char **cmd, char *in, char *out) {
    pid_t pid;
    switch (pid = fork())
    {
    case -1:
        fork_error();
        break;
    case 0:
        if (in)
        {
            int fd = open(in, O_RDONLY);
            dup2(fd, 0);
            close(fd);
        }
        if (out)
        {
            int fd = open(out, O_WRONLY | O_CREAT, 0644);
            dup2(fd, 1);
            close(fd);
        }
        execvp(cmd[0], cmd);
        break;
    default:
        waitpid(pid, NULL, 0);
        break;
    }   
    return 0;
}