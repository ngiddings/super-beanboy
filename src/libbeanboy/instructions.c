#include "instructions.h"

void add(machine_state* state)
{
	arithmetic* inst = state->ram + state->registers[3];
	state->registers[inst->dest] += state->registers[inst->src];	
	state->registers[3] += 1;
}

void add_carry(machine_state* state)
{
	arithmetic* inst = state->ram + state->registers[3];
	state->registers[inst->dest] += state->registers[inst->src] + state->flag_register.carry;	
	state->registers[3] += 1;
}

void add_imm(machine_state* state)
{
	arithmetic* inst = state->ram + state->registers[3];
	state->registers[inst->dest] += inst->src;	
	state->registers[3] += 1;
}

void shift(machine_state* state)
{
	shift_inst* inst = state->ram + state->registers[3];
	if(inst->dir == 0)
	{
		state->registers[inst->dest] <<= state->registers[inst->src];
	}
	else
	{
		state->registers[inst->dest] >>= state->registers[inst->src];
	}
}

void rotate(machine_state* state)
{
	shift_inst* inst = state->ram + state->registers[3];
	if(inst->dir == 0)
	{
		state->registers[inst->dest] = (state->registers[inst->dest] << state->registers[inst->src]) | (state->registers[inst->dest] >> (16 - state->registers[inst->src]));
	}
	else
	{
		state->registers[inst->dest] = (state->registers[inst->dest] >> state->registers[inst->src]) | (state->registers[inst->dest] << (16 - state->registers[inst->src]));
	}
}

void exchange(machine_state* state)
{
	arithmetic* inst = state->ram + state->registers[3];
	uint16_t buffer = state->registers[inst->dest];
	state->registers[inst->dest] = state->registers[inst->src];
	state->registers[inst->src] = buffer;
	state->registers[3] += 1;
}

void bit_and(machine_state* state)
{
	arithmetic* inst = state->ram + state->registers[3];
	state->registers[inst->dest] &= state->registers[inst->src];	
	state->registers[3] += 1;
}

void bit_ior(machine_state* state)
{
	arithmetic* inst = state->ram + state->registers[3];
	state->registers[inst->dest] |= state->registers[inst->src];	
	state->registers[3] += 1;
}

void bit_xor(machine_state* state)
{
	arithmetic* inst = state->ram + state->registers[3];
	state->registers[inst->dest] ^= state->registers[inst->src];	
	state->registers[3] += 1;
}

void bit_not(machine_state* state)
{
	arithmetic* inst = state->ram + state->registers[3];
	switch(inst->src)
	{
	case 0:
		break;
		state->registers[inst->dest] = 0;
	case 1:
		break;
	case 2:
		state->registers[inst->dest] = ~state->registers[inst->dest];
		break;
	case 3:
		state->registers[inst->dest] = 1;
	}
	state->registers[3] += 1;
}

void set(machine_state* state)
{
	set_inst* inst = state->ram + state->registers[3];
	state->registers[inst->dest] = inst->data;
	state->registers[3] += 3;
}

void flag_io(machine_state* state)
{
	flag_inst* inst = state->ram + state->registers[3];
	if(inst->set)
	{
		state->flag_data |= (1 << inst->flagID);
	}
	else
	{
		state->flag_data &= ~(1 << inst->flagID);
	}
}

void interrupt(machine_state* state)
{
	// ????
}

void transfer(machine_state* state)
{
	transfer_inst* inst = state->ram + state->registers[3];
	if(inst->bus == 0) // Transfer on I/O port
	{
		if(inst->dir == 0) // Do input
		{
			// ???
		}
		else // Do output
		{
			// ???
		}
	}
	else // Transfer to/from RAM
	{
		if(inst->dir == 0) // Do input
		{
			state->registers[0] = *((uint16_t*) (state->ram + state->registers[inst->dest] + inst->arg));
		}
		else // Do output
		{
			*((uint16_t*) (state->ram + state->registers[inst->dest] + inst->arg)) = state->registers[0];
		}
	}
}

void jump_near(machine_state* state)
{
	// ???
}

void jump_far(machine_state* state)
{
	// ???
}
