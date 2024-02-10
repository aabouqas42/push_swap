/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:20:05 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/09 16:42:18 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	strlen_printf(const char *s);
int	putstr_printf(char *str);
int	putchar_printf(int c);
int	print_number_printf(int num);
int	base_printf(unsigned int num, char *base);
int	pointer_printf(unsigned long p);
int	unsigned_printf(unsigned int num);

#endif
