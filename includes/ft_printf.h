/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibosc <pibosc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:31:45 by pibosc            #+#    #+#             */
/*   Updated: 2023/11/14 20:31:10 by pibosc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# define HEX_BASE_LOW "0123456789abcdef"
# define HEX_BASE_UP "0123456789ABCDEF"

int	ft_putnbrc_fd(int n, int fd, int size);
int	ft_unbrc_fd(unsigned int n, int fd, int size);
int	ft_puthex_fd(size_t address, int fd, int size);
int	ft_puthexup_fd(size_t address, int fd, int size);

#endif