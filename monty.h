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

typedef struct {
	FILE *fp;
	char *line;
	char **tokens;
} handle_free;

handle_free data;

#define LINE_SIZE 100

/* main_functions.c */
FILE *get_file(char *file_name, int args);
char *allocate_line(FILE *fp);

int _strlen(char *str);
int _strncmp(const char *s1, const char *s2, int n);
char **_strtok(char *str, char delimiter);
char *write_word(char *str, char delimiter);
int length_d(char *str, char delimiter);
char *int_to_string(int number);
long absolute(long n);
int pot(int x, int y);
void *_calloc(unsigned int nmemb, unsigned int size);
void (*get_op(char *s))(stack_t **stack, unsigned int line_number);
void push_function(stack_t **stack, unsigned int line_number);
stack_t *create_node(void);
void pall_function(stack_t **stack, unsigned int line_number);
int get_lines(char *file);
void free_dp(char **to_free);
void pint_function(stack_t **stack, unsigned int line_number);
void pop_function(stack_t **head, unsigned int line_number);
void free_list(stack_t *head);
void free_leaks(stack_t **stack);
int stack_len(stack_t *h);
void swap_function(stack_t **stack, unsigned int line_number);
void nop_function(stack_t **stack, unsigned int line_number);
//aritmetic
void add_function(stack_t **stack, unsigned int line_number);
void sub_function(stack_t **stack, unsigned int line_number);
void mul_function(stack_t **stack, unsigned int line_number);
void div_function(stack_t **stack, unsigned int line_number);
void mod_function(stack_t **stack, unsigned int line_number);
#endif /*MONTY_H*/
