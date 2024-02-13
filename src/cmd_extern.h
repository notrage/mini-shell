
/**
 * @fn quit
 * @param void
 * @brief end the execution of the shell
 * @return void
*/

void fork_error();

/**
 * @fn exec_cmd_extern
 * @param cmd command in a string array
 * @param in input file, can be null
 * @param out output file, can be null
 * @brief execute an external command to the shell and return 0 if everything goes along, 1 either.
*/
int exec_cmd_extern(char **cmd, char * in, char * out);