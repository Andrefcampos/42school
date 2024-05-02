/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:00:35 by andrefil          #+#    #+#             */
/*   Updated: 2024/05/02 23:25:25 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef enum e_tokens tokens;
enum	e_tokens
{
	NONE = 0,
	WORD,
	EXPANSION,
	LESS,
	GREAT,
	DLESS,
	DGREAT,
	PIPE,
};

typedef enum e_ast_type type_ast;
enum	e_ast_type
{
	STRING = 10,
	FILENAME,
	COMMAND,
	OUTPUT,
	INPUT,
	APPEND,
	HERE_DOC,
	PIPE_LINE,
};

typedef enum e_returns	returns;
enum	e_returns
{
	END = 666,
	ERROR = -1,
	FALSE = 0,
	TRUE = 1,
};

typedef enum e_sides	side;
enum	e_sides
{
	LEFT = 1,
	RIGHT,
};

typedef enum e_check	check;
enum	e_check
{
	KO = -1,
	EMPTY = 0,
	OK = 1,
};

typedef struct	s_token	t_token;
struct	s_token
{
	char		*content;
	tokens		token;
	t_token		*next;
	t_token		*prev;
};

typedef struct s_ast	t_ast;
struct	s_ast
{
	char		*content;
	type_ast	ast_type;
	t_token		*token_node;
	t_token		*left_token; //viabilizar a possibilidade de usar esses endereços ta variavel "token_node";
	t_token		*right_token; // essa também.
	t_ast		*left;
	t_ast		*right;
};

typedef struct s_env_var	t_env_var;
struct s_env_var
{
	char		*key;
	char		*value;
	t_env_var	*next;
};

/*----- TOKENIZER: -----*/
t_token	*build_redirect_token(int *i, char *cmd_line);
t_token	*build_word_token(int *i, char *cmd_line);
t_token	*build_expansion_token(int *i, char *cmd_line);
t_token	*build_quote_token(int *i, char *cmd_line);
int		build_token(char *cmd_line, t_token **token_list);

/*----- TOKENIZER-UTILS: -----*/
void	token_lstclear(t_token **lst);
void	token_lstadd_back(t_token **lst, t_token *new);
t_token	*token_lstnew(char *content, tokens type);
t_token	*token_lstlast(t_token *lst);

/*----- AST: -----*/
void	build_ast_node(t_token *new_node, t_ast **ast_list, int state);
t_ast	*break_in_two(t_token *current, t_ast **ast_list, int state);
void	continue_division_left(tokens operator, t_ast *ast_current_node, \
							t_ast **ast_list);
void	continue_division_right(tokens operator, t_ast *ast_current_node, \
							 t_ast **ast_list);
int		start_ast(t_token **token_list, tokens operator, t_ast **ast_list);
void	scan_token_list(t_token **token_list, t_ast **ast_list);

/*----- AST-UTILS: -----*/
void		ast_lstadd_right(t_ast **lst, t_ast *new);
void		ast_lstadd_left(t_ast **lst, t_ast *new);
t_ast		*ast_lstnew(char *content, tokens type);
void		ast_lstclear(t_ast **lst);
type_ast	type_check(char *content, tokens token);

/*----- BUILT-INS: -----*/
int		call_builtins(char *input);
void	put_pwd(void);
void	change_dir(char *cmd);

/*----- EXECUTION: -----*/
int	execute_operator(t_ast *operator);
void	execute_ast(t_ast *node, t_ast **ast_list, t_token **token_list);
void	execute_single_cmd(t_ast *node, t_ast **ast_list, t_token **token_list);
void	begin_executing(t_ast **ast_list, t_token **token_list);
char	**get_command_args(char *content);
int	execute_command(char *content);
int	execute_here_doc(t_ast *operator);
void	execute_redirect(t_ast *operator, int file_fd, int redirection_flag);
int	execute_pipe(t_ast *operator);
int	execute_redirect_input(t_ast *operator);
int	execute_redirect_output(t_ast *operator);
int	execute_redirect_append(t_ast *operator);


/*----- PARSER: -----*/
int		syntax_checker(const char *input);

/*----- STR-UTILS: -----*/
int		is_space(char c);
int		ft_isspace(int c);
char	*ft_strndup(const char *src, int size);

/*----- FREE: -----*/
void	free_data(t_ast **ast_list, t_token **token_list);

#endif
