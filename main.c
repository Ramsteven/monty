#include "monty.h"

/**
 *
 */

int main(int argc, char *argv[])
{
	void (*f_check)(stack_t **stack, unsigned int line_number);
	stack_t *STACK = NULL;
	data.line_counter = 0;
	data.fp = get_file(argv[1], argc);
	data.line = allocate_line(data.fp);

	while (fgets(data.line, LINE_SIZE, data.fp) && ++data.line_counter)
	{
		*(data.line + strlen(data.line) - 1) = '\0';
		data.tokens = _strtok(data.line, 32);
		if (data.tokens == NULL)
			continue;
		if (!strcmp(*(data.tokens), "push"))
			if(*(data.tokens + 1) == NULL || (atoi(*(data.tokens + 1)) == 0 && *(*(data.tokens + 1)) != '0'))
			{
				fclose(data.fp);
				free(data.line);
				free_list(STACK);
				free_dp(data.tokens);
				fprintf(stderr, "L%d: usage: push integer\n", data.line_counter);
				exit(EXIT_FAILURE);
			}
		f_check = get_op(*(data.tokens));
		if (f_check)
			get_op(*data.tokens)(&STACK, (*(data.tokens + 1))? atoi(*(data.tokens + 1)): 0);
		else
		{
			fclose(data.fp);
			free(data.line);
			free_list(STACK);
			fprintf(stderr, "L%d: unknown instruction %s\n", data.line_counter, *(data.tokens));
			free_dp(data.tokens);
			exit(EXIT_FAILURE);
		}
 		free_dp(data.tokens);
	}
	free_list(STACK);
	free(data.line);
	fclose(data.fp);
	return (0);
}
