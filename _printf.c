#include "main.h"

/**
 * _printf - printf function recreation
 * format: string inout
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
				int str_len = strlen(str);

				write(1, str, str_len);
				chara_print += str_len;
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(list_of_args, int);
				char buffer[20];
				int len = sprintf(buffer, "%d", num);

				write(1, buffer, len);
				chara_print += len;
			}
			else if (*format == 'b')
			{
				unsigned int num = va_arg(list_of_args, unsigned int);
				char buffer[33];
				int index;

				buffer[32] = '\0';
				for (index = 31; index >= 0; index--)
				{
					buffer[index] = (num & 1) ? '1' : '0';
					num >>= 1;
				}
				write(1, buffer, 32);
				chara_print += 32;
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
