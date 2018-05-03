/*
** EPITECH PROJECT, 2018
** PSU_2017_strace
** File description:
** main.c
*/

#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "strace.h"

char get_args(int ac, char **av)
{
	char options = 0;
	args_t  args[] = {
		{"-p", P_ARG},
		{"-s", S_ARG},
		{"-o", O_ARG},
		{"\0", NULL_ARG}
	};

	for (int i = 1; i < ac; i++){
		for (int j = 0; j < 4; j++){
			if (strcmp(args[j].arg, av[i]) == 0){
				options |= args[j].mask;
				break;
			}
			if (j == 3)
				return (options);
		}
	}
	return (options);
}


int get_p_pid(char **av)
{
	int pid;

	for (int i = 1; av[i]; i++){
		if (strcmp(av[i], "-p") == 0){
			if (av[i + 1]){
				pid = atoi(av[i + 1]);
				if (pid > 0)
					return (pid);
				break;
			} else {
				printf("T'as oublié le pid\n");
				return (-1);
			}

		}
	}
	return (-1);
}

int main(int ac, char **av)
{
	char flags = get_args(ac, av);
	int pid_attach;

	if (ac < 2){
		printf("Usage :\n");
		return (-1);
	}
	if (flags & P_ARG){
		pid_attach = get_p_pid(av);
		printf("-p Found : %d\n", pid_attach);
		if (pid_attach > 0){
			return (attach_process(pid_attach));
		} else {
			printf("Wrong pid\n");
			return (84);
		}
	}
	return (start_fork(&av[0], flags));
}

