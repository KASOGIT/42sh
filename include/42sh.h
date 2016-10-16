/*
** 42sh.h for 42sh in /home/benjamin/rendu/C/PSU/tmp/PSU_2014_42sh
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Wed May 20 13:41:56 2015 Benjamin Rascol
** Last update Sun May 24 21:55:54 2015 adam soto
*/

#ifndef		_42SH_H_
# define	_42SH_h_

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<sys/wait.h>
#include	<glob.h>
#include	<ctype.h>
#include	"termcap_manager.h"
#include	"linked_list.h"
#include	"get_next_line.h"

# define ABS(nb)		(nb < 0 ? -nb : nb)
# define SIZE			4096
# define SUCCESS		0
# define ERROR_MYSH		-1
# define EXIT_MODE		-42
# define ANSI_COLOR_RED		"\x1b[31m"
# define ANSI_COLOR_GREEN	"\x1b[32m"
# define ANSI_COLOR_YELLOW	"\x1b[33m"
# define ANSI_COLOR_BLUE	"\x1b[34m"
# define ANSI_COLOR_MAGENTA	"\x1b[35m"
# define ANSI_COLOR_CYAN	"\x1b[36m"
# define ANSI_COLOR_RESET	"\x1b[0m"

typedef	struct	s_alia
{
  char		*str;
  char		*result;
  struct s_alia	*next;
  struct s_alia	*prev;
}		t_alia;

typedef struct	s_bracket
{
  int		count;
  int		i;
  int		a;
  int		boolean;
}		t_bracket;

typedef struct	s_tree
{
  char		*data;
  struct s_tree	*left;
  struct s_tree	*right;
}		t_tree;

typedef struct	s_info
{
  t_alia	*alias;
  t_list	*ev;
  t_tree	*tree;
  char		**op;
  int		nbr_cmd;
  int		state_multi;
  int		state_redir;
  int		val_exit;
  int		status;
  mode_t	mode;
  int		size_prompt;
}		t_info;

typedef struct	s_func_op
{
  int		id_op;
  int		(*func_op)();
}		t_func_op;

typedef struct	s_builtin
{
  char		*id;
  int		(*func_builtin)();
}		t_builtin;

typedef struct	s_exec
{
  int		i;
  int		j;
  int		count;
  int		comp;
  int		boolean;
}		t_exec;

extern	t_info	g_info;

int	only_space_tab(char *user_input);
int	str_is_printable(unsigned char *str);
char	*unconcat_str(char *str);
int	get_pos_star(char **array);
char	*add_star(char *str, int where);
char	*concat_path_to_str(char *str, char *path);
char    **get_tab_path(t_list *ev);
int	check_star(char *str);
void	my_putstr(char *str);
char	*search_in_history(char *str);
char	*concat_str(char *start, char *end);
int	isnum(char *str);
int	builtin_history(char **tab_input);
void	my_free_list_hist(t_hist_list **ptr);
int	count_word(char *str);
char	**get_history_command(char **tab_input);
int	act_on_user_input_and_run_act(char *user_input, int *boolean);
void	my_free_alias(t_alia **alias);
int	add_list_alias(t_alia **alias, char *str);
int	builtin_alias(char **tab_input);
char	**get_alias(t_alia *alias, char **array);
int	fill_file_alias();
void	handle_sev();
int	wait_pid_and_sev(pid_t pid);
char	**get_glob(char **tab_input);
int	wait_user_input_and_init_action();
char	*search_on_env(t_list *ev, char *search);
char	*search_varenv_and_replace(char *user_input);
int	size_tab(char **array);
char	*get_next_line(int fd);
void	my_put_nbr(int nb);
void	my_putchar(char c);
void	my_putstr(char *str);
int	my_getnbr(char *str);
int	error_env(char *name_env);
int	file_error_redir();
int	kill_set_and_put_error_redir();
int	kill_proc_and_set_status();
char	*my_strcat(char *dest, char *add);
char	*my_strcat_alloc(char *dest, char *src);
void	my_putstr_color(char *str, char *color);
char	*strcat_path(char *start_path, char *end_path);
char	**path_to_wordtab(char *str);
char	**str_to_wordtab(char *str);
char	*wordtab_to_str(char **array);
char	**list_to_wordtab(t_list **ev);
int	redir_reset_glob_and_set_status();
void	free_tab(char **array);
int	display_prompt();
void	free_binary(t_tree *tree);
int	eval_and_create_tree(t_tree **node, char *str);
int	is_backquote(char *str);
int	remove_backquote(char **str, char **op, int *pos_op_str);
int	is_bracket(char *str);
int	remove_bracket(char **str, char **op, int *pos_op_str);
int	get_pos_op(char **str, char **op, int *pos_op_str);
int	run_act_on_tree(char *input);
int	run_tree(t_tree **node);
int	exec_cmd_func(t_tree **node);
int	semicolon_func(t_tree **node);
int	and_func(t_tree **node);
int	or_func(t_tree **node);
int	pipe_func(t_tree **node);
int	double_right_func(t_tree **node);
int	right_func(t_tree **node);
int	double_left_func(t_tree **node);
int	left_func(t_tree **node);
int	count_nb_sep(char *str);
int	is_redir_first(char *str);
char	*put_exotic_in_order(char *str);
int	put_in_order_exotic_param(t_tree **node, char **tab_epur_name);
int	search_builtin_and_run(char **tab_input);
int	builtin_cd(char **tab_input);
int	builtin_exit(char **tab_input);
int	builtin_env(char **tab_input);
int	builtin_setenv(char **tab_input);
int	builtin_unsetenv(char **tab_input, int choice);
int	builtin_unalias(char **tab_input);
int	builtin_echo(char **tab_input);
int	putnchar(char c, int nb);

#endif	/* !_42SH_H_ */
