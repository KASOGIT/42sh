/*
** del.c for mysh in /home/benjamin/rendu/C/PSU/PSU_2014_42sh
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Wed May  6 15:16:44 2015 Benjamin Rascol
** Last update Wed May 20 14:58:48 2015 Benjamin Rascol
*/

#include "42sh.h"

int	del(char **command_buffer, int *i_buffer)
{
  char	*str;

  if (*i_buffer < (int)strlen(*command_buffer))
    {
      (*command_buffer)[*i_buffer] = '\0';
      if ((int)strlen(*command_buffer) != *i_buffer - 1)
	strncat(*command_buffer, &(*command_buffer)[*i_buffer + 1],
		(int)strlen(&(*command_buffer)[*i_buffer + 1]));
      if ((str = tgetstr("cd", NULL)) == NULL
	  || termcap_move_cursor(str, 1) == ERROR_MYSH)
	return (ERROR_MYSH);
      my_putstr(&(*command_buffer)[*i_buffer]);
      my_putstr(" ");
      termcap_move_cursor(MOVE_LEFT, 1);
      if (termcap_cursor_placing(*command_buffer, *i_buffer) == ERROR_MYSH)
	return (ERROR_MYSH);
    }
  return (SUCCESS);
}
