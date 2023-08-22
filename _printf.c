#include "main.h"

/**
 * _printf - printf function recreation
 * format: string input
 * Return: number of characters printed
 */

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
				chara_print++;
			}
			else if (*format == 's')
			{
<<<<<<< HEAD
				handle_string(list_of_args, &chara_print);
=======
				char *str = va_arg(list_of_args, char*);
				int str_len = strlen(str);

				write(1, str, str_len);
				chara_print += str_len;
>>>>>>> parent of 583b1dd... Avoid Buffer overflow
			}
			else if (*format == 'd' || *format == 'i')
			{
				handle_decimal(list_of_args, &chara_print);
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
