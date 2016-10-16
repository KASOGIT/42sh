/*
** exec_cmd_func.c for  in /home/soto_a/rendu/PSU_2014_42sh/refurbish_42sh/src/manage_cmd
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Fri May  8 14:45:46 2015 adam soto
** Last update Sun May 24 23:24:17 2015 adam soto
*/

#include "42sh.h"

static int	concat_path_and_exec(char **tab_input, char **tab_path_bin,
				     char **tab_env, t_exec *exec)
{
  char		*final_path;

  if ((tab_input[0][0] == '/' || tab_input[0][0] == '.'
      || strncmp(tab_path_bin[exec->i], tab_input[0],
		 strlen(tab_path_bin[exec->i])) == 0))
    final_path = strdup(tab_input[0]);
  else
    final_path = strcat_path(tab_path_bin[exec->i], tab_input[0]);
  if (access(final_path, X_OK) == 0)
    {
      exec->boolean = 0;
      g_info.status = EXIT_SUCCESS;
      if (execve(final_path, tab_input, tab_env) == -1)
	{
	  fprintf(stderr, "execve error on cmd: %s\n", tab_input[0]);
	  g_info.status = EXIT_FAILURE;
	  kill(getpid(), SIGKILL);
	  return (0);
	}
    }
  free(final_path);
  return (EXIT_SUCCESS);
 }

static int	exec_bin(char **tab_input, char **tab_path_bin)
{
  char		**tab_env;
  t_exec	exec;

  exec.i = -1;
  exec.boolean = 1;
  tab_env = list_to_wordtab(&(g_info.ev));
  while (tab_path_bin[++(exec.i)] && exec.boolean)
    concat_path_and_exec(tab_input, tab_path_bin, tab_env, &exec);
  free_tab(tab_env);
  if (exec.boolean)
    {
      g_info.status = EXIT_FAILURE;
      fprintf(stderr, "%s: Command not found.\n", tab_input[0]);
      kill(getpid(), SIGKILL);
      return (EXIT_FAILURE);
    }
  else
    return ((g_info.status = EXIT_SUCCESS));
  return (EXIT_SUCCESS);
}

char		**get_tab_path(t_list *ev)
{
  char		*path_bin;
  char		**tab_path_bin;

  if ((path_bin = search_on_env(ev, "PATH=")) == NULL)
    path_bin = strdup("");
  path_bin = my_strcat(path_bin, ":\0");
  tab_path_bin = path_to_wordtab(path_bin);
  free(path_bin);
  return (tab_path_bin);
}

static char	**get_final_tab(t_tree **node)
{
  char		**tab_input;

  tab_input = str_to_wordtab((*node)->data);
  tab_input = get_glob(tab_input);
  if ((tab_input = get_history_command(tab_input)) == NULL)
    return (NULL);
  tab_input = get_alias(g_info.alias, tab_input);
  return (tab_input);
}

int	exec_cmd_func(t_tree **node)
{
  pid_t	pid;
  char	**tab_path_bin;
  char	**tab_input;

  if ((tab_input = get_final_tab(node)) == NULL)
    return (EXIT_FAILURE);
  if (search_builtin_and_run(tab_input) == 0)
    {
      tab_path_bin = get_tab_path(g_info.ev);
      if (g_info.state_multi == 0)
      	{
  	  if ((pid = vfork()) == 0)
  	    exec_bin(tab_input, tab_path_bin);
  	  else
	    wait_pid_and_sev(pid);
      	}
      else
      	exec_bin(tab_input, tab_path_bin);
      free_tab(tab_path_bin);
    }
  free_tab(tab_input);
  return (EXIT_SUCCESS);
}
