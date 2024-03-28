#ifndef INTERNAL_CMD_H
#define INTERNAL_CMD_H

#include "csapp.h"

/**
 * @brief quit the current shell
 * @param void
 * @return void
*/
void quit();

/**
 * @brief changes the current directory
 * @param path path to the new directory
 * @return void
*/
void cd(char *path);

#endif // INTERNAL_CMD_H