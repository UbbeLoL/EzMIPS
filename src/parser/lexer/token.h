#pragma once
#include "platform_dependencies.h"
#include <string>
#include <memory>
#include <vector>

enum TOKEN_TYPE{
	UNDEFINED_TOK = 0x1,
	ASM_DIRECTIVE_TOK = 0x2,
	INSTR_TOK = 0x4,
	LABEL_DECL_TOK = 0x8,
	LABEL_REF_TOK = 0x10,
	REG_TOK = 0x20,
	LITERAL_TOK = 0x40
};

class mips_token
{
public:
	mips_token(TOKEN_TYPE type, unsigned int tok_row,
		unsigned int tok_col, mips_str formatted_prefix);

	~mips_token(void);
	
	void set_tok_type(TOKEN_TYPE type);
	TOKEN_TYPE get_tok_type();

	void set_tok_row(unsigned int tok_row);
	unsigned int get_tok_row();

	void set_tok_col(unsigned int tok_col);
	unsigned int get_tok_col();

	void set_raw_tok(mips_str raw_tok);
	mips_str get_raw_tok();
	void append_raw_tok(mips_char chr);

	void set_formatted_prefix(mips_str prefix);
	mips_str set_formatted_prefix();

	mips_str get_formatted_token();

	mips_token operator+(const mips_token& rhs);

private:
	unsigned int m_tok_row;
	unsigned int m_tok_col;
	mips_str m_raw_tok;
	mips_str m_formatted_prefix;
	TOKEN_TYPE m_tok_type;
};

typedef std::shared_ptr<mips_token> mips_token_ptr;
typedef std::vector<mips_token_ptr> mips_tok_vector;
typedef std::shared_ptr<mips_tok_vector> mips_tok_vectorPtr;