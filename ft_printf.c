/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:09:09 by jcummins          #+#    #+#             */
/*   Updated: 2023/12/13 18:48:27 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format(va_list arg, char c)
{
	int				len;
	unsigned int	u_arg;

	len = 0;
	if (c == 'd' || c == 'i')
		len += print_int(va_arg(arg, int));
	if (c == 'u')
	{
		u_arg = (unsigned int)va_arg(arg, int);
		len += print_usi(u_arg);
	}
	if (c == 'c')
		len += print_char(va_arg(arg, int));
	if (c == 's')
		len += print_str(va_arg(arg, char *));
	if (c == 'x')
		len += print_hex(va_arg(arg, int), 0);
	if (c == 'X')
		len += print_hex(va_arg(arg, int), 1);
	if (c == 'p')
		len += print_ptr(va_arg(arg, void *));
	else if (c == '%')
		len += print_char('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	argptr;
	int		i;
	int		len;

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

int	main(void)
{
	int		i = -128;
	char	*str = "tester";
	char	c = 'P';
	int		og_pf;
	int		ft_pf;
	void	*ptr = malloc(1);

	og_pf = printf("%%Int is %x, string is %s, char is %c, ptr is %p.\n", i, str, c, ptr);
	ft_pf = ft_printf("%%Int is %x, string is %s, char is %c, ptr is %p.\n", i, str, c, ptr);
	printf("The built in function returned length of %d\n", og_pf);
	printf("The fake function returned length of %d\n", ft_pf);
	free (ptr);
	return (0);
}
