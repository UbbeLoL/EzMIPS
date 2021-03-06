#ifndef MIPS_INSTR_WRITER_H
#define MIPS_INSTR_WRITER_H

#include "runtime_context.h"


class mips_instr_writer
{
public:
	mips_instr_writer(void);
	~mips_instr_writer(void);

	void write_instr(const mips_instr &instr, mem_segment &segment,
		unsigned int addr);


    bool m_big_endian;
private:
	runtime_context *ctx;
};

#endif
