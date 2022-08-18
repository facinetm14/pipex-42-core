/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 22:43:32 by fakouyat          #+#    #+#             */
/*   Updated: 2022/08/15 22:43:32 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
    t_pipe	my_pipe;

    my_pipe.fd_args[0] = 0;
    my_pipe.fd_args[1] = 0;
    if (ft_valid_nb_args(argc) == 0)
        exit(0);
    if (ft_valid_args(argv, envp, &my_pipe) == 0)
        exit(-1);
    if ((my_pipe.id = pipe(my_pipe.fd) < 0))
        exit(0);
    my_pipe.child = fork();
    if ( my_pipe.child != 0)
        ft_parent_process(my_pipe);
    else if (my_pipe.child == 0)
    {
        my_pipe.child = fork();
        if (my_pipe.child != 0)
        {
            waitpid(my_pipe.child, &(my_pipe.status), 0);
            my_pipe.fd_args[1] = open(argv[4], O_CREAT | O_RDWR, 00700);
            dup2(my_pipe.fd[0], 0);
            dup2(my_pipe.fd_args[1], 1);
            close(my_pipe.fd[0]);
            close(my_pipe.fd[1]);
            execve(my_pipe.cmds[1].bin_path, my_pipe.cmds[1].options, envp);
        }
        else
			ft_exec_cmd_1(my_pipe, argv[1], envp);
    }
    return (0);
}