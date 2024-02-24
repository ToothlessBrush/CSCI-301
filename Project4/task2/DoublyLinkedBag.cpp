//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include "DoublyLinkedBag.h"
#include "Node.h"
#include <cstddef>
#include <vector>

template <class T>
DoublyLinkedBag<T>::DoublyLinkedBag() : headPtr(NULL), itemCount(0)
{
}

template <class T>
DoublyLinkedBag<T>::DoublyLinkedBag(const DoublyLinkedBag<T> &aBag)
{
    itemCount = aBag.itemCount;
    Node<T> *origChainPtr = aBag.headPtr;
    if (origChainPtr == NULL)
    { // if the original bag is empty
        headPtr = NULL;
    }
    else
    {
        // copy first node
        headPtr = new Node<T>();
        headPtr->setItem(origChainPtr->getItem());
        Node<T> *newChainPtr = headPtr;
        // copy remaining nodes
        origChainPtr = origChainPtr->getNext();
        // while the original chain has more nodes
        while (origChainPtr != NULL)
        {

            // get next item from original chain
            T nextItem = origChainPtr->getItem();
            // create a new node containing the next item
            Node<T> *newNodePtr = new Node<T>(nextItem);
            // link new node to end of new chain
            newChainPtr->setNext(newNodePtr);
            // advance pointer to new last node
            newChainPtr = newChainPtr->getNext();
            // advance pointer to next node
            origChainPtr = origChainPtr->getNext();
        }
        // set the next pointer of the last node to NULL
        newChainPtr->setNext(NULL);
    }
}

template <class T>
DoublyLinkedBag<T>::~DoublyLinkedBag()
{
    clear();
}

template <class T>
int DoublyLinkedBag<T>::getCurrentSize() const
{
    return itemCount;
}

template <class T>
bool DoublyLinkedBag<T>::isEmpty() const
{
    return itemCount == 0;
}

template <class T>
bool DoublyLinkedBag<T>::add(const T &newEntry)
{
    // add to beginning of chain: new node references rest of chain;
    //  (headPtr is null if chain is empty)
    Node<T> *nextNodePtr = new Node<T>(newEntry, headPtr);
    headPtr = nextNodePtr;

    itemCount++;

    return true;
}

template <class T>
bool DoublyLinkedBag<T>::remove(const T &anEntry)
{
    Node<T> *entryNodePtr = getPointerTo(anEntry);
    bool canRemoveItem = !isEmpty() && (entryNodePtr != NULL);
    if (canRemoveItem)
    {
        // copy data from first node to located node
        entryNodePtr->setItem(headPtr->getItem());
        // delete first node
        Node<T> *nodeToDeletePtr = headPtr;
        headPtr = headPtr->getNext();
        // return node to the system
        nodeToDeletePtr->setNext(NULL);
        delete nodeToDeletePtr;
        nodeToDeletePtr = NULL;
        itemCount--;
    }
    return canRemoveItem;
}

template <class T>
void DoublyLinkedBag<T>::clear()
{
    while (!isEmpty())
    {
        remove(headPtr->getItem());
    }
}

template <class T>
int DoublyLinkedBag<T>::getFrequencyOf(const T &anEntry) const
{
    int frequency = 0;
    int counter = 0;
    Node<T> *curPtr = headPtr;
    while ((curPtr != NULL) && (counter < itemCount))
    {
        if (anEntry == curPtr->getItem())
        {
            frequency++;
        }
        counter++;
        curPtr = curPtr->getNext();
    }
    return frequency;
}

template <class T>
bool DoublyLinkedBag<T>::contains(const T &anEntry) const
{
    return (getPointerTo(anEntry) != NULL);
}

template <class T>
std::vector<T> DoublyLinkedBag<T>::toVector() const
{
    std::vector<T> bagContents;
    Node<T> *curPtr = headPtr;
    int counter = 0;
    while ((curPtr != NULL) && (counter < itemCount))
    {
        bagContents.push_back(curPtr->getItem());
        curPtr = curPtr->getNext();
        counter++;
    }
    return bagContents;
}