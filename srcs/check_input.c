/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:31:45 by fakouyat          #+#    #+#             */
/*   Updated: 2022/08/16 13:31:45 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_valid_nb_args(int argc)
{
	if (argc != 5)
	{
		ft_printf("Error : few arguments\n");
		return (0);
	}
	return (1);
}

int	ft_valid_args(char **argv, char **envp, t_pipe *my_pipe)
{
	char	*dirs_path;
	char	**paths;

	if (access(argv[1], F_OK | R_OK) != 0)
		my_pipe->error[0] = strerror(errno);
	dirs_path = ft_get_path(envp);
	paths = ft_split(&dirs_path[5], ':');
	my_pipe->cmds[0].options = ft_split(argv[2], ' ');
	my_pipe->cmds[1].options = ft_split(argv[3], ' ');
	ft_parse(my_pipe, paths, 0);
	ft_parse(my_pipe, paths, 1);
	free(paths);
	if (status >= 2)
		return (1);
	perror("Error");
	return (0);
}
