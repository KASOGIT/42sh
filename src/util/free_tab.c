/*
** free_tab.c for  in /home/soto_a/rendu/PSU_2014_42sh/refurbish_42sh/src/util
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Thu May  7 01:05:48 2015 adam soto
** Last update Sun May 24 02:51:55 2015 Benjamin Rascol
*/

#include "42sh.h"

void	free_tab(char **array)
{
  int	i;

  i = 0;
  if (!array)
    return ;
  while (array[i])
    {
      free(array[i]);
      i++;
    }
  free(array);
}
