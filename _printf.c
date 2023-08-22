#include "main.h"

/**
 * print_buffer - Prints contents fo the bufffer
 * @buffer: Array of chars
 * @buff_ind: Represents the length
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
<<<<<<< HEAD
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer, flags,
					width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
=======
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
				handle_string(list_of_args, &chara_print);
				char *str = va_arg(list_of_args, char*);
				int str_len = strlen(str);

				write(1, str, str_len);
				chara_print += str_len;
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
>>>>>>> 160141456a7118d41dbb0d15f8509242633fe477
		}
	}
	print_buffer(buffer, &buff_ind);

	va_end(list);
	return (printed_chars);
}
