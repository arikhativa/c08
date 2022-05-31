/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:37:00 by yrabby            #+#    #+#             */
/*   Updated: 2022/05/31 16:41:45 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_stock_str.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while (*s)
	{
		ft_putchar(*s);
		++s;
	}
}

void	rec(long n)
{
	if (n / 10)
	{
		rec(n / 10);
		rec(n % 10);
	}
	if (n < 10)
		ft_putchar(n + '0');
}

void	ft_putnbr(int nb)
{
	long	n;

	n = (long)nb;
	if (n < 0)
	{
		n = n * -1;
		write(1, "-", 1);
	}
	rec(n);
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (*par)
	{
		ft_putstr(par->str);
		ft_putchar('\n');
		ft_putnbr(par->size);
		ft_putchar('\n');
		ft_putstr(par->copy);
		ft_putchar('\n');
		++par;
	}
}
