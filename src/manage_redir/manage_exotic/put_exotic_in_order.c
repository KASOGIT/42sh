/*
** put_exotic_in_order.c for  in /home/soto_a/rendu/PSU_2014_42sh/refurbish_42sh/src/manage_redir
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Wed May 13 04:28:04 2015 adam soto
** Last update Sun May 17 23:16:06 2015 adam soto
*/

#include "42sh.h"

static void	reset_sep(t_exec *sep)
{
  sep->comp = sep->j;
  sep->boolean = 0;
  sep->count++;
}

int		count_nb_sep(char *expr)
{
  t_exec	sep;
  char		**tab_sep;
  char		**tab_expr;

  tab_sep = str_to_wordtab("; && || | < > << >>");
  tab_expr = str_to_wordtab(expr);
  sep.i = -1;
  sep.count = 0;
  sep.comp = -1;
  while (tab_sep[++(sep.i)])
    {
      sep.j = 0;
      sep.boolean = 1;
      while (tab_expr[sep.j] && sep.boolean)
	{
	  if (sep.j != sep.comp && strncmp(tab_sep[sep.i],
	      tab_expr[sep.j], strlen(tab_sep[sep.i])) == 0)
	    reset_sep(&sep);
	  sep.j++;
	}
    }
  free_tab(tab_sep);
  free_tab(tab_expr);
  return (sep.count);
}

int	is_redir_first(char *str)
{
  int	i;
  char	**redir;
  char	**tab_str;

  i = 0;
  redir = str_to_wordtab(">> << > <");
  tab_str = str_to_wordtab(str);
  while (redir[i])
    {
      if (strncmp(redir[i], tab_str[0], strlen(redir[i])) == 0)
	{
	  free_tab(redir);
	  free_tab(tab_str);
	  return (1);
	}
      i++;
    }
  free_tab(redir);
  free_tab(tab_str);
  return (0);
}

static int	concat_param(char **tab_str)
{
  int		i;

  i = 3;
  while (tab_str[i])
    {
      if ((tab_str[2] = realloc(tab_str[2],
	 (strlen(tab_str[2]) + strlen(tab_str[i]) + 1))) == NULL)
	return (EXIT_FAILURE);
      tab_str[2] = strcat(tab_str[2], " ");
      tab_str[2] = strcat(tab_str[2], tab_str[i]);
      i++;
    }
  return (EXIT_FAILURE);
}

char	*put_exotic_in_order(char *str)
{
  char	**tab_str;
  char	*tmp;

  tab_str = str_to_wordtab(str);
  if (size_tab(tab_str) >= 3)
    {
      tmp = tab_str[0];
      tab_str[0] = tab_str[1];
      tab_str[1] = tmp;
      tmp = tab_str[0];
      concat_param(tab_str);
      tab_str[0] = tab_str[2];
      tab_str[2] = tmp;
    }
  else if (size_tab(tab_str) == 2)
    {
      tmp = tab_str[0];
      tab_str[0] = tab_str[1];
      tab_str[1] = tmp;
    }
  return (wordtab_to_str(tab_str));
}
