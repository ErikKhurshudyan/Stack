#ifndef __STACK_HPP__
#define __STACK_HPP__

#include <deque>

template <typename T, typename Sequence = std::deque<T> >
class Stack : private Sequence
{
public:
    typedef typename std::deque<T>::value_type      value_type;
    typedef typename std::deque<T>::size_type       size_type;
    typedef typename std::deque<T>::reference       reference;
    typedef typename std::deque<T>::const_reference const_reference;

public:
    Stack();
    Stack(const Stack<T, Sequence>& rhv);
    ~Stack();

    Stack<T, Sequence>& operator=(const Stack<T, Sequence>& rhv);
    bool                operator==(const Stack<T, Sequence>& rhv) const;
    bool                operator!=(const Stack<T, Sequence>& rhv) const;
    bool                operator<(const Stack<T, Sequence>& rhv)  const;
    bool                operator>(const Stack<T, Sequence>& rhv)  const;
    bool                operator>=(const Stack<T, Sequence>& rhv) const;
    bool                operator<=(const Stack<T, Sequence>& rhv) const;

    reference       top();
    const_reference top() const; 
    void            push(const_reference value);
    void            pop();

    bool      empty() const;
    size_type size()  const;
};

#include "../templates/Stack.cpp"

#endif /// __STACK_HPP__

