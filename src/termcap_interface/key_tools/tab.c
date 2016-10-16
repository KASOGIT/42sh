/*
** tab.c for  in /home/trambe_m/PSU_2014_42sh/src/termcap_interface/key_tools
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Sun May 24 06:38:35 2015 Manuel Trambert
** Last update Sun May 24 06:39:16 2015 Manuel Trambert
*/

#include "42sh.h"

static char	**fill_first_tab(char **array)
{
  int		i;
  int		e;
  char		**tmp;

  i = 0;
  e = 0;
  if ((tmp = malloc(sizeof(*array) * (size_tab(array) + 1))) == NULL)
    return (NULL);
  while (array[i] != NULL)
    {
      if (check_star(array[i]) == 0)
      	{
	  tmp[e] = strdup(array[i]);
	  e += 1;
	}
      i += 1;
    }
  tmp[e] = NULL;
  free_tab(array);
  return (tmp);
}

static int	already_in_tab(char **cmd, char *str)
{
  int		i;
  char		*tmp;
  char		*tmp_cmd;

  i = 0;
  tmp = strdup(str);
  tmp = unconcat_str(tmp);
  while (cmd[i] != NULL)
    {
      tmp_cmd = strdup(cmd[i]);
      tmp_cmd = unconcat_str(tmp_cmd);
      if (strcmp(tmp, tmp_cmd) == 0)
	return (1);
      i += 1;
    }
  return (0);
}

static char	**fill_new_tab(char **to_copy, char **cmd)
{
  int		e;
  int		f;
  int		i;
  char		**tmp;

  e = 0;
  f = 0;
  i = -1;
  if ((tmp = malloc(sizeof(*tmp) * (size_tab(to_copy)
				    + size_tab(cmd) + 1))) == NULL)
    return (NULL);
  while (to_copy[f] != NULL)
    {
      if (check_star(to_copy[f]) == 0
	  && already_in_tab(cmd, to_copy[f]) == 0)
	{
	  tmp[e] = strdup(to_copy[f]);
	  e += 1;
	}
      f += 1;
    }
  while (cmd[++i] != NULL)
    tmp[e++] = strdup(cmd[i]);
  tmp[e] = NULL;
  return (tmp);
}

char	**unconcat_path(char **cmd)
{
  int	i;
  char	**tmp;

  i = 0;
  if (cmd == NULL)
    return (cmd);
  if ((tmp = malloc(sizeof(*tmp) * (size_tab(cmd) + 1))) == NULL)
    return (NULL);
  while (cmd[i] != NULL)
    {
      tmp[i] = unconcat_str(cmd[i]);
      i += 1;
    }
  tmp[i] = NULL;
  free(cmd);
  return (tmp);
}

char		**get_bin_cmd(char **command_buffer, int i)
{
  int		e;
  char		**path;
  char		*tmp;
  char		**array;
  char		**cmd;
  glob_t	pattern;

  e = 0;
  if ((tmp = add_star(*command_buffer, i)) == NULL)
    return (NULL);
  cmd = NULL;
  path = get_tab_path(g_info.ev);
  while (path[e + 2] != NULL && (e += 1))
    {
      array = str_to_wordtab(tmp);
      array[get_pos_star(array)]
	= concat_path_to_str(array[get_pos_star(array)], path[e]);
      glob(array[get_pos_star(array)], GLOB_NOCHECK, NULL, &pattern);
      if (cmd != NULL)
	cmd = fill_new_tab(pattern.gl_pathv, cmd);
      else if (cmd == NULL)
	cmd = fill_first_tab(pattern.gl_pathv);
    }
  return (cmd);
}
