#include "monty.h"

/**
* _strtok - tokenizes a string
* @buff: string to be tokenized
* Return: array of tokens
*/
char **_strtok(char *buff)
{
	char **tokens = NULL;
	int toksize;
	char delimeter[] = " \n\t\b\0";

	toksize = token_size(buff, delimeter);
	tokens = tokenize(toksize, buff, delimeter);
	return (tokens);
}
/**
* free_array - frees double array
* @arr: array to be freed
* Return: void
*/
void free_array(char **arr)
{
	int i = 0;

	if (arr == NULL)
		return;

	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	arr = NULL;
}
/**
 * if_empty_line - A function that checks if line only contains delimiters.
 * @line: The pointer to the line.
 * Return: 1 if the line only contains delimiters, otherwise 0.
 */
int if_empty_line(char *line)
{
	int i, j;
	char *delims = " \n\t\b\a";

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}
/**
* free_stack - frees a stack from memeory
* @stack: stack address
* Return: void
*/
void free_stack(stack_t **stack)
{
	stack_t *tmp = NULL;

	tmp = *stack;
	if (tmp == NULL)
		return;

	while (*stack)
	{
		*stack = tmp->next;
		free(tmp);
		tmp = *stack;
	}
	*stack = NULL;
}
