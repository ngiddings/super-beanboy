#ifndef MACHINE_H
#define MACHINE_H

#include <stdint.h>
#include <string.h>

#define REG_FLAGS 13
#define REG_IP 14
#define REG_ZERO 15

enum opcode
{
	OP_ADD = 0,
	OP_ADD_CARRY = 1,
	OP_SUB = 1,
	OP_SUB_BORROW = 3,
	OP_AND = 4,
	OP_OR = 5,
	OP_XOR = 6,
	OP_NOT = 7,
	OP_SHR = 8,
	OP_SHL = 9,
	OP_ROR = 10,
	OP_ROL = 11,
	OP_SAR = 12,
	OP_XCHG = 13,
	OP_MOV_REG = 14,
	OP_MOV_IMM = 15,
	OP_JMP_NEAR = 16,
	OP_JMP_FAR = 17,
	OP_SWI = 18
};

typedef struct flags_t
{
	uint16_t carry		: 1;
	uint16_t zero		: 1;
	uint16_t overflow	: 1;
	uint16_t negative	: 1;
	uint16_t queue		: 1;
	uint16_t interrupt	: 1;
	uint16_t reserved	: 3;
	uint16_t unused		: 8;
} flags;

typedef struct machine_state_t
{
	void* ram;
	uint16_t registers[16];
	union
	{
		uint16_t flag_data;
		flags flag_register;
	};
} machine_state;

typedef struct __attribute__ ((__packed__)) inst_type_a_t
{
	
	uint16_t dest 	: 4;
	uint16_t src 	: 4;
	uint16_t unused : 2;
	uint16_t opcode : 6;
} arithmetic_inst;

typedef struct __attribute__ ((__packed__)) inst_type_b_t
{
	uint16_t dest : 4;
	uint16_t imm : 6;
	uint16_t opcode : 6;
} inst_type_b;

typedef union instruction_t
{
	arithmetic_inst arithmetic;
	inst_type_b type_b;
	uint16_t raw;
} instruction;

typedef void (*instruction_impl)(machine_state* state, instruction* inst);

void initialize_machine(machine_state* state);

void do_instruction(machine_state* state);

void add(machine_state* state, instruction* inst);

void add_carry(machine_state* state, instruction* inst);

void sub(machine_state* state, instruction* inst);

void sub_borrow(machine_state* state, instruction* inst);

void bit_and(machine_state* state, instruction* inst);

void bit_or(machine_state* state, instruction* inst);

void bit_xor(machine_state* state, instruction* inst);

void bit_not(machine_state* state, instruction* inst);

void exchange(machine_state* state, instruction* inst);

void mov_reg(machine_state* state, instruction* inst);

void mov_imm(machine_state* state, instruction* inst);

void jump_near(machine_state* state, instruction* inst);

void jump_far(machine_state* state, instruction* inst);

void swi(machine_state* state, instruction* inst);

#endif
