##
## Makefile for Makefile in /home/soto_a/rendu/minishell2
## 
## Made by Kaso Soto
## Login   <soto_a@epitech.net>
## 
## Started on  Mon Nov 10 11:40:59 2014 Kaso Soto
## Last update Sun Oct 16 15:32:06 2016 
##

NAME	=	42sh

CC	=	gcc

SRC	=	42sh.c						\
		linked_list/usual_func_on_list.c		\
		linked_list/display_on_list.c			\
		linked_list/delete_func_on_list.c		\
		manage_alias/read_file_alias.c			\
		manage_alias/free_alias.c			\
		manage_alias/check_alias.c			\
		manage_globing/glob.c				\
		manage_history/get_last_command.c		\
		manage_history/tools_history.c			\
		manage_env/search_on_env.c			\
		manage_env/search_varenv_and_replace.c		\
		manage_cmd/wait_user_input_and_init_action.c	\
		manage_cmd/manage_prompt.c			\
		manage_cmd/catch_segfault.c			\
		manage_cmd/exec_cmd_func.c			\
		manage_tree/eval_tree.c				\
		manage_tree/manage_tree.c			\
		manage_tree/run_tree.c				\
		manage_tree/delete_tree.c			\
		manage_tree/semicolon_func.c			\
		manage_tree/and_func.c				\
		manage_tree/or_func.c				\
                manage_tree/manage_op/get_pos_op.c              \
                manage_tree/manage_bracket/is_bracket.c         \
                manage_tree/manage_bracket/remove_bracket.c     \
                manage_tree/manage_backquote/is_backquote.c	\
                manage_tree/manage_backquote/remove_backquote.c	\
		manage_redir/double_right_func.c		\
		manage_redir/right_func.c			\
		manage_redir/double_left_func.c			\
		manage_redir/left_func.c			\
		manage_redir/manage_exotic/put_exotic_in_order.c\
		manage_redir/manage_exotic/put_in_order_exotic_param.c\
		manage_pipe/pipe_func.c				\
		manage_builtin/search_builtin_and_run.c		\
		manage_builtin/builtin_cd.c			\
		manage_builtin/builtin_exit.c			\
		manage_builtin/builtin_history.c		\
		manage_builtin/builtin_env.c			\
		manage_builtin/builtin_setenv.c			\
		manage_builtin/builtin_unsetenv.c		\
		manage_builtin/builtin_alias.c			\
		manage_builtin/builtin_unalias.c		\
		manage_builtin/builtin_echo.c			\
                termcap_interface/termcap_manager.c		\
		termcap_interface/command_concat.c		\
		termcap_interface/get_command_line.c		\
                termcap_interface/termcap_cursor_placing.c	\
                termcap_interface/termcap_save_load_cursor.c	\
                termcap_interface/termcap_init.c		\
                termcap_interface/termcap_utils.c		\
                termcap_interface/get_and_apply_key.c		\
                termcap_interface/key_tools/ctrl_a.c		\
                termcap_interface/key_tools/ctrl_t.c		\
                termcap_interface/key_tools/ctrl_d.c		\
                termcap_interface/key_tools/ctrl_i.c		\
                termcap_interface/key_tools/ctrl_l.c		\
                termcap_interface/key_tools/ctrl_e.c		\
                termcap_interface/key_tools/ctrl_k_w_u_y.c	\
                termcap_interface/key_tools/ctrl_arrow_keys.c	\
                termcap_interface/key_tools/arrow_keys.c	\
                termcap_interface/key_tools/tabulation.c	\
                termcap_interface/key_tools/tabulation_gen.c	\
                termcap_interface/key_tools/tabulation_fct.c	\
                termcap_interface/key_tools/tab.c		\
                termcap_interface/key_tools/del.c		\
                termcap_interface/key_tools/alt_del.c		\
                termcap_interface/key_tools/backspace.c		\
                termcap_interface/key_tools/alt_backspace.c	\
                termcap_interface/history/list.c		\
		wordtabing/path_to_wordtab.c			\
		wordtabing/list_to_wordtab.c			\
		util/get_next_line.c				\
		util/my_put_nbr.c				\
		util/putnchar.c					\
		util/my_putchar.c				\
		util/my_putstr_func.c				\
		util/str_to_wordtab.c				\
		util/free_tab.c					\
		util/my_strcat.c				\
		util/strcat_path.c				\
		util/size_tab.c					\
		util/my_strcat_alloc.c				\
		util/my_getnbr.c				\
		util/error_env.c				\
		util/kill_proc_and_set_status.c			\
		util/kill_set_and_put_error_redir.c		\
		util/file_error_redir.c				\
		util/wordtab_to_str.c				\
		util/redir_reset_glob_and_set_status.c		\

OBJ	=	$(addprefix src/, $(SRC:.c=.o))

RM	=	rm -f

CFLAGS	+=	-O2 -pipe #-W -Wall -Wextra -Werror
CFLAGS	+=	-I./include/

DEBUG	=	yes

ifeq	($(DEBUG), no)

CFLAGS	+=	-g -g3 -ggdb -Wunused-parameter

endif

all	:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) -lncurses

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
