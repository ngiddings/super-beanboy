#ifndef MACHINE_H
#define MACHINE_H

#include <stdint.h>

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
	uint16_t registers[4];
	union
	{
		uint16_t flag_data;
		flags flag_register;
	}
} machine_state;

typedef struct opcode_t
{
	uint8_t code	: 4;
	uint8_t args	: 4;
} opcode;

typedef void (*instruction)(machine_state* state);

void initialize_machine(machine_state* state);

void do_instruction(machine_state* state);

#endif
