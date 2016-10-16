/*
** put_in_order_exotic_param.c for  in /home/soto_a/rendu/PSU_2014_42sh/src/manage_redir/manage_exotic
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Tue May 19 21:31:16 2015 adam soto
** Last update Tue May 19 22:24:16 2015 adam soto
*/

#include "42sh.h"

static char	*wordtab_to_param(char **array)
{
  char		*str;
  int		i;

  i = 0;
  while (array[i])
    {
      if (i == 0)
        str = strdup(array[i]);
      else
        {
          if ((str = realloc(str,
			     (strlen(str) + strlen(array[i]) + 1))) == NULL)
            return (NULL);
          str = strcat(str, array[i]);
        }
      if (array[i + 1])
        {
          if ((str = realloc(str, (strlen(str) + 2))) == NULL)
            return (NULL);
          str = strcat(str, " ");
        }
      i++;
    }
  return (str);
}

int	put_in_order_exotic_param(t_tree **node, char **tab_epur_name)
{
  char	*param;

  if (size_tab(tab_epur_name) > 1)
    {
      param = wordtab_to_param(tab_epur_name + 1);
      (*node)->left->data = my_strcat((*node)->left->data, " ");
      (*node)->left->data = my_strcat((*node)->left->data, param);
      free(param);
    }
  return (EXIT_SUCCESS);
}
