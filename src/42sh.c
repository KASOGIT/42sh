/*
** 42sh.c for  in /home/trambe_m/PSU_2014_42sh/src
** 
** Made by Manuel Trambert
** Login   <trambe_m@epitech.net>
** 
** Started on  Tue May 19 18:57:42 2015 Manuel Trambert
** Last update Sun May 24 22:21:18 2015 adam soto
*/

#include "42sh.h"

t_info		g_info;
t_history	g_history;

void	handler()
{
  my_putstr("\b  \n");
  display_prompt();
}

void	resize_handler()
{
  termcap_get_win_size(LOAD_SIZE);
}

static void	init_g_info()
{
  g_info.mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
  g_info.status = EXIT_SUCCESS;
  g_info.state_multi = 0;
  g_info.state_redir = 0;
  g_info.val_exit = 0;
}

int		main(__attribute__((unused))int ac,
		     __attribute__((unused))char **av,
		     char **env)
{
  init_g_info();
  if ((g_info.alias = malloc(sizeof(*(g_info.alias)))) == NULL)
    return (-1);
  if ((fill_file_alias()) == -1)
    return (-1);
  my_init_list(&(g_info.ev));
  signal(SIGINT, handler);
  signal(SIGWINCH, resize_handler);
  if (env[0] == NULL)
    {
      fprintf(stderr, "No env found, a basic is running...\n");
      my_put_in_list(&(g_info.ev), "PATH=/usr/bin", 0);
    }
  else
    my_create_list(&(g_info.ev), env);
  if (command_manager(g_info.ev) == ERROR_MYSH)
    return (wait_user_input_and_init_action());
  return (g_info.val_exit);
}
