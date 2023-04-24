#include "main.h"

/**
 * is_printable - Function that checks if a char can be printed
 * @c: Char for printing
 * Return: Int
 */

int is_printable(char c)
{
	if (c >= 32 && c < 127)
	{
		return (1);
	}
	return (0);
}

/**
 * append_hexa_code - Function that appends ascii to the buffer
 * @buffer: Array of chars for printing
 * @i: Index
 * @ascii_code: Ascii code values
 * Return: int
 */

int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - confirms for digits
 * @c: Char for printing
 * Return: int
 */

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

/**
 * convert_size_number - Function that casts an int
 * @num:  value for casting
 * @size: Indicates the size to be casted
 * Return: int
 */

long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
	{
		return (num);
	}
	else if (size == S_SHORT)
	{
		return ((short)num);
	}
	return ((int)num);
}

/**
 * convert_size_unsgnd - Casts a number to the specified size
 * @num: value for casting
 * @size: Indicates the size to be casted
 * Return: Int
 */

long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
	{
		return (num);
	}
	else if (size == S_SHORT)
	{
		return ((unsigned short)num);
	}
	return ((unsigned int)num);
}
