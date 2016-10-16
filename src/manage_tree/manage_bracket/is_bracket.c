/*
** is_bracket.c for  in /home/soto_a/rendu/PSU_2014_42sh/src/manage_tree/manage_bracket
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sat May 23 23:18:41 2015 adam soto
** Last update Sat May 23 23:19:16 2015 adam soto
*/

#include "42sh.h"

int	is_bracket(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '(' || str[i] == ')')
        return (1);
      i++;
    }
  return (0);
}
