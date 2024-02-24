#ifndef NODE_H
#define NODE_H

/**
 * @brief Node class for a doubly linked list
 *
 * @tparam T type of the item in the node
 */
template <class T>
class Node
{
private:
    T item;
    Node<T> *next;
    Node<T> *prev;

public:
    /**
     * @brief Construct a new Node object
     *
     * @post item is initialized to 0, next and prev are initialized to NULL
     */
    Node();

    /**
     * @brief Construct a new Node object
     *
     * @param anItem item to be stored in the node
     * @post item is initialized to anItem, next and prev are initialized to NULL
     */
    Node(const T &anItem);

    /**
     * @brief Construct a new Node object
     *
     * @param anItem item to be stored in the node
     * @param nextNodePtr pointer to the next node
     */
    Node(const T &anItem, Node<T> *nextNodePtr);

    /**
     * @brief Construct a new Node object
     *
     * @param anItem item to be stored in the node
     * @param nextNodePtr pointer to the next node
     * @post item is initialized to anItem, next is initialized to nextNodePtr, prev is initialized to NULL
     */
    Node(const T &anItem, Node<T> *nextNodePtr, Node<T> *prevNodePtr);

    /**
     * @brief Set the item in the node
     *
     * @param anItem item to be stored in the node
     */
    void setItem(const T &anItem);

    /**
     * @brief Set the next node
     *
     * @param nextNodePtr pointer to the next node
     */
    void setNext(Node<T> *nextNodePtr);

    /**
     * @brief Set the previous node
     *
     * @param prevNodePtr pointer to the previous node
     */
    void setPrev(Node<T> *prevNodePtr);

    /**
     * @brief Get the item in the node
     *
     * @return T item in the node
     */
    T getItem() const;

    /**
     * @brief Get the next node
     *
     * @return Node<T>* pointer to the next node
     */
    Node<T> *getNext() const;

    /**
     * @brief Get the previous node
     *
     * @return Node<T>* pointer to the previous node
     */
    Node<T> *getPrev() const;
};

#include "Node.cpp"
#endif