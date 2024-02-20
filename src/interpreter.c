#include "csapp.h"
#include "error.h"
#include "interpreter.h"

void exec_cmd_line(struct cmdline *cmd_line) {

    int nb_cmds;
    char **cmd;
    int **pipes;
    int fd;
    pid_t pid;
    
    // if user type ^D (EOF) in the shell, quit the executions
    if (!cmd_line) return;

    if (cmd_line->err) {
        cmd_line_error(cmd_line->err);
        return;
    }

    // counting the number of commandes in the command line
    for (nb_cmds = 0; cmd_line->seq[nb_cmds] != 0; nb_cmds++) {
    }

    if (cmd_line->mode == 1) {
        fprintf(stderr, "Processus yfuaca en background\n");
        fprintf(stderr, "nb cmds: %d\n", nb_cmds);
    }
    
    // allocating memory for nb_cmds-1 pipes
    pipes = (int **) malloc(sizeof(int *) * nb_cmds -1);

    // creating the pipes
    for (int pipe_index = 0; pipe_index < nb_cmds-1; pipe_index++) {
        pipes[pipe_index] = (int *) malloc(sizeof(int) * 2);
        pipe(pipes[pipe_index]);
    }

    // for each command in the command line
    for (int process_index = 0; process_index < nb_cmds; process_index++) {

        // getting the command
        cmd = cmd_line->seq[process_index];

        // if the command is "quit" or "exit", we quit the program
        if (!strcmp(cmd[0], "quit") || !strcmp(cmd[0], "exit")) 
            exit(0);
        // don't use else there because we want to quit the program if the command is "quit" or "exit"

        // forking
        if (!(pid = Fork())) // child
        {
            // if the command has an input file, we open it
            if (cmd_line->in && process_index == 0) {
                fd = open(cmd_line->in, O_RDONLY);
                if (fd < 0) open_error(cmd_line->in);
                dup2(fd, 0);
                close(fd);
            }

            // if the command has an output file, we open it
            if (cmd_line->out && process_index == nb_cmds-1) {
                fd = open(cmd_line->out, O_WRONLY | O_CREAT, 0644);
                if (fd < 0) open_error(cmd_line->out);
                dup2(fd, 1);
                close(fd);
            }

            // opening and closing the right pipes depending on the command rank
            pipes_handling(pipes, nb_cmds-1, process_index);
            // executing the command
            execvp(cmd[0], cmd);
            // if execvp returns, it must have failed
            exec_error(cmd[0]);
        } 
    }
    // clossing all pipes in the parent process
    pipes_handling(pipes, nb_cmds-1, -1);
    // waiting for all the children to terminate
    while(wait(NULL) > 0);
    return;
}

void pipes_handling(int **pipes, int nb_pipes, int rank) {

    // for each pipe
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