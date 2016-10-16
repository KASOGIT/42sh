/*
** read_file_alias.c for  in /home/trambe_m/PSU_2014_42sh/src/manage_alias
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Tue May 19 18:00:36 2015 Manuel Trambert
** Last update Sun May 24 08:03:06 2015 adam soto
*/

#include "42sh.h"

static char	*split_to_equal(char *str)
{
  int		i;
  char		*tmp;

  i = 0;
  if ((tmp = malloc(sizeof(*tmp) * (strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[i] != '\0' && str[i] != '=')
    {
      tmp[i] = str[i];
      i += 1;
    }
  tmp[i] = '\0';
  return (tmp);
}

static char	*split_end(char *str)
{
  int		i;
  int		e;
  char		*tmp;

  i = strlen(str) - 1;
  e = 0;
  if ((tmp = malloc(sizeof(*tmp) * (strlen(str) + 1))) == NULL)
    return (NULL);
  while (i > 1 && str[i - 1] != '=')
    i -= 1;
  if (i == 0)
    return (NULL);
  while (str[i] != '\0')
    {
      tmp[e] = str[i];
      e += 1;
      i += 1;
    }
  tmp[e] = '\0';
  return (tmp);
}

int	add_list_alias(t_alia **alias, char *str)
{
  t_alia	*tmp;

  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    return (-1);
  if ((tmp->str = split_end(str)) == NULL)
    return (EXIT_FAILURE);
  if ((tmp->result = split_to_equal(str)) == NULL)
    return (EXIT_FAILURE);
  tmp->prev = (*alias)->prev;
  tmp->next = (*alias);
  (*alias)->prev->next = tmp;
  (*alias)->prev = tmp;
  return (0);
}

int		fill_file_alias()
{
  int		fd;
  char		*str;

  if ((fd = open("./.sotoshrc", O_CREAT | O_RDWR | O_APPEND,
		 g_info.mode)) == -1)
    return (EXIT_FAILURE);
  g_info.alias->next = g_info.alias;
  g_info.alias->prev = g_info.alias;
  g_info.alias->str = NULL;
  g_info.alias->result = NULL;
  if ((add_list_alias(&g_info.alias, "ll=ls -l")) == -1)
    return (-1);
  while ((str = get_next_line(fd)) != NULL)
    {
      if ((add_list_alias(&g_info.alias, str)) == -1)
	return (-1);
      free(str);
    }
  return (0);
}
