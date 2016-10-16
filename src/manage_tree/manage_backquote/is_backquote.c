/*
** is_backquote.c for  in /home/soto_a/rendu/PSU_2014_42sh/src/manage_tree
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sun May 24 14:24:59 2015 adam soto
** Last update Sun May 24 14:26:13 2015 adam soto
*/

#include "42sh.h"

int	is_backquote(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '\"' || str[i] == '\'')
	return (1);
      i++;
    }
  return (0);
}
