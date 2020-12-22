#include "monty.h"

/**
 * push_function - Push a number in a stack DLL
 *
 * @stack: The head of the DLL
 * @line_number: The number for the line in case of errors
 */

void push_function(stack_t **stack, unsigned int line_number)
{
	int n = 0;
	char *aux = *(data.tokens + 1);

	if (*(data.tokens + 1) == NULL || !isnumber(*(data.tokens + 1)) ||
	(atoi(*(data.tokens + 1)) == 0 && *(*(data.tokens + 1)) != '0' &&
	strcmp(*(data.tokens + 1), "-0")))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_leaks(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (!(*(aux) == 45 && *(aux + 1) == 48 && *(aux + 2) == 0))
			n = atoi(*(data.tokens + 1));
	}

	if (data.flag == 'q')
		add_node_end(stack, n);
	else
		add_node(stack, n);
}

/**
 * pall_function - Prints all elements of Stack
 *
 * @stack: The head of the DLL
 * @line_number: The number for the line in case of errors
 */

void pall_function(stack_t **stack, unsigned int line_number)
{
	size_t i = 0;
	stack_t *h = *stack;

	if (stack_len(*stack) < (int)line_number)
	{
	}

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		i++;
	}
}

/**
 * pint_function - Prints top element of the stack
 *
 * @stack: The head of the DLL
 * @line_number: The number for the line in case of errors
 */

void pint_function(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_leaks(stack);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}

/**
 * pop_function - Removes top element of the stack
 *
 * @stack: The head of the DLL
 * @line_number: The number for the line in case of errors
 */

void pop_function(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	unsigned int i = 0, index = 0;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_leaks(stack);
		exit(EXIT_FAILURE);
	}
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	if (index == 0)
	{
		if (i != 0)
		{
			tmp = *stack;
			if (tmp->next)
				tmp->next->prev = NULL;
			*stack = tmp->next;
			free(tmp);
		}
	}
	else if (i == index)
	{
		tmp->prev->next = NULL;
		free(tmp);
	}
	else
	{
		tmp = *stack;
		for (i = 0; i < index && tmp; i++)
			tmp = tmp->next;
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		free(tmp);
	}
}

/**
 * swap_function - Swaps top and second element of the satck
 *
 * @stack: The head of the DLL
 * @line_number: The number for the line in case of errors
 */

void swap_function(stack_t **stack, unsigned int line_number)
{
	int aux;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_leaks(stack);
		exit(EXIT_FAILURE);
	}

	aux = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = aux;
}
