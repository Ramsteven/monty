#include "monty.h"

/**
 * add_function - Adds top and second elements in the stack
 *
 * @stack: The head of the stack DLL
 * @line_number: The number for the line in case of errors
 */

void add_function(stack_t **stack, unsigned int line_number)
{
	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_leaks(stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop_function(stack, line_number);
}

/**
 * nop_function - Does nothing
 *
 * @stack: The head of the stack DLL
 * @line_number: The number for the line in case of errors
 */


void nop_function(stack_t **stack, unsigned int line_number)
{
	if (stack_len(*stack) < (int)line_number)
	{
	}
}

/**
 * sub_function - Substracts top and second elements in the stack
 *
 * @stack: The head of the stack DLL
 * @line_number: The number for the line in case of errors
 */

void sub_function(stack_t **stack, unsigned int line_number)
{
	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_leaks(stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	pop_function(stack, line_number);
}

/**
 * mul_function - Multiplies top and second elements in the stack
 *
 * @stack: The head of the stack DLL
 * @line_number: The number for the line in case of errors
 */

void mul_function(stack_t **stack, unsigned int line_number)
{
	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_leaks(stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	pop_function(stack, line_number);
}

/**
 * div_function - Divides top and second elements in the stack
 *
 * @stack: The head of the stack DLL
 * @line_number: The number for the line in case of errors
 */

void div_function(stack_t **stack, unsigned int line_number)
{
	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_leaks(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_leaks(stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	pop_function(stack, line_number);
}
