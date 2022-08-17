/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:15:05 by fakouyat          #+#    #+#             */
/*   Updated: 2022/08/16 13:15:05 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libs/ft_printf/ft_printf.h"
# include "libs/gnl/get_next_line.h"
# include "libs/libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

typedef struct s_cmd
{
	char 	*bin_path;
	char	**options;
}			t_cmd;
typedef struct s_pipe
{
    int		fd[2];
    t_cmd	cmds[2];
}               t_pipe;
/* check_input.c */
int	ft_valid_nb_args(int argc);
int	ft_valid_args(char **argv, char **envp, t_pipe *my_pipe);

/* utils.c */
char    *ft_get_path(char **envp);
void    ft_parse(t_pipe *my_pipe, char  **paths, int *status);

#endif
