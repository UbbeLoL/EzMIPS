#pragma once
#include "../token.h"

#define identifier  "OPERAND_REG: "

class reg_tok :
	public mips_token
{
public:
	reg_tok(unsigned int tok_row, unsigned int tok_col);
	~reg_tok(void);
};

