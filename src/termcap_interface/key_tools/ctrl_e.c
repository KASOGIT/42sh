/*
** ctrl_e.c for mysh in /home/benjamin/rendu/C/PSU/PSU_2014_42sh
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Wed May  6 15:19:26 2015 Benjamin Rascol
** Last update Wed May 20 14:42:27 2015 Benjamin Rascol
*/

#include "42sh.h"

int	ctrl_e(char **command_buffer, int *i_buffer)
{
  my_putstr(&(*command_buffer)[*i_buffer]);
  *i_buffer = (int)strlen(*command_buffer);
  return (SUCCESS);
}
