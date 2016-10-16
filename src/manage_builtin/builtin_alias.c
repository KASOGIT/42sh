/*
** builtin_alias.c for  in /home/trambe_m/PSU_2014_42sh/src/manage_builtin
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Tue May 19 19:18:13 2015 Manuel Trambert
** Last update Sun May 24 08:28:12 2015 adam soto
*/

#include "42sh.h"

void	print_list_alias(t_alia *alias)
{
  alias = alias->next;
  while (alias != g_info.alias)
    {
      printf("alias '%s'='%s'\n", alias->result, alias->str);
      alias = alias->next;
    }

}

static	char	*my_strcopy(char *src, char *dest)
{
  char		*tmp;
  int		i;
  int		e;

  i = 0;
  e = 0;
  if ((tmp = malloc(sizeof(*tmp)
		    * (strlen(src) + strlen(dest) + 2))) == NULL)
    return (NULL);
  while (src[i] != '\0')
    {
      tmp[i] = src[i];
      i += 1;
    }
  tmp[i++] = '=';
  while (dest[e] != '\0')
    {
      tmp[i] = dest[e];
      i += 1;
      e += 1;
    }
  tmp[i] = '\0';
  return (tmp);
}

static	char	*my_str_first_copy(char *src, char *dest)
{
  char		*tmp;
  int		i;
  int		e;

  i = 0;
  e = 0;
  if ((tmp = malloc(sizeof(*tmp)
		    * (strlen(src) + strlen(dest) + 2))) == NULL)
    return (NULL);
  while (src[i] != '\0')
    {
      tmp[i] = src[i];
      i += 1;
    }
  tmp[i++] = ' ';
  while (dest[e] != '\0')
    {
      tmp[i] = dest[e];
      i += 1;
      e += 1;
    }
  tmp[i] = '\0';
  free(src);
  return (tmp);
}

static void	check_del_alias(char *input, t_alia **current)
{
  t_alia	*tmp;
  char		*cmd;
  char		**array_tmp;

  tmp = g_info.alias->next;
  cmd = strdup("unalias");
  cmd = my_str_first_copy(cmd, input);
  array_tmp = str_to_wordtab(cmd);
  while (tmp != g_info.alias)
    {
      if (strcmp(array_tmp[1], tmp->result) == 0)
	{
	  *current = (*current)->prev;
	  builtin_unalias(array_tmp);
	  free(cmd);
	  free_tab(array_tmp);
	  return ;
	}
      tmp = tmp->next;
    }
  free(cmd);
  free_tab(array_tmp);
}

int		builtin_alias(char **tab_input)
{
  int		i;
  t_alia	*ptr;
  char		*tmp;

  i = 2;
  if (tab_input[1] == NULL)
    print_list_alias(g_info.alias);
  else if (size_tab(tab_input) >= 3)
    {
      if (strcmp(tab_input[1], "alias") == 0)
	{
	  fprintf(stderr, "alias: Too dangerous to alias that.\n");
	  return (0);
	}
      ptr = g_info.alias;
      if ((tmp = my_strcopy(tab_input[1], tab_input[2])) == NULL)
	return (EXIT_FAILURE);
      while (tab_input[i + 1] != NULL && (i += 1))
	if ((tmp = my_str_first_copy(tmp, tab_input[i])) == NULL)
	  return (EXIT_FAILURE);
      check_del_alias(tab_input[1], &ptr);
      add_list_alias(&(g_info.alias), tmp);
      free(tmp);
    }
  return (kill_proc_and_set_status());
}
