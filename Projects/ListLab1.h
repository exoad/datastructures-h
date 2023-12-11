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
    
}

string second(ListNode* head)
{
    
}

ListNode* copyOfLast(ListNode* head)
{
    
}

ListNode* pointerToLast(ListNode* head)
{
    
}

ListNode* insertFirst(ListNode* head, string arg)
{
    
}

ListNode* insertLast(ListNode* head, string arg)
{
    
}

ListNode::ListNode(string value,ListNode* next) : value(value), next(next)
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

