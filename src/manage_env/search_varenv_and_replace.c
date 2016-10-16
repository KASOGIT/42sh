/*
** search_varenv_and_replace.c for  in /home/soto_a/rendu/PSU_2014_42sh/refurbish_42sh/src/manage_env
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Wed May  6 22:32:31 2015 adam soto
** Last update Sun May 24 07:57:56 2015 adam soto
*/

#include "42sh.h"

static char	*wordtab_to_st(char **array)
{
  char		*str;
  int		i;

  i = 0;
  while (array[i])
    {
      if (i == 0)
	str = strdup(array[i]);
      else
	{
	  if ((str = realloc(str, (strlen(str) + strlen(array[i]) + 1))) == NULL)
	    return (NULL);
	  str = strcat(str, array[i]);
	}
      if (array[i + 1])
	{
	  if ((str = realloc(str, (strlen(str) + 2))) == NULL)
	    return (NULL);
	  str = strcat(str, " ");
	}
      i++;
    }
  free_tab(array);
  return (str);
}

static void	replace_str_by_varenv(char **tab_usr_input, int i)
{
  char		*read_var;

  if ((read_var =
       search_on_env(g_info.ev, tab_usr_input[i] + 1)) != NULL)
    {
      free(tab_usr_input[i]);
      tab_usr_input[i] = read_var;
    }
}

char    *search_varenv_and_replace(char *user_input)
{
  int   i;
  char  *read_var;
  char  **tab_usr_input;

  i = 0;
  tab_usr_input = str_to_wordtab(user_input);
  while (tab_usr_input[i])
    {
      if (tab_usr_input[i][0] == '$' && tab_usr_input[i][1])
	replace_str_by_varenv(tab_usr_input, i);
      else if (tab_usr_input[i][0] == '~'
	       && (read_var = search_on_env(g_info.ev, "HOME")) != NULL)
	{
	  if (strlen(tab_usr_input[i]) > 1)
	    read_var = my_strcat(read_var, tab_usr_input[i] + 1);
	  free(tab_usr_input[i]);
	  tab_usr_input[i] = read_var;
	}
      i++;
    }
  return (wordtab_to_st(tab_usr_input));
}
