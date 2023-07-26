#include "shell.h"

/**
 * interactive_mode - returns 1 if shell is in interactive mode, 0 otherwise
 * @info: pointer to the info_t structure
 *
 * Return: 1 if in interactive mode, 0 otherwise
 */
int interactive_mode(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delimiter - checks if character is a delimiter
 * @character: character to check
 * @delim: delimiter string
 * Return: 1 if true, 0 if false
 */
int is_delimiter(char character, char *delim)
{
	while (*delim)
	{
		if (*delim == character)
			return (1);
		delim++;
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
	return ((c >= 'b' && c <= 'x') || (c >= 'B' && c <= 'X'));
}

/**
 * _atoi - converts a string to an integer
 * @str: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */
int _atoi(char *str)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; str[i] != '\0' && flag != 2; i++)
	{
		if (str[i] == '-')
			sign *= -1;

		if (str[i] >= '0' && str[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (str[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
