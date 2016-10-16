/*
** run_tree.c for  in /home/soto_a/rendu/PSU_2014_42sh/refurbish_42sh/src/manage_tree
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Thu May  7 13:52:07 2015 adam soto
** Last update Sun May 24 23:25:48 2015 adam soto
*/

#include "42sh.h"

static t_func_op	g_tab_func_op[] =
  {
    {0, &semicolon_func},
    {1, &or_func},
    {2, &and_func},
    {3, &pipe_func},
    {4, &double_right_func},
    {5, &right_func},
    {6, &double_left_func},
    {7, &left_func},
    {8, &exec_cmd_func},
  };

static int	get_op(char *data, char **op)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  if (strlen(data) > 2)
    return (8);
  while (op[i])
    {
      while (data[j])
        {
          if (strncmp(op[i], data + j, strlen(op[i])) == 0)
            return (i);
          j++;
        }
      j = 0;
      i++;
    }
  return (i);
}

int		run_tree(t_tree **node)
{
  char		*epur_data;

  if (g_info.status == EXIT_MODE)
    return (EXIT_SUCCESS);
  if (*node && (*node)->data && strlen((*node)->data) > 0)
    {
      epur_data = search_varenv_and_replace((*node)->data);
      if (only_space_tab(epur_data) != 0
	  || str_is_printable((unsigned char *)epur_data) == 0)
	return (EXIT_SUCCESS);
      free((*node)->data);
      (*node)->data = epur_data;
      return (g_tab_func_op[get_op((*node)->data, g_info.op)].func_op(node));
    }
  return (EXIT_SUCCESS);
}
