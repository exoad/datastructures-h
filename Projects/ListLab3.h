#pragma once

/**
 * @file ListLab3.h
 * @author Jack Meng
 * @brief Demonstrates some basics with LinkedLists
 * @date 2024-2-6
 */

#include <string>

using STR=std::string;

/**
 * @brief A node in a doubly linked list
 */
class ListNode
{
    public:
        STR data;
        ListNode* next;
        ListNode* prev;
        /**
         * @brief Construct a new List Node object
         *
         * @param data The data to be stored in the node
         * @param next The next node in the list
         * @param prev The previous node in the list
         */
        ListNode(STR data,ListNode* next,ListNode* prev);
        /**
         * @brief Add a node to the list at the beginning
         *
         * @param n The node to be added
         * @return ListNode* The new head of the list
         */
        ListNode* add(ListNode* n);
        /**
         * @brief Add a node to the list at a specific position
         *
         * @param position The position to add the node
         * @param n The node to be added
         * @return ListNode* The new head of the list
         */
        ListNode* add(int position,ListNode* n);
        /**
         * @brief Remove a node from a specific position in the list
         *
         * @param position The position to remove the node
         * @return ListNode* The new head of the list
         */
        ListNode* remove(int position);
        /**
         * @brief Remove a node from the beginning of the list
         * @return ListNode* The new head of the list
         */
        ListNode* remove();
        /**
         * @brief Output the list to the stream
         *
         * @param os The stream to output to
         * @param node The node to output
         * @return std::ostream& The stream
         */
        friend std::ostream& operator<<(std::ostream& os, const ListNode& node);
};

ListNode::ListNode(STR data,ListNode* next,ListNode* prev):data(data),next(next),prev(prev)
{}

std::ostream& operator<<(std::ostream& os, const ListNode& node)
{
    os<<node.data;
    if(node.next!=nullptr)
        os<<*node.next;
    return os;
}

ListNode* ListNode::add(int position,ListNode* n)
{
    return position==0?add(n):next->add(position-1,n);
}

ListNode* ListNode::add(ListNode* n)
{
    n->next=this;
    n->prev=prev;
    prev=n;
    return n;
}

ListNode* ListNode::remove()
=======
}


ListNode* ListNode::remove(int position)
{
    return position==0?remove():next->remove(position-1);
}
=======
    delete this;
}

void ListNode::remove(int position)
{
    if(position==0)
        remove();
    else
        next->remove(position-1);
}
>>>>>>> 04200898796383d8ac671f894bedb555dba19ce3
