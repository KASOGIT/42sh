/*
** tabulation_gen.c for 42sh in /home/benjamin/rendu/C/PSU/PSU_2014_42sh
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Sun May 24 00:49:36 2015 Benjamin Rascol
** Last update Sun May 24 14:27:38 2015 Manuel Trambert
*/

#include "42sh.h"

static int	is_sep(char *str)
{
  int		i;
  int		j;
  char		**t_sep;

  j = 0;
  t_sep = str_to_wordtab("; && || | >> > < <<");
  while (t_sep[j])
    {
      i = 0;
      while (str[i])
	{
	  if (strncmp(t_sep[j], str + i, strlen(t_sep[j])) == 0)
	    {
	      free_tab(t_sep);
	      return (1);
	    }
	  i++;
	}
      j++;
    }
  free_tab(t_sep);
  return (0);
}

int	check_pos_curs(char *str, int i_buffer)
{
  int	i;

  if (i_buffer == 0)
    return (1);
  i = i_buffer;
  while (--i > 0 && str[i] != ' ');
  if (i == 0)
    return (1);
  if (i > 2 && str + i - 2 && is_sep(str + i - 2))
    return (1);
  return (0);
}

char		**get_current_match(char **str, int i)
{
  char		**to_glob;
  int		to_copy;
  int		cpt;
  char		*tmp;
  char		**cmd;
  char		**end;

  cpt = 0;
  to_copy = 0;
  if ((to_glob = malloc(sizeof(*to_glob) * 2)) == NULL)
    return (NULL);
  if ((tmp = add_star(*str, i)) == NULL)
    return (NULL);
  cmd = str_to_wordtab(tmp);
  while (check_star(cmd[to_copy]) != 1 && (to_copy += 1));
  to_glob[0] = strdup(cmd[to_copy]);
  to_glob[1] = NULL;
  to_glob = get_glob(to_glob);
  if ((end = malloc(sizeof(*end) * (size_tab(to_glob) + 1))) == NULL)
    return (NULL);
  while (to_glob[cpt] != NULL && (cpt += 1))
    end[cpt - 1] = strdup(to_glob[cpt - 1]);
  end[cpt] = NULL;
  return (end);
}

int	get_max_word_len(char **wordtab)
{
  int	i;
  int	ret;
  int	max_word_len;

  i = 0;
  max_word_len = 0;
  while (wordtab[i])
    {
      if ((ret = (int)strlen(wordtab[i])) > max_word_len)
	max_word_len = ret;
      i++;
    }
  return (max_word_len);
}

char	**tabulation_gen(char **command_buffer, int *i_buffer)
{
  char	**wordtab;

  wordtab = NULL;
  if (*i_buffer == 0 || (check_pos_curs(*command_buffer, *i_buffer) == 0))
    wordtab = get_current_match(command_buffer, *i_buffer);
  if (*i_buffer != 0 && (wordtab == NULL
			 || check_pos_curs(*command_buffer, *i_buffer) != 0))
    {
      wordtab = get_bin_cmd(command_buffer, *i_buffer);
      wordtab = unconcat_path(wordtab);
    }
  return (wordtab);
}
