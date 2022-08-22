/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_last_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 02:27:18 by fakouyat          #+#    #+#             */
/*   Updated: 2022/08/18 02:27:18 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_exec_cmd_n(t_pipe *my_pipe, char *argv[], char *envp[])
{
	int	curr;

	waitpid(my_pipe->child, &(my_pipe->status), 0);
	curr = my_pipe->counter + 1;
	if (my_pipe->nb_cmds > 0)
		exit(0);
	else
	{
		my_pipe->fd_args[1] = open(argv[4], O_CREAT | O_RDWR, 00700);
		dup2(my_pipe->fd[curr - 1][0], 0);
		dup2(my_pipe->fd_args[1], 1);
		close(my_pipe->fd[curr - 1][0]);
		close(my_pipe->fd[curr - 1][1]);
		execve(my_pipe->cmds[curr].bin_path, my_pipe->cmds[curr].options, envp);
	}
}
