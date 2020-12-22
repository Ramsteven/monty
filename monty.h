#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct handle_s - Elements to be freed before exit
 * @fp: Pointer to current working file
 * @line: Space allocated to store line data
 * @tokens: Tokens of the line readed
 *
 * Description: All the elements you need to free
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct handle_s
{
	FILE *fp;
	char *line;
	char **tokens;
	char flag;
} handle_free;

handle_free data;
#define LINE_SIZE 2048

/* main.c */
void (*get_op(char *s))(stack_t **stack, unsigned int line_number);
FILE *get_file(char *file_name, int args);
char *allocate_line(FILE *fp);

/* free.c */
void free_leaks(stack_t **stack);
void free_stack(stack_t *head);
void free_dp(char **to_free);

/* tokenizer.c */
char **tokenizer(char *str, char delimiter);
char *write_word(char *str, char delimiter);
int length_d(char *str, char delimiter);
void *_calloc(unsigned int nmemb, unsigned int size);

/* aux_func.c */
int stack_len(stack_t *stack);
stack_t *create_node(void);
void add_node(stack_t **stack, int n);
void add_node_end(stack_t **stack, int n);
int isnumber(char *number);

/* monty_functions.c */
void push_function(stack_t **stack, unsigned int line_number);
void pall_function(stack_t **stack, unsigned int line_number);
void pint_function(stack_t **stack, unsigned int line_number);
void pop_function(stack_t **head, unsigned int line_number);
void swap_function(stack_t **stack, unsigned int line_number);

/* monty_functions1.c */
void nop_function(stack_t **stack, unsigned int line_number);
void add_function(stack_t **stack, unsigned int line_number);
void sub_function(stack_t **stack, unsigned int line_number);
void mul_function(stack_t **stack, unsigned int line_number);
void div_function(stack_t **stack, unsigned int line_number);

/* monty_functions2.c */
void mod_function(stack_t **stack, unsigned int line_number);
void pchar_function(stack_t **stack, unsigned int line_number);
void pstr_function(stack_t **stack, unsigned int line_number);
void rotl_function(stack_t **stack, unsigned int line_number);
void rotr_function(stack_t **stack, unsigned int line_number);

/*monty_functions3.c*/
void stack_function(stack_t **stack, unsigned int line_number);
void queue_function(stack_t **stack, unsigned int line_number);

#endif /*MONTY_H*/
