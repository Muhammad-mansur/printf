#include "main.h"

/**
 * _printf - printf function recreation
 * format: string inout
 * Return: number of characters printed
 */

/* Function prototypes for specifier handlers */
void handle_char(va_list args);
void handle_string(va_list args);
void handle_decimal(va_list args);
void handle_binary(va_list args);

int _printf(const char *format, ...)
{
	int chara_print = 0;
	va_list list_of_args;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(list_of_args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			chara_print++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == '%')
			{
				write(1, format, 1);
				chara_print++;
			}
			else if (*format == 'c')
			{
				handle_char(list_of_args);
			}
			else if (*format == 's')
			{
				handle_string(list_of_args);
			}
			else if (*format == 'd' || *format == 'i')
			{
				handle_decimal(list_of_args);
			}
			else if (*format == 'b')
			{
				handle_binary(list_of_args);
			}
			else
			{
				write(1, format - 1, 2);
				chara_print += 2;
			}
		}
		format++;
	}
	va_end(list_of_args);
	return (chara_print);
}

/* Implementation of specifier handler functions */
void handle_char(va_list args)
{
	char c = va_arg(args, int);
	write(1, &c, 1);
}

void handle_string(va_list args)
{
	char *str = va_arg(args, char*);
	int str_len = strlen(str);
	write(1, str, str_len);
}

void handle_decimal(va_list args)
{
	int num = va_arg(args, int);
	char buffer[20];
	int len = sprintf(buffer, "%d", num);
	write(1, buffer, len);
}

void handle_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[33];
	int index;
	int significant_digit_found = 0;

	buffer[32] = '\0';

	for (index = 31; index >= 0; index--)
	{
		int bit_value = (num >> index) & 1;
		if (bit_value)
			significant_digit_found = 1;

		if (significant_digit_found)
			buffer[31 - index] = bit_value ? '1' : '0';
		else
			buffer[31 - index] = ' ';
	}

	write(1, buffer, 32);
}
