#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "machine.h"

typedef struct arithmetic_t
{
	uint8_t code 	: 4;
	uint8_t dest 	: 2;
	uint8_t src 	: 2;
} arithmetic;

typedef struct shift_inst_t
{
	uint8_t code 	: 4;
	uint8_t dest 	: 2;
	uint8_t src 	: 1;
	uint8_t dir		: 1;
} shift_inst;

typedef struct set_inst_t
{
	uint8_t code 	: 4;
	uint8_t dest 	: 2;
	uint8_t ignore 	: 2;
	uint16_t data;
} set_inst;

typedef struct flag_inst_t
{
	uint8_t code 	: 4;
	uint8_t flagID 	: 3;
	uint8_t set	 	: 1;
} flag_inst;

typedef struct transfer_inst_t
{
	uint8_t code 	: 4;
	uint8_t dest 	: 2;
	uint8_t bus	 	: 1;
	uint8_t dir	 	: 1;
	uint8_t arg;
} transfer_inst;

typedef struct near_jump_inst_t
{
	uint8_t code 	: 4;
	uint8_t cond 	: 4;
	uint8_t dist;
} near_jump_inst;

typedef struct far_jump_inst_t
{
	uint8_t code 	: 4;
	uint8_t cond 	: 4;
} far_jump_inst;

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
