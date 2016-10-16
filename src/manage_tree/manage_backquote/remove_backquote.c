/*
** remove_bracket.c for  in /home/soto_a/rendu/PSU_2014_42sh/src/manage_tree/manage_bracket
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sat May 23 23:06:16 2015 adam soto
** Last update Sun May 24 17:18:45 2015 adam soto
*/

#include "42sh.h"

static int	is_only_backquote(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] != ' ' && str[i] != '\t'
	  && str[i] != '\"' && str[i] != '\'')
        return (0);
      i++;
    }
  return (1);
}

static void	init_var(t_bracket *backquote)
{
  backquote->i = 0;
  backquote->a = 0;
  backquote->count = 0;
  backquote->boolean = 1;
}

static void	check_backquote(char **str,
				t_bracket *backquote, char **new_str)
{
  static char	c = 0;

  if ((*str)[backquote->i] == '\"' || (*str)[backquote->i] == '\'')
    {
      if (backquote->count == 0)
	{
	  c = (*str)[backquote->i];
	  backquote->count++;
	  backquote->i++;
	  if (!(*str)[backquote->i])
	    backquote->boolean = 0;
	}
      if ((*str)[backquote->i]
	  && backquote->count == 1 && (*str)[backquote->i] == c)
	{
	  c = 0;
	  backquote->count++;
	  backquote->i++;
	  if (!(*str)[backquote->i])
	    backquote->boolean = 0;
	  backquote->count++;
	}
    }
  (*new_str)[backquote->a++] = (*str)[backquote->i];
  backquote->i++;
}

static int	is_no_backquote(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '\"' || str[i] == '\'')
	return (0);
      i++;
    }
  return (1);
}

int		remove_backquote(char **str, char **op, int *pos_op_str)
{
  char		*new_str;
  t_bracket	backquote;

  init_var(&backquote);
  if (is_only_backquote(*str))
    {
      free(*str);
      *str = strdup("");
      return (get_pos_op(str, op, pos_op_str));
    }
  if ((new_str = malloc(sizeof(char) * (strlen(*str) + 1))) == NULL)
    return (-1);
  while (backquote.boolean && (*str)[backquote.i])
    check_backquote(str, &backquote, &new_str);
  new_str[backquote.a] = '\0';
  free(*str);
  *str = new_str;
  return (is_no_backquote(*str) ? -1 : get_pos_op(str, op, pos_op_str));
}
