#include "monty.h"
/**
 * stack_function - set value data.flag to s
 *
 * @stack: The head of the stack DLL
 * @line_number: The number for the line in case of errors
 */

void stack_function(stack_t **stack, unsigned int line_number)
{
	if (stack_len(*stack) < (int)line_number)
	{
	}

	data.flag = 's';
}


/**
 * queue_function - set value data.flag to q
 *
 * @stack: The head of the stack DLL
 * @line_number: The number for the line in case of errors
 */

void queue_function(stack_t **stack, unsigned int line_number)
{
	if (stack_len(*stack) < (int)line_number)
	{
	}

	data.flag = 'q';
}

