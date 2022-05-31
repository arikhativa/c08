/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:54:47 by yrabby            #+#    #+#             */
/*   Updated: 2022/05/31 16:53:08 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_stock_str.h"

#define ERROR	-1
#define SUCCESS	0

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

int	create_struct(struct s_stock_str *ret, char *s)
{
	int	i;

	i = 0;
	ret->size = ft_strlen(s);
	ret->str = s;
	ret->copy = (char *)malloc(sizeof(char) * (ret->size + 1));
	if (!ret->copy)
		return (ERROR);
	while (i < ret->size)
	{
		ret->copy[i] = s[i];
		++i;
	}
	ret->copy[i] = 0;
	return (SUCCESS);
}

void	free_all(struct s_stock_str *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(arr[i].copy);
		++i;
	}
	free(arr);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*ret;
	int					i;
	int					stt;

	ret = (struct s_stock_str *)malloc(sizeof(struct s_stock_str *) * (ac + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		stt = create_struct(&(ret[i]), av[i]);
		if (stt == ERROR)
		{
			free_all(ret, i);
			return (NULL);
		}
		++i;
	}
	ret->size = 0;
	ret->str = NULL;
	ret->copy = NULL;
	return (ret);
}
