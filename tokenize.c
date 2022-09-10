#include "monty.h"

/**
 * tokenize - get the path strings
 * @size: number of path variables
 * @path: full string path joined by ':'
 * @delimiter: string seperator
 * Return: the pointer to the array of the path variables
 */
char **tokenize(int size, char *path, char *delimiter)
{
	char **paths = NULL;
	int i;
	char *command, *holder;

	if (path)
	{
		i = 0;
		holder = strdup(path);
		command = holder;
		paths = malloc(sizeof(char *) * (size + 1));
		command = strtok(command, delimiter);
		while (command)
		{
			paths[i] = strdup(command);
			command = strtok(NULL, delimiter);
			i++;
		}
		paths[i] = NULL;
		free(holder);
	}
	return (paths);
}
/**
 * token_size - determines the size of tokens in a string
 * @str: string to be evaluated
 * @delimiter: delimiter to be used
 * Return: the size of strings
 */
int token_size(char *str, char *delimiter)
{
	int size, flag = 0;
	char *buffer, *holder;

	size = 0;
	if (str)
	{
		buffer = strdup(str);
		holder = buffer;
		while (*holder != '\0' && *holder != EOF)
		{
			if (strchr(delimiter, *holder) != NULL && flag == 0)
			{
				size++;
				flag = 1;
			}
			else if (strchr(delimiter, *holder) == NULL && flag == 1)
			{
				flag = 0;
			}
			holder++;
		}
		holder--;
		if (strchr(delimiter, *holder) == NULL)
			size++;
		free(buffer);
	}
	return (size);
}
