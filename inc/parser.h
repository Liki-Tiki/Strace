/*
** EPITECH PROJECT, 2018
** k
** File description:
** k
*/

#ifndef PARSER_PARSER_H
#define PARSER_PARSER_H

#define SET_BIT(a,b) ((a) |= (1ULL<<(b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) ((a) & (1ULL<<(b)))

typedef unsigned char mask_t;

enum specials_e
{
	PTR_1,
	PTR_2,
	PTR_3,
	UNSIGNED
};

enum types_e
{
	VOID,
	INT,
	DOUBLE,
	FLOAT,
	CHAR,
	LONG
};

typedef struct function_s
{
	char *f_name;
	mask_t f_return;
	int p_amount;
	char **p_name;
	char *name;
	char *line;
	int wait_return;
	int status;
	int count;
	int f_extern;
	mask_t *p_type;
	mask_t *p_type_s;
} function_t;

int parameters_amount(char *prototype);
int function_is_extern(char *);
char *get_type(mask_t mask);
char *parse_function_name(char *, function_t func);
int return_type(char *);

#endif //PARSER_PARSER_H
