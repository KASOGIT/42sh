/*
** ctrl_i.c for mysh in /home/benjamin/rendu/C/PSU/PSU_2014_42sh
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Fri May 15 18:55:06 2015 Benjamin Rascol
** Last update Fri May 22 13:32:57 2015 Benjamin Rascol
*/

#include "42sh.h"

int	ctrl_i(char **command_buffer, int *i_buffer)
{
  if (*i_buffer == 0)
    {
      command_concat(command_buffer, "ls", i_buffer);
      return (END_OF_COMMAND);
    }
  return (SUCCESS);
}
