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

void    ft_exec_cmd_1(t_pipe my_pipe, char *infile, char *envp[])
{
    my_pipe.fd_args[0] = open(infile, O_RDONLY);
    dup2(my_pipe.fd_args[0], 0);
    dup2(my_pipe.fd[1], 1);
    close(my_pipe.fd[0]);
    close(my_pipe.fd[1]);
    execve(my_pipe.cmds[0].bin_path, my_pipe.cmds[0].options, envp);
}