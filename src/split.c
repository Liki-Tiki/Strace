/*
** EPITECH PROJECT, 2018
** ok
** File description:
** k
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *split_str(char *str, char sep)
{
	static char *splitted = NULL;
	static int i = 0;
	int save;

	if (str != NULL){
		splitted = strdup(str);
		save = 0;
		i = 0;
	}
	else {
		i = i + 1;
		save = i;
	}
	while (splitted[i] && splitted[i] != sep)
		i++;
	splitted[i] = '\0';
	return (strdup(&splitted[save]));
}
