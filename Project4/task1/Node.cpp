#include "Node.h"
#include <cstddef>

template <class T>
Node<T>::Node() : next(NULL), prev(NULL)
{
}

template <class T>
Node<T>::Node(const T &anItem) : item(anItem), next(NULL), prev(NULL)
{
}

template <class T>
Node<T>::Node(const T &anItem, Node<T> *nextNodePtr) : item(anItem), next(nextNodePtr), prev(NULL)
{
}

template <class T>
Node<T>::Node(const T &anItem, Node<T> *nextNodePtr, Node<T> *prevNodePtr) : item(anItem), next(nextNodePtr), prev(prevNodePtr)
{
}

template <class T>
void Node<T>::setItem(const T &anItem)
{
    item = anItem;
}

template <class T>
void Node<T>::setNext(Node<T> *nextNodePtr)
{
    next = nextNodePtr;
}

template <class T>
void Node<T>::setPrev(Node<T> *prevNodePtr)
{
    prev = prevNodePtr;
}

template <class T>
T Node<T>::getItem() const
{
    return item;
}

template <class T>
Node<T> *Node<T>::getNext() const
{
    return next;
}

template <class T>
Node<T> *Node<T>::getPrev() const
{
    return prev;
}