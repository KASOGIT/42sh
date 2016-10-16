/*
** builtin_setenv.c for  in /home/soto_a/rendu/PSU_2014_42sh/refurbish_42sh/src/manage_builtin
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sat May  9 02:03:49 2015 adam soto
** Last update Thu May 21 16:59:17 2015 adam soto
*/

#include "42sh.h"

static void	setenv_error()
{
  g_info.status = EXIT_FAILURE;
  fprintf(stderr, "setenv: Too many arguments.\n");
}

static int	run_setenv(char **tab_input, int nb_arg)
{
  char		*str_start;
  char		*str_end;
  char		*get_env;

  str_start = my_strcat_alloc(tab_input[1], "=");
  str_end = nb_arg == 2 ?
    my_strcat_alloc(str_start, "") :
    my_strcat_alloc(str_start, tab_input[2]);
  if ((get_env = search_on_env(g_info.ev, str_start)) == NULL)
    my_put_in_list(&(g_info.ev), str_end, 0);
  else
    {
      free(get_env);
      builtin_unsetenv(tab_input, 1);
      my_put_in_list(&(g_info.ev), str_end, 0);
    }
  free(str_start);
  free(str_end);
  return (EXIT_SUCCESS);
}

int	builtin_setenv(char **tab_input)
{
  int	nb_arg;

  nb_arg = size_tab(tab_input);
  if (nb_arg == 2 || nb_arg == 3)
    run_setenv(tab_input, nb_arg);
  else if (nb_arg == 1)
    my_show_list(1, g_info.ev, 0);
  else
    setenv_error();
  return (kill_proc_and_set_status());
}
