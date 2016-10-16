/*
** size_tab.c for  in /home/soto_a/rendu/PSU_2014_42sh/refurbish_42sh/src/util
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sat May 16 01:14:21 2015 adam soto
** Last update Wed May 20 14:12:45 2015 Benjamin Rascol
*/

#include "42sh.h"

int	size_tab(char **array)
{
  int	i;

  i = 0;
  while (array[i])
    i++;
  return (i);
}
