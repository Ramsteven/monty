#include "monty.h"

/**
 * main - monty bytecode interpeter
 *
 * @argc: Number of arguments passed to main
 * @argv: Array with the arguments passed to main
 *
 * Return: 0 on success. EXIT_FAILURE otherwise
 */

int main(int argc, char *argv[])
{
	void (*f_check)(stack_t **stack, unsigned int line_number);
	stack_t *STACK = NULL;
	unsigned int line_counter = 0;

	data.fp = get_file(argv[1], argc);
	data.line = allocate_line(data.fp);
	data.tokens = NULL;

	while (fgets(data.line, LINE_SIZE, data.fp) && ++line_counter)
	{
		*(data.line + strlen(data.line) - 1) = '\0';
		data.tokens = tokenizer(data.line, 32);
		if (data.tokens == NULL)
			continue;
		f_check = get_op(*(data.tokens));
		if (f_check)
			f_check(&STACK, line_counter);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_counter,
			 *(data.tokens));
			free_leaks(&STACK);
			exit(EXIT_FAILURE);
		}
		free_dp(data.tokens);
		data.tokens = NULL;
	}
	free_leaks(&STACK);
	return (0);
}

/**
 * get_op - Checks if a string is a valid function to execute
 *
 * @s: String to check if is a valid function
 *
 * Return: Function pointer if string matches any function. NULL otherwise
 */

void (*get_op(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push_function},
		{"pall", pall_function},
		{"pint", pint_function},
		{"swap", swap_function},
		{"pop", pop_function},
		{"add", add_function},
		{"nop", nop_function},
		{"mul", mul_function},
		{"div", div_function},
		{"mod", mod_function},
		{"sub", sub_function},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].opcode)
	{
		if (!(strcmp(s, ops[i].opcode)))
			return (ops[i].f);
		i++;
	}

	return (NULL);
}

/**
 * get_file - Gets a file pointer to given file (as absolute path)
 *
 * @file_name: Absolute pathe to the file with monty byte code
 * @args: Number of arguments passed to main.
 *
 * Return: The pointer to file wheter file exists. Exit otherwise.
 */

FILE *get_file(char *file_name, int args)
{
	FILE *fp = NULL;

	if (args == 2)
	{
		fp = fopen(file_name, "r");
		if (fp == NULL)
		{
			fprintf(stderr, "Error: Can't open file %s\n",
				 file_name);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (fp);
}

/**
 * allocate_line - Allocates memory for a line readed from file
 *
 * @fp: File pointer, to monty bytecode file.
 *
 * Return: The pointer to allocated memory. Exit otherwise.
 */

char *allocate_line(FILE *fp)
{
	char *line = NULL;

	line = malloc(sizeof(char) * LINE_SIZE);
	if (!line)
	{
		fclose(fp);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	return (line);
}
