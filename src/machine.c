#include "machine.h"
#include <stdlib.h>

void initialize_machine(machine_state* state)
{
	state->ram = malloc(65536);
	state->register_a = 0;
	state->register_b = 0;
	state->stack_pointer = 0;
	state->instruction_pointer = 0;
	state->flags = 0;
}

void add(machine_state* state)
{
	arithmetic* opcode = state->ram + state->instruction_pointer;
	state->registers[opcode->dest] = state->registers[opcode->dest] + state->registers[opcode->src];	
}
