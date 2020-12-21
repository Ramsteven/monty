#include "monty.h"

/**
 * mod_function - Mod operation of top and second elements in the stack
 *
 * @stack: The head of the stack DLL
 * @line_number: The number for the line in case of errors
 */

void mod_function(stack_t **stack, unsigned int line_number)
{
	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_leaks(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_leaks(stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	pop_function(stack, line_number);
}
