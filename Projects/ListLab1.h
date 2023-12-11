#pragma once

#include <cstring>

using namespace std;

class ListNode 
{
    private:
        string value;
        ListNode* next;  
    public:
        ListNode(string value,ListNode* next);
        ListNode* copyNode(ListNode* arg);
        ListNode* copyList(ListNode* arg);
        ListNode* rest(ListNode* h);
        string getValue();
        ListNode* getNext();
};

string first(ListNode* head)
{
    return head==NULL?NULL:head->getValue();
}

string second(ListNode* head)
{
    return head==NULL||head->getNext()==NULL?NULL:head->getNext()->getValue();
}

ListNode* copyOfLast(ListNode* head)
{
    ListNode* temp=pointerToLast(head);
    return new ListNode(temp->getValue(),temp->getNext());
}

ListNode* pointerToLast(ListNode* head)
{
    ListNode* curr=head;
    while(curr!=NULL)
        curr=curr->getNext();
    return curr;
}

ListNode* insertFirst(ListNode* head, string arg)
{
    return new ListNode(arg,head);
}

ListNode* insertLast(ListNode* head, string arg)
{
    return new ListNode(arg,pointerToLast(head));
}

ListNode::ListNode(string value,ListNode* next) : value(value), next(next)
{
}

ListNode* ListNode::copyNode(ListNode* arg) noexcept
{
    return new ListNode(arg->getValue(),arg->getNext());
}

ListNode* ListNode::copyList(ListNode* arg) noexcept
{
    
}

ListNode* ListNode::rest(ListNode* h) noexcept
{
    
}

ListNode* ListNode::getNext() 
{
    return next;
}

string ListNode::getValue()
{
    return value;
}
