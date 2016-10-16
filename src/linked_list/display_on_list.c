/*
** display_on_list.c for display_on_list in /home/soto_a/rendu/CPE_2014_Pushswap
** 
** Made by Kaso Soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sat Dec 13 18:17:55 2014 Kaso Soto
** Last update Sun Oct 16 15:36:18 2016 
*/

#include "42sh.h"

static	void	my_putvalue_env(char *str)
{
  if (write(1, str, strlen(str)) == -1)
    printf("Error write\n");
  if (write(1, "\n", 1) == -1)
    printf("Error write\n");    
}

void		my_show_list(int fd, t_list *list, int direction)
{
  t_list	*tmp;

  (void)fd;
  if (direction == 0)
    {
      tmp = list->next;
      while (tmp != list)
        {
	  my_putvalue_env(tmp->str);
          tmp = tmp->next;
        }
    }
  else
    {
      tmp = list->prev;
      while (tmp != list)
        {
	  printf("%s\n", tmp->str);
          tmp = tmp->prev;
        }
    }
}
