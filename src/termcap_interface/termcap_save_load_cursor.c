/*
** termcap_save_load_cursor.c for mysh in /home/benjamin/rendu/C/PSU/PSU_2014_42sh
** 
** Made by Benjamin Rascol
** Login   <rascol_b@epitech.net>
** 
** Started on  Wed May 13 11:40:27 2015 Benjamin Rascol
** Last update Wed May 20 13:44:07 2015 Benjamin Rascol
*/

#include "42sh.h"

int	termcap_save_cursor_pos()
{
  char  *str;

  if ((str = tgetstr("sc", NULL)) == NULL)
    return (ERROR_MYSH);
  if (tputs(str, 0, termcap_putchar) == -1)
    return (ERROR_MYSH);
  return (SUCCESS);
}

int	termcap_load_cursor_pos()
{
  char  *str;

  if ((str = tgetstr("rc", NULL)) == NULL)
    return (ERROR_MYSH);
  if (tputs(str, 0, termcap_putchar) == -1)
    return (ERROR_MYSH);
  return (SUCCESS);
}
