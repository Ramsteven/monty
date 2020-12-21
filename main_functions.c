#include "monty.h"

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

void free_leaks(stack_t **stack){
	fclose(data.fp);
	free(data.line);
	free_list(*stack);
	free_dp(data.tokens);
}


