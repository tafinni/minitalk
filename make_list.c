/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:11:18 by tfinni            #+#    #+#             */
/*   Updated: 2023/05/09 16:11:22 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_save	*do_new_list(t_save *save, int base, int size)
{
	save = malloc(sizeof(t_save));
	if (!save)
		return (NULL);
	save->data = NULL;
	save->data = ft_calloc(size, sizeof(char));
	if (!save->data)
		return (NULL);
	save->data[0] = base;
	save->data[1] = '\0';
	save->next = NULL;
	save->previous = NULL;
	return (save);
}

static t_save	*do_new_str(t_save *save, int base, int size)
{
	save->next = malloc(sizeof(t_save));
	if (!save->next)
		return (NULL);
	save->next->previous = save;
	save = save->next;
	save->next = NULL;
	save->data = ft_calloc(size, sizeof(char));
	if (!save->data)
		return (NULL);
	save->data[0] = base;
	save->next = NULL;
	return (save);
}

t_save	*do_result(t_save *save, int base, int flag)
{
	static int		counter;
	static int		size;
	int				i;

	i = 0;
	if (flag == 0)
	{
		if (counter == size - 1)
		{
			counter = 2;
			save = do_new_str(save, base, size);
		}
		else
			save->data[ft_strlen(save->data)] = base;
		counter++;
	}
	else if (flag == 1)
	{
		size = 1000;
		counter = 2;
		save = NULL;
		save = do_new_list(save, base, size);
	}
	return (save);
}
