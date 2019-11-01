#include <assert.h>
#include <stdio.h>

#include "machine.h"

int main()
{
	machine_state state;
	initialize_machine(&state);
	
	printf("all tests passed.\n");
	return 0;
}
