#include "csapp.h"
#include "execution.h"
#include "interpreter.h"

void close_pipes(int **pipes, int nb_pipes, int rank) {
    if (rank == 0) {
        close(pipes[0][0]);
    } else if (rank == nb_pipes) {
        close(pipes[nb_pipes-1][1]);
    }
    else {
        for (int i = 0; i < nb_pipes; i++) {
            if (i == rank-1) {
                close(pipes[i][0]);
            } else if (i == rank) {
                if (i == 0) {
                    close(pipes[i][0]);
                } else {
                    close(pipes[i][1]);
                }
            } else {
                close(pipes[i][0]);
                close(pipes[i][1]);
            }
        }
    }
}

int is_internal_cmd(char **cmd) {
	char *exec = cmd[0];
	if (!strcmp(exec, "cd") || !strcmp(exec, "quit"))
		return 1;
	else
		return 0;
}

void exec_cmd_line(struct cmdline *cmd_line) {
    
    int nb_cmds;
    for (nb_cmds = 0; cmd_line->seq[nb_cmds] != 0; nb_cmds++) {
    }

    int **pipes = malloc(sizeof(int *) * (nb_cmds-1));

    for (int i = 0; i < nb_cmds-1; i++) {
        int fd[2];
        pipes[i] = pipe(fd);
    }



    for (int i = 0; i < nb_cmds; i++) {
        char **cmd = cmd_line->seq[i];
        if (is_internal_cmd(cmd))
            internal_cmd(cmd);
        else 
            external_cmd(cmd, cmd_line->in, cmd_line->out);
    }

    return;
}
