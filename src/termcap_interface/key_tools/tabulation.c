/*
** tab.c for 42sh in /home/benjamin/rendu/C/PSU/PSU_2014_42sh
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Thu May 21 19:57:18 2015 Benjamin Rascol
** Last update Sun May 24 14:20:37 2015 Manuel Trambert
*/

#include "42sh.h"

static int	display_tabulation(char **wordtab,
				   int nb_col, int max_word_len)
{
  int		i;
  int		nb_put;

  i = 0;
  nb_put = 0;
  while (wordtab[i])
    {
      my_putstr(wordtab[i]);
      if (nb_put == nb_col)
	{
	  nb_put = 0;
	  my_putchar('\n');
	}
      else
	putnchar(' ', max_word_len - strlen(wordtab[i]) + 7);
      nb_put++;
      i++;
    }
  return (SUCCESS);
}

static int	get_pos_end_str(char *str, int i_buffer)
{
  int		i;

  i = i_buffer;
  while (i != 0 && str[i] != ' ')
    i -= 1;
  return (i);
}

static char	*add_end_str(char *str, char *end, int i_buffer)
{
  int		i;
  int		e;
  int		to_copy;
  char		*tmp;

  i = 0;
  e = 0;
  if ((tmp = malloc(sizeof(*tmp) * (strlen(str) + strlen(end) + 2))) == NULL)
    return (NULL);
  to_copy = get_pos_end_str(str, i_buffer);
  while (str[i] != '\0' && i != to_copy)
    {
      tmp[i] = str[i];
      i += 1;
    }
  tmp[i++] = ' ';
  while (end[e] != '\0')
    {
      tmp[i] = end[e];
      i += 1;
      e += 1;
    }
  tmp[i] = '\0';
  free(str);
  return (tmp);
}

int		tabulation(char **command_buffer, int *i_buffer)
{
  int		max_word_len;
  int		nb_word;
  int		nb_col;
  char		**wordtab;
  t_winsize	*win_size;

  wordtab = tabulation_gen(command_buffer, i_buffer);
  my_putchar('\n');
  if (wordtab != NULL && (nb_word = size_tab(wordtab)) == 1)
    *command_buffer = add_end_str(*command_buffer, wordtab[0], *i_buffer);
  else if (wordtab != NULL && nb_word > 1)
    {
      if ((win_size = termcap_get_win_size(GET_SIZE)) == NULL)
	return (ERROR_MYSH);
      max_word_len = get_max_word_len(wordtab);
      if ((nb_col = win_size->x / (max_word_len + 8)) == 0)
	nb_col = 1;
      display_tabulation(wordtab, nb_col, max_word_len);
    }
  my_putchar('\n');
  display_prompt();
  my_putstr(*command_buffer);
  *i_buffer = strlen(*command_buffer);
  termcap_cursor_placing(*command_buffer, *i_buffer);
  return (SUCCESS);
}
