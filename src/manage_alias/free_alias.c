/*
** free_alias.c for  in /home/trambe_m/PSU_2014_42sh
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Tue May 19 20:32:52 2015 Manuel Trambert
** Last update Thu May 21 01:12:33 2015 adam soto
*/

#include "42sh.h"

void		my_free_alias(t_alia **alias)
{
  t_alia	*to_del;
  t_alia	*tmp;

  tmp = (*alias)->next;
  while (tmp != *alias)
    {
      to_del = tmp;
      tmp = tmp->next;
      free(to_del->str);
      free(to_del->result);
      free(to_del);
    }
}
