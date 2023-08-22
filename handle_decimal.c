#include "main.h"

/**
 * handle_decimal - Format specifier for decimal
 * @args: Input string
 * Return: Nothing
 */

void handle_decimal(va_list args, int *chara_print)
{
	int num = va_arg(args, int);
	char *buffer = NULL;
	int len = snprintf(NULL, 0, "%d", num);

	buffer = (char *)malloc(len + 1);
	if (buffer)
	{
		snprintf(buffer, len + 1, "%d", num);
		write(1, buffer, len);
		chara_print += len;
		free(buffer);
	}
}
