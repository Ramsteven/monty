#include "monty.h"

/**
 * _strlen - Measure the length of a string
 *
 * @str: The string whose length is needed
 *
 * Return: The length of the string (number of elements)
 */

int _strlen(char *str)
{
	int i;

	for (i = 0; *(str + i); i++)
		;
	return (i);
}


/**
 * _strncmp - compare two strings
 *
 * @s1: string 1
 * @s2: string 2
 * @n: bytes to compare
 *
 * Return: 1 if two strings are iquals, 0 if don
 **/

int _strncmp(const char *s1, const char *s2, int n)
{
	char str1, str2;

	while (n-- > 0)
	{
		str1 = *s1++;
		str2 = *s2++;

		if (str1 != str2)
			return (0);
		else if (str1 == '\0' || str2 == '\0')
			return (0);
	}
	return (1);
}

/**
 * _strtok - Splits a string in separated words
 *
 * @str: The string to be separated
 * @delimiter: The delimiter to make the tokens
 *
 * Return: An array of pointers with each word
 */

char **_strtok(char *str, char delimiter)
{
	char **words = NULL;
	int count = 0, i;

	if (str == NULL || *(str) == '\0' ||
	(*(str) == delimiter && *(str + 1) == 0))
		return (NULL);
	for (i = 0; *(str + i); i++)
	{
		if ((*(str + i + 1) != 0 && *(str + i) == delimiter &&
		 *(str + i + 1) != delimiter) || (i == 0 && *(str + i) != delimiter))
			count++;
	}
	if (count == 0)
		return (NULL);
	words = (char **)_calloc((count + 1), sizeof(char *));
	if (words == NULL)
		return (NULL);
	count = 0;
	i = 0;
	if (*(str + i) != delimiter)
	{
		*(words + count) = write_word(str + i, delimiter);
		count++;
		i++;
	}
	for (; *(str + i); i++)
	{
		if (*(str + i + 1) != 0 && *(str + i) == delimiter &&
		 *(str + i + 1) != delimiter)
		{
			*(words + count) = write_word(str + i + 1, delimiter);
			count++;
		}
	}
	*(words + count) = NULL;
	return (words);
}

/**
 * write_word - Write a word in the desired direction
 *
 * @str: The string having the word
 * @delimiter: The delimiter of the words
 *
 * Return: A pointer with a copy of str until first delimiter found
 */

char *write_word(char *str, char delimiter)
{
	char *word;
	int i = 0;

	word = (char *)_calloc((length_d(str + i, delimiter) + 1), sizeof(char));
	if (word == NULL)
		return (NULL);

	for (i = 0; *(str + i) != delimiter && *(str + i); i++)
		*(word + i) = *(str + i);
	*(word + i) = 0;

	return (word);
}

/**
 * length_d - Computes the length of a string until a delimiter
 *
 * @str: The string having the word beggining at firs char
 * @delimiter: The delimiter to compute length
 *
 * Return: The length of the string
 */

int length_d(char *str, char delimiter)
{
	int i = 0;

	for (i = 0; *(str + i) != delimiter && *(str + i); i++)
		;
	return (i);
}

/**
 * int_to_string - processes a number as a string
 * @number: The number to be processed
 *
 * Return: The number as a string
 */

char *int_to_string(int number)
{
	char *num_str;
	int len = 0, digits = 1, j;
	long i;

	for (i = 10; absolute(number) / i > 0; i = i * 10)
	{
		digits++;
	}
	if (number < 0)
		len = digits + 1;
	else
		len = digits;

	num_str = malloc(sizeof(char) * (len + 1));
	if (num_str == NULL)
		exit(0);

	i = 0;
	if (number < 0)
	{
		*(num_str) = '-';
		i++;
	}
	for (j = 1; i < len; i++, j++)
	{
		*(num_str + i) = ((absolute(number) / (pot(10, (digits - j)))) % 10) + 48;
	}
	*(num_str + i) = '\0';

	return (num_str);
}

/**
 * absolute - Absolute value
 *
 * @n: The number whose absolute value is needed
 *
 * Return: The absolute value
 */

long absolute(long n)
{
	if (n < 0)
		return (-1 * n);
	else
		return (n);
}

/**
 * pot - potetiation of x ** y
 *
 * @x: The base
 * @y: The exponenr
 *
 * Return: The result of x ** y
 */

int pot(int x, int y)
{
	int i, resultado = 1;

	for (i = 0; i < y; i++)
	{
		resultado = resultado * x;
	}
	return (resultado);
}

/**
 * _calloc - allocate memory wich has been initialized to zero
 * @nmemb: amount of elements
 * @size: size depend data type
 * Return: pointer
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *P = NULL;

	if (nmemb == 0 || size == 0)
		return (NULL);

	P = malloc(nmemb * size);

	if (P == NULL)
	{
		free(P);
		return (NULL);
	}
	for (i = 0; i < nmemb * size; i++)
		*(P + i) = 0;

	return (P);

}
