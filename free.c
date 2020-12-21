#include "monty.h"

/**
 * free_leaks - Frees all the allocated data
 *
 * @stack: The stack to be freed.
 */

void free_leaks(stack_t **stack)
{
	fclose(data.fp);
	free_dp(data.tokens);
	free_stack(*stack);
	free(data.line);
}

/**
 * free_dp - Frees a double pointer
 *
 * @to_free: Double pointer to be freed.
 */

void free_dp(char **to_free)
{
	int i = 0;

	if (to_free)
	{
		while (*(to_free + i))
			free(*(to_free + i++));

		free(to_free);
	}
}


/**
 * free_stack - frees a stack DLL
 *
 * @head: Top element of the stack
 */

void free_stack(stack_t *head)
{
	stack_t *walker = head;

	while (walker)
	{
		walker = head->next;
		free(head);
		head = walker;
	}

}
