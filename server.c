/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:02:57 by tfinni            #+#    #+#             */
/*   Updated: 2023/04/28 16:08:26 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_print_list(t_save *save)
{
	t_save		*temp;
	static int	counter;

	temp = save;
	while (temp->previous != NULL)
		temp = temp->previous;
	while (temp->next != NULL)
	{
		ft_printf("%s", temp->data);
		ft_bzero(temp->data, ft_strlen(temp->data));
		free(temp->data);
		temp->data = NULL;
		temp->previous = NULL;
		temp = temp->next;
		free(temp->previous);
	}
	ft_printf("%s", temp->data);
	ft_bzero(temp->data, ft_strlen(temp->data));
	free(temp->data);
	temp->previous = NULL;
	temp->data = NULL;
	free(temp);
	write(1, "\n", 1);
	counter++;
}

static int	ft_to_str(int base, int flag, int start)
{
	static t_save	*save;

	if (start == 0)
		save = do_result(save, base, 1);
	else if (flag == 1)
		save = do_result(save, base, 0);
	else if (flag == 0)
	{
		if (save->previous != NULL)
			ft_print_list(save);
		else
		{
			ft_printf("%s", save->data);
			ft_bzero(save->data, ft_strlen(save->data));
			free(save->data);
			save->data = NULL;
			free(save);
			save = NULL;
			write(1, "\n", 1);
		}
	}
	return (0);
}

static void	ft_sighandler(int signal)
{
	static int	place;
	static int	base;
	static int	counter;
	static int	start;

	if (signal == SIGUSR1)
		base |= (1 << place);
	else
		counter++;
	place++;
	if (counter == 8 && place == 8)
	{
		start = ft_to_str(base, 0, start);
		counter = 0;
		place = 0;
		base = 0;
	}
	if (place == 8)
	{
		ft_to_str(base, 1, start++);
		place = 0;
		base = 0;
		counter = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	signal(SIGUSR1, ft_sighandler);
	signal(SIGUSR2, ft_sighandler);
	while (1)
		pause();
	return (0);
}
