/*
** termcap_cursor_placing.c for mysh in /home/benjamin/rendu/C/PSU/PSU_2014_42sh
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Wed May 13 16:38:35 2015 Benjamin Rascol
** Last update Sun May 24 08:15:21 2015 adam soto
*/

#include "42sh.h"

int		termcap_cursor_placing(char *command_buffer, int i_buffer)
{
  int		prompt_size;
  t_winsize	*win_size;

  prompt_size = g_info.size_prompt;
  win_size = termcap_get_win_size(GET_SIZE);
  termcap_move_cursor(MOVE_UP, ((prompt_size + strlen(command_buffer))
				/ win_size->x)
		      - ((prompt_size + i_buffer) / win_size->x));
  termcap_move_cursor(tgoto(MOVE_POS_X, 0, 0), 1);
  termcap_move_cursor(MOVE_RIGHT, (prompt_size + i_buffer) % win_size->x);
  return (SUCCESS);
}
