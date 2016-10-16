/*
** list.c for mysh in /home/benjamin/rendu/C/PSU/PSU_2014_42sh
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Sun May 17 22:36:32 2015 Benjamin Rascol
** Last update Fri May 22 18:41:18 2015 Benjamin Rascol
*/

#include "42sh.h"

static t_hist_list	*create_hist_node(char *str)
{
  t_hist_list		*node;

  if ((node = malloc(sizeof(t_hist_list))) == NULL)
    return (NULL);
  node->str = str;
  node->prev = NULL;
  node->next = NULL;
  return (node);
}

int		add_list_hist(t_history *history, char *str)
{
  t_hist_list	*new;

  dprintf(history->fd_file_history, "%s\n", str);
  if ((new = create_hist_node(strdup(str))) == NULL)
    return (ERROR_MYSH);
  if (history->start == NULL)
    {
      history->start = new;
    }
  else
    {
      new->next = history->start;
      history->start->prev = new;
      history->start = new;
    }
  return (SUCCESS);
}

void		free_list_hist(t_hist_list **ptr)
{
  t_hist_list	*to_del;
  t_hist_list	*tmp;

  tmp = (*ptr)->next;
  while (tmp != NULL)
    {
      to_del = tmp;
      tmp = tmp->next;
      free(to_del->str);
      free(to_del);
    }
  free(*ptr);
}
