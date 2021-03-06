/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 10:02:26 by curquiza          #+#    #+#             */
/*   Updated: 2017/05/27 23:56:13 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# define CMD_FAILURE 1
# define CMD_SUCCESS 0

# include "struct.h"

enum	e_cmd_search
{
	ISDIR = 1,
	NOSUCHFILE = 2,
	NOTFOUND = 3,
	NOPERM = 4,
	FOUND = 5
};

/*
** execution.c
*/

int					ft_execution(t_ast *ast);
void				ft_cmd_line_execution(t_ast **ast, t_shell *shell);

/*
** exec_apply_ctrl_op.c
*/

int					ft_apply_semic(t_ast *ast);
int					ft_right_pipe(int pfd[2], int left, t_ast *ast_right);
int					ft_apply_pipe(t_ast *ast);
int					ft_apply_d_pipe(t_ast *ast);
int					ft_apply_d_and(t_ast *ast);

/*
** exec_simple_cmd.c
*/

int					ft_get_cmdret(int status);
int					ft_exec_simple_cmd(t_ast *ast);
int					ft_fork_and_exec(t_ast *ast);

/*
** exec_error_msg.c
*/

void				ft_put_errmsg(char *bin, char *s, char *msg);
int					ft_putmsg_cmderr(char *cmd, enum e_cmd_search ret);

/*
** exec_cmd.c
*/

enum e_cmd_search	ft_check_cmd_slash(t_ast *ast);
char				**ft_get_pathtab(t_shell *shell);
enum e_cmd_search	ft_check_path(char *cmd);
enum e_cmd_search	ft_check_cmd_noslash(t_ast *ast);
int					ft_do_cmd(t_ast *ast);

/*
** exec_redirection.c
*/

int					ft_connect_fd(char *output, int to, int from);
int					ft_create_file(enum e_op op, char *output);
int					ft_is_uns_nbr(char *s);
int					ft_apply_fd_aggr(t_redir *redir);
int					ft_apply_hdoc(t_redir *redir);
int					ft_do_redirection(t_redir *redir);

/*
** exec_ass_word.c
*/

void				ft_add_assword_var(char *assword, t_shell *shell, int mode);
void				ft_do_ass_word(t_ast *ast, int mode);

#endif
