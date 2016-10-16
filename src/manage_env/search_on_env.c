/*
** search_on_env.c for  in /home/soto_a/rendu/PSU_2014_42sh/refurbish_42sh/src/manage_env
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Wed May  6 16:10:06 2015 adam soto
** Last update Wed May  6 16:11:40 2015 adam soto
*/

#include "42sh.h"

char		*search_on_env(t_list *ev, char *search)
{
  t_list	*tmp_ev;
  int		j;

  tmp_ev = ev->next;
  j = 0;
  while (tmp_ev != ev)
    {
      if (strlen(tmp_ev->str) >= strlen(search) &&
          strncmp(tmp_ev->str, search, strlen(search)) == 0)
        {
          while (tmp_ev->str[j] != '=')
            j++;
          return (strdup(tmp_ev->str + j + 1));
        }
      tmp_ev = tmp_ev->next;
    }
  return (NULL);
}
