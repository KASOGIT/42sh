/*
** sort_word.c for  in /home/exam/rendu/ex_4
** 
** Made by Exam User
** Login   <exam@epitech.net>
** 
** Started on  Fri Apr 24 10:59:10 2015 Exam User
** Last update Fri May 22 18:48:12 2015 Benjamin Rascol
*/

#include "42sh.h"

static int	is_char(char c)
{
  if (c >= 33 && c <= 126)
    return (1);
  return (0);
}

static int	is_sep(char c)
{
  if (c == ' ' || c == '\t')
    return (1);
  return (0);
}

int	count_word(char *str)
{
  int		count;
  int		i;

  i = 0;
  count = 0;
  while (str[i])
    {
      if (i == 0 && is_char(str[i]))
	count++;
      else if (i != 0 && is_sep(str[i - 1]) && is_char(str[i]))
	count++;
      i++;
    }
  return (count);
}

static char	*my_str_copy(char *src, int n)
{
  int	i;
  char	*str;

  i = 0;
  if ((str = malloc(sizeof(char) * (n + 1))) == NULL)
    return (NULL);
  while (i != n)
    {
      str[i] = src[i];
      i++;
    }
  str[i] = '\0';
  return (str);
}

char	**str_to_wordtab(char *str)
{
  char	**tab_str;
  int	i = 0;
  int	pos;
  int	count = 0;

  if (str == NULL)
    return (NULL);
  if ((tab_str = malloc(sizeof(char *) * (count_word(str) + 1))) == NULL)
    return (NULL);
  while (count != count_word(str))
    {
      while (is_sep(str[i]))
	i++;
      pos = i;
      while (is_char(str[pos]))
	pos++;
      tab_str[count] = my_str_copy(str + i, pos - i);
      i = pos;
      count++;
    }
  tab_str[count] = NULL;
  return (tab_str);
}
