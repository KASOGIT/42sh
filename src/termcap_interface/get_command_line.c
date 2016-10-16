/*
** get_command_line.c for mysh in /home/benjamin/rendu/C/PSU/PSU_2014_42sh
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Sun May 17 18:15:14 2015 Benjamin Rascol
** Last update Fri May 22 18:42:00 2015 Benjamin Rascol
*/

#include "42sh.h"

static int	spe_strlen(char *str)
{
  int		i;

  i = 0;
  if (str != NULL)
    while (str[i])
      i++;
  return (i);
}

static int	concat_and_display(char **command_buffer,
				   int *i_buffer, char *str)
{
  if (command_concat(command_buffer, str, i_buffer) == ERROR_MYSH)
    return (ERROR_MYSH);
  my_putstr(str);
  if ((int)strlen(*command_buffer) != *i_buffer)
    {
      my_putstr(&(*command_buffer)[*i_buffer]);
      my_putchar(' ');
      termcap_move_cursor(MOVE_LEFT, 1);
      termcap_cursor_placing(*command_buffer, *i_buffer);
    }
  else
    {
      my_putchar(' ');
      termcap_move_cursor(MOVE_LEFT, 1);
    }
  return (SUCCESS);
}

static char	*end_of_line_manager(char *command_buffer,
				     int i_buffer, char *str)
{
  free(str);
  if (strlen(command_buffer) == 0)
    return (NULL);
  else
    {
      my_putstr(&command_buffer[i_buffer]);
      return (command_buffer);
    }
  return (NULL);
}

char	*get_command_line(const int fd)
{
  char	*str;
  char	*command_buffer;
  int	ret;
  int	i_buffer;

  i_buffer = 0;
  if ((command_buffer = malloc(sizeof(char) * 1)) == NULL)
    return (NULL);
  command_buffer[i_buffer] = '\0';
  while (spe_strlen((str = get_next_line(fd))) > 0)
    {
      ret = get_and_apply_key(&command_buffer, str, &i_buffer);
      if (ret == NO_KEY_FOUND)
	{
	  if (concat_and_display(&command_buffer, &i_buffer, str)
	      == ERROR_MYSH)
	    return (NULL);
	}
      else if (ret == END_OF_COMMAND)
	return (end_of_line_manager(command_buffer, i_buffer, str));
      free(str);
    }
  return (command_buffer);
}
