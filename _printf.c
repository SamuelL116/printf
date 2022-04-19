#include "main.h"
<<<<<<< HEAD
#include <stdio.h>

=======
>>>>>>> 4b14d88c71f4aa4bd08756877231c22dd6aa8f6d
/**
 * _printf - produces output according to a format
 * @format: format string containing the characters and the specifiers
 * Description: this function will call the get_print() function that will
 * determine which printing function to call depending on the conversion
 * specifiers contained into fmt
 * Return: length of the formatted output string
 */
<<<<<<< HEAD

int _printf(const char *format, ...)
{
int (*pfunc)(va_list, flags_t *);
const char *p;
va_list arguments;
flags_t flags = {0, 0, 0};

register int count = 0;

va_start(arguments, format);
if (!format || (format[0] == '%' && !format[1]))
return (-1);
if (format[0] == '%' && format[1] == ' ' && !format[2])
return (-1);
for (p = format; *p; p++)
{
if (*p == '%')
{
p++;
if (*p == '%')
{
count += _putchar('%');
continue;
}
while (get_flag(*p, &flags))
p++;
pfunc = get_print(*p);
count += (pfunc)
? pfunc(arguments, &flags)
: _printf("%%%c", *p);
} else
count += _putchar(*p);
}
_putchar(-1);
va_end(arguments);
return (count);
=======
int _printf(const char * const format, ...)
{
	convert_match m[] = {
		{"%s", printf_string}, {"%c", printf_char},
		{"%%", printf_37},
		{"%i", printf_int}, {"%d", printf_dec}, {"%r", printf_srev},
		{"%R", printf_rot13}, {"%b", printf_bin}, {"%u", printf_unsigned},
		{"%o", printf_oct}, {"%x", printf_hex}, {"%X", printf_HEX},
		{"%S", printf_exclusive_string}, {"%p", printf_pointer}
	};

	va_list args;
	int i = 0, j, len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	while (format[i] != '\0')
	{
		j = 13;
		while (j >= 0)
		{
			if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
			{
				len += m[j].f(args);
				i = i + 2;
				goto Here;
			}
			j--;
		}
		_putchar(format[i]);
		len++;
		i++;
	}
	va_end(args);
	return (len);
>>>>>>> 4b14d88c71f4aa4bd08756877231c22dd6aa8f6d
}
