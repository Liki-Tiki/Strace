/*
** EPITECH PROJECT, 2018
** k
** File description:
** k
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

void    print_string(long long unsigned int reg, pid_t child)
{
	int   i;
	char  count;

	i = 0;
	printf("\"");
	while ((count = ptrace(PTRACE_PEEKTEXT, child, reg + i, NULL)) != 0)
	{
		if (count == '\n')
			printf("\\n");
		else
			printf("%c", count);
		i = i + 1;
	}
	printf("\"");
}

void    print_arguments(long long unsigned int reg, int type,
			pid_t son, char *proto)
{
	if (!strcmp(proto, "execve"))
		printf("0x%llx", reg);
	else {
		if (type == 1)
			printf("%u", (unsigned int )reg);
		if (type == 2)
			printf("%p", (void *)reg);
		if (type == 4)
			printf("%d", (int)reg);
		if (type == 8)
			print_string(reg, son);
		if (type == 16)
			printf("%c", (char)reg);
		if ((!strcmp(proto, "write") && (type == 32 || type == 0)))
			print_string(reg, son);
		else if (type == 32 || type == 0)
			explicit_null(proto, reg);
	}
}

int     analyse_arg(char *arg,
	struct user_regs_struct *regs,
		pid_t child,
		char *name)
{
	int     i;
	int     nbr_arg = 1;
	int     type;

	for (i = 0; arg[i] && arg[i] == ' '; i++);
	if (strlen(&arg[i]) < 2 || !strncmp(&arg[i], "()", 2) ||
	!strncmp(&arg[i], "(void)", 6))
		return (0);
	else {
		for (; arg[i]; i++) {
			type = return_type(&arg[i]);
			if (arg[i] == ',') {
				print_arguments(return_reg(*regs, nbr_arg++),
						type, child, name);
				type = 0;
			}
		}
		print_arguments(return_reg(*regs, nbr_arg), type, child, name);
		return (nbr_arg);
	}
}

void    end_print(struct user_regs_struct regs)
{
	if (regs.rax == (long long unsigned int)-2)
		printf("\t= -1\n");
	else
		printf("\t= %lld\n", regs.rax);
}
