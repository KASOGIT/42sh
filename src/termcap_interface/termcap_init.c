/*
** termcap_init.c for mysh in /home/benjamin/rendu/C/PSU/PSU_2014_42sh
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Fri May  1 18:28:43 2015 Benjamin Rascol
** Last update Sun May 24 08:22:21 2015 adam soto
*/

#include "42sh.h"

static char	*get_term(t_list *ev)
{
  char		*term;

  if ((term = search_on_env(ev, "TERM=")) == NULL)
    return (NULL);
  return (term);
}

int	termcap_init(t_termcap *data, t_list *ev)
{
  char	*str;
  char	*term;

  if (isatty(0) == 0)
    return (ERROR_MYSH);
  if ((str = get_term(ev)) == NULL)
    return (ERROR_MYSH);
  if (tcgetattr(1, &data->edited_data) == -1
      || tcgetattr(1, &data->default_data) == -1)
    return (ERROR_MYSH);
  data->edited_data.c_lflag &= ~ICANON;
  data->edited_data.c_lflag &= ~ECHO;
  data->edited_data.c_cc[VMIN] = 1;
  data->edited_data.c_cc[VTIME] = 0;
  if ((term = get_term(ev)) == NULL)
    return (ERROR_MYSH);
  if (tgetent(NULL, term) == ERR
      || termcap_get_win_size(LOAD_SIZE) == NULL)
    return (ERROR_MYSH);
  free(term);
  return (SUCCESS);
}
