/*
** get_last_command.c for 42sh in /home/benjamin/rendu/C/PSU/PSU_2014_42sh
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Sat May 23 19:03:47 2015 Benjamin Rascol
** Last update Sun May 24 15:30:30 2015 Manuel Trambert
*/

#include "42sh.h"

static char	**get_new_line(char **tab_input, char *str)
{
  char		**tmp;
  char		**cmd;
  int		e;
  int		i;

  i = -1;
  e = 1;
  if ((tmp = malloc(sizeof(*tmp) * (size_tab(tab_input)
				    + count_word(str) + 1))) == NULL)
    return (NULL);
  cmd = str_to_wordtab(str);
  while (cmd[++i] != NULL)
    tmp[i] = strdup(cmd[i]);
  free_tab(cmd);
  while (tab_input[e] != NULL)
    {
      tmp[i] = strdup(tab_input[e]);
      i += 1;
      e += 1;
    }
  tmp[i] = NULL;
  free_tab(tab_input);
  return (tmp);
}

static char	*get_prev_cmd(char *str)
{
  t_hist_list	*tmp;
  int		turn;
  int		i;

  turn = atoi(str);
  turn *= -1;
  tmp = g_history.start;
  i = -1;
  if (turn > 0)
    while (tmp != NULL && ++i < turn)
      tmp = tmp->next;
  else
    {
      if (tmp == NULL)
	return (NULL);
      while (tmp->next != NULL)
	tmp = tmp->next;
      while (tmp != NULL && i > turn + 1 && (i -= 1))
	tmp = tmp->prev;
    }
  if (tmp == NULL)
    return (NULL);
  else if (tmp->str[0] == '!' && isnum(str + 1) == 0)
    return (get_prev_cmd(str + 1));
  return (tmp->str);
}

static char	**change_exclamation(char **tab_input, t_hist_list *tmp)
{
  char		*str;
  int		turn;

  str = strdup(tab_input[0]);
  turn = 0;
  while (tmp != NULL && strncmp(tmp->str, "!!", 2) == 0)
    tmp = tmp->next;
  while (turn < 10 && tmp != NULL && strstr(str, "!!") != NULL)
    {
      str = concat_str(tmp->str, str);
      turn += 1;
    }
  if ((tab_input = get_new_line(tab_input, str)) == NULL)
    return (NULL);
  return (tab_input);
}

static char		**rec_doble_excl(char **tab_input)
{
  t_hist_list		*tmp;
  int			i;

  i = -1;
  if (g_history.start && g_history.start->str == NULL)
    return (tab_input);
  tmp = g_history.start;
  tab_input = change_exclamation(tab_input, tmp);
  if ((strstr("!!", tab_input[0])) != NULL)
    {
      tab_input = NULL;
      printf("0: event not found\n");
      return (tab_input);
    }
  if (tab_input != NULL)
    while (tab_input[++i] != NULL)
      my_putstr(tab_input[i]);
  printf("\n");
  return (tab_input);
}

char		**get_history_command(char **tab_input)
{
  char		*str;

  if (strstr(tab_input[0], "!!") != NULL)
    return (rec_doble_excl(tab_input));
  else if (strstr(tab_input[0], "!") != NULL && strlen(tab_input[0]) > 1
	   && isnum(tab_input[0] + 1) == EXIT_FAILURE)
    {
      if ((str = search_in_history(tab_input[0])) == NULL)
	return (NULL);
      if ((tab_input = get_new_line(tab_input, str)) == NULL)
	return (NULL);
    }
  else if (strstr(tab_input[0], "!") != NULL && isnum(tab_input[0] + 1) == 0)
    {
      if ((str = get_prev_cmd(tab_input[0] + 1)) == NULL)
	{
	  printf("%d: event not found\n", atoi(tab_input[0] + 1));
	  return (NULL);
	}
      printf("%s\n", str);
      if ((tab_input = get_new_line(tab_input, str)) == NULL)
	return (NULL);
    }
  return (tab_input);
}
