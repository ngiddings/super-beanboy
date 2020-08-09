#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "machine.h"

void dump_registers(machine_state* state)
{
	printf("\nA: %X\nB: %X\nSP: %X\nIP: %X\nFLAGS: %X\n\n", 
		state->registers[0], 
		state->registers[1], 
		state->registers[2], 
		state->registers[3], 
		state->flag_data);
}

void dump_memory(machine_state* state)
{
	for(uint16_t i = 0; i < 4096; i++)
	{
		printf("%04hX ", i*16);
		printf("| ");
		for(uint16_t j = 0; j < 16; j++)
		{
			uint8_t byte = *((uint8_t*) (state->ram + (i*16) + j));
			printf("%02hhX ", byte);
		}
		printf("|\n");
	}
}

int main(int argc, char** args)
{
	if(argc != 2) 
	{
		return -1;
	}
	
	FILE* binary = fopen(args[1], "r");
	fseek(binary, 0, SEEK_END);
	long fileSize = ftell(binary);
	rewind(binary);
	
	machine_state machine;
	initialize_machine(&machine);
	machine.registers[REG_IP] = 0;
	fread(machine.ram, 1, fileSize, binary);
	dump_registers(&machine);
	do_instruction(&machine);
	dump_registers(&machine);
	do_instruction(&machine);
	dump_registers(&machine);
	do_instruction(&machine);
	dump_registers(&machine);
	dump_memory(&machine);
}
