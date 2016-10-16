/*
** get_and_apply_key.c for  in /home/soto_a/rendu/PSU_2014_42sh/src
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Sun May 24 08:25:54 2015 adam soto
** Last update Sun May 24 08:25:55 2015 adam soto
*/

#include "42sh.h"

static t_key	key[] =
  {
    {{1, '\0'}, &ctrl_a},
    {{2, '\0'}, &fkey_left},
    {{4, '\0'}, &ctrl_d},
    {{5, '\0'}, &ctrl_e},
    {{6, '\0'}, &fkey_right},
    {{8, '\0'}, &backspace},
    {{9, '\0'}, &tabulation},
    {{11, '\0'}, &ctrl_k},
    {{12, '\0'}, &ctrl_l},
    {{16, '\0'}, &fkey_up},
    {{20, '\0'}, &ctrl_t},
    {{21, '\0'}, &ctrl_u},
    {{23, '\0'}, &ctrl_w},
    {{25, '\0'}, &ctrl_y},
    {{127, '\0'}, &backspace},
    {{27, 127, '\0'}, &alt_backspace},
    {{27, 91, 65, '\0'}, &fkey_up},
    {{27, 91, 66, '\0'}, &fkey_down},
    {{27, 91, 67, '\0'}, &fkey_right},
    {{27, 91, 68, '\0'}, &fkey_left},
    {{27, 91, 51, 126, '\0'}, &del},
    {{27, 91, 49, 59, 53, 67, '\0'}, &ctrl_key_right},
    {{27, 91, 49, 59, 53, 68, '\0'}, &ctrl_key_left},
    {{27, 91, 51, 59, 51, 126, '\0'}, &alt_del},
    {{0}, NULL}
  };

static int	char_is_printable(unsigned char c)
{
  if (c >= 7 && c <= 127)
    return (1);
  return (0);
}

int	get_and_apply_key(char **command_buffer, char *str, int *i_buffer)
{
  int	i;

  i = 0;
  while (key[i].ptr != NULL)
    {
      if (strcmp(key[i].key, str) == 0)
	return (key[i].ptr(command_buffer, i_buffer));
      i++;
    }
  if (strlen(str) > 1 || iscntrl(str[0]) || char_is_printable(str[0]) == 0)
    return (IGNORE_KEY);
  return (NO_KEY_FOUND);
}
