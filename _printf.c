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
				char c = va_arg(list_of_args, int);

				write(1, &c, 1);
				chara_print++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(list_of_args, char*);
				if (str == NULL)
				{
					write(1, "(null)", 6);
					chara_print += 6;
				}
				else
				{
					int str_len = strlen(str);
					
					write(1, str, str_len);
					chara_print += str_len;
				}
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(list_of_args, int);
				char buffer[20];
				int len = sprintf(buffer, "%d", num);

				write(1, buffer, len);
				chara_print += len;
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
