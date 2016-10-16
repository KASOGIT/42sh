/*
** strcat_path.c for  in /home/soto_a/rendu/PSU_2014_42sh/refurbish_42sh/src
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sat May  9 19:42:55 2015 adam soto
** Last update Sat May  9 19:47:38 2015 adam soto
*/

#include "42sh.h"

char	*strcat_path(char *start_path, char *end_path)
{
  int	i;
  int	j;
  char	*final_path;

  i = 0;
  j = 0;
  if ((final_path = malloc(sizeof(char) * (strlen(start_path)
					   + strlen(end_path) + 1))) == NULL)
    return (NULL);
  while (start_path[i])
    final_path[j++] = start_path[i++];
  i = 0;
  while (end_path[i])
    final_path[j++] = end_path[i++];
  final_path[j] = '\0';
  return (final_path);
}
