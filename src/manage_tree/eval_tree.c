/*
** eval_tree.c for  in /home/soto_a/rendu/PSU_2014_42sh/refurbish_42sh/src/manage_tree
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Thu May  7 13:54:02 2015 adam soto
** Last update Sat May 23 23:29:13 2015 adam soto
*/

#include "42sh.h"

static char	*get_right_str(char *str, int pos_op_str, int size_op)
{
  int		i;
  int		size_old_str;
  char		*right_str;

  i = 0;
  size_old_str = strlen(str);
  pos_op_str += size_op;
  if ((right_str = malloc(sizeof(char) *
                          (size_old_str - pos_op_str + 1))) == NULL)
    return (NULL);
  while (str[pos_op_str])
    {
      right_str[i] = str[pos_op_str];
      pos_op_str++;
      i++;
    }
  right_str[i] = '\0';
  return (right_str);
}

static char	*get_left_str(char *str, int pos_op_str)
{
  int		i;
  char		*left_str;

  i = 0;
  if (pos_op_str != 0)
    pos_op_str--;
  if ((left_str = malloc(sizeof(char) * (pos_op_str + 2))) == NULL)
    return (NULL);
  while (i != pos_op_str + 1)
    {
      left_str[i] = str[i];
      i++;
    }
  left_str[i] = '\0';
  return (left_str);
}

static int	call_recursivity(t_tree **node, char *exotic_epur,
				 int pos_op_op, int pos_op_str)
{
  (*node)->data = strdup(g_info.op[pos_op_op]);
  eval_and_create_tree(&((*node)->left),
  get_left_str(exotic_epur, pos_op_str));
  eval_and_create_tree(&((*node)->right),
  get_right_str(exotic_epur, pos_op_str, strlen(g_info.op[pos_op_op])));
  return (EXIT_SUCCESS);
}

int	eval_and_create_tree(t_tree **node, char *str)
{
  char	*exotic_epur;
  int	pos_op_str;
  int	pos_op_op;

  if (count_nb_sep(str) == 1 && is_redir_first(str))
    {
      exotic_epur = put_exotic_in_order(str);
      free(str);
    }
  else
    exotic_epur = str;
  if (((*node) = malloc(sizeof(t_tree))) == NULL)
    return (EXIT_FAILURE);
  if (strlen(exotic_epur) > 1 &&
      (pos_op_op = get_pos_op(&exotic_epur, g_info.op, &pos_op_str)) != -1)
    call_recursivity(node, exotic_epur, pos_op_op, pos_op_str);
  else
    {
      (*node)->data = strdup(exotic_epur);
      (*node)->left = NULL;
      (*node)->right = NULL;
    }
  free(exotic_epur);
  return (EXIT_SUCCESS);
}
