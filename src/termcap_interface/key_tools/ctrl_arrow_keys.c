/*
** ctrl_arrow_keys.c for mysh in /home/benjamin/rendu/C/PSU/PSU_2014_42sh
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Wed May 13 17:01:13 2015 Benjamin Rascol
** Last update Sun May 24 08:16:15 2015 adam soto
*/

#include "42sh.h"

int	ctrl_key_right(char **command_buffer, int *i_buffer)
{
  int	i;
  int	nb_move;

  i = *i_buffer;
  nb_move = 0;
  while ((*command_buffer)[i] == ' ' || (*command_buffer)[i] == '\t')
    {
      nb_move++;
      i++;
    }
  while ((*command_buffer)[i] != '\0'
	 && (*command_buffer)[i] != ' '
	 && (*command_buffer)[i] != '\t')
    {
      nb_move++;
      i++;
    }
  while (nb_move)
    {
      if (fkey_right(command_buffer, i_buffer) == ERROR_MYSH)
	return (ERROR_MYSH);
      nb_move--;
    }
  return (SUCCESS);
}

int	ctrl_key_left(char **command_buffer, int *i_buffer)
{
  int	i;
  int	nb_move;

  i = *i_buffer;
  nb_move = 0;
  while (i - 1 > 0 && ((*command_buffer)[i - 1] == ' '
		       || (*command_buffer)[i - 1] == '\t'))
    {
      nb_move++;
      i--;
    }
  while (i > 0
	 && (*command_buffer)[i - 1] != ' '
	 && (*command_buffer)[i - 1] != '\t')
    {
      nb_move++;
      i--;
    }
  while (nb_move)
    {
      if (fkey_left(command_buffer, i_buffer) == ERROR_MYSH)
	return (ERROR_MYSH);
      nb_move--;
    }
  return (SUCCESS);
}
