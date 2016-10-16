/*
** termcap.h for mysh in /home/benjamin/rendu/C/PSU/PSU_2014_42sh
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Mon Apr 27 13:45:34 2015 Benjamin Rascol
** Last update Sun May 24 15:28:05 2015 Manuel Trambert
*/

#ifndef			TERMCAP_H_
# define		TERMCAP_H_

# include		<sys/ioctl.h>
# include		<term.h>
# include		<termios.h>
# include		<curses.h>
# include		"linked_list.h"

# define SIZE			4096
# define BUFF_SIZE		4096
# define NO_KEY_FOUND		1
# define IGNORE_KEY		2
# define END_OF_COMMAND		3
# define END_OF_PROGRAM		4
# define LOAD_SIZE		5
# define GET_SIZE		6
# define MOVE_UP		tgetstr("up", NULL)
# define MOVE_LEFT		tgetstr("le", NULL)
# define MOVE_DOWN		tgetstr("do", NULL)
# define MOVE_RIGHT		tgetstr("nd", NULL)
# define MOVE_POS_X		tgetstr("ch", NULL)

typedef struct		s_hist_list
{
  char			*str;
  struct s_hist_list	*next;
  struct s_hist_list	*prev;
}			t_hist_list;

typedef struct		s_history
{
  int			fd_file_history;
  t_hist_list		*current;
  t_hist_list		*start;
}			t_history;

typedef struct		s_winsize
{
  int			x;
  int			y;
}			t_winsize;

typedef struct		s_termcap
{
  struct termios	edited_data;
  struct termios	default_data;
}			t_termcap;

# define KEY_SIZE	8

typedef struct		s_key
{
  char			key[KEY_SIZE];
  int			(*ptr)(char **command_buffer, int *i);
}			t_key;

extern t_history	g_history;

int			add_list_hist(t_history *history, char *str);
void			free_list_hist(t_hist_list **ptr);
t_winsize		*termcap_get_win_size(char instruction);
char			*get_next_line(const int fd);
char			*get_command_line(const int fd);
int			command_concat(char **command_buffer,
				       char *src, int *cursor_pos);
int			command_is_concatenable(char **command_buffer, char *str);
int			command_manager(t_list *ev);
int			termcap_set_mode(struct termios *data);
int			termcap_init(t_termcap *data, t_list *ev);
int			termcap_move_cursor(char *str_data, int nb_loop);
int			termcap_clear();
int			termcap_load_cursor_pos();
int			termcap_save_cursor_pos();
int			termcap_putchar(int c);
int			termcap_cursor_placing(char *command_buffer, int i);
int			prompt_display();
int			get_and_apply_key(char **command_buffer,
					  char *str, int *i_buffer);
int			ctrl_a(char **command_buffer, int *i_buffer);
int			ctrl_b(char **command_buffer, int *i_buffer);
int			ctrl_d(char **command_buffer, int *i_buffer);
int			ctrl_e(char **command_buffer, int *i_buffer);
int			ctrl_f(char **command_buffer, int *i_buffer);
int			ctrl_h(char **command_buffer, int *i_buffer);
int			ctrl_i(char **command_buffer, int *i_buffer);
int			ctrl_k(char **command_buffer, int *i_buffer);
int			ctrl_l(char **command_buffer, int *i_buffer);
int			ctrl_t(char **command_buffer, int *i_buffer);
int			ctrl_u(char **command_buffer, int *i_buffer);
int			ctrl_w(char **command_buffer, int *i_buffer);
int			ctrl_y(char **command_buffer, int *i_buffer);
int			fkey_right(char **command_buffer, int *i_buffer);
int			fkey_left(char **command_buffer, int *i_buffer);
int			fkey_down(char **command_buffer, int *i_buffer);
int			fkey_up(char **command_buffer, int *i_buffer);
int			ctrl_key_right(char **command_buffer, int *i_buffer);
int			ctrl_key_left(char **command_buffer, int *i_buffer);
int			backspace(char **command_buffer, int *i_buffer);
int			alt_backspace(char **command_buffer, int *i_buffer);
int			del(char **command_buffer, int *i_buffer);
int			alt_del(char **command_buffer, int *i_buffer);

/*
** Tabulation
*/

int			check_pos_curs(char *str, int i_buffer);
int			tabulation(char **command_buffer, int *i_buffer);
int			get_max_word_len(char **wordtab);
char			**get_bin_cmd(char **command_buffer, int i);
char			**get_current_match(char **str, int i);
char			**unconcat_path(char **cmd);
char			**tabulation_gen(char **command_buffer, int *i_buffer);

#endif			/* !TERMCAP_H_ */
