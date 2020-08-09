#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "machine.h"

instruction_impl opcodes[64];

void initialize_machine(machine_state* state)
{
	memset((void*) state, 0, sizeof(machine_state));
	state->ram = malloc(65536);	
	opcodes[OP_ADD] = &add;
	opcodes[OP_ADD_CARRY] = &add_carry;
	opcodes[OP_SUB] = &sub;
	opcodes[OP_AND] = &bit_and;
	opcodes[OP_OR] = &bit_or;
	opcodes[OP_XOR] = &bit_xor;
	opcodes[OP_NOT] = &bit_not;
	opcodes[OP_XCHG] = &exchange;
	opcodes[OP_MOV_REG] = &mov_reg;
	opcodes[OP_MOV_IMM] = &mov_imm;
	opcodes[OP_SWI] = &swi;
	opcodes[OP_JMP_NEAR] = &jump_near;
	opcodes[OP_JMP_FAR] = &jump_far;
}

void do_instruction(machine_state* state)
{
	instruction inst = *((instruction*) (state->ram + state->registers[REG_IP]));
	printf("doing instruction with data %04X\n", inst.raw);
	printf("op: %04X\tdest: %04X\tsrc: %04X\n", inst.arithmetic.opcode, inst.arithmetic.dest, inst.arithmetic.src);
	opcodes[inst.arithmetic.opcode](state, &inst);
	state->registers[REG_IP] += sizeof(instruction);
}

void add(machine_state* state, instruction* inst)
{
	state->registers[inst->arithmetic.dest] += state->registers[inst->arithmetic.src];
}

void add_carry(machine_state* state, instruction* inst)
{
	state->registers[inst->arithmetic.dest] += state->registers[inst->arithmetic.src] + state->flag_register.carry;
}

void sub(machine_state* state, instruction* inst)
{
	state->registers[inst->arithmetic.dest] += state->registers[inst->arithmetic.src];
}

void sub_borrow(machine_state* state, instruction* inst)
{
	state->registers[inst->arithmetic.dest] -= state->registers[inst->arithmetic.src] - state->flag_register.carry;
}

void bit_and(machine_state* state, instruction* inst)
{
	state->registers[inst->arithmetic.dest] &= state->registers[inst->arithmetic.src];
}

void bit_or(machine_state* state, instruction* inst)
{
	state->registers[inst->arithmetic.dest] |= state->registers[inst->arithmetic.src];
}

void bit_xor(machine_state* state, instruction* inst)
{
	state->registers[inst->arithmetic.dest] ^= state->registers[inst->arithmetic.src];
}

void bit_not(machine_state* state, instruction* inst)
{
	state->registers[inst->arithmetic.dest] = ~state->registers[inst->arithmetic.dest];
}

void exchange(machine_state* state, instruction* inst)
{
	uint16_t buffer = state->registers[inst->arithmetic.dest];
	state->registers[inst->arithmetic.dest] = state->registers[inst->arithmetic.src];
	state->registers[inst->arithmetic.src] = buffer;
}

void mov_reg(machine_state* state, instruction* inst)
{
	state->registers[inst->arithmetic.dest] = state->registers[inst->arithmetic.src];
}

void mov_imm(machine_state* state, instruction* inst)
{
	state->registers[inst->type_b.dest] = state->registers[inst->type_b.imm];
}

void jump_near(machine_state* state, instruction* inst)
{

}

void jump_far(machine_state* state, instruction* inst)
{

}

void swi(machine_state* state, instruction* inst)
{

}
