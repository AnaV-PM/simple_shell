#include "shell.h"

/**
 * print_alias - Prints the alias in the form name='value'
 * @node: The alias node to print
 */
void print_alias(list_t *node)
{
	char *name = NULL, *value = NULL;

	if (node)
	{
		name = node->str;
		value = _strchr(name, '=');
		*value = '\0';
		value++;

		_puts(name);
		_putchar('=');
		_putchar('\'');
		_puts(value);
		_putchar('\'');
		_putchar('\n');
		*--value = '=';
	}
}

/**
 * print_all_aliases - Prints all the aliases
 */
void print_all_aliases(void)
{
	list_t *node = shell_info.alias;

	while (node)
	{
		print_alias(node);
		node = node->next;
	}
}

/**
 * find_alias - Finds an alias by name
 * @name: The alias name to find
 * Return: The alias node if found, NULL otherwise
 */
list_t *find_alias(char *name)
{
	list_t *node = shell_info.alias;

	while (node)
	{
		if (_strcmp(name, node->str) == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * alias_builtin - Implements the alias builtin command
 * @args: The arguments passed to alias
 * Return: Always 0 (Success)
 */
int alias_builtin(char **args)
{
	int i;
	list_t *alias_node;

	if (!args[1])
		print_all_aliases();
	else
	{
		for (i = 1; args[i]; i++)
		{
			alias_node = find_alias(args[i]);
			if (alias_node)
				print_alias(alias_node);
			else
			{
				if (add_node_end(&shell_info.alias, args[i], 0) == NULL)
				{
					perror("Error");
					return (EXIT_FAILURE);
				}
			}
		}
	}
	return (EXIT_SUCCESS);
}
