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
	//pushDLL(dll, 2322);
	printf("DLL 0: %p\n", dll);
	dll = deleteDLL(dll, 0);
	printf("Del 0: %p\n", dll);
	dll = deleteDLL(dll, 0);
	printf("Del 0: %p\n", dll);
}
