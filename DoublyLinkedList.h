#include <stdlib.h>

/* Struct to hold doubly linked list */
typedef struct DLL {
	struct DLL *prev, *next;
	void* val;
} DLL;

/* Init functino for DLL. Uses malloc for the allocation of system resources, 
 * so the user must free memory to avoid memory leaks and keep undefined behavior
 * to a minimum.
 * */
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

/* Frees all items in the list. DOES NOT FREE THEIR VAL POINTER 
 * The rFreeDLL function frees the val pointer, if need be. Use 
 * that one on void*'s that were allocated with malloc.
 * */
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
 *
 * Since this method has the potential to delete and free the memory pointed to by the user's DLL* variable,
 * it is important that the DLL* that is returned be assigned back to the DLL* variable passed to the function.
 *
 * Example:
 * 	my_variable = deleteDLL(my_variable, 0); // This would delete the first link in the list and return a valid link pointer, to ensure that the passed variable still contains a valid link.
 *
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

/* Creates a link and adds it at the specified index. Adds it so that the new link is at the specified index, pushing 
 * everything after it back one. If the index given is equal to the size of the list, it will place the new link at the
 * end of the list.  Nothing happens if the index is smaller than 0 or larger than the size of the list. 
 * */
void insertDLL(DLL* list, int index, void* val){
	DLL *t = DLLstart(list), *prev=NULL;

	int counter = 0;
	while(1){
		if(counter == index){
			DLL* ndll = initDLL(val);
			if(prev)
				prev->next = ndll;
			ndll->prev = prev;
			if(t){
				ndll->next = t;
				t->prev = ndll;
			}
		}
		if(t == NULL)
			break;
		prev = t;
		t = t->next;
		counter++;
	}
}

/* Sets the value of a given link to that given. 
 * Sort of impossible to screw up, as nothing happens if the index is invalid.
 * If void* that is passed is malloc'd, the mDeleteDLL() method or the rFreeDLL() methods
 * should be used to free the memory necessary. 
 * */
void setDLL(DLL *list, int index, void* val){
	
	DLLat(list, index)->val = val;

}
