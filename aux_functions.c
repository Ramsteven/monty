#include "monty.h"

/**
 * 
 */

int get_lines(char *file)
{
	int check = 0, lines = 0;
	FILE *fp = NULL;

	fp = fopen(file, "r");

	check = getc(fp);

	while (check != EOF)
	{
		if (check == 10)
			lines++;
		check = getc(fp);
	}

	fclose(fp);
	return (lines);
}

/**
 * 
 */

void free_dp(char **to_free)
{
	int i = 0;

	while (*(to_free + i))
		free(*(to_free + i++));

	free(to_free);
}
