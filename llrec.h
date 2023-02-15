#ifndef LLREC_H
#define LLREC_H
#ifndef NULL
#define NULL 0
#endif

/**
 * Node struct for both problems
 */
struct Node
{
    int val;
    Node *next;

    Node(int v, Node* n) : val(v), next(n) {}
};


/**
 * Given a linked list pointed to by head, creates two lists
 * where all values less than or equal to the pivot value are
 * placed in a linked list whose head will be pointed to by
 * smaller and all values greater than the pivot
 * value are placed in a linked list whose head will be pointed to
 * by larger.  The input list pointed to by head should be empty
 * upon return and head set to NULL (i.e. we are not making copies)
 * in the smaller and larger lists but simply moving Nodes out of
 * the input list and into the two other lists.
 * 
 * ==============================================================
 * MUST RUN IN O(n) where n is the number of nodes in the input list
 * ==============================================================
 *
 * @pre: smaller and larger may containing garbage (do NOT have
 *       to be NULL)
 *
 * @param[inout] head
 *   Reference to the head pointer to the input list.
 *   Should be set to NULL upon return
 * @param[out] smaller
 *   Reference to a head pointer for the list of nodes with values
 *   less than or equal to the pivot
 * @param[out] larger
 *   Reference to a head pointer for the list of nodes with values
 *   greater than the pivot
 * @param[in] pivot
 *   Pivot value
 *
 */
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot);

/**
 * Given a linked list pointed to by head, removes (filters out) nodes
 * whose value does not meet the criteria given by the predicate
 * function object, pred (i.e. pred should be a function object that implements
 * `bool operator()(int value)` and returns *true* for items that should
 * be *removed/filtered*.  Removed items should be deallocated.
 *
 * ==============================================================
 * MUST RUN IN O(n) where n is the number of nodes in the input list
 * ==============================================================
 *
 * @param[in] head
 *   Reference to the head pointer to the input list.
 * @param[in] pred
 *   Predicate object implementing: `bool operator()(int value)` that
 *   returns true if a node (based on its value) should be removed.
 * @return a head pointer to the resulting list (since the head pointer
 *   may change [i.e. be filtered])
 *
 */
template <typename Comp>
Node* llfilter(Node* head, Comp pred);

//*****************************************************************************
// Since template implementations should be in a header file, we will
// implement the above function now.
//*****************************************************************************


//using head recursion
//recurse FIRST!!!
//each iteration will either return itself OR the next valid item
template <typename Comp>
Node* llfilter(Node* head, Comp pred)
{
    //*********************************************
    // Provide your implementation below
    //*********************************************
    //checks for empty list
    //base case when end of list is reached
    if (head == NULL) {
        return NULL;
    }

    //in both cases below, we return after recursing (as we must do in head recursion)
    
    //check if current item should stay in list
    if(!pred(head -> val)) {
        Node* continuing_address = head -> next;
        //continue the function call for rest of list, skipping current object
        head -> next = llfilter(continuing_address, pred);
        //return current item since it remains in list
        return head;
    }
        
    //code to execute if current item shouldn't stay in list
    else {
        //create variable to hold address of the next item in list
        Node* return_address = head -> next;
        //continue the recursive function call on rest of list, skipping current object
        Node* next_func_call = llfilter(return_address, pred);
        //delete current head
        delete head;
        //return address from function call (will be next item that remains in list)
        return next_func_call; 
    }

}

#endif
