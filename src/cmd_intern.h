#include <stdio.h>
#include <stdlib.h>

/**
 * @fn exec_cmd
 * @param cmd command in a string array
 * @brief execute an internal command of the shell and return 0 if everything goes along, 1 either.
 * @return int
*/
int exec_cmd_intern(char **cmd);

void quit();