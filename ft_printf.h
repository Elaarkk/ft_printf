/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:04:45 by acolonne          #+#    #+#             */
/*   Updated: 2024/11/29 20:05:17 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);

char	*ft_itoa_ptr(unsigned long long n);

int		ft_itoa_printf(long n);

int		ft_itoa_hexa(unsigned int n, int x);

void	ft_putchar_fd(char c, int fd);

void	ft_putstr_fd(char *s, int fd);

size_t	ft_strlen(const char *s);

#endif
