/*
** EPITECH PROJECT, 2018
** k
** File description:
** s
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "strace.h"

int get_start_cmd(char flags)
{
	int start = 1;
	char args[] = {
		S_ARG,
		P_ARG,
		O_ARG
	};

	for (int i = 0; i < 3; i++){
		if (flags & args[i]){
			start++;
		}
	}
	return (start);
}

int *split_tokens(char *str, char sep)
{
	int *places;
	int j = 1;

	if (!str)
		return (NULL);
	places = malloc((2 + count_char_in_str(str, sep)) * sizeof(int));
	places[0] = 0;
	for (int i = 0; str[i]; i++){
		if (str[i] == sep){
			str[i] = '\0';
			places[j] = i + 1;
			j++;
		}
	}
	places[j] = -1;
	return (places);
}

char *get_path(char **env)
{
	char *path = NULL;
	int i = 0;

	while (env[i]){
		if (strncmp(env[i], "PATH=", 5))
		{
			path = strdup(&env[i][5]);
			break;
		}
		i++;
	}
	return (path);
}

char *my_strcatcat(char *str1, char *str2, char *str3)
{
	char *final;

	final = malloc((strlen(str1)
			+ strlen(str2) + strlen(str3) + 2) * sizeof(char));
	final[0] = '\0';
	strcat(final, str1);
	strcat(final, str2);
	strcat(final, str3);
	return (final);
}

int count_char_in_str(char *str, char to_search)
{
	int amount = 0;

	if (!str || !to_search)
		return (-1);
	for (int i = 0; str[i]; i++) {
		if (str[i] == to_search){
			amount++;
		}
	}
	return (amount);
}
