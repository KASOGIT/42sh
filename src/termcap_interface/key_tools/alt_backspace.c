/*
** alt_backspace.c for 42sh in /home/benjamin/rendu/C/PSU/PSU_2014_42sh
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Thu May 21 19:54:25 2015 Benjamin Rascol
** Last update Thu May 21 23:12:05 2015 Benjamin Rascol
*/

#include "42sh.h"

int	alt_backspace(char **command_buffer, int *i_buffer)
{
  char	*str;
  int	tmp;

  if (*i_buffer <= 0)
    return (SUCCESS);
  tmp = *i_buffer;
  ctrl_key_left(command_buffer, i_buffer);
  (*command_buffer)[tmp - 1] = '\0';
  (*command_buffer)[*i_buffer] = '\0';
  strcat(*command_buffer, &(*command_buffer)[tmp]);
  if ((str = tgetstr("ce", NULL)) == NULL)
    return (ERROR_MYSH);
  if (termcap_move_cursor(str, 1) == ERROR_MYSH)
    return (ERROR_MYSH);
  my_putstr(&(*command_buffer)[*i_buffer]);
  termcap_cursor_placing(*command_buffer, *i_buffer);
  return (SUCCESS);
}
