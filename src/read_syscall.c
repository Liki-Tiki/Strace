/*
** EPITECH PROJECT, 2018
** d
** File description:
** s
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_prot(int id)
{
	FILE* file = fopen("prot_syscall", "r");
	char line[256];
	int i = 0;

	while (fgets(line, sizeof(line), file)) {
		i++;
		if (i == id + 1)
			break;
	}
	fclose(file);
	if (i <= 10133)
		return (strdup(line));
	else {
		return (NULL);
	}
}

char *read_line(int id)
{
	FILE* file = fopen("syscall64", "r");
	char line[256];
	int i = 0;

	while (fgets(line, sizeof(line), file)) {
		i++;
		if (i == id + 1)
			break;
	}
	fclose(file);
	if (i <= 313)
		return (strdup(line));
	else {
		return (NULL);
	}
}
