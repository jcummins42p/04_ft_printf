/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:09:09 by jcummins          #+#    #+#             */
/*   Updated: 2023/12/11 17:53:56 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str (char *print)
{
	int i;

	i = 0;
	while (print[i])
		write (1, &print[i], 1);
	return (i);
}

int	print_hex (int print)
{
	char c;

	c = print + '0';
	write (1, &c, 1);
	return (1);
}

int	print_char (int print)
{
	char c;

	c = print + '0';
	write (1, &c, 1);
	return (1);
}

int	print_digit (int print)
{
	char	c;

	c = print + '0';
	if (c < '0' || c > '9')
		return (-1);
	write (1, &c, 1);
	return (1);
}

int	format (va_list arg, char c)
{
	int len;

	len = 0;
	if (c == 'd' || c == 'i')
		len += print_digit(va_arg(arg, int));
	if (c == 'c')
		len += print_char(va_arg(arg, int));
	if (c == 's')
		len += print_str(va_arg(arg, char *));
	if (c == 'x')
		len += print_hex(va_arg(arg, int));
	else if (c == '%')
		write (1, "%", 1);
	return (1);
}

int	ft_printf (const char *str, ...)
{
	va_list	argptr;
	int		i;
	int 	len;

	i = 0;
	len = 0;
	va_start(argptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += format(argptr, str[i]);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			len++;
			i++;
		}
	}
	va_end(argptr);
	return (len);
}

int	main (void)
{
	int		i = 99;
	char	*str = "tester";
	char	c = 'P';

	printf("%%Your integer is %d, your string is %s, your char is %c.\n", i, str, c);
	ft_printf("%%Your integer is %d, your string is %s, your char is %c.\n", i, str, c);
	return (0);
}
