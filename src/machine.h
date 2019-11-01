#ifndef MACHINE_H
#define MACHINE_H

#include <stdint.h>

typedef struct machine_state_t
{
	void* ram;
	uint16_t registers[4];
	uint16_t flags;
} machine_state;

typedef struct arithmetic_t
{
	uint8_t opcode 	: 4;
	uint8_t dest 	: 2;
	uint8_t src 	: 2;
} arithmetic;

typedef void (*instruction)(machine_state* state);

void initialize_machine(machine_state* state);

void add(machine_state* state);

#endif
