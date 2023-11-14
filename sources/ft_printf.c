/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibosc <pibosc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:13:04 by pibosc            #+#    #+#             */
/*   Updated: 2023/11/14 20:39:12 by pibosc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	handle_flag(const char *f, va_list params)
{
	int	chars;

	chars = 0;
	if (*f == 'c' && ++chars)
		ft_putchar_fd((char) va_arg(params, int), 1);
	else if ((*f == 'd' || *f == 'i') && ++f)
		chars += ft_putnbrc_fd((int) va_arg(params, int), 1, 0);
	else if (*f == 'u' && ++f)
		chars += ft_unbrc_fd((unsigned int) va_arg(params, unsigned int), 1, 0);
	else if (*f == '%' && ++chars && ++f)
		ft_putchar_fd('%', 1);
	else if (*f == 'p' && ++f && ++chars && ++chars && ft_putstr_fd("0x", 1))
		chars += ft_puthex_fd((size_t) va_arg(params, size_t), 1, 0);
	else if (*f == 'x' && ++f)
		chars += ft_puthex_fd((size_t) va_arg(params, size_t), 1, 0);
	else if (*f == 'X' && ++f)
		chars += ft_puthexup_fd((size_t) va_arg(params, size_t), 1, 0);
	return (chars);
}

int	ft_printf(const char	*f, ...)
{
	va_list			params;
	char			c;
	int				chars;

	va_start(params, f);
	c = *f;
	chars = 0;
	while (*f)
	{
		c = *f;
		f++;
		if (c != '%')
		{
			ft_putchar_fd(c, 1);
			chars++;
			continue ;
		}
		chars += handle_flag(f++, params);
	}
	return (chars);
}

// int main(int argc, char const *argv[])
// {
// 	char *s = malloc(1);
// 	printf("%d\n", ft_printf("%u\n", -1324));
// 	printf("%d\n", printf("%u\n", -1324));
// 	free(s);
// 	return 0;
// }