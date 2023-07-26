#include "shell.h"

/**
 * is_interactive - returns true if shell is in interactive mode
 * @shell_info: struct address
 *
 * Return: 1 if in interactive mode, 0 otherwise
 */
int is_interactive(info_t *shell_info)
{
	return (isatty(STDIN_FILENO) && shell_info->readfd <= 2);
}

/**
 * is_delimiter - checks if character is a delimiter
 * @c: the char to check
 * @delimiter: the delimiter string
 * Return: 1 if true, 0 if false
 */
int is_delimiter(char c, char *delimiter)
{
	while (*delimiter)
	{
		if (*delimiter == c)
			return (1);
		(delimiter++);
	}
	return (0);
}

/**
 * is_alphabetic - checks for alphabetic character
 * @c: The character to check
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int is_alphabetic(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * _atoi - converts a string to an integer
 * @str: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */
int _atoi(char *str)
{
	return _atoi(str);
}
