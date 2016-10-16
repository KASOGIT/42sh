/*
** tools_history.c for  in /home/soto_a/rendu/PSU_2014_42sh/src
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sun May 24 08:04:29 2015 adam soto
** Last update Sun May 24 15:30:38 2015 Manuel Trambert
*/

#include "42sh.h"

int	isnum(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] > '9' || str[i] < '0') && str[i] != '-')
	return (EXIT_FAILURE);
      i += 1;
    }
  return (0);
}

char		*search_in_history(char *str)
{
  t_hist_list	*ptr;
  char		*tmp;

  if (g_history.start != NULL && g_history.start->next != NULL)
    ptr = g_history.start->next;
  else
    ptr = g_history.start;
  tmp = strdup(str + 1);
  while (ptr != NULL && ptr != g_history.start)
    {
      if (strncmp(tmp, ptr->str, strlen(tmp)) == 0)
	{
	  tmp = strdup(ptr->str);
	  return (tmp);
	}
      ptr = ptr->next;
    }
  fprintf(stderr, "%s: Event not found.\n", str + 1);
  return (NULL);
}

char		*concat_str(char *start, char *end)
{
  char		*tmp;
  int		e;
  int		f;
  int		i;

  i = 0;
  e = -1;
  if ((tmp = malloc(sizeof(*tmp) *
		    (strlen(start) + strlen(end) + 1))) == NULL)
    return (NULL);
  while (end[i] != '!')
    {
      tmp[i] = end[i];
      i += 1;
    }
  f = i + 1;
  while (start[++e] != '\0')
    tmp[i++] = start[e];
  while (end[++f] != '\0')
    tmp[i++] = end[f];
  tmp[i] = '\0';
  free(end);
  return (tmp);
}
