/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfinni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:14:29 by tfinni            #+#    #+#             */
/*   Updated: 2023/04/27 15:14:34 by tfinni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <signal.h>

typedef struct s_save
{
	char			*data;
	struct s_save	*previous;
	struct s_save	*next;
}	t_save;

t_save	*do_result(t_save *save, int base, int flag);

#endif
