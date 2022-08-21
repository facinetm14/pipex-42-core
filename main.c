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
	my_pipe.nb_cmds = argc - 3;
	my_pipe.counter = 0;
	if (ft_valid_nb_args(argc) == 0)
		exit(0);
	if (ft_valid_args(argv, envp, &my_pipe, argc) == 0)
		ft_exit_prog(my_pipe, argc);
	if (pipe(my_pipe.fd[0]) < 0)
		exit(0);
	my_pipe.nb_cmds -= 2;
	my_pipe.child = fork();
	if (my_pipe.child != 0)
		ft_parent_process(my_pipe, argc);
	else if (my_pipe.child == 0)
	{
		my_pipe.child = fork();
		if (my_pipe.child != 0)
			ft_exec_cmd_n(&my_pipe, argv, envp);
		else
			ft_exec_cmd_1(my_pipe, argv[1], envp);
	}
	return (0);
}
