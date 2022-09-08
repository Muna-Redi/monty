#include "monty.h"

/**
* tokenize - tokenizes a string
* @buff: string to be tokenized
* Return: array of tokens
*/
char **tokenize(char *buff)
{
	char **tokens = NULL, *token = NULL;
	int toksize = 3, i = 0;

	if (buff == NULL || !(*buff) || if_empty_line(buff) != 0)
		return (NULL);
	tokens = malloc(toksize * sizeof(char *));
	if (tokens == NULL)
	{
		free(buff);
		buff = NULL;
		free(tokens);
		return (NULL);
	}
	token = strtok(buff, " \t\b\a\n");
	if (token == NULL)
	{
		return (NULL);
	}
	while (token && i < toksize)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, " \n\b\a\t");
	}
	tokens[i] = NULL;
	buff = NULL;
	free(buff);
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

	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
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
	while (*stack)
	{
		*stack = tmp->next;
		free(tmp);
		tmp = *stack;
	}
}
