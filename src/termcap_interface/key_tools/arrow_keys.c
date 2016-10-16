/*
** arrow_keys.c for mysh in /home/benjamin/rendu/C/PSU/PSU_2014_42sh
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Wed May  6 15:24:37 2015 Benjamin Rascol
** Last update Sun May 24 15:36:17 2015 Manuel Trambert
*/

#include "42sh.h"

int		fkey_left(__attribute__((unused))char **command_buffer,
			  int *i_buffer)
{
  t_winsize	*size;
  int		prompt_len;

  if (*i_buffer > 0)
    {
      size = termcap_get_win_size(GET_SIZE);
      prompt_len = g_info.size_prompt;
      if ((*i_buffer + prompt_len) % size->x == 0)
	{
	  termcap_move_cursor(MOVE_UP, 1);
	  termcap_move_cursor(MOVE_RIGHT, size->x);
	}
      else
	termcap_move_cursor(MOVE_LEFT, 1);
      *i_buffer -= 1;
    }
  return (SUCCESS);
}

int		fkey_right(char **command_buffer, int *i_buffer)
{
  t_winsize	*size;
  int		prompt_len;

  if (*i_buffer < (int)strlen(*command_buffer))
    {
      size = termcap_get_win_size(GET_SIZE);
      prompt_len = g_info.size_prompt;
      if ((*i_buffer + prompt_len) % size->x == size->x - 1)
	{
	  termcap_move_cursor(MOVE_DOWN, 1);
	  termcap_move_cursor(MOVE_LEFT, size->x);
	}
      else
	termcap_move_cursor(MOVE_RIGHT, 1);
      *i_buffer += 1;
    }
  return (SUCCESS);
}

int	fkey_up(char **command_buffer, int *i_buffer)
{
  char	*str;

  if (g_history.current == NULL)
    return (SUCCESS);
  if (g_history.current == g_history.start && strlen(*command_buffer)
      && strcmp(g_history.start->str, *command_buffer))
    if (add_list_hist(&g_history, *command_buffer) == ERROR_MYSH)
      return (ERROR_MYSH);
  my_putstr(&(*command_buffer)[*i_buffer]);
  termcap_cursor_placing(*command_buffer, 0);
  if ((str = tgetstr("cd", NULL)) == NULL)
    return (ERROR_MYSH);
  termcap_move_cursor(str, 1);
  my_putstr(g_history.current->str);
  *i_buffer = (int)strlen(g_history.current->str);
  free(*command_buffer);
  if ((*command_buffer = strdup(g_history.current->str)) == NULL)
    return (ERROR_MYSH);
  if (g_history.current->next != NULL)
    g_history.current = g_history.current->next;
  return (SUCCESS);
}

int	fkey_down(char **command_buffer, int *i_buffer)
{
  char	*str;

  if (g_history.current == NULL)
    return (SUCCESS);
  if (g_history.current->next == NULL && g_history.current->prev)
    g_history.current = g_history.current->prev;
  my_putstr(&(*command_buffer)[*i_buffer]);
  termcap_cursor_placing(*command_buffer, 0);
  if ((str = tgetstr("cd", NULL)) == NULL)
    return (ERROR_MYSH);
  termcap_move_cursor(str, 1);
  my_putstr(g_history.current->str);
  *i_buffer = (int)strlen(g_history.current->str);
  free(*command_buffer);
  if ((*command_buffer = strdup(g_history.current->str)) == NULL)
    return (ERROR_MYSH);
  if (g_history.current->prev != NULL)
    g_history.current = g_history.current->prev;
  return (SUCCESS);
}
