/*
** ctrl_l.c for mysh in /home/benjamin/rendu/C/PSU/PSU_2014_42sh
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Wed May 13 16:56:48 2015 Benjamin Rascol
** Last update Wed May 20 15:50:54 2015 Benjamin Rascol
*/

#include "42sh.h"

int	ctrl_l(char **command_buffer, int *i_buffer)
{
  if (termcap_clear() == ERROR_MYSH)
    return (ERROR_MYSH);
  display_prompt();
  my_putstr(*command_buffer);
  my_putchar(' ');
  termcap_move_cursor(MOVE_LEFT, 1);
  termcap_cursor_placing(*command_buffer, *i_buffer);
  return (SUCCESS);
}
