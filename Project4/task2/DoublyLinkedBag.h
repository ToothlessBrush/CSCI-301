

#ifndef DOUBLYLINKEDBAH_H
#define DOUBLYLINKEDBAH_H

#include "BagInterface.h"
#include "Node.h"

template <class T>
class DoublyLinkedBag : public BagInterface<T>
{
private:
    Node<T> *headPtr;
    int itemCount;

    Node<T> *getPointerTo(const T &target) const;

public:
    /**
     * @brief Construct a new Doubly Linked Bag object
     */
    DoublyLinkedBag();

    /**
     * @brief Construct a new Doubly Linked Bag object
     *
     * @param aBag bag to be copied
     */
    DoublyLinkedBag(const DoublyLinkedBag<T> &aBag);

    /**
     * @brief Destroy the Doubly Linked Bag object
     */
    virtual ~DoublyLinkedBag();

    /**
     * @brief Get the current size of the bag
     *
     * @return int number of items in the bag
     */
    int getCurrentSize() const;

    /**
     * @brief Check if the bag is empty
     *
     * @return bool true if the bag is empty, false otherwise
     */
    bool isEmpty() const;

    /**
     * @brief Add a new entry to the bag
     *
     * @param newEntry entry to be added
     * @return bool true if the addition was successful, false otherwise
     */
    bool add(const T &newEntry);

    /**
     * @brief Remove an entry from the bag
     *
     * @param anEntry entry to be removed
     * @return bool true if the removal was successful, false otherwise
     */
    bool remove(const T &anEntry);

    /**
     * @brief Remove all entries from the bag
     */
    void clear();

    /**
     * @brief Get the frequency of an entry in the bag
     *
     * @param anEntry entry to be counted
     * @return int number of times anEntry appears in the bag
     */
    int getFrequencyOf(const T &anEntry) const;

    /**
     * @brief Check if the bag contains an entry
     *
     * @param anEntry entry to be located
     * @return bool true if the bag contains anEntry, false otherwise
     */
    bool contains(const T &anEntry) const;

    /**
     * @brief Convert the bag to a vector
     *
     * @return std::vector<T> vector containing all the entries in the bag
     */
    std::vector<T> toVector() const;
};

template <class ItemType>
Node<ItemType> *DoublyLinkedBag<ItemType>::getPointerTo(const ItemType &anEntry) const
{
    bool found = false;
    Node<ItemType> *curPtr = headPtr;

    while (!found && (curPtr != NULL))
    {
        if (anEntry == curPtr->getItem())
            found = true;
        else
            curPtr = curPtr->getNext();
    } // end while

    return curPtr;
}

#include "DoublyLinkedBag.cpp"
#endif