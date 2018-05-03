/*
** EPITECH PROJECT, 2018
** ok
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

int	get_nbr_args(char *syscall)
{
	int i = 0;

	printf("(");
	while (syscall[i] != ' ')
		i++;
	syscall[i] = '\0';
	return (0);
}

int father_process2(char **line, struct user_regs_struct regs)
{
	int i = 0;

	(*line) = read_line(regs.rax);
	while ((*line)[i] && ((*line)[i] != ' ' ||
		(*line)[i] != '\n'))
		i++;
	(*line)[i - 1] = '\0';
	for (int z = 0; (*line)[z] && (*line)[z] != ' '; z++)
		printf("%c", (*line)[z]);
	return (0);
}

int	father_process(pid_t son)
{
	struct user_regs_struct regs;
	struct function_s *tmp = malloc(sizeof(*tmp));

	tmp->wait_return = 1;
	for (;1;ptrace(PTRACE_SINGLESTEP, son, NULL, NULL)) {
		wait4(son, &tmp->status, 0, NULL);
		if (WIFEXITED(tmp->status) || WIFSIGNALED(tmp->status))
			break;
		ptrace(PTRACE_GETREGS, son, 0, &regs);
		if (is_syscall(son, &regs) == 1 || tmp->wait_return == 0) {
			if (tmp->wait_return == 1){
				father_process2(&tmp->line, regs);
			} else {
				nbr_args(tmp->line, &regs, son);
				end_print(regs);
			}
			tmp->wait_return = !tmp->wait_return;
		}
	}
	return (0);
}

int start_fork(char **cmd, char flags)
{
	int get = father_process(0);
	pid_t son;

	son = fork();
	if (son == 0){
		ptrace(PTRACE_TRACEME, 0, 0, 0);
		kill(getpid(), SIGSTOP);
		execvp(cmd[get_start_cmd(flags)], &cmd[get_start_cmd(flags)]);
	} else {
		father_process(son);
	}
	printf("\n+++ exited with %d +++\n", get);
	return (0);
}

int attach_process(pid_t pid)
{
	ptrace(PTRACE_ATTACH, pid, NULL, NULL);
	return (father_process(pid));
}
