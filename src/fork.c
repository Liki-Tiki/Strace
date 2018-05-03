/*
** EPITECH PROJECT, 2018
** Project
** File description:
** fork.c
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

long long unsigned int	return_reg(struct user_regs_struct regs, int nbr)
{
	long long unsigned int	reg;
	struct function_s *tmp = malloc(sizeof(*tmp));
	tmp->count = nbr;

	if (tmp->count == 1)
		reg = regs.rdi;
	else if (tmp->count == 2)
		reg = regs.rsi;
	else if (tmp->count == 3)
		reg = regs.rdx;
	else if (tmp->count == 4)
		reg = regs.rcx;
	else if (tmp->count == 5)
		reg = regs.r8;
	else
		reg = regs.r9;
	if (tmp->count >= 2)
		printf(", ");
	return (reg);
}

void	explicit_null(char *name, long long unsigned int reg)
{
	if (!strcmp(name, "brk") && reg == 0)
		printf("O");
	else if (reg == 0)
		printf("NULL");
	else
		printf("%p", (void *)reg);
}

int	return_type(char *carac)
{
	int	count;

	if (!strncmp(carac, "unsigned int", 12))
		count = 1;
	else if (!strncmp(carac, "size_t", 6))
		count = 1;
	else if (!strncmp(carac, "int *", 5))
		count = 2;
	else if (!strncmp(carac, "int", 3))
		count = 4;
	else if (!strncmp(carac, "char *", 6))
		count = 8;
	else if (!strncmp(carac, "char", 4))
		count = 16;
	else if (!strncmp(carac, "void *", 6))
		count = 32;
	else if (!strncmp(carac, "char **", 7))
		count = 8;
	return (count);
}
