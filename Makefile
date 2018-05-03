##
## EPITECH PROJECT, 2018
## strace
## File description:
## Project made by kevin.barroso@epitech.eu
##

IFLAG           =       -I inc/
CFLAGS          +=      -W -Wall -Wextra $(IFLAG) -g
RM              =       rm -rf
CC              =       gcc

strace		=	strace
strace_OBJS		=	$(strace_SRCS:.c=.o)

strace_SRCS		=	src/main.c\
					src/exec.c\
					src/parsing.c\
					src/fork.c\
					src/fork2.c\
					src/fork3.c\
					src/fork4.c\
					src/read_syscall.c\
					src/split.c \

test_bin_name	= $(strace)_tests

tests_SRCS	=	tests/main.c\
				src/read_syscall.c

tests_OBJS		=	$(tests_SRCS:.c=.o)

all	:	$(strace)

$(strace)	:	$(strace_OBJS)
		$(CC) -o $(strace) $(strace_OBJS)

clean	:
		$(RM) $(strace_OBJS)
		$(RM) $(tests_OBJS)
		@$(RM) *.c~
		@$(RM) *#

fclean	:	clean
		$(RM) $(strace)
		$(RM) $(test_bin_name)

re	:	fclean all

tests_run	: $(tests_OBJS)
		$(CC) -o $(test_bin_name) $(tests_OBJS) --coverage 	-lcriterion
		@ echo "Running tests"
		@ ./$(test_bin_name)

.PHONY	:	all clean fclean re tests_run

.SUFFIXES	:	.c .o
