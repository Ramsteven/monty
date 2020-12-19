#include "monty.h"
/**
 *
 *
 * */
void (*get_op(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push_function},	
//		{"pop", pop_function},
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

void push_function(stack_t **stack, unsigned int line_number)
{
	printf("line number %d\n", (int)line_number);
}

/*int pop_function(char *n)
{
	printf("soy pop: %s\n", n);
	return 0;
}*/
