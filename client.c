/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:02:40 by tfinni            #+#    #+#             */
/*   Updated: 2023/04/28 16:07:01 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_end_str(int pid)
{
	int	counter;

	counter = 0;
	while (counter < 8)
	{
		kill(pid, SIGUSR2);
		counter++;
		usleep(100);
	}
}

static void	ft_send_str(char **argv, int pid)
{
	int		i;
	char	c;
	int		counter;

	i = 0;
	while (argv[2][i])
	{
		c = argv[2][i];
		counter = 0;
		while (counter < 8)
		{
			if ((c & (1 << counter)) != 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			counter++;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		counter;

	if (argc != 3)
		return (0);
	if (argc >= 1)
		pid = ft_atoi(argv[1]);
	if (argv[2][0] == '\0')
		return (0);
	ft_send_str(argv, pid);
	ft_end_str(pid);
	return (0);
}
