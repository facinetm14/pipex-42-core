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

void	ft_parse(t_pipe *my_pipe, char **paths, int *status)
{
	char	*tmp[2];
	int		i;

	i = 0;
	while (paths[i])
	{
		tmp[0] = ft_strjoin("/", my_pipe->cmds[0].options[0]);
		tmp[1] = ft_strjoin(paths[i], tmp[0]);
		if (access(tmp[1], X_OK) == 0 && *status == 0)
		{
			my_pipe->cmds[0].bin_path = ft_strdup(tmp[1]);
			*status = 1;
		}
		free(tmp[0]);
		free(tmp[1]);
		free(paths[i]);
		i++;
	}
	free(paths);
}
