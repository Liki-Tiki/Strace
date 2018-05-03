/*
** EPITECH PROJECT, 2018
** k
** File description:
** d
*/

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include "parser.h"

char *parse_function_name(char *prototype, function_t func)
{
	int i;
	int j = 0;
	char *name;

	if (func.f_extern >= 0)
		i = func.f_extern + 6;
	else
		i = 0;
	while (prototype[i] && (prototype[i] == ' ' ||
		prototype[i] == '\t'))
		i++;
	i += strlen(get_type(func.f_return));
	name = malloc(strlen(&prototype[i]) * sizeof(char));
	while (prototype[i] != '(' && prototype[i] != ' '
	&& prototype[i] != '\t'){
		name[j++] = prototype[i++];
	}
	name[j] = '\0';
	return (name);
}

int function_is_extern(char *prototype)
{
	int i = 0;

	while (prototype[i] && prototype[i] == ' '
		&& prototype[i] == '\t')
		i++;
	if (strncmp(&prototype[i], "extern", 6) == 0){
		return (i);
	} else {
		return (-1);
	}
}
