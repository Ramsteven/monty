#include "monty.h"

/**
 *
 */

int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	char *line = NULL, **tokens = NULL;
	int i = 0;
	void (*f_check)(stack_t **stack, unsigned int line_number);
	stack_t *STACK = NULL;

	fp = get_file(argv[1], argc);
	line = allocate_line(fp);

	while (fgets(line, LINE_SIZE, fp) && ++i)
	{
		*(line + strlen(line) - 1) = '\0';
		tokens = _strtok(line, 32);
		if (tokens == NULL)
			continue;
		if (!strcmp(*(tokens), "push"))
			if(*(tokens + 1) == NULL || (atoi(*(tokens + 1)) == 0 && *(*(tokens + 1)) != '0'))
			{
				fclose(fp);
				free(line);
				free_list(STACK);
				free_dp(tokens);
				fprintf(stderr, "L%d: usage: push integer\n", i);
				exit(EXIT_FAILURE);
			}
		f_check = get_op(*tokens);
		if (f_check)
			get_op(*tokens)(&STACK, (*(tokens + 1))? atoi(*(tokens + 1)): 0);
		else
		{
			fclose(fp);
			free(line);
			free_list(STACK);
			fprintf(stderr, "L%d: unknown instruction %s\n", i, *(tokens));
			free_dp(tokens);
			exit(EXIT_FAILURE);
		}
 		free_dp(tokens);
	}
	free_list(STACK);
	free(line);
	fclose(fp);
	return (0);
}
