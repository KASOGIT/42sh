/*
** glob.c for  in /home/trambe_m/trash/PSU_2014_42sh/src/globing
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Mon May 18 21:13:36 2015 Manuel Trambert
** Last update Sun May 24 03:56:42 2015 adam soto
*/

#include "42sh.h"

int	check_star(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '*')
        return (1);
      i += 1;
    }
  return (0);
}

static char	**add_end_tab(char **cmd, char **tmp, int i, int f)
{
  while (cmd[f] != NULL)
    {
      tmp[i] = strdup(cmd[f]);
      i += 1;
      f += 1;
    }
  return (tmp);
}

static char	**fill_new_tab(char **to_copy, char **cmd)
{
  int		i;
  int		f;
  int		e;
  char		**tmp;

  i = -1;
  e = 0;
  if ((tmp = malloc(sizeof(*tmp) * (size_tab(to_copy)
				    + size_tab(cmd) + 1))) == NULL)
    return (NULL);
  while (check_star(cmd[++i]) != 1)
    tmp[i] = strdup(cmd[i]);
  f = i + 1;
  while (to_copy[e] != NULL)
    {
      if (to_copy[e] != NULL)
	tmp[i] = strdup(to_copy[e]);
      i += 1;
      e += 1;
    }
  tmp = add_end_tab(cmd, tmp, i, f);
  tmp[i] = NULL;
  free_tab(to_copy);
  free_tab(cmd);
  return (tmp);
}

static char		**get_new_tab(char **tab_input)
{
  glob_t		pattern;
  int			i;

  i = 0;
  while (tab_input[i] != NULL)
    {
      if (check_star(tab_input[i]) == 1)
	{
	  glob(tab_input[i], GLOB_NOCHECK, NULL, &pattern);
	  tab_input = fill_new_tab(pattern.gl_pathv, tab_input);
	}
      i += 1;
    }
  return (tab_input);
}

char	**get_glob(char **tab_input)
{
  int	i;

  i = 0;
  while (tab_input[i] != NULL)
    {
      if (check_star(tab_input[i]) == 1)
	tab_input = get_new_tab(tab_input);
      i += 1;
    }
  return (tab_input);
}
