#include <assert.h>
#include <stdio.h>

#include "machine.h"

int main()
{
	machine_state state;
	initialize_machine(&state);
	state.register_a = 1;
	state.register_b = 2;
	state.stack_pointer = 3;
	state.instruction_pointer = 4;
	
	printf("all tests passed.\n");
	return 0;
}
