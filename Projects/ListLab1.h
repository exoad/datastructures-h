#pragma once

/**
 * @file ListLab1.h
 * @author Jack Meng
 * @brief Demonstrates some basics with LinkedLists
 * @date 2023-12-12
 */

#ifndef LISTBLAB1_H
#define LISTBLAB1_H

#include <cstring>

using namespace std;

/**
 * @brief The ListNode class
 */
class ListNode
{
    public:
        /**
         * @brief Value currently held
         */
        string value;
        /**
         * @brief The next ListNode
         */
        ListNode* next;
        ListNode(string,ListNode*);
        ListNode* copyNode(ListNode*);
        ListNode* copyList(ListNode*);
        ListNode* rest(ListNode*);
        ListNode* pointerToLast(ListNode*);
        ListNode* copyOfLast(ListNode*);
        ListNode* insertFirst(ListNode*,string);
        ListNode* insertLast(ListNode*,string);
        string first(ListNode*);
        string second(ListNode*);
        string getValue();
        ListNode* getNext();
};

/**
 * @brief retrieves the value of the head node
 * @param head the first or head of the linkedlist
 * @return the value held
 */
string ListNode::first(ListNode* head)
{
    return head==nullptr?nullptr:head->getValue();
}

/**
 * @brief retrieves the value of the second node
 * @param head the second of the linkedlist
 * @return the value held
 */
string ListNode::second(ListNode* head)
{
    return head==nullptr||head->getNext()==nullptr?NULL:head->getNext()->getValue();
}

/**
 * @brief returns a copy of the last node (not just its value!). copyofLast can be recursive.
 * @param head the head or first of the linkedlist
 * @return a copy
 */
ListNode* ListNode::copyOfLast(ListNode* head)
{
    return copyNode(pointerToLast(head));
}

/**
 * @brief returns a reference to the last node in the list, or NULL if the list is empty.
 * @param head the head or first of the linkedlist
 * @return a pointer
 */
ListNode* ListNode::pointerToLast(ListNode* head)
{
    ListNode* curr=head;
    while(curr->getNext()!=nullptr)
        curr=curr->getNext();
    return curr;
}

/**
 * @brief returns a reference to a list whose first node&#39;s value is specified by the argument, and the first node's next links to the original list.
 * @param head the head or first of the linkedlist
 * @param arg the value held by this node to insert
 * @return a pointer to the node inserted
 */
ListNode* ListNode::insertFirst(ListNode* head,string arg)
{
    return new ListNode(arg,head);
}

/**
 * @brief returns a reference to a list whose last node's value is specified by the argument, such that this last node has been appended to the original list and had its next is set to nullptr
 * @param head the head or first of the linkedlist
 * @param arg the value held by this node to insert
 * @return a pointer to the node inserted
 */
ListNode* ListNode::insertLast(ListNode* head,string arg)
{
    head->pointerToLast(head)->next=new ListNode(arg,nullptr);
    return head;
}

/**
 * @brief constructs a new ListNode instance
 * @param value the value held by this node
 * @param next a pointer to the next list node
 */
ListNode::ListNode(string value,ListNode* next):value(value),next(next)
{
}

/**
 * @brief returns a new node that is a copy of the argument node.
 * @param the node to copy
 * @return a pointer to this newly copied node
 */
ListNode* ListNode::copyNode(ListNode* arg)
{
    return new ListNode(arg->getValue(),arg->getNext());
}

/**
 * @brief returns a new list that is a copy of the original list.
 * @param the node to copy from
 * @return a pointer to this newly copied node with all of the following nodes in the linkedlist
 */
ListNode* ListNode::copyList(ListNode* arg)
{
    return arg->getNext()==nullptr?copyNode(arg):new ListNode(arg->getValue(),copyList(arg->getNext()));
}

/**
 * @brief returns a new linked list containing copies of each node in the original list except the first node, maintaining the order of the original list.
 * @param h the node to look at the rest
 * @return the rest of the nodes as a pointer
 */
ListNode* ListNode::rest(ListNode* h)
{
    return copyList(h->getNext());
}

/**
 * @return the next listnode pointed to by this current node
 */
ListNode* ListNode::getNext()
{
    return next;
}

/**
 * @return the current value held by this listnode
 */
string ListNode::getValue()
{
    return value;
}


#endif
