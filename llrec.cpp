#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


//implement tail recursion
//change smaller and/or larger and then recurse
void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot) {
	//check if head equals null
	//if so, set both smaller and larger to null and then return
	if (head == NULL) {
		smaller = NULL;
		larger = NULL;
		return;
	}

	//check if value fits in smaller list
	if (head -> val <= pivot) {
		//set smaller to head and then change smaller and head to next values to keep track of end and keep iterating through input
		smaller = head;
		//change head to make sure it is not longer pointing at smaller item
		head = head -> next;
		llpivot(head, smaller -> next, larger, pivot);
	}

	//check if value fits in larger list
	else if (head -> val > pivot) {
		//set larger to head and then change larger and head to next values to keep track of end and keep iterating through input
		larger = head;
		//change head to make sure it is not longer pointing at larger item
		head = head -> next;
		llpivot(head, smaller, larger -> next, pivot );
	}

}

