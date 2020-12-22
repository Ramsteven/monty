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

/**
 * add_node- add node to beggining of the list
 *@stack: the head of the DLL
 *@n: number to save
 * Return: nothing
 **/

void add_node(stack_t **stack, int n)
{
	stack_t *new_node = NULL;

	new_node = create_node();
	if (new_node == NULL)
	{
		free_leaks(stack);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->next = *stack;
	new_node->prev = NULL;
	new_node->n = n;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * add_node_end- add node to end of list
 *@stack: the head of the DLL
 *@n: number to save
 * Return: nothing
 */

void add_node_end(stack_t **stack, int n)
{
	stack_t *end;
	stack_t *tmp = *stack;

	end = create_node();
	if (end == NULL)
	{
		free_leaks(stack);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	end->n = n;
	end->next = NULL;
	end->prev = NULL;


	if (*stack == NULL)
		*stack = end;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;

		tmp->next = end;
		end->prev = tmp;
	}
}

/**
 * isnumber - Checks if a char array has only digits
 *
 * @number: The char array to be checked
 *
 * Return: 0 if is invalid. 1 if has only digits
 */

int isnumber(char *number)
{
	int i = 0;

	if (*(number) == 45 && *(number + 1))
		i++;

	while (*(number + i))
	{
		if (*(number + i) < 48 || *(number + i) > 57)
			return (0);
		i++;
	}
	return (1);
}
