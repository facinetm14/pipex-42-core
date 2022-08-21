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

void	free_my_pipe(t_pipe my_pipe, int argc)
{
	int i;
	int j;

	i = 0;
	while (i < argc - 3)
	{
		j = 0;
		while (my_pipe.cmds[i].options[j])
		{
			free(my_pipe.cmds[i].options[j]);
			j++;
		}
		free(my_pipe.cmds[i].bin_path);
		free(my_pipe.cmds[i].options);
		i++;
	}
}

void	ft_exit_prog(t_pipe my_pipe, int argc)
{
	free_my_pipe(my_pipe, argc);
	exit(0);
}
