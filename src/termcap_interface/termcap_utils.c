/*
** termcap_initialisation.c for mysh in /home/benjamin/rendu/C/PSU/PSU_2014_42sh
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Fri May  1 14:00:25 2015 Benjamin Rascol
** Last update Wed May 20 13:44:19 2015 Benjamin Rascol
*/

#include "42sh.h"

int	termcap_putchar(int c)
{
  return (write(1, &c, 1));
}

int	termcap_set_mode(struct termios *data)
{
  if (tcsetattr(1, 0, data) == -1)
    return (ERROR_MYSH);
  return (SUCCESS);
}

int	termcap_move_cursor(char *str_data, int nb_loop)
{
  int	i;

  if (str_data == NULL)
    return (ERROR_MYSH);
  i = 0;
  while (i < nb_loop)
    {
      if (tputs(str_data, 1, termcap_putchar) == -1)
	return (ERROR_MYSH);
      i++;
    }
  return (SUCCESS);
}

int	termcap_clear()
{
  char	*str;

  if ((str = tgetstr("cl", NULL)) == NULL)
    return (ERROR_MYSH);
  if (tputs(str, 0, termcap_putchar) == -1)
    return (ERROR_MYSH);
  return (SUCCESS);
}

t_winsize		*termcap_get_win_size(char instruction)
{
  static t_winsize	data;
  struct winsize	w;

  if (instruction == LOAD_SIZE)
    {
      if (ioctl(1, TIOCGWINSZ, &w) == -1)
	{
	  my_putstr("Error : ioctl Failed.\"get_win_size()\".\n");
	  return (NULL);
	}
      data.x = w.ws_col;
      data.y = w.ws_row;
    }
  return (&data);
}
