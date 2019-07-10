#include <stdlib.h>

/* Struct to hold doubly linked list */
typedef struct DLL {
	struct DLL *prev, *next;
	void* val;
} DLL;

/* TODO: Make init function, free function, and a RECURSIVE free function */
DLL* initDLL(void* val){
	DLL* nDLL = malloc(sizeof(DLL*)*2 + sizeof(void*));
	nDLL->prev = NULL;
	nDLL->next = NULL;
	nDLL->val = val;
	return nDLL;
}

/* Returns pointer to first link in DLL */
DLL* DLLstart(DLL* list){
	DLL *t = list;
	while(t->prev != NULL)
		t = t->prev;
	return t;
}

/* Frees all items in the list. DOES NOT FREE THEIR VAL POINTER */
void freeDLL(DLL *list)
{
	DLL *t = DLLstart(list), *f = t;
	while(f != NULL){
		f=t->next;
		free(t);
		t=f;
	}
}

/* Frees all items in the list, including their val pointers.
 * ALL LINKS MUST BE INTITIALIZED WITH MALLOC, AND THE VALUES THEY STORE MUST
 * ALSO BE MALLOC'D!
 */
void rFreeDLL(DLL *list){
	DLL *t = DLLstart(list), *f = t;
	while(f != NULL){
		f=t->next;
		free(t->val);
		free(t);
		t=f;
	}
}


/* Returns pointer to last link in DLL */
DLL* DLLend(DLL* list){
	DLL* t = list;
	while(t->next != NULL)
		t = t->next;
	return t;
}

/* Returns the size of the DLL */
int DLLsize(DLL* list){
	DLL *t = DLLstart(list);
	int count = 1;
	while(t->next != NULL){
		count++;
		t = t->next;
	}
	return count;
}

/* Returns the pointer to a specific link in the list 
 * Returns NULL if the index specified is invalid. 
 * */
DLL* DLLat(DLL* list, int index){
	DLL* t = DLLstart(list);
	int counter = 0;
	while(1){
		if(counter == index)
			return t;
		if(t->next == NULL && counter != index)
			return NULL;
		counter++;
		t=t->next;
	}
}

/* Returns the value held by the first link */
void* frontDLL(DLL* list){
	return DLLstart(list)->val;
}

/* Returns the value held by the last link */
void* backDLL(DLL* list){
	return DLLend(list)->val;
}

/* Returns the value held by a specific link in the list
 * Returns NULL if the index is out of bounds.
 * */
void* atDLL(DLL* list, int index){
	DLL* t = DLLstart(list);
	void* val = NULL;
	int counter = 0;
	while(counter < index){
		counter++;
		if(t->next != NULL)
			t = t->next;
		else
			break;
	}
	if(counter == index)
		return t->val;
	else
		return NULL;
}

/* Adds a link to end of DLL */
void pushDLL(DLL* list, void* val){
	DLL* t = DLLend(list);
	DLL* n = initDLL(val);
	t->next = n;
	n->prev = t;
}

/* Removes the last link in the DLL 
 * This method has the ability to remove the object pointed to by the given DLL pointer.
 * Thus, it returns a pointer to the last DLL object, or NULL if no more objects exist within
 * the list.
 * */
DLL* popDLL(DLL* list){
	DLL* t = DLLend(list);
	if(t->prev == NULL){
		free(t);
		return NULL;
	}
	t = t->prev;
	free(t->next);
	t->next = NULL;
	return t;
}

/* Removes a link from a specified index. 
 * Returns a pointer to the previous DLL object to the one deleted, the next one if that one doesn't exist,
 * or NULL if neither exist.
 *
 * Returns the original list if the specified index is invalid.
 */
DLL* deleteDLL(DLL* list, int index){

	DLL *t = DLLat(list, index), *p, *n;
	if(!t)
		return list;
	p=t->prev;
	n=t->next;

	if(!p && n)
		n->prev = NULL;
	else if(!n && p)
		p->next = NULL;
	else if(p && n){
		p->next = n;
		n->prev = p;
	}
	free(t);

	// Return the correct pointer
	return (p != NULL) ? p : (n != NULL) ? n : NULL;
}

/* Removes a link from a specified index. ONLY USE ON MALLOC'D MEMORY
 * Returns a pointer to the previous DLL object to the one deleted, the next one if that one doesn't exist,
 * or NULL if neither exist.
 *
 * Returns the original list if the specified index is invalid.
 */
DLL* mDeleteDLL(DLL* list, int index){

	DLL *t = DLLat(list, index), *p, *n;
	if(!t)
		return list;
	p=t->prev;
	n=t->next;

	if(!p && n)
		n->prev = NULL;
	else if(!n && p)
		p->next = NULL;
	else if(p && n){
		p->next = n;
		n->prev = p;
	}
	free(t->val);
	free(t);

	// Return the correct pointer
	return (p != NULL) ? p : (n != NULL) ? n : NULL;
}
