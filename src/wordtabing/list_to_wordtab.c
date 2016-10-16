/*
** list_to_wordtab.c for  in /home/soto_a/rendu/PSU_2014_42sh/refurbish_42sh/src/wordtabing
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sat May  9 03:20:54 2015 adam soto
** Last update Sat May  9 03:24:36 2015 adam soto
*/

#include "42sh.h"

char		**list_to_wordtab(t_list **ev)
{
  int		i;
  t_list	*tmp_ev;
  char		**tab_env;

  i = 0;
  tmp_ev = (*ev)->next;
  if ((tab_env = malloc(sizeof(char *) * (my_size_list((*ev)) + 1))) == NULL)
    return (NULL);
  while (tmp_ev != (*ev))
    {
      tab_env[i] = strdup(tmp_ev->str);
      i++;
      tmp_ev = tmp_ev->next;
    }
  tab_env[i] = NULL;
  return (tab_env);
}
