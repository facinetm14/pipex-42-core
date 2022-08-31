/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_first_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 01:54:56 by fakouyat          #+#    #+#             */
/*   Updated: 2022/08/18 01:54:56 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_exec_cmd_1(t_pipe *p)
{
	p->fd_args[0] = open(p->av[1], O_RDONLY, 0777);
	dup2(p->fd_args[0], 0);
	dup2(p->fd[0][1], 1);
}

void	ft_exec_cmd_last(t_pipe *p)
{
	p->fd_args[1] = open(p->av[p->ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
	dup2(p->fd[p->child - 1][0], 0);
	dup2(p->fd_args[1], 1);
	close(p->fd_args[1]);
}

void	ft_close_fds(t_pipe *p)
{
	int	i;

	i = 0;
	while (i < p->nb_cmd - 1)
	{
		close(p->fd[i][0]);
		close(p->fd[i][1]);
		i++;
	}
}
