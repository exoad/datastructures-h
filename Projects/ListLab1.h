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
 *
 */
class ListNode
{
    private:
        /**
         * @brief Value currently held
        */
        string value;
        /**
         * @brief The next ListNode
         */
        ListNode* next;
    public:
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

string ListNode::first(ListNode* head)
{
    return head==nullptr?nullptr:head->getValue();
}

string ListNode::second(ListNode* head)
{
    return head==nullptr||head->getNext()==nullptr?NULL:head->getNext()->getValue();
}

ListNode* ListNode::copyOfLast(ListNode* head)
{
    return copyNode(pointerToLast(head));
}

ListNode* ListNode::pointerToLast(ListNode* head)
{
    ListNode* curr=head;
    while(curr->getNext()!=nullptr)
        curr=curr->getNext();
    return curr;
}

ListNode* ListNode::insertFirst(ListNode* head,string arg)
{
    return new ListNode(arg,head);
}

ListNode* ListNode::insertLast(ListNode* head,string arg)
{
    return new ListNode(arg,nullptr);
}

ListNode::ListNode(string value,ListNode* next):value(value),next(next)
{
}

ListNode* ListNode::copyNode(ListNode* arg)
{
    return new ListNode(arg->getValue(),arg->getNext());
}

ListNode* ListNode::copyList(ListNode* arg)
{
    return arg->getNext()==nullptr?copyNode(arg):new ListNode(arg->getValue(),copyList(arg->getNext()));
}

ListNode* ListNode::rest(ListNode* h)
{
    return copyList(h->getNext());
}

ListNode* ListNode::getNext()
{
    return next;
}

string ListNode::getValue()
{
    return value;
}

#endif