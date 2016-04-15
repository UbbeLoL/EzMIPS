#ifndef LABEL_DECL_TOK_H
#define LABEL_DECL_TOK_H

#include "../token.h"

#define identifier "LABEL_DECL: "

class label_decl_tok :
	public mips_token
{
public:
	label_decl_tok(unsigned int tok_row, unsigned int tok_col);
	~label_decl_tok(void);
};

#endif
