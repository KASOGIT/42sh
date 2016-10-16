/*
** manage_prompt.c for  in /home/soto_a/rendu/PSU_2014_42sh/refurbish_42sh/src/manage_cmd
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Wed May  6 20:53:57 2015 adam soto
** Last update Wed May 20 15:22:33 2015 Benjamin Rascol
*/

#include "42sh.h"

static int	is_not_last_folder(char *pwd)
{
  int		i;

  i = 0;
  while (pwd[i])
    {
      if (pwd[i] == '/')
	return (1);
      i++;
    }
  return (0);
}

static char	*get_last_folder(char *pwd, char *adjust_pwd, int *i, int *j)
{
  if ((adjust_pwd = realloc(adjust_pwd, (strlen(adjust_pwd)
       + strlen(pwd + *i + 1) + 2))) == NULL)
    return (NULL);
  while (pwd[*i])
    {
      adjust_pwd[*j] = pwd[*i];
      (*i)++;
      (*j)++;
    }
  adjust_pwd[*j] = '\0';
  return (adjust_pwd);
}

static char	*create_adjust_pwd(char *pwd, char *adjust_pwd, int i, int j)
{
  while (pwd[i])
    {
      if (pwd[i] == '/' && pwd[i + 1] && is_not_last_folder(pwd + i + 1))
        {
          if ((adjust_pwd = realloc(adjust_pwd,
				    strlen(adjust_pwd) + 3)) == NULL)
            return (NULL);
          adjust_pwd[j] = '/';
          adjust_pwd[j + 1] = pwd[i + 1];
          adjust_pwd[j + 2] = '\0';
          j += 2;
	  i += 2;
        }
      else if (pwd[i] == '/' && pwd[i + 1] && !is_not_last_folder(pwd + i + 1))
	{
	  if ((adjust_pwd = get_last_folder(pwd, adjust_pwd, &i, &j)) == NULL)
	    return (NULL);
	}
      else
	i++;
    }
  return (adjust_pwd);
}

static char	*get_adjust_pwd(char *pwd)
{
  char		*adjust_pwd;
  char		*home;
  int		i;
  int		j;

  j = 1;
  if ((home = search_on_env(g_info.ev, "HOME=")) == NULL)
    home = strdup("");
  if (strncmp(home, pwd, strlen(home)) == 0)
    adjust_pwd = strdup("~");
  else
    {
      adjust_pwd = strdup("");
      j = 0;
    }
  i = strlen(home);
  free(home);
  return (adjust_pwd = create_adjust_pwd(pwd, adjust_pwd, i, j));
}

int	display_prompt()
{
  char	*pwd;
  char	buffer[4096];
  char	*adjust_pwd;

  g_info.size_prompt = 12;
  if ((pwd = search_on_env(g_info.ev, "PWD=")) == NULL)
    pwd = strdup("");
  if ((adjust_pwd = get_adjust_pwd(pwd)) == NULL)
    return (EXIT_FAILURE);
  g_info.size_prompt += strlen(adjust_pwd);
  g_info.size_prompt += sprintf(buffer, "%d", g_info.nbr_cmd);
  my_putstr_color("[", ANSI_COLOR_BLUE);
  my_put_nbr(g_info.nbr_cmd);
  my_putstr_color("] ", ANSI_COLOR_BLUE);
  my_putstr_color(adjust_pwd, ANSI_COLOR_RED);
  my_putstr_color(" YinB $> ", ANSI_COLOR_YELLOW);
  free(adjust_pwd);
  free(pwd);
  return (EXIT_SUCCESS);
}
