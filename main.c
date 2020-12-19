#include "monty.h"

/**
 *
 */

int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	char *line = NULL, **tokens = NULL;
	int i = 0;

	line = malloc(50);

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Couldn't open file %s\n", argv[1]);
		return (1);
	}

	while (fgets(line, 50, fp))
	{
		*(line + strlen(line) - 1) = '\0';
		tokens = _strtok(line, 32);
		printf("%s, %s\n", *(tokens), *(tokens + 1));
		free(tokens);
	}
	free(line);
	fclose(fp);
	return (0);
}