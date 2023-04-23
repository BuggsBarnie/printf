#include "main.h"

/**
 * print_unsigned - A function that displays an unsigned int
 * @types: Arguments listed
 * @buffer: Array for printing
 * @flags:  Counts the flags which are active
 * @width: Specified dimension
 * @precision: Accuracy in the explanation
 * @size: Checks for physical dimensions
 * Return: Int
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int e = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	{
		buffer[e--] = '0';
	}

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[e--] = (num % 10) + '0';
		num /= 10;
	}

	e++;

	return (write_unsgnd(0, e, buffer, flags, width, precision, size));
}

/**
 * print_octal - A function that displays an unsigned int in octal notation
 * @types: Arguments listed
 * @buffer: Array for printing
 * @flags:  Counts the flags which are active
 * @width: Specified dimension
 * @precision: Accuracy in the explanation
 * @size: Checks for physical dimension
 * Return: Int
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int r = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	{
		buffer[r--] = '0';
	}

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[r--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[r--] = '0';

	r++;

	return (write_unsgnd(0, r, buffer, flags, width, precision, size));
}


/**
 * print_hexadecimal -  Function that prints an unsigned int in hexadecimal
 * @types: Arguments listed
 * @buffer: Array for printing
 * @flags:  Counts the flags which are active
 * @width: Specified dimension
 * @precision: Accuracy in the explanation
 * @size: Checks for physical dimension
 * Return: Int
 */

int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}


/**
 * print_hexa_upper - Displays an int in upper hexadecimal notation
 * @types: Arguments listed
 * @buffer: Array for printing
 * @flags:  Counts the flags which are active
 * @width: Specified dimension
 * @precision: Accuracy in the explanation
 * @size: Checks for physical dimension
 * Return: Int
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}


/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: Arguments  listed
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Counts the flags which are active
 * @flag_ch: Counts active flags
 * @width: Checks for physical dimension
 * @precision: Accuracy in the explanation
 * @size: Checks for physical dimension
 * @size: Confirms physical dimension
 * Return: int
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
