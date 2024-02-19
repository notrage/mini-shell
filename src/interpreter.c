#include "csapp.h"
#include "error.h"
#include "execution.h"
#include "interpreter.h"

void exec_cmd_line(struct cmdline *cmd_line) {
    
    if (!cmd_line) quit();

    int nb_cmds;
    for (nb_cmds = 0; cmd_line->seq[nb_cmds] != 0; nb_cmds++) {
    }
    

    int **pipes = (int **) malloc(sizeof(int *) * nb_cmds -1);

    for (int pipe_index = 0; pipe_index < nb_cmds-1; pipe_index++) {
        pipes[pipe_index] = (int *) malloc(sizeof(int) * 2);
        pipe(pipes[pipe_index]);
    }
    
    for (int process_index = 0; process_index < nb_cmds; process_index++) {

        char **cmd = cmd_line->seq[process_index];
        if (!strcmp(cmd[0], "quit") || !strcmp(cmd[0], "exit")) 
        {
            quit();
        }
        else 
        {
            pid_t pid;

            if (!(pid = Fork())) // child
            {
                if (cmd_line->in) {
                    int fd = open(cmd_line->in, O_RDONLY);
                    if (fd < 0) open_error(cmd_line->in);
                    dup2(fd, 0);
                    close(fd);
                }
                if (cmd_line->out) {
                    int fd = open(cmd_line->out, O_WRONLY | O_CREAT, 0644);
                    if (fd < 0) open_error(cmd_line->out);
                    dup2(fd, 1);
                    close(fd);
                }

                pipes_handling(pipes, nb_cmds-1, process_index);
                
                execvp(cmd[0], cmd);
                // if execvp returns, it must have failed
                exec_error(cmd[0]);
            } 
            else // parent 
            { 
                // nothing to do here
            }
        }
    }
    while(wait(NULL) == 0);
    return;
}

void pipes_handling(int **pipes, int nb_pipes, int rank) {

    for (int i = 0; i < nb_pipes; i++) {

        if (i == rank-1) {
            dup2(pipes[i][0],0);
            close(pipes[i][1]);
        } else if (i == rank) {
            close(pipes[i][0]);
            dup2(pipes[i][1],1);
        } else {
            close(pipes[i][0]);
            close(pipes[i][1]);
        }
    }
    return;
}