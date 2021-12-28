#include <iostream>

int no_1_globalvar;
int no_12_globalvarInit = 2;

static int no_2_static_globalvar;
static int no_22_static_globalvarInit = 2;

static int *no_7_dynamicArray_ptr = (int *)malloc(10 * sizeof(int));

int main(int argc, char **argv)
{
	int no_3_localvar;
	static int no_4_staticLocalVar;
	static int no_42_staticLocalVar_init = 2;
	register int no_5_registerLocalVar;

	register int no_5quick;
	int *no_6_dynamicArray_ptr;

	no_6_dynamicArray_ptr = (int *)malloc(10 * sizeof(int));

	std::cout << "\n"
			  << "--------\n"
			  << "Stack \n"
			  << (uintptr_t)&no_3_localvar << "\t" << &no_3_localvar << "\t local var \n"
			  << (uintptr_t)&no_5_registerLocalVar << "\t" << &no_5_registerLocalVar << "\t register local var \n"
			  << (uintptr_t)&no_6_dynamicArray_ptr << "\t" << &no_6_dynamicArray_ptr << "\t dynamic array ptr (in func)\n"

			  << (uintptr_t)no_6_dynamicArray_ptr << "\t" << no_6_dynamicArray_ptr << "\t dynamic array  (in func)\n"

			  << (uintptr_t)no_7_dynamicArray_ptr << "\t" << no_7_dynamicArray_ptr << "\t dynamic array  (not in func)\n"
			  
			  << "--------\n"
			  << "--------\n"
			  << "Heap\n"
			  

			  << "--------\n"
			  << "--------\n"
			  << "Uninitialized data(bss)\n"
			  << (uintptr_t)&no_2_static_globalvar << "\t" << &no_2_static_globalvar << "\t static globalvar \n"
			  << (uintptr_t)&no_4_staticLocalVar << "\t" << &no_4_staticLocalVar << "\t static local var \n"
			  << (uintptr_t)&no_1_globalvar << "\t" << &no_1_globalvar << "\t global var \n"
			  << "--------\n"
			  << "--------\n"
			  << "Initialized data\n"
			  << (uintptr_t)&no_22_static_globalvarInit << "\t" << &no_22_static_globalvarInit << "\t static globalvar inited\n"
			  << (uintptr_t)&no_42_staticLocalVar_init << "\t" << &no_42_staticLocalVar_init << "\t static local var inited\n"
			  << (uintptr_t)&no_12_globalvarInit << "\t" << &no_12_globalvarInit << "\t global var inited\n"
			  << "--------\n"
			  << "--------\n"
			  << "Text\n"
			  << "--------\n";
}