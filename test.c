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
}

int main(){
	DLL* myDLL = initDLL();
	myDLL->val = 234;
	
	printDLL(myDLL);

	pushDLL(myDLL, 290);

	printDLL(myDLL);

	freeDLL(myDLL);
}
