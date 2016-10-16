/*
** command_concat.c for 42sh in /home/benjamin/rendu/C/PSU/PSU_2014_42sh
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Thu May 21 14:08:57 2015 Benjamin Rascol
** Last update Fri May 22 08:17:25 2015 Benjamin Rascol
*/

#include "42sh.h"

int	command_concat(char **command, char *to_concat, int *cursor_pos)
{
  char	*tmp;
  int	command_len;
  int	to_concat_len;

  command_len = (*command != NULL) ? ((int)strlen(*command)) : (0);
  to_concat_len = (int)strlen(to_concat);
  if ((*command = realloc(*command, command_len + to_concat_len + 1)) == NULL)
    return (ERROR_MYSH);
  (*command)[command_len] = '\0';
  if (command_len != *cursor_pos)
    {
      tmp = strdup(&(*command)[*cursor_pos]);
      if (tmp == NULL)
	return (ERROR_MYSH);
      (*command)[*cursor_pos] = '\0';
    }
  strcat(*command, to_concat);
  if (command_len != *cursor_pos)
    {
      strcat(*command, tmp);
      free(tmp);
    }
  *cursor_pos += to_concat_len;
  return (SUCCESS);
}
