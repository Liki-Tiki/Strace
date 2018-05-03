/*
** EPITECH PROJECT, 2018
** s
** File description:
** s
*/

#ifndef PSU_2017_STRACE_STRACE_H
#define PSU_2017_STRACE_STRACE_H

#include <sys/user.h>

#define S_ARG (0x1)
#define P_ARG (0x2)
#define O_ARG (0x4)
#define NULL_ARG (0x8)

#define DEBUG(name, value) printf("%s : [%s]\n", name, value);

typedef struct args_s
{
	char *arg;
	char mask;
} args_t;

int	return_type(char *ctype);
void	explicit_null(char *name, long long unsigned int  reg);
void print_arguments(long long unsigned int, int, pid_t son, char *);
void	print_string(long long unsigned int  reg, pid_t child);
long long unsigned int 	return_reg(struct user_regs_struct
		regs, int nbr);
char *read_prot(int id);
char *split_str(char *str, char sep);
int attach_process(pid_t pid);
char *read_line(int line_to_read);
int is_syscall(pid_t child, struct user_regs_struct *);
char *execute(char **cmd, char **env, char flags);
void print_string(long long unsigned int reg, pid_t child);
int analyse_arg(char *, struct user_regs_struct *, pid_t child, char *);
int father_process2(char **, struct user_regs_struct regs);
void end_print(struct user_regs_struct regs);
int get_start_cmd(char flags);
int print_fin(void);
void vendnorme(char **, char **);
void nbr_args(char *, struct user_regs_struct *regs, pid_t child);
int get_nbr_args(char *);
int *split_tokens(char *str, char sep);
char *get_path(char **env);
char *my_strcatcat(char *, char *, char *);
int count_char_in_str(char *str, char to_search);
int start_fork(char **cmd, char flags);

#endif //PSU_2017_STRACE_STRACE_H
