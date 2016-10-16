/*
** tabulation_fct.c for  in /home/trambe_m/PSU_2014_42sh/src/termcap_interface/key_tools
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Sun May 24 06:37:54 2015 Manuel Trambert
** Last update Sun May 24 06:40:43 2015 Manuel Trambert
*/

#include "42sh.h"

char	*unconcat_str(char *str)
{
  int	i;
  int	e;
  char	*tmp;

  i = strlen(str);
  e = 0;
  if ((tmp = malloc(sizeof(*tmp) * (strlen(str) + 1))) == NULL)
    return (NULL);
  while (i > 0 && str[i - 1] != '/')
    i -= 1;
  while (str[i] != '\0')
    {
      tmp[e] = str[i];
      e += 1;
      i += 1;
    }
  tmp[e] = '\0';
  free(str);
  return (tmp);
}

int	get_pos_star(char **array)
{
  int	i;

  i = 0;
  while (array[i] != NULL)
    {
      if (check_star(array[i]) == 1)
	return (i);
      i += 1;
    }
  return (0);
}

char	*add_star(char *str, int where)
{
  char	*tmp;
  int	e;
  int	i;

  i = 0;
  if ((tmp = malloc(sizeof(*tmp) * (strlen(str) + 2))) == NULL)
    return (NULL);
  while (i < where)
    {
      tmp[i] = str[i];
      i += 1;
    }
  e = i;
  tmp[i++] = '*';
  while (str[e] != '\0')
    {
      tmp[i] = str[e - 1];
      e += 1;
    }
  tmp[i] = '\0';
  return (tmp);
}

char	*concat_path_to_str(char *str, char *path)
{
  char	*tmp;
  int	i;
  int	e;

  i = 0;
  e = 0;
  if ((tmp = malloc(sizeof(*tmp) * (strlen(str) + strlen(path) + 1))) == NULL)
    return (NULL);
  while (path[i] != '\0')
    {
      tmp[i] = path[i];
      i += 1;
    }
  while (str[e] != '\0')
    {
      tmp[i] = str[e];
      e += 1;
      i += 1;
    }
  tmp[i] = '\0';
  return (tmp);
}
