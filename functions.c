#include "monty.h"

/**
 *
 *
 */

void (*get_op(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push_function},
		{"pall", pall_function},
		{NULL, NULL}
	};
	int i = 0;
	while(ops[i].opcode)
	{
		if(!(strcmp(s, ops[i].opcode)))
			return (ops[i].f);
		i++;
	}

	return NULL;
}

/**
 * add_dnodeint - Adds a node in the beggining of a DLL
 *
 * @head: The head of the DLL
 * @n: The number for the new_node
 *
 * Return: The address of the new_node
 */

void push_function(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;

	if (stack == NULL)
		return;

	new_node = create_node();
	if (new_node == NULL)
		return;
	new_node->next = *stack;
	new_node->prev = NULL;
	new_node->n = line_number;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * create_node - Creates a new node of a dlistint_t DLL
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
 * print_dlistint - Prints all the elements in a DLL
 *
 * @h: The head of the DLL
 *
 * Return: the number of nodes in the DLL
 */

void pall_function(stack_t **stack, unsigned int line_number)
{
	size_t i = 0;
	stack_t *h = *stack;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		i++;
	}
}
