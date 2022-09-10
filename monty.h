#ifndef MONTY_H

/****************************                   ***************************/
/*                               LIBRARIES USED                           */
/****************************                   ***************************/


#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <unistd.h>



/****************************                   ***************************/
/*                             DATA STRUCTURES USED                       */
/****************************                   ***************************/

/*
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 *truct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/*                               FUNCTIONS USED                           */



            /*****************                   ******************/
/***********                Op_code Functions Used                  *****************/
            /*****************                   ******************/
int op_push(stack_t **stack, char **tokens, unsigned int linecount);

void op_pall(stack_t **stack, unsigned int linecount);

void op_pint(stack_t **stack, unsigned int linecount);

void op_nop(stack_t **stack, unsigned int linecount);

void op_pop(stack_t **stack, unsigned int linecount);

void op_add(stack_t **stack, unsigned int linecount);

void op_sub(stack_t **stack, unsigned int linecount);

void op_div(stack_t **stack, unsigned int linecount);

void op_mul(stack_t **stack, unsigned int linecount);

void op_mod(stack_t **stack, unsigned int linecount);

void op_swap(stack_t **stack, unsigned int linecount);

void op_pchar(stack_t **stack, unsigned int linecount);

void op_pstr(stack_t **stack, unsigned int linecount);

void op_rotl(stack_t **stack, unsigned int linecount);

void op_rotr(stack_t **stack, unsigned int linecount);


            /*****************                   ******************/
/***********                Helper Functions USED                  *****************/
            /*****************                   ******************/
char **_strtok(char *buff);

int token_size(char *str, char *delimiter);

char **tokenize(int size, char *path, char *delimiter);

int _err(char *c, char *s, unsigned int linecount, char *command);

int _monty(stack_t **stack, unsigned int linecount, char **tokens);

void (*op_func(const char *mcode))(stack_t **, unsigned int);

int errors(unsigned int line, char *fname, char **tokens, int f);

void free_stack(stack_t **stack);

int if_empty_line(char *line);

void free_array(char **arr);

void clean(FILE *fd, char **tokens, char *buff, stack_t **stack);

#endif
