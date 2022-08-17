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

int main(int argc, char **argv, char **envp)
{
    t_pipe  my_pipe;
    int     pipe_id;
    int     child;
    int     status;

    if (ft_valid_nb_args(argc) == 0)
        exit(0);
    if (ft_valid_args(argv, envp, &my_pipe) == 0)
        exit(-1);
    pipe_id = pipe(my_pipe.fd);
    if (pipe_id < 0)
        exit(0);
    child = fork();
    if (child != 0)
        waitpid(child, &status, 0);
    else if (child == 0)
    {
        child = fork();
        if (child != 0)
        {
            waitpid(child, &status, 0);
            ft_printf("child\n");
        }
        else
        {
            close(my_pipe.fd[0]);
            execve(my_pipe.cmds[0].bin_path, my_pipe.cmds[0].options, envp);
        }
    }
    return (0);
}