#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "machine.h"
#include "instructions.h"

instruction opcodes[16];

void initialize_machine(machine_state* state)
{
	state->ram = malloc(65536);	
	opcodes[0] = &add;
	opcodes[1] = &add_carry;
	opcodes[2] = &add_imm;
	opcodes[3] = &shift;
	opcodes[4] = &rotate;
	opcodes[5] = &exchange;
	opcodes[6] = &bit_and;
	opcodes[7] = &bit_ior;
	opcodes[8] = &bit_xor;
	opcodes[9] = &bit_not;
	opcodes[10] = &set;
	opcodes[11] = &flag_io;
	opcodes[12] = &interrupt;
	opcodes[13] = &transfer;
	opcodes[14] = &jump_near;
	opcodes[15] = &jump_far;
}

void do_instruction(machine_state* state)
{
	opcode inst = *((opcode*) (state->ram + state->registers[3]));
	printf("doing instruction with opcode %X and args %X\n", inst.code, inst.args);
	(*opcodes[inst.code])(state);
}
