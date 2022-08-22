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
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>

typedef struct s_cmd
{
	char	*bin_path;
	char	**options;
}			t_cmd;
typedef struct s_pipe
{
	int		fd[2];
	t_cmd	cmds[2];
	int		fd_args[2];
	int		child;
	int		status;
	char	error[2][100];
}				t_pipe;
/* check_input.c */
int		ft_valid_nb_args(int argc);
int		ft_valid_args(char **argv, char **envp, t_pipe *my_pipe);
void	ft_check_files(t_pipe *my_pipe, char *argv[]);
void	ft_check_full_cmd_path(t_pipe *my_pipe, char **tmp, int cmd);
/* utils_2.c*/
void	free_my_pipe(t_pipe *my_pipe);
int		len_path(char **paths);
/* utils.c */
char	*ft_get_path(char **envp);
void	ft_parse(t_pipe *my_pipe, char **paths, int cmd, char **argv);
void	ft_put_error_outfile(t_pipe *my_pipe, char *outfile, char *error);
void	ft_set_cmd_error_msg(t_pipe *my_pipe, char **tmp, int cmd, char **argv);
/* parent.c */
void	ft_parent_process(t_pipe *my_pipe);
/* exec_first_cmd.c*/
void	ft_exec_cmd_1(t_pipe my_pipe, char *infile, char *envp[]);
/*exec_last_cmd.c*/
void	ft_exec_cmd_n(t_pipe *my_pipe, char *argv[], char *envp[]);
#endif
