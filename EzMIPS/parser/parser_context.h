#pragma once

#include "lexer\token.h"
#include "parser_error.h"
#include "file\source_reader.h"
#include "..\include\source_file.h"
#include <vector>
#include <string>

class parser_context{
public:
	parser_context(void);
	parser_context(source_file *input);
	~parser_context(void);

	void push_err(std::wstring err_desc);
	void push_token(mips_token_ptr token);
	void push_label(std::wstring label);
	
	bool pool_contains_label(std::wstring label);

	source_reader* get_src_reader();
	mips_tok_vector* get_parsed_tokens();

private:
	unsigned int m_current_row;
	unsigned int m_current_col;
	ParserErrorVector m_parser_errors;
	source_reader *m_src_reader;
	mips_tok_vector *m_parsed_tokens;
	std::vector<std::wstring> m_label_pool;
};

typedef parser_context parser_ctx;
typedef std::shared_ptr<parser_ctx> ParserCtxPtr;