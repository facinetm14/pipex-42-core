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
	if (argc < 5)
	{
		ft_printf("Error : few arguments\n");
		return (0);
	}
	return (1);
}

void	ft_check_files(t_pipe *my_pipe, char *argv[])
{
	ft_bzero(my_pipe->error[0], 100);
	ft_bzero(my_pipe->error[1], 100);
	if (access(argv[1], F_OK | R_OK) != 0)
	{
		ft_strcat(my_pipe->error[0], strerror(errno));
		ft_strcat(my_pipe->error[0], " : ");
		ft_strcat(my_pipe->error[0], argv[1]);
	}
	if (access(argv[4], F_OK) == 0)
	{
		my_pipe->fd_args[1] = open(argv[4], O_RDWR, 00700);
		if (my_pipe->fd_args[1] < 0)
			ft_put_error_outfile(my_pipe, argv[4], strerror(errno));
		else
			close(my_pipe->fd_args[1]);
	}
	else if (ft_strchr(argv[4], '/'))
		ft_put_error_outfile(my_pipe, argv[4], strerror(errno));
}

int	ft_valid_args(char **argv, char **envp, t_pipe *my_pipe, int argc)
{
	char	*dirs_path;
	char	**paths;

	ft_check_files(my_pipe, argv);
	dirs_path = ft_get_path(envp);
	paths = ft_split(&dirs_path[5], ':');
	ft_parse_all_cmds(paths, argv, my_pipe, argc);
	free(paths);
	if (my_pipe->error[0][0] == 0 && my_pipe->error[1][0] == 0)
		return (1);
	if (my_pipe->error[0][0] != 0)
		ft_printf("%s\n", my_pipe->error[0]);
	if (my_pipe->error[1][0] != 0)
		ft_printf("%s\n", my_pipe->error[1]);
	return (0);
}

void	ft_check_full_cmd_path(t_pipe *my_pipe, char **tmp, int cmd)
{
	char	**tmp_cmd;
	int		i;

	if (ft_strchr(my_pipe->cmds[cmd].options[0], '/'))
	{
		tmp_cmd = ft_split(my_pipe->cmds[cmd].options[0], '/');
		i = 0;
		while (tmp_cmd[i])
		{
			i++;
		}
		my_pipe->cmds[cmd].bin_path = ft_strdup(my_pipe->cmds[cmd].options[0]);
		free(my_pipe->cmds[cmd].options[0]);
		my_pipe->cmds[cmd].options[0] = ft_strdup(tmp_cmd[i -1]);
		while (tmp_cmd[i])
		{
			free(tmp_cmd[i]);
			i++;
		}
		free(tmp_cmd);
	}
	if (access(my_pipe->cmds[cmd].bin_path, X_OK) == 0)
		*tmp = "OK";
}
