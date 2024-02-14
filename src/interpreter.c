#include "csapp.h"
#include "execution.h"
#include "interpreter.h"

int is_internal_cmd(char **cmd) {
	char *exec = cmd[0];
	if (!strcmp(exec, "cd") || !strcmp(exec, "quit"))
		return 1;
	else
		return 0;
}

void exec_cmd_line(struct cmdline *cmd_line) {

    for (int i = 0; cmd_line->seq[i] != 0; i++) {
        char **cmd = cmd_line->seq[i];
        if (is_internal_cmd(cmd)) 
            internal_cmd(cmd);
        else 
            external_cmd(cmd, cmd_line->in, cmd_line->out);
    }
    return;
}
