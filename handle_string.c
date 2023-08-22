#include "main.h"

/**
 * handle_string - Format specifier for string
 * @args: input string
 * Return: Nothing
 */

void handle_string(va_list args, int *chara_print)
{
	char *str = va_arg(args, char*);

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
