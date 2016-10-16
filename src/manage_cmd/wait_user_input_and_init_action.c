/*
** wait_user_input_and_init_action.c for  in /home/soto_a/rendu/PSU_2014_42sh/refurbish_42sh/src/manage_cmd
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Wed May  6 15:08:50 2015 adam soto
** Last update Sun May 24 22:01:57 2015 adam soto
*/

#include "42sh.h"

int	only_space_tab(char *user_input)
{
  int	i;

  i = 0;
  while (user_input[i])
    {
      if (!(user_input[i] == ' ' || user_input[i] == '\t'))
	return (0);
      i++;
    }
  return (1);
}

int	act_on_user_input_and_run_act(char *user_input, int *boolean)
{
  char	*epur_input;

  epur_input = NULL;
  if (user_input && strlen(user_input) > 0
      && only_space_tab(user_input) == 0
      && str_is_printable((unsigned char *)user_input) == 1)
    {
      epur_input = search_varenv_and_replace(user_input);
      if (epur_input && strlen(epur_input) > 0
	  && only_space_tab(epur_input) == 0
	  && str_is_printable((unsigned char *)epur_input) == 1)
	{
	  run_act_on_tree(strdup(epur_input));
	  g_info.nbr_cmd++;
	  free(epur_input);
	  if (g_info.status == EXIT_MODE)
	    *boolean = 0;
	}
    }
  return (EXIT_SUCCESS);
}

int	str_is_printable(unsigned char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] < 7 || str[i] > 127)
	return (0);
      i++;
    }
  return (1);
}

int		wait_user_input_and_init_action()
{
  char		*user_input;
  int		boolean;

  boolean = 1;
  g_info.nbr_cmd = 0;
  if (display_prompt() == EXIT_FAILURE)
    return (EXIT_FAILURE);
  while (boolean && (user_input = get_next_line(0)) != NULL)
    {
      if (str_is_printable((unsigned char *)user_input) == 1)
	act_on_user_input_and_run_act(user_input, &boolean);
      free(user_input);
      if (boolean && display_prompt() == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  fprintf(stderr, "exit\n");
  my_free_alias(&(g_info.alias));
  my_free_list(&g_info.ev);
  free(g_info.alias);
  return (g_info.val_exit);
}
