#ifndef R_INSTR_TOK_H
#define R_INSTR_TOK_H

#include "instr_base_tok.h"
class r_instr_tok :
	public instr_base_tok
{
public:
    r_instr_tok(INSTRUCTION_CODE code, INSTRUCTION_TYPE type, unsigned int tok_row,
		unsigned int tok_col);
	~r_instr_tok(void);
};

#endif
