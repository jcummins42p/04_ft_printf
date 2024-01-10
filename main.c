/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:09:09 by jcummins          #+#    #+#             */
/*   Updated: 2023/12/15 20:30:07 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	test_int(void)
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	result;

	a = 42;
	b = -42;
	c = 0;
	d = 2147483647;
	e = 0xFF;
	result = og_printf(
}

int	main(void)
{
	int		i = -9;
	char	*str = NULL;
	char	c = 'p';
	int		og_pf;
	int		ft_pf;
	void	*ptr = malloc(1);
	unsigned int	ui = 2147483648;

	og_pf = printf("OG:%%, %x, %i, %s, %c, %p, %u.\n", i, i, str, c, ptr, ui);
	ft_pf = ft_printf("FT:%%, %x, %i, %s, %c, %p, %u.\n", i, i, str, c, ptr, ui);
	og_pf = printf("%%, %s\n", str);
	ft_pf = ft_printf("%%, %s\n", str);
	printf("the built in function returned length of %d\n", og_pf);
	printf("the fake function returned length of %d\n", ft_pf);
	free (ptr);
	return (0);
}
