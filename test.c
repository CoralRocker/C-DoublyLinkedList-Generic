#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

#define getVar(var) #var

void printDLL(DLL* list){
	int size = DLLsize(list);
	printf("DLL\n");
	for(int i = 0; i < size; i++)
	{
		printf("\tLink:  %d: %d\n", i, atDLL(list, i));
	}
}

int main(){
	DLL *dll = initDLL(2320);
	pushDLL(dll, 2321);
	
	printDLL(dll);

	insertDLL(dll, 0, 9003);

	printDLL(dll);

	insertDLL(dll, 3, 9003);
	insertDLL(dll, 2, 9003);

	printDLL(dll);

	freeDLL(dll);
}
