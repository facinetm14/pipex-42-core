/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:43:16 by fakouyat          #+#    #+#             */
/*   Updated: 2022/08/16 15:43:16 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_get_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", ft_strlen(envp[i]))
			&& (envp[i][0] == 'P'))
			return (envp[i]);
		i++;
	}
	return (NULL);
}

void	ft_set_cmd_error_msg(t_pipe *my_pipe, char *tmp, int cmd)
{
	if ((ft_strncmp(tmp, "OK", 2) != 0)
		&& (my_pipe->error[cmd][0] == 0))
	{
		ft_strcat(my_pipe->error[cmd], "command not found : ");
		ft_strcat(my_pipe->error[cmd], my_pipe->cmds[cmd].options[0]);
	}
}

void	ft_parse(t_pipe *my_pipe, char **paths, int cmd)
{
	char	*tmp[3];
	int		i;

	i = 0;
	tmp[2] = "";
	while (paths[i])
	{
		tmp[0] = ft_strjoin("/", my_pipe->cmds[cmd].options[0]);
		tmp[1] = ft_strjoin(paths[i], tmp[0]);
		if (access(tmp[1], X_OK) == 0)
		{
			my_pipe->cmds[cmd].bin_path = ft_strdup(tmp[1]);
			tmp[2] = "OK";
		}
		free(tmp[0]);
		free(tmp[1]);
		if (cmd > 0)
			free(paths[i]);
		i++;
	}
	ft_check_full_cmd_path(my_pipe, &tmp[2], cmd);
	ft_set_cmd_error_msg(my_pipe, tmp[2], cmd);
}

void	ft_put_error_outfile(t_pipe *my_pipe, char *outfile, char *error)
{
	ft_strcat(my_pipe->error[1], error);
	ft_strcat(my_pipe->error[1], " : ");
	ft_strcat(my_pipe->error[1], outfile);
}
