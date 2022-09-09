#include "monty.h"

/**
* op_pop - pops the first element in the stack
* @stack: stack address
* @line: file line number
* Return: void
*/
void op_pop(stack_t **stack, unsigned int line)
{
	stack_t *tmp = NULL;

	tmp = *stack;
	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		*stack = NULL;
		return;
	}
	*stack = tmp->next;
	free(tmp);
}
