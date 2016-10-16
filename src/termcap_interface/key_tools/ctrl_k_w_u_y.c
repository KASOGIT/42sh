/*
** ctrl_k_w_y.c for mysh in /home/benjamin/rendu/C/PSU/PSU_2014_42sh
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Mon May  4 17:02:26 2015 Benjamin Rascol
** Last update Fri May 22 13:33:19 2015 Benjamin Rascol
*/

#include "42sh.h"

static char	*g_str = NULL;

int	ctrl_k(char **command_buffer, int *i_buffer)
{
  char	*str;

  if ((*command_buffer)[*i_buffer] == '\0')
    return (SUCCESS);
  if (g_str != NULL)
    free(g_str);
  g_str = strdup(&(*command_buffer)[*i_buffer]);
  (*command_buffer)[*i_buffer] = '\0';
  if ((str = tgetstr("cd", NULL)) == NULL
      || termcap_move_cursor(str, 1) == ERROR_MYSH)
    return (ERROR_MYSH);
  return (SUCCESS);
}

int	ctrl_w(char **command_buffer, int *i_buffer)
{
  char	*str;
  char	c;

  if (*i_buffer == 0)
    return (SUCCESS);
  if (g_str != NULL)
    free(g_str);
  if (termcap_cursor_placing(*command_buffer, *i_buffer) == ERROR_MYSH)
    return (ERROR_MYSH);
  c = (*command_buffer)[*i_buffer];
  (*command_buffer)[*i_buffer] = '\0';
  g_str = strdup(*command_buffer);
  (*command_buffer)[*i_buffer] = c;
  my_putstr(&(*command_buffer)[*i_buffer]);
  termcap_cursor_placing(*command_buffer, 0);
  (*command_buffer)[0] = '\0';
  strncat(*command_buffer, &(*command_buffer)[*i_buffer],
	     strlen(&(*command_buffer)[*i_buffer]));
  *i_buffer = 0;
  if ((str = tgetstr("cd", NULL)) == NULL
      || termcap_move_cursor(str, 1) == ERROR_MYSH)
    return (ERROR_MYSH);
  my_putstr(*command_buffer);
  termcap_cursor_placing(*command_buffer, *i_buffer);
  return (SUCCESS);
}

int	ctrl_u(char **command_buffer, int *i_buffer)
{
  char	*str;

  if (strlen(*command_buffer) != 0)
    {
      if (g_str != NULL)
	free(g_str);
      g_str = strdup(*command_buffer);
      my_putstr(&(*command_buffer)[*i_buffer]);
      if (termcap_cursor_placing(*command_buffer, 0) == ERROR_MYSH
	  || (str = tgetstr("cd", NULL)) == NULL
	  || termcap_move_cursor(str, 1) == ERROR_MYSH)
	return (ERROR_MYSH);
      *i_buffer = 0;
      (*command_buffer)[0] = '\0';
    }
  return (SUCCESS);
}

int	ctrl_y(char **command_buffer, int *i_buffer)
{
  if (g_str != NULL)
    {
      if (command_concat(command_buffer, g_str, i_buffer) == ERROR_MYSH)
	return (ERROR_MYSH);
      my_putstr(g_str);
      if ((int)strlen(*command_buffer) != *i_buffer)
	{
	  my_putstr(&(*command_buffer)[*i_buffer]);
	  my_putchar(' ');
	  termcap_move_cursor(MOVE_LEFT, 1);
	  termcap_cursor_placing(*command_buffer, *i_buffer);
	}
      else
	{
	  my_putchar(' ');
	  termcap_move_cursor(MOVE_LEFT, 1);
	}
    }
  return (SUCCESS);
}
