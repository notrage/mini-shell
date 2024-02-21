#include "interpreter.h"

/**
 * @fn exec_cmd_line
 * @brief handles the execution of the command line received as parameter.
 * @param cmd_line structure cmdline containing a sequence of command, the mode with which they should be launch 
 *        (foreground or background) and potential intput / output redirections and/or error messages.
 * @return void
*/
void exec_cmd_line(struct cmdline *cmd_line) {

    int nb_cmds, fd;
    char **cmd;
    int **pipes;
    pid_t pid;

    // if user type ^D (EOF) in the shell, quit the executions
    if (!cmd_line) return;

    if (cmd_line->err) {
        cmd_line_error(cmd_line->err);
        return;
    }

    // counting the number of commandes in the command line
    for (nb_cmds = 0; cmd_line->seq[nb_cmds] != 0; nb_cmds++) {}
    
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
            Signal(SIGINT, SIG_DFL);
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
        } else {
            // the parent process adds the child process pids to the right list
            if (cmd_line->mode == FG)
                add_to_list(fg_list, pid);
            else
                add_to_list(bg_list, pid);
        }
    }

    // clossing all pipes in the parent process
    pipes_handling(pipes, nb_cmds-1, -1);
    // waiting for all foreground processes to finish
    while(!is_empty_list(fg_list));
    return;
}

/**
 * @fn pipes_handling
 * @brief handles the redirection and closing of pipes for one command.
 * @param pipes array of pipes
 * @param nb_pipes number of pipes
 * @param rank rank of the current command in the command line, to know which pipe to close and 
 *        what redirections to make.
 * @return void
*/
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