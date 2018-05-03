/*
** EPITECH PROJECT, 2018
** ok
** File description:
** k
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "strace.h"

static int try_access(char *path)
{
	return (access(path, X_OK));
}

char *find_path(char **cmd, char **env, int start)
{
	char *path = get_path(env);
	int *tokens;
	char *path_exec;
	int i;

	tokens = split_tokens(path, ':');
	for (i = 0; tokens[i] != -1; i++) {
		path_exec = my_strcatcat(&path[tokens[i]], "/", cmd[start]);
		if (try_access(path_exec) == 0)
			return (path_exec);
		free(path_exec);
	}
	return (NULL);
}

char *execute(char **cmd, char **env, char flags)
{
	int cmd_start = get_start_cmd(flags);
	char *final = NULL;

	if (!cmd[cmd_start])
		return (NULL);
	if (cmd[cmd_start][0] != '/') {
		final = find_path(cmd, env, cmd_start);
		return (final);
	} else {
		if (try_access(cmd[cmd_start]) == 0)
			return (cmd[cmd_start]);
		else
			printf("Wrong cmd\n");
	}
	return (0);
}
