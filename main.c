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

	line = malloc(sizeof(char) * LINE_SIZE);
	if (!line)
		return (1);

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Couldn't open file %s\n", argv[1]);
		return (1);
	}

	while (fgets(line, LINE_SIZE, fp))
	{
		*(line + strlen(line) - 1) = '\0';
		tokens = _strtok(line, 32);
		if (*(tokens + 1))
			if((atoi(*(tokens + 1)) == 0 && *(*(tokens + 1)) != '0' ))
				exit(4);
		//check if token + 1 is empty
		// function pointer check the return value
		f_check = get_op(*tokens);
		if (f_check)
			get_op(*tokens)(&STACK, (*(tokens + 1))? atoi(*(tokens + 1)): 0);
/*		else
			mensaje de error
*/
 		free_dp(tokens);
	}
	free(line);
	fclose(fp);
	return (0);
}
