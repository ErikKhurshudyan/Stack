#include "../headers/Stack.hpp"

template <typename T, typename Sequence>
Stack<T, Sequence>::Stack()
    : Sequence()
{}

template <typename T, typename Sequence>
Stack<T, Sequence>::Stack(const Stack<T, Sequence>& rhv)
    : Sequence(rhv)
{}

template <typename T, typename Sequence>
Stack<T, Sequence>::~Stack()
{
    Sequence::clear();
}

template <typename T, typename Sequence>
Stack<T, Sequence>&
Stack<T, Sequence>::operator=(const Stack<T, Sequence>& rhv)
{
    if (this != &rhv) {
        Sequence::operator=(rhv);
    }
    return *this;
}

template <typename T, typename Sequence>
bool
Stack<T, Sequence>::operator==(const Stack<T, Sequence>& rhv) const
{
    return (static_cast<const Sequence&>(*this)) == (static_cast<const Sequence&>(rhv));
}

template <typename T, typename Sequence>
bool
Stack<T, Sequence>::operator!=(const Stack<T, Sequence>& rhv) const
{
    return !(*this == rhv);
}

template <typename T, typename Sequence>
bool
Stack<T, Sequence>::operator<(const Stack<T, Sequence>& rhv) const
{
    return (static_cast<const Sequence&>(*this)) < (static_cast<const Sequence&>(rhv));
}

template <typename T, typename Sequence>
bool
Stack<T, Sequence>::operator>(const Stack<T, Sequence>& rhv) const
{
    return (static_cast<const Sequence&>(*this)) > (static_cast<const Sequence&>(rhv));
}

template <typename T, typename Sequence>
bool
Stack<T, Sequence>::operator<=(const Stack<T, Sequence>& rhv) const
{
    return !(*this > rhv);
}

template <typename T, typename Sequence>
bool
Stack<T, Sequence>::operator>=(const Stack<T, Sequence>& rhv) const
{
    return !(*this < rhv);
}

template <typename T, typename Sequence>
typename Stack<T, Sequence>::reference
Stack<T, Sequence>::top()
{
    assert(!empty());
    return Sequence::back();     
}

template <typename T, typename Sequence>
typename Stack<T, Sequence>::const_reference
Stack<T, Sequence>::top() const
{
    assert(!empty());
    return Sequence::back();     
}

template <typename T, typename Sequence>
void
Stack<T, Sequence>::push(const_reference value)
{
    return Sequence::push_back(value);
}

template <typename T, typename Sequence>
void
Stack<T, Sequence>::pop()
{
    assert(!empty());
    return Sequence::pop_back();
}

template <typename T, typename Sequence>
bool
Stack<T, Sequence>::empty() const
{
    return Sequence::empty();
}

template <typename T, typename Sequence>
typename Stack<T, Sequence>::size_type
Stack<T, Sequence>::size() const
{
    return Sequence::size();
}

