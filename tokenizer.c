#include "monty.h"

/**
 * tokenizer - Splits a string in separated words
 *
 * @str: The string to be separated
 * @delimiter: The delimiter to make the tokens
 *
 * Return: An array of pointers with each word
 */

char **tokenizer(char *str, char delimiter)
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
