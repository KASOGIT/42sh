/*
** my_strcat_alloc.c for  in /home/soto_a/rendu/PSU_2014_42sh/refurbish_42sh/src/manage_builtin
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sat May 16 11:00:10 2015 adam soto
** Last update Sun May 24 22:11:16 2015 adam soto
*/

#include "42sh.h"

char	*my_strcat_alloc(char *dest, char *src)
{
  int	i;
  int	a;
  int	size_a;
  int	size_b;
  char	*new_str;

  i = -1;
  size_a = strlen(dest);
  size_b = strlen(src);
  if ((new_str = malloc(sizeof(char) * (size_a + size_b + 2))) == NULL)
    return (NULL);
  while (dest[++i])
    new_str[i] = dest[i];
  a = i;
  i = 0;
  while (src[i])
    {
      new_str[a] = src[i];
      a++;
      i++;
    }
  new_str[a] = '\0';
  return (new_str);
}
