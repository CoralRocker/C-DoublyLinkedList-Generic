#include <stdio.h>
#include "DoublyLinkedList.h"

void printLL(LL *start)
{
	for(int i = 0; i < linkedListSize(start);i++)
		printf("Link %d: %d\n", i, getLink(start, i));
}

int main()
{
	/* Create Linked List of size 10 */
	printf("Init 10 length linked list...\n\n");
	LL *ll = initLinkedList(0);
	for(int i = 1; i < 10; i++)
		pushBackLinkedList(ll, i);
	printLL(ll);

	/* Test accessor methods */
	printf("Accessor Methods:\n");
	printf("\tgetLink(ll, 4): %d\n", getLink(ll, 4));
	printf("\tfrontLink(ll): %d\n", frontLink(ll));
	printf("\tbackLink(ll): %d\n", backLink(ll));
	printf("\tlinkPointer(ll, 4): %p\n", linkPointer(ll, 4));

	/* Test modifier Methods */
	printf("\nModifier Methods:\n");
	printf("\tinsertLinkedList(ll, 0, 2019)\n");
	printf("\tpopBackLinkedList(ll)\n");
	printf("\tpushBackLinkedList(ll, 2018)\n");
	printf("\tdeleteLink(ll, 2)\n");
	printf("\tinsertLinkedList(ll, 6, 69)\n");
	printf("\tsetLink(ll, 1, 1000)\n");
	printf("\tswapLink(ll, 3, 4)\n");

	ll = insertLinkedList(ll, 0, 2019);	
	popBackLinkedList(ll);
	pushBackLinkedList(ll, 2018);
	deleteLink(ll, 2);
	ll = insertLinkedList(ll, 6, 69);
	setLink(ll, 1, 1000);
	swapLink(ll, 3, 4);

	printf("\nFinal List:\n"); 

	printLL(ll);
	freeLinkedList(ll);
}
