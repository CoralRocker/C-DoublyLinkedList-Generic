#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"


void printDLL(DLL* list){
	int size = DLLsize(list);
	printf("DLL\n");
	for(int i = 0; i < size; i++)
	{
		printf("\tLink:  %d: %d\n", i, atDLL(list, i));
	}
	printf("\n");
}

int main(){
	DLL *dll = initDLL(0);

	/* Fill In DLL with Values */
	for(int i = 1; i < 20; i++)
		pushDLL(dll, i);

	printDLL(dll);

	printf("Testing Pointer Return Functions...\n");
	printf("\tDLLstart(dll): %p\n", DLLstart(dll));
	printf("\tDLLend(dll): %p\n", DLLend(dll));
	printf("\tDLLat(dll, 0): %p\n", DLLat(dll, 0));
	putc('\n', stdout);

	printf("Testing Accessor Functions...\n");
	printf("\tDLLsize(dll): %d\n", DLLsize(dll));
	printf("\tfrontDLL(dll): %d\n", frontDLL(dll));
	printf("\tbackDLL(dll): %d\n", backDLL(dll));
	printf("\tatDLL(dll, 0): %d\n", atDLL(dll, 0));
	putc('\n', stdout);

	printf("Testing Modifier Methods...\n");

	dll = popDLL(dll);
	printf("\tpopDLL(dll)\n");
	pushDLL(dll, 20);
	printf("\tpushDLL(dll, 20)\n");
	dll = deleteDLL(dll, 0);
	printf("\tdeleteDLL(dll, 0)\n");
	printf("\tmDeleteDLL() is not able to be tested as nothing was malloc'd...\n");
	insertDLL(dll, 0, -1);
	printf("\tinsertDLL(dll, 0, -1)\n");
	setDLL(dll, 1, -2);
	printf("\tsetDLL(dll, 1, -2)\n");
	putc('\n', stdout);

	printDLL(dll);
	freeDLL(dll);
	
	puts("\nTesting system with malloc'd data...");
	dll = initDLL(malloc(sizeof(size_t)));
	

	puts("Filling dll with 20 malloc'd values...");
	for(int i = 0; i < 19; i++){
		pushDLL(dll, malloc(sizeof(size_t)*i));					
	}
	
	puts("Malloc'd DLL:");
	for(int i = 0; i < 20; i++){
		printf("%d: %p\n", i, atDLL(dll, i));
	}
	puts("");

	printf("\tmDeleteDLL(dll, 2)\n");
	mDeleteDLL(dll, 2);

	puts("Malloc'd DLL:");
	for(int i = 0; i < 20; i++){
		printf("%d: %p\n", i, atDLL(dll, i));
	}
	puts("");

	rFreeDLL(dll);

}
