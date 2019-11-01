#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "machine.h"

typedef struct arithmetic_t
{
	uint8_t opcode 	: 4;
	uint8_t dest 	: 2;
	uint8_t src 	: 2;
} arithmetic;

void add(machine_state* state);

void add_carry(machine_state* state);

void add_imm(machine_state* state);

void shift(machine_state* state);

void rotate(machine_state* state);

void exchange(machine_state* state);

void bit_and(machine_state* state);

void bit_ior(machine_state* state);

void bit_xor(machine_state* state);

void bit_not(machine_state* state);

void set(machine_state* state);

void flag_io(machine_state* state);

void interrupt(machine_state* state);

void transfer(machine_state* state);

void jump_near(machine_state* state);

void jump_far(machine_state* state);

#endif
