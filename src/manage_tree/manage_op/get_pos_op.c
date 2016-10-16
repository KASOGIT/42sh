/*
** get_pos_op.c for  in /home/soto_a/rendu/PSU_2014_42sh/src/manage_tree/manage_op
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sat May 23 23:22:03 2015 adam soto
** Last update Sun May 24 16:24:41 2015 adam soto
*/

#include "42sh.h"

static	int	display_error_or_call_recurs(char **str, char **op,
					     int *pos_op_str, int bb[])
{
  if (bb[1] % 2 == 1)
    {
      fprintf(stderr, "Missmatch backquote.\n");
      return (-1);
    }
  else if (bb[1] % 2 == 0 && is_backquote(*str))
    return (remove_backquote(str, op, pos_op_str));
  else if (bb[0] % 2 == 1)
    {
      fprintf(stderr, "Missmatch bracket.\n");
      return (-1);
    }
  else if (bb[0] % 2 == 0 && is_bracket(*str))
    return (remove_bracket(str, op, pos_op_str));
  return (-1);
}

static void	incr_bb(char **str, int bb[], int j)
{
  if ((*str)[j] == '(')
    bb[0]++;
  else if ((*str)[j] == ')')
    bb[0]--;
  else if ((*str)[j] == '\"' || (*str)[j] == '\'')
    {
      if (bb[1] == 0)
	bb[1]++;
      else
	bb[1]--;
    }
}

int	get_pos_op(char **str, char **op, int *pos_op_str)
{
  int	bb[2];
  int	i;
  int	j;

  i = -1;
  j = -1;
  while (op[++i])
    {
      bb[0] = 0;
      bb[1] = 0;
      while ((*str)[++j])
        {
          if (bb[0] == 0 && bb[1] == 0
	      && strncmp(op[i], *str + j, strlen(op[i])) == 0)
            {
              *pos_op_str = j;
              return (i);
            }
	  incr_bb(str, bb, j);
        }
      j = -1;
    }
  return (display_error_or_call_recurs(str, op, pos_op_str, bb));
}
