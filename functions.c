#include "main.h"

/**
 * print_char - Function that prints a char
 * @types: Arguments listed
 * @buffer: Array for printing
 * @flags:  Counts the flags which are active
 * @width: Specified dimension
 * @precision: accuracy in the explanation
 * @size: checks for physical dimension
 * Return: int
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char q = va_arg(types, int);

	return (handle_write_char(q, buffer, flags, width, precision, size));
}

/**
 * print_string - Function that produces a string
 * @types: Arguments listed
 * @buffer: Array for printing
 * @flags: Counts the flags which are active
 * @width: specified dimension
 * @precision: Accuracy in the explanation
 * @size: Checks for physical dimension
 * Return: int
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, z;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (z = width - length; z > 0; z--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (z = width - length; z > 0; z--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/**
 * print_percent - Function that displays percent sign
 * @types: Arguments listed
 * @buffer: Array for printing
 * @flags: Counts the flags which are active
 * @width: Specified dimension
 * @precision: Accuracy in the explanation
 * @size: Checks for physical dimension
 * Return: int
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * print_int - Function to print a number
 * @types: Arguments listed
 * @buffer: Array for printing
 * @flags: Counts the flags which are active
 * @width: Specified dimension
 * @precision: Accuracy in the explanation
 * @size: Checks for physical dimension
 * Return: int
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int y = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[y--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[y--] = (num % 10) + '0';
		num /= 10;
	}

	y++;

	return (write_number(is_negative, y, buffer, flags, width, precision, size));
}

/**
 * print_binary - Function that prints 0 or 1
 * @types: Arguments listed
 * @buffer: Array for printing
 * @flags:  Counts the flags which are active
 * @width: Specified dimension
 * @precision: Accuracy in the explanation
 * @size: Checks for physical dimension
 * Return: int
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int g, v, i, sum;
	unsigned int b[32];
	int calc;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	g = va_arg(types, unsigned int);
	v = 2147483648; /* (2 ^ 31) */
	b[0] = g / v;
	for (i = 1; i < 32; i++)
	{
		v /= 2;
		b[i] = (g / v) % 2;
	}
	for (i = 0, sum = 0, calc = 0; i < 32; i++)
	{
		sum += b[i];
		if (sum || i == 31)
		{
			char z = '0' + b[i];

			write(1, &z, 1);
			calc++;
		}
	}
	return (calc);
}
