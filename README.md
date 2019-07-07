# C-LinkedList-Generic

# Why use a Linked List?
A linked list allows for a non-continuous area of memory to be used as though it were continuous in memory. This is especially usefull in systems with very little or very erratic memory. There are downsides, however. The linked list is much slower to use than a vector of the same size, as the program has to traverse through the entire list in order to reach any given index. Additionally, it uses slightly more memory, as the list must store a pointer to the next link. The size of a single link is dependent on the address size of the system it is compiled and used on, such that the size is equal to two times the adress size of the system (the size of 2 void pointers).

# Accessor Methods
|Method|Usage|
|:-:|:-|
|int linkedListSize(LL *start)|linkedListSize(ll) where ll is the linkedList start. Returns the amount of links in the list.
|void* getLink(LL *start, int index)|getLink(ll, index) where ll is the linkedList start, and index is the index. Returns the value held by the link. If the pointer directly to the link is desired, the `LL* linkPointer(LL *start, int index)` method should be used.|
|void* frontLink(LL *start)|frontLink(ll) where ll is the linkedList start. Returns the first link in the list.|
|void* backLink(LL *start)|backLink(ll) where ll is the linkedList start. Returns the last link in the list.|
|LL* linkPointer(LL *start, int index)|linkPointer(ll, index) where ll is the linkedList start, and index is the index. Returns the pointer to requested link.|

# Modifier Methods
|Method|Usage|
|:-:|:-|
|LL* insertLinkedList(LL *start, int index, void* val)|insertLinkedList(ll, index, yourNum) where ll is the linkedList start, index is the index, and yourNum is the value to place. Places a new link into the list at a given index, and relinks list in order to preserve continuity. Returns the address to the first item in the link. Only important if your index is 0, so that your start variable is correctly assigned to the start of the list.|
|void pushBackLinkedList(LL *start, void* val)|pushBackLinkedList(ll, yourNum) where ll is the linkedList start, and yourNum is the value to place. Adds given value to a new link at the back of the list.|
|void popBackLinkedList(LL *start)|popBackLinkedList(ll) where ll is the linkedList start. Removes the last link from the list.|
|void deleteLink(LL *start, int index)|deleteLink(ll, index) where ll is the linkedList start, and index is the index. Removes the link at the given index. Relinks list for continuity.|
|void setLink(LL *start, int index, void* val)|setLink(ll, index, yourNum) where ll is the linkedList start, index is the index, and yourNum is the value to place. Updates the given link to hold the given value.|
|void swapLink(LL *start, int index1, int index2)|swapLink(ll, index1, index2) where ll is the linkedList start, and the indeces are indeces. Swaps the value held by the links in each of the indeces. |

# Creating a Linked List
Linked Lists should be created by using the provided `LL* initLinkedList(void* val)` method and manipulated using the given methods to ensure that no undocumented behavior occurs. The `void freeLinkedList(LL* start)` method is provided to free memory used by the list.

# Basic Quirks To Be Aware Of
The LinkedList works because `void*` can be any type. You will get warnings when passing any value to it unless you cast said value to `void*` by doing `(void*)xyz`. There is currently no way to track what type of variable the list holds. It is up to you to do so. I am working on making a simple system to keep track of types, but there is no way to standardize the types, so it will be up to the programmer to keep track of types.

# More information
The header file is thoroughly commented, and contains more insights on the uses and quirks of each method in its headings and comments.
