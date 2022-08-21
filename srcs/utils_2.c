/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 04:37:57 by fakouyat          #+#    #+#             */
/*   Updated: 2022/08/21 04:37:57 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_parse_all_cmds(char **paths, char **argv, t_pipe *my_pipe, int argc)
{
	int	i;
	int	j;

	i = 0;
	j = 2;
	while (i < argc - 3)
	{
		my_pipe->cmds[i].options = ft_split(argv[j], ' ');
		ft_parse(my_pipe, paths, i);
		i++;
		j++;
	}
}
