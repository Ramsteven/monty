#include "monty.h"

/**
 * stack_len - Calculates the length of a Stack DLL
 *
 * @stack: The head of the DLL
 *
 * Return: The length of the DLL
 */

int stack_len(stack_t *stack)
{
	int i = 0;

	while (stack)
	{
		i++;
		stack = stack->next;
	}

	return (i);
}

/**
 * create_node - Creates a new node of a stack_t DLL
 *
 * Return: The address of the created node.
 */

stack_t *create_node(void)
{
	stack_t *node = NULL;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		return (NULL);

	return (node);
}
