/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:26:32 by jcummins          #+#    #+#             */
/*   Updated: 2023/12/13 18:56:31 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

/* ft_printf */
int	format(va_list arg, char c);
int	ft_printf(const char *str, ...);
//int	main(void);

/* nformats */
int	print_ptr(void *ptr);
int	print_int(int num);
int	print_hex(unsigned long long num, int cap);
int	print_usi(unsigned int num);

/* cformats */
int	print_str(char *str);
int	print_char(char chr);

#endif
