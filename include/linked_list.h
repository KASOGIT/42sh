/*
** linkedlist.h for linked_list.h in /home/soto_a/rendu/PSU_2014_minishell1/myshll
** 
** Made by Kaso Soto
** Login   <soto_a@epitech.net>
** 
** Started on  Tue Jan 20 19:10:23 2015 Kaso Soto
** Last update Mon Apr 27 13:47:58 2015 Benjamin Rascol
*/

#ifndef		LINKED_LIST_H_
# define	LINKED_LIST_H_

typedef struct	s_list
{
  char		*str;
  struct s_list *prev;
  struct s_list *next;
}		t_list;

void		my_init_list(t_list **list);
void		my_put_in_list(t_list **list, char *str, int choice);
void		my_free_list(t_list **list);
void		my_create_list(t_list **list, char **env);
void		my_delete_elem(t_list *list);
void		my_delete_on_edges(t_list *list, int choice);
void		my_show_list(int fd, t_list *list, int direction);
int		my_size_list(t_list *list);

#endif		/* !LINKED_LIST_H_ */
