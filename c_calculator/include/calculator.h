#ifndef CALCULATOR_H
# define CALCULATOR_H
# include <stdlib.h>

typedef enum e_tok_type		t_tok_type;
typedef union u_tok_value	t_tok_value;
typedef struct s_tok		t_tok;

typedef enum e_tok_type
{
	NULL_TOKEN,
	INTEGER,
	OPERAND,
	LBRACKET,
	RBRACKET,
}	t_tok_type;

struct s_tok
{
	t_tok_type	type;
	long		value;
};

t_tok	*new_tok(t_tok_type type, long value);
void	del_tok(t_tok *tok);

#endif
