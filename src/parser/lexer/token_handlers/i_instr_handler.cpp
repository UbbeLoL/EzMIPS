#include "i_instr_handler.h"
#include "../tokens/i_instr_tok.h"

#include <list>

using namespace std;

i_instr_handler::i_instr_handler(){

}


i_instr_handler::~i_instr_handler(void) {
}

mips_token_ptr i_instr_handler::parse_token(parser_ctx &ctx, std::string buff){
    i_instr_tok *tok = NULL;

    if(buff == instr_addi){
		tok = new i_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
        tok->set_raw_tok(instr_addi);
		ctx.get_src_reader()->advance(4);
    } else if(buff == instr_addiu){
		tok = new i_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
        tok->set_raw_tok(instr_addiu);
		ctx.get_src_reader()->advance(5);

    } else if(buff == instr_beq){
		tok = new i_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
        tok->set_raw_tok(instr_beq);
		ctx.get_src_reader()->advance(3);

    } else if(buff == instr_bne){
		tok = new i_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
        tok->set_raw_tok(instr_bne);
		ctx.get_src_reader()->advance(3);

    } else if(buff == instr_lbu){
		tok = new i_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
        tok->set_raw_tok(instr_lbu);
		ctx.get_src_reader()->advance(3);

    } else if(buff == instr_lhu){
		tok = new i_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
        tok->set_raw_tok(instr_lhu);
		ctx.get_src_reader()->advance(3);

    } else if(buff == instr_lui){
		tok = new i_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
        tok->set_raw_tok(instr_lui);
		ctx.get_src_reader()->advance(3);

    } else if(buff == instr_lw){
		tok = new i_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
        tok->set_raw_tok(instr_lw);
		ctx.get_src_reader()->advance(2);

    } else if(buff == instr_sb){
		tok = new i_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
        tok->set_raw_tok(instr_sb);
		ctx.get_src_reader()->advance(2);

    } else if(buff == instr_sh){
		tok = new i_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
        tok->set_raw_tok(instr_sh);
		ctx.get_src_reader()->advance(2);

    } else if(buff == instr_slti){
		tok = new i_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
        tok->set_raw_tok(instr_slti);
		ctx.get_src_reader()->advance(4);

    } else if(buff == instr_sltiu){
		tok = new i_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
        tok->set_raw_tok(instr_sltiu);
		ctx.get_src_reader()->advance(5);

    } else if(buff == instr_sw){
		tok = new i_instr_tok(ctx.get_src_reader()->get_current_row(),
			ctx.get_src_reader()->get_current_col());
        tok->set_raw_tok(instr_sw);
		ctx.get_src_reader()->advance(2);

	} else {
		return NULL;
	}

	return mips_token_ptr(tok);
}
