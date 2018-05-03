/*
** EPITECH PROJECT, 2018
** fork
** File description:
** fork
*/

#include <unistd.h>
#include <wait.h>
#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/reg.h>
#include <stdlib.h>
#include <string.h>
#include <sys/user.h>
#include "strace.h"
#include "parser.h"

int     is_syscall(pid_t child, struct user_regs_struct *regs)
{
	unsigned char   syscall[2];
	long val = ptrace(PTRACE_PEEKTEXT, child, regs->rip, NULL);
	unsigned char *p = (unsigned char *)&val;

	syscall[0] = 0x0f;
	syscall[1] = 0x05;
	if ((p[0] == syscall[0] && p[1] == syscall[1])){
		return (1);
	}
	return (0);
}

int print_fin(void)
{
	printf(")");
	return (0);
}

void    vendnorme(char **line, char **name)
{
	(*line) = split_str(NULL , ' ');
	(*name) = split_str(NULL, ' ');
}

void     nbr_args(char *syscall,
	struct user_regs_struct *regs,
	pid_t child)
{
	struct function_s *tmp = malloc(sizeof(*tmp));
	get_nbr_args(syscall);
	for (int i = 0; i < 10133; i++){
		tmp->line = split_str(read_prot(i) , ' ');
		if (!strcmp(tmp->line, "extern")){
			free(tmp->line);
			vendnorme(&tmp->line, &tmp->name);
			if (!strcmp(tmp->line, "unsigned"))
				tmp->name = split_str(NULL, ' ');
			if (!strcmp(tmp->name, syscall)
	|| (tmp->name[0] == '*' && !strcmp(tmp->name + 1, syscall))){
				tmp->line = split_str(NULL, '\n');
				analyse_arg(tmp->line, regs, child, tmp->name);
				break;
			}
			free(tmp->name);
		}
		free(tmp->line);
	}
	print_fin();
}
