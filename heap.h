#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
std::vector<T> items_;
PComparator comp;
int nodes;


};

// Add implementation of member functions here

//constructor for heap
//instantiate data members with m where m defines m-ary heap and comp = c where c is the comparator
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) {
  nodes = m;
  comp = c;
}

//destructor for heap
template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {
}

//push function for heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  //add item to back
  items_.push_back(item);
  //keep track of last item
  std::size_t index = items_.size() - 1;
  //loop through heap, swapping items with parent until the item is in its appropriate place depending on comparator
  while (index != 0) {
    std::size_t parent_index = (index - 1) / nodes;
    T& current = items_[index];
    T& parent = items_[parent_index];
    //if the compare between the current item and parent no longer returns true, break the loop
    if (!comp(current,parent)) {
        break;
    }
    //swap and change index to continue following current node up the tree
    std::swap(current, parent);
    index = parent_index;
  }
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // throw the appropriate exception
    throw(std::underflow_error("List is empty")); 
  }
  //returns top element
  return items_[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // throw the appropriate exception
    throw(std::underflow_error("List is empty"));
  }
  //set "best" item = to last item
  items_[0] = items_[items_.size() - 1];
  //delete last item
  items_.pop_back();
  //declare index of current = 0
  std::size_t index = 0;
  //create loop that runs while current item is not a leaf node
  while (index*nodes < items_.size()) {
    //declare index for first child
    std::size_t bestchild = nodes*index + 1;
    //check if child returns true for comp with its siblings, if so, replace its index with that of smallest child
		for (int i = 2; i <= nodes; i++) {
    if(nodes*index + i  < items_.size() && comp(items_[nodes*index + i], items_[bestchild])) {

        bestchild = nodes*index + i;
    }
		}
    //swap smallest child with current item
    T& current = items_[index];
    T& child = items_[bestchild];
    //break if current is in right place (comparator between current and child returns true)
    if(comp(current,child)) {
      break;
    }
    std::swap(current, child);
    //change index to continue following current node
    index = bestchild;
  }
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const {
  //returns vector data member's size
  return items_.size();
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const {
  //returns vector data member's empty value
  return items_.empty();
}


#endif

