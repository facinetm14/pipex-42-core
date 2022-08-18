/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 01:15:41 by fakouyat          #+#    #+#             */
/*   Updated: 2022/08/18 01:15:41 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void    ft_parent_process(t_pipe my_pipe)
{
    close(my_pipe.fd_args[0]);
    close(my_pipe.fd_args[1]);
    close(my_pipe.fd[0]);
    close(my_pipe.fd[1]);
    waitpid(my_pipe.child, &(my_pipe.status), 0);
}