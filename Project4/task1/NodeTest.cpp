#include "Node.h"
#include <iostream>
#include <cassert>
#include <cstddef>

int main()
{
    // create some nodes
    Node<int> node1(1);
    Node<int> node2(50);
    Node<int> node3(10);

    // setters and getters
    // item
    assert(node1.getItem() == 1);
    assert(node2.getItem() == 50);

    node1.setItem(100);
    assert(node1.getItem() == 100);

    // pointers
    node1.setNext(&node2);
    node2.setPrev(&node1);
    node2.setNext(&node3);
    node3.setPrev(&node2);

    assert(node1.getNext() == &node2);
    assert(node2.getPrev() == &node1);
    assert(node2.getNext() == &node3);
    assert(node3.getPrev() == &node2);

    // test constructors
    Node<int> node4(20, &node3);
    Node<int> node5(30, &node4, &node1);

    assert(node4.getItem() == 20);
    assert(node4.getNext() == &node3);
    assert(node4.getPrev() == NULL);
    assert(node5.getItem() == 30);

    std::cout << "All tests passed." << std::endl;

    return 0;
}