/*
** remove_bracket.c for  in /home/soto_a/rendu/PSU_2014_42sh/src/manage_tree/manage_bracket
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sat May 23 23:06:16 2015 adam soto
** Last update Sun May 24 16:45:29 2015 adam soto
*/

#include "42sh.h"

static int	is_only_bracket(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] != ' ' && str[i] != '\t' && str[i] != '(' && str[i] != ')')
        return (0);
      i++;
    }
  return (1);
}

static void	init_var(t_bracket *bracket)
{
  bracket->i = 0;
  bracket->a = 0;
  bracket->count = 0;
  bracket->boolean = 1;
}

static void	check_bracket(char **str, t_bracket *bracket, char **new_str)
{
  if ((*str)[bracket->i] == '(')
    {
      bracket->i++;
      if (!(*str)[bracket->i])
	bracket->boolean = 0;
      bracket->count++;
    }
  if ((*str)[bracket->i] == ')')
    {
      bracket->i++;
      if (!(*str)[bracket->i])
	bracket->boolean = 0;
      bracket->count--;
    }
  (*new_str)[bracket->a] = (*str)[bracket->i];
  bracket->a++;
  bracket->i++;
}

int		remove_bracket(char **str, char **op, int *pos_op_str)
{
  char		*new_str;
  t_bracket	bracket;

  init_var(&bracket);
  if (is_only_bracket(*str))
    {
      free(*str);
      *str = strdup("");
      return (get_pos_op(str, op, pos_op_str));
    }
  if ((new_str = malloc(sizeof(char) * (strlen(*str) + 1))) == NULL)
    return (-1);
  while (bracket.boolean && (*str)[bracket.i])
    check_bracket(str, &bracket, &new_str);
  new_str[bracket.a] = '\0';
  free(*str);
  *str = new_str;
  return (get_pos_op(str, op, pos_op_str));
}
