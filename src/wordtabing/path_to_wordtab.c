/*
** path_to_wordtab.c for  in /home/soto_a/rendu/PSU_2014_42sh/refurbish_42sh/src/wordtabing
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sat May  9 01:00:49 2015 adam soto
** Last update Tue May 12 23:40:51 2015 adam soto
*/

#include "42sh.h"

static int	count_word_path(char *str)
{
  int		i;
  int		w;

  i = 0;
  w = 0;
  while (str[i])
    {
      if (str[i] == ':')
        w++;
      i++;
    }
  return (w + 1);
}

char	**path_to_wordtab(char *str)
{
  int	i;
  int	c;
  int	w;
  char	**ptr_char;

  i = 0;
  c = 0;
  if ((ptr_char = malloc(sizeof(char*) * (count_word_path(str) + 1))) == NULL)
    return (NULL);
  while (i < count_word_path(str))
    {
      w = 0;
      while (str[c + w] && str[c + w] != ':')
        w++;
      if ((ptr_char[i] = malloc(sizeof(char) * (w + 2))) == NULL)
	return (NULL);
      ptr_char[i] = strncpy(ptr_char[i], str + c, w);
      ptr_char[i][w] = '/';
      ptr_char[i][w + 1] = '\0';
      c += w + 1;
      i++;
    }
  ptr_char[i] = NULL;
  return (ptr_char);
}
