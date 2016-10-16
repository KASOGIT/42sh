/*
** check_alias.c for  in /home/trambe_m/PSU_2014_42sh
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Tue May 19 18:34:09 2015 Manuel Trambert
** Last update Sun May 24 07:18:35 2015 adam soto
*/

#include "42sh.h"

static char	**realloc_tab(char **tab_input, char *str, int *i)
{
  char		**tmp;
  char		**cmd;
  int		line;
  int		tmp_i;
  int		e;

  line = -1;
  e = -1;
  tmp_i = *i;
  if ((tmp = malloc(sizeof(*tmp)
		    * (size_tab(tab_input) + count_word(str)) + 1)) == NULL)
    return (NULL);
  while (++line != *i)
    tmp[line] = strdup(tab_input[line]);
  cmd = str_to_wordtab(str);
  while (cmd[++e] != NULL)
    tmp[line++] = strdup(cmd[e]);
  while (tab_input[++*i] != NULL)
    tmp[line++] = strdup(tab_input[*i]);
  *i = tmp_i + count_word(str);
  tmp[line] = NULL;
  free_tab(cmd);
  free_tab(tab_input);
  return (tmp);
}

static char	**check_alias(char **tab_input, t_alia *alias, int *i)
{
  int		turn;
  t_alia	*tmp;

  tmp = alias->next;
  turn = 0;
  while (tab_input[*i] != NULL && turn < 50 && tmp != alias)
    {
      if (strcmp(tab_input[*i], tmp->result) == 0)
	{
	  if ((tab_input = realloc_tab(tab_input, tmp->str, i)) == NULL)
	    return (NULL);
	  tmp = alias->next;
	}
      *i = 0;
      tmp = tmp->next;
      turn += 1;
    }
  return (tab_input);
}

char	**get_alias(t_alia *alias, char **tab_input)
{
  int	i;

  i = 0;
  if (tab_input[i] != NULL)
    {
      if ((tab_input = check_alias(tab_input, alias, &i)) == NULL)
	return (NULL);
      if (tab_input[i] == NULL)
	return (tab_input);
      i += 1;
    }
  return (tab_input);
}
