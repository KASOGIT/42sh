/*
** init_end.c for mysh in /home/benjamin/rendu/C/PSU/PSU_2014_42sh
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Mon Apr 27 13:45:41 2015 Benjamin Rascol
** Last update Sun May 24 15:35:30 2015 Manuel Trambert
*/

#include "42sh.h"

static int	init_history(t_history *history)
{
  if ((history->fd_file_history = open(".history", O_CREAT | O_RDWR
			  | O_TRUNC, S_IRWXU)) == -1)
    return (ERROR_MYSH);
  history->start = NULL;
  return (SUCCESS);
}

static int	apply_command(t_termcap *data, char *command, int *boolean)
{
  if (g_history.start == NULL)
    {
      if (add_list_hist(&g_history, command) == ERROR_MYSH)
	return (ERROR_MYSH);
    }
  if (g_history.start->str
      && strcmp(g_history.start->str, command) != 0)
    {
      if (add_list_hist(&g_history, command) == ERROR_MYSH)
	return (ERROR_MYSH);
    }
  g_history.current = g_history.start;
  termcap_set_mode(&data->default_data);
  act_on_user_input_and_run_act(command, boolean);
  return (SUCCESS);
}

static int	end_termcap_program(t_termcap *data)
{
  termcap_set_mode(&data->default_data);
  my_putstr("exit\n");
  return (END_OF_PROGRAM);
}

int		command_manager(t_list *ev)
{
  int		boolean;
  t_termcap	data;
  char		*command;

  boolean = 1;
  if (termcap_init(&data, ev) == ERROR_MYSH
      || init_history(&g_history) == ERROR_MYSH)
    return (ERROR_MYSH);
  display_prompt();
  while (boolean)
    {
      termcap_set_mode(&data.edited_data);
      if ((command = get_command_line(0)) == NULL)
	return (end_termcap_program(&data));
      my_putchar('\n');
      if (strlen(command) > 0)
	if (apply_command(&data, command, &boolean) == ERROR_MYSH)
	  return (ERROR_MYSH);
      if (boolean)
	display_prompt();
      free(command);
    }
  return (SUCCESS);
}
