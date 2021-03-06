#ifndef ASM_DIRECTIVE_TOK_H
#define ASM_DIRECTIVE_TOK_H

#include "../token.h"

#define identifier "ASM_DIRECTIVE: "

enum ASSEMBLER_DIRECTIVE{
	DIRECTIVE_ALIGN = 0,
	DIRECTIVE_ASCII = 1,
	DIRECTIVE_ASCIIZ = 2,
	DIRECTIVE_DATA = 4,
	DIRECTIVE_TEXT = 8
};

class asm_directive_tok :
	public mips_token
{
public:
	asm_directive_tok(unsigned int tok_row, unsigned int tok_col);
	~asm_directive_tok(void);

	void set_directive(ASSEMBLER_DIRECTIVE directive);
	ASSEMBLER_DIRECTIVE get_directive();

private:
	ASSEMBLER_DIRECTIVE m_directive;
};

#endif
