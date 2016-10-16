/*
** backspace.c for mysh in /home/benjamin/rendu/C/PSU/PSU_2014_42sh
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Wed May  6 15:13:37 2015 Benjamin Rascol
** Last update Thu May 21 22:39:32 2015 Benjamin Rascol
*/

#include "42sh.h"

int		backspace(char **command_buffer, int *i_buffer)
{
  char		*str;

  if (*i_buffer > 0)
    {
      termcap_move_cursor(MOVE_LEFT, 1);
      if ((int)strlen(*command_buffer) != *i_buffer)
	my_putstr(&(*command_buffer)[*i_buffer]);
      if ((str = tgetstr("ce", NULL)) == NULL)
	return (ERROR_MYSH);
      if (termcap_move_cursor(str, 1) == ERROR_MYSH)
	return (ERROR_MYSH);
      *i_buffer -= 1;
      my_putstr("  ");
      termcap_cursor_placing(*command_buffer, *i_buffer);
      (*command_buffer)[*i_buffer] = '\0';
      if ((int)strlen(*command_buffer) != *i_buffer - 1)
	strncat(*command_buffer, &(*command_buffer)[*i_buffer + 1],
		   strlen(&(*command_buffer)[*i_buffer + 1]));
    }
  return (SUCCESS);
}
