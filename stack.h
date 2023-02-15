#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
//using private inheritance so users can't access other features like insert() -> only push_back
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
private:
};

//constructor
template <typename T>
Stack<T>::Stack(): std::vector<T>() {
}

//destructor
template <typename T>
Stack<T>::~ Stack(){
}

//return empty() parent function
template <typename T>
bool Stack<T>::empty() const {
    return std::vector<T>::empty();
}

//return size() parent function
template <typename T>
size_t Stack<T>::size() const {
    return std::vector<T>::size();
}

//use parent's push_back function
template <typename T>
void Stack<T>::push(const T& item) {
    std::vector<T>::push_back(item);
}

//use parent push_back function
//throw exception if stack is empty
template <typename T>
void Stack<T>::pop() {
    if (empty()) {
        throw std::underflow_error("List is empty");
    }

    else {
        std::vector<T>::pop_back();
    }
}

//use parent back function
//throw exception if stack
template <typename T>
const T& Stack<T>::top() const {
    if (empty()) {
        throw std::underflow_error("List is empty");
    }
    return std::vector<T>::back();
}


#endif