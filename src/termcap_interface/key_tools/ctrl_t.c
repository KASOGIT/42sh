/*
** ctrl_t.c for mysh in /home/benjamin/rendu/C/PSU/PSU_2014_42sh
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Sat May 16 02:25:07 2015 Benjamin Rascol
** Last update Wed May 20 14:40:13 2015 Benjamin Rascol
*/

#include "42sh.h"

int	ctrl_t(char **command_buffer, int *i_buffer)
{
  char	c;

  if (*i_buffer == 0 || strlen(*command_buffer) <= 1)
    return (SUCCESS);
  if ((int)strlen(*command_buffer) != *i_buffer)
    {
      c = (*command_buffer)[*i_buffer];
      (*command_buffer)[*i_buffer] = (*command_buffer)[*i_buffer - 1];
      (*command_buffer)[*i_buffer - 1] = c;
    }
  else if (*i_buffer > 1)
    {
      c = (*command_buffer)[*i_buffer - 1];
      (*command_buffer)[*i_buffer - 1] = (*command_buffer)[*i_buffer - 2];
      (*command_buffer)[*i_buffer - 2] = c;
    }
  if ((int)strlen(*command_buffer) == *i_buffer)
    fkey_left(command_buffer, i_buffer);
  fkey_left(command_buffer, i_buffer);
  my_putstr(&(*command_buffer)[*i_buffer]);
  if ((int)strlen(*command_buffer) == *i_buffer)
    *i_buffer += 1;
  *i_buffer += 2;
  termcap_cursor_placing(*command_buffer, *i_buffer);
  return (SUCCESS);
}
