#include "reg_handler.h"
#include "..\tokens\reg_tok.h"

#include <list>

using namespace std;

reg_handler::reg_handler(){

}


reg_handler::~reg_handler(void) {
}

mips_token_ptr reg_handler::parse_token(parser_ctx &ctx, std::wstring buff){
	wchar_t firstChar = ctx.get_src_reader()->peek();
	wchar_t nextChar = ctx.get_src_reader()->peek(1);
	wstring finalBuff;
	finalBuff += firstChar;

	reg_tok *tok = NULL;

	if(ctx.get_src_reader()->is_integer(nextChar)){
		finalBuff += read_int(1, ctx);

		// Only accept within range 0-31
		int regNumber = 0;
		try {
			int regNumber = stoi(finalBuff.substr(1, finalBuff.length()-1), 0, 10);
		} catch(...){
			// Invalid number
			return NULL;
		}
		
		if(regNumber >= 0 && regNumber <= 31){
			tok = new reg_tok(ctx.get_src_reader()->get_current_row(), 
				ctx.get_src_reader()->get_current_col());
		}
	}

	// TODO: l�t zero, at osv matcha unikt fast med , p� slutet
	switch(nextChar){
	case 'a':
		if(ctx.get_src_reader()->matches(L"$at")){
			tok = new reg_tok(ctx.get_src_reader()->get_current_row(), 
				ctx.get_src_reader()->get_current_col());
			finalBuff = L"$at";
		} else if(ctx.get_src_reader()->is_integer(ctx.get_src_reader()->peek(2))){
			int regNumber = parse_reg_number(finalBuff, ctx);
		
			// Only accept within range a0-a3
			if(regNumber >= 0 && regNumber <= 3){
				tok = new reg_tok(ctx.get_src_reader()->get_current_row(), 
					ctx.get_src_reader()->get_current_col());
			}
		}
		break;
	case 'z':
		if(ctx.get_src_reader()->matches(L"$zero")){
			tok = new reg_tok(ctx.get_src_reader()->get_current_row(), 
				ctx.get_src_reader()->get_current_col());
			finalBuff = L"$zero";
		}
		break;
	case 't':
		if(ctx.get_src_reader()->is_integer(ctx.get_src_reader()->peek(2))){
			int regNumber = parse_reg_number(finalBuff, ctx);

			// Only accept within range t0-t9
			if(regNumber >= 0 && regNumber <= 9){
				tok = new reg_tok(ctx.get_src_reader()->get_current_row(), 
					ctx.get_src_reader()->get_current_col());
			}
		}
		break;
	case 's':
		if(ctx.get_src_reader()->matches(L"$sp")){
			tok = new reg_tok(ctx.get_src_reader()->get_current_row(), 
				ctx.get_src_reader()->get_current_col());
			finalBuff = L"$sp";
		} else if(ctx.get_src_reader()->is_integer(ctx.get_src_reader()->peek(2))){
			int regNumber = parse_reg_number(finalBuff, ctx);

			// Only accept within range s0-s8
			if(regNumber >= 0 && regNumber <= 8){
				tok = new reg_tok(ctx.get_src_reader()->get_current_row(), 
					ctx.get_src_reader()->get_current_col());
			}
		}
		break;
	case 'v':
		if(ctx.get_src_reader()->is_integer(ctx.get_src_reader()->peek(2))){
			int regNumber = parse_reg_number(finalBuff, ctx);

			// Only accept within range v0-v1
			if(regNumber >= 0 && regNumber <= 1){
				tok = new reg_tok(ctx.get_src_reader()->get_current_row(), 
					ctx.get_src_reader()->get_current_col());
			}
		}
		break;
	case 'k':
		if(ctx.get_src_reader()->is_integer(ctx.get_src_reader()->peek(2))){
			int regNumber = parse_reg_number(finalBuff, ctx);

			// Only accept within range k0-k1
			if(regNumber >= 0 && regNumber <= 1){
				tok = new reg_tok(ctx.get_src_reader()->get_current_row(), 
					ctx.get_src_reader()->get_current_col());
			}
		}
		break;
	case 'g':
		if(ctx.get_src_reader()->matches(L"$gp")){
			tok = new reg_tok(ctx.get_src_reader()->get_current_row(), 
				ctx.get_src_reader()->get_current_col());
			finalBuff = L"$gp";
		}
		break;
	case 'f':
		if(ctx.get_src_reader()->matches(L"$fp")){
			tok = new reg_tok(ctx.get_src_reader()->get_current_row(), 
				ctx.get_src_reader()->get_current_col());
			finalBuff = L"$fp";
		} else if(ctx.get_src_reader()->is_integer(ctx.get_src_reader()->peek(2))){
			int regNumber = parse_reg_number(finalBuff, ctx);

			// Only accept within range f0-f31
			if(regNumber >= 0 && regNumber <= 31){
				tok = new reg_tok(ctx.get_src_reader()->get_current_row(), 
					ctx.get_src_reader()->get_current_col());
			}
		}
		break;
	case 'r':
		if(ctx.get_src_reader()->matches(L"$ra")){
			tok = new reg_tok(ctx.get_src_reader()->get_current_row(), 
				ctx.get_src_reader()->get_current_col());
			finalBuff = L"$ra";
		}
		break;
	}

	if(tok != NULL){
		tok->set_raw_tok(finalBuff);
		ctx.get_src_reader()->advance(finalBuff.length());
		return mips_token_ptr(tok);
	}
	return NULL;
}

wstring reg_handler::read_int(int peek_start, parser_context &ctx){
	int counter = peek_start;
	wstring finalBuff;
	while(ctx.get_src_reader()->is_integer(
		ctx.get_src_reader()->peek(counter))){
		finalBuff += ctx.get_src_reader()->peek(counter++);
	}
	return finalBuff;
}

int reg_handler::parse_reg_number(wstring &finalBuff, parser_ctx &ctx){
	finalBuff += ctx.get_src_reader()->peek(1);
	finalBuff += read_int(2, ctx);
	int regNumber = 0;
	try {
		regNumber = stoi(finalBuff.substr(2, finalBuff.length() -2), 0, 10);
	} catch(...){
		return -1;
	}
	return regNumber;
}