#include "monty.h"

/**
 *
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
		data.tokens = _strtok(data.line, 32);
		if (data.tokens == NULL)
			continue;
		f_check = get_op(*(data.tokens));
		if (f_check)
			f_check(&STACK, line_counter);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_counter, *(data.tokens));
			free_leaks(&STACK);
			exit(EXIT_FAILURE);
		}
 		free_dp(data.tokens);
		data.tokens = NULL;
	}
	free_leaks(&STACK);
	return (0);
}
