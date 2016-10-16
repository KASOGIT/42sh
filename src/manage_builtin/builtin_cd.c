/*
** builtin_cd.c for  in /home/soto_a/rendu/PSU_2014_42sh/refurbish_42sh/src/manage_builtin
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sat May  9 02:01:06 2015 adam soto
** Last update Sun May 17 18:51:44 2015 adam soto
*/

#include "42sh.h"

static int	error_cd(char *msg)
{
  g_info.status = EXIT_FAILURE;
  fprintf(stderr, "%s\n", msg);
  if (g_info.state_multi == 1)
    kill(getpid(), SIGKILL);
  return (EXIT_FAILURE);
}

static int	reverse_pwd_old_new(t_list *ev)
{
  char		**array;
  char		*old_pwd;
  char		*pwd;

  if ((pwd = search_on_env(ev, "OLDPWD=")) == NULL)
    return (error_env("oldpwd"));
  if ((old_pwd = search_on_env(ev, "PWD=")) == NULL)
    return (error_env("pwd"));
  if (chdir(pwd) == -1)
    return (-1);
  pwd = my_strcat_alloc("setenv PWD ", pwd);
  array = str_to_wordtab(pwd);
  builtin_setenv(array);
  free(pwd);
  free_tab(array);
  pwd = my_strcat_alloc("setenv OLDPWD ", old_pwd);
  array = str_to_wordtab(pwd);
  builtin_setenv(array);
  free(pwd);
  free(old_pwd);
  free_tab(array);
  return (0);
}

static int	set_pwd_at_home(t_list *ev)
{
  char		**array;
  char		*old_pwd;
  char		*pwd;

  if ((old_pwd = search_on_env(ev, "PWD=")) == NULL)
    return (error_env("pwd"));
  if ((pwd = search_on_env(ev, "HOME=")) == NULL)
    return (error_env("home"));
  if (chdir(pwd) == -1)
    return (-1);
  old_pwd = my_strcat_alloc("setenv OLDPWD ", old_pwd);
  array = str_to_wordtab(old_pwd);
  builtin_setenv(array);
  free_tab(array);
  free(old_pwd);
  pwd = my_strcat_alloc("setenv PWD ", pwd);
  array = str_to_wordtab(pwd);
  builtin_setenv(array);
  free_tab(array);
  free(pwd);
  return (0);
}

static int	advance_in_folder_and_refresh_pwd(char *dest_fold)
{
  char		*pwd;
  char		*old_pwd;
  char		**array;
  char		path[4098];

  if (chdir(dest_fold) == -1)
    return (-1);
  if ((old_pwd = search_on_env(g_info.ev, "PWD=")) == NULL)
    return (error_env("pwd"));
  pwd = my_strcat_alloc("setenv OLDPWD ", old_pwd);
  array = str_to_wordtab(pwd);
  builtin_setenv(array);
  free(pwd);
  free(old_pwd);
  free_tab(array);
  if ((pwd = getcwd(path, 4098)) == NULL)
    return (error_env("actual path"));
  old_pwd = my_strcat_alloc("setenv PWD ", pwd);
  array = str_to_wordtab(old_pwd);
  builtin_setenv(array);
  free(old_pwd);
  free_tab(array);
  return (0);
}

int	builtin_cd(char **tab_input)
{
  if (size_tab(tab_input) == 2)
    {
      if (tab_input[1][0] == '-' && strlen(tab_input[1]) == 1)
        {
          if (reverse_pwd_old_new(g_info.ev) == -1)
            return (error_cd("No such file or directory."));
        }
      else
	{
	  if (advance_in_folder_and_refresh_pwd(tab_input[1]) == -1)
	    return (error_cd("No such file or directory."));
	}
    }
  else if (size_tab(tab_input) == 1)
    {
      if (set_pwd_at_home(g_info.ev) == -1)
        return (error_cd("Path set by HOME in env is not reachable."));
    }
  else
    return (error_cd("cd: Too many arguments."));
  g_info.status = EXIT_SUCCESS;
  if (g_info.state_multi == 1)
    kill(getpid(), SIGKILL);
  return (EXIT_SUCCESS);
}
