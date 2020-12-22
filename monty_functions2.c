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

/**
 * pchar_function - function that print the ascii characet
 *
 * @stack: The head of the DLL
 * @line_number: The number for the new_node
 *
 * Return: no return
 */

void pchar_function(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_leaks(stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n > 32 && (*stack)->n < 127)
	{
		printf("%c\n", (*stack)->n);

	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_leaks(stack);
		exit(EXIT_FAILURE);
	}
}
/**
 * pstr_function - function thar print all caracters o a list
 *
 * @stack: The head of the DLL
 * @line_number: The number for the new_node
 *
 * Return: no return
 */
void pstr_function(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (stack_len(*stack) < (int)line_number)
	{

	}

	while (tmp)
	{

		if (tmp->n > 32 && tmp->n < 127)
		{
			printf("%c", tmp->n);
			tmp = tmp->next;
		}
		else if (tmp->n == 0 || 1)
		{
			break;
		}
	}
	printf("\n");
}
