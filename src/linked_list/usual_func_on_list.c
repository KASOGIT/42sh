/*
** usual_func_on_list.c for usual_func in /home/soto_a/rendu/CPE_2014_Pushswap
** 
** Made by Kaso Soto
** Login   <soto_a@epitech.net>
** 
** Started on  Tue Dec  2 15:55:03 2014 Kaso Soto
** Last update Tue May 12 23:56:02 2015 adam soto
*/

#include "42sh.h"

void	my_init_list(t_list **list)
{
  if (((*list) = malloc(sizeof(t_list))) == NULL)
    return ;
  (*list)->prev = *list;
  (*list)->next = *list;
}

void	my_create_list(t_list **list, char **env)
{
  int	i;

  i = 0;
  while (env[i])
    my_put_in_list(list, env[i++], 0);
}

void		my_put_in_list(t_list **list, char *str, int choice)
{
  t_list	*new_elem;

  if ((new_elem = malloc(sizeof(t_list))) == NULL)
    return ;
  if (choice == 0)
    {
      new_elem->prev = (*list)->prev;
      new_elem->next = (*list);
      (*list)->prev->next = new_elem;
      (*list)->prev = new_elem;
      new_elem->str = strdup(str);
    }
  else
    {
      new_elem->str = strdup(str);
      new_elem->prev = (*list);
      new_elem->next = (*list)->next;
      (*list)->next->prev = new_elem;
      (*list)->next = new_elem;
    }
}

int		my_size_list(t_list *list)
{
  t_list	*tmp;
  int		i;

  tmp = list->next;
  i = 0;
  while (tmp != list)
    {
      tmp = tmp->next;
      i++;
    }
  return (i);
}
