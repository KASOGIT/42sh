/*
** ctrl_a.c for mysh in /home/benjamin/rendu/C/PSU/PSU_2014_42sh/src/termcap
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Thu Apr 30 16:28:04 2015 Benjamin Rascol
** Last update Fri May 22 13:28:22 2015 Benjamin Rascol
*/

#include "42sh.h"

int	ctrl_a(char **command_buffer, int *i_buffer)
{
  *i_buffer = 0;
  if (termcap_cursor_placing(*command_buffer, *i_buffer) == ERROR_MYSH)
    return (ERROR_MYSH);
  return (SUCCESS);
}
