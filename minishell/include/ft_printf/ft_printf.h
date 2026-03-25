/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkpg-md- <dkpg-md-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:55:29 by dkpg-md-          #+#    #+#             */
/*   Updated: 2025/07/03 19:44:24 by dkpg-md-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		f_specifier(char c);
void	handle_fs(int *count, char spec, va_list args);
int		ft_printf(const char *format, ...);

void	ff_putchar(int *count, char c);
void	ff_putstr(int *count, char *s);
void	ff_putnbr_base(int *count, unsigned long long nbr, const char *base);

void	ff_putnbr(int *count, int nb);
void	ff_putnbr2(int *count, unsigned int nb);
void	h_int(int *count, va_list args);
void	h_unint(int *count, va_list args);

void	h_char(int *count, va_list args);
void	h_str(int *count, va_list args);
void	h_ptr(int *count, va_list args);

void	h_hexd(int *count, va_list args);
void	h_hexu(int *count, va_list args);

#endif
