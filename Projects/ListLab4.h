#pragma once

/**
 * @file ListLab4.h
 * @author Jack Meng
 * @brief Demonstrates some basics with LinkedLists
 * @date 2024-2-6
 */

#include <string>
#include <iostream>

using STR=std::string;

/**
 * @brief A node in a doubly circular linked list
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
        /**
         * @brief Print the list forward from a specific position
         *
         * @param position The position to start printing from
         * @param head The head of the list
         */
        void printForward(int position,ListNode* head);
        /**
         * @brief Print the list backward from a specific position
         *
         * @param position The position to start printing from
         * @param head The head of the list
         */
        void printBackward(int position,ListNode* head);
};

ListNode::ListNode(STR data,ListNode* next,ListNode* prev):data(data),next(next),prev(prev)
{}

void ListNode::printForward(int position,ListNode* head)
{
      if(head->prev==head)
      {
            std::cout<<"Empty"<<std::endl;
            return;
      }
      ListNode* curr=head; // keep track of the curr node
      for(int i=0;i<position&&curr->next!=head;i++)
            curr=curr->next;
      do{std::cout<<*curr<<"<=>";
         curr=curr->next;}while(curr!=head);
}

void ListNode::printBackward(int position,ListNode* head)
{
      if(head->next==head)
      {
            std::cout<<"Empty"<<std::endl;
            return;
      }
      ListNode* curr=head; // keep track of the curr node
      for(int i=0;i<position&&curr->prev!=head;i++)
            curr=curr->prev;
      std::cout<<curr->data;
      do{curr=curr->prev;
         std::cout<<"<=>"<<curr->data;}while(curr!=head);
}

std::ostream& operator<<(std::ostream& os, const ListNode& node)
{
    if(node.next==&node)
    {
      os<<"Empty";
      return os;
    }
    ListNode* temp=node.next;
    os<<node.data;
    do{temp=temp->next;
       os<<"<=>"<<temp->data;}while(temp->next!=&node);
    return os;
}

ListNode* ListNode::add(int position,ListNode* n)
{
      if(n==nullptr)
            return this;
      if(position==0)
            return add(n);
      ListNode* temp=this;
      for(int i=0;i<position-1&&temp->next!=nullptr;i++)
            temp=temp->next;
      if(temp->next==this)
      {
            n->next=this;
            n->prev=this->prev;
            this->prev->next=n;
            this->prev=n;
      }
      else
      {
            n->next=temp->next;
            n->prev=temp;
            temp->next->prev=n;
            temp->next=n;
      }
      return this;
}

ListNode* ListNode::add(ListNode* n)
{
      if(n==nullptr)
            return this;
      n->next=this;
      n->prev=this->prev;
      this->prev->next=n;
      this->prev=n;
      return n;
}

ListNode* ListNode::remove()
{
      if(this->next==this)
            return nullptr;
      this->next->prev=this->prev;
      this->prev->next=this->next;
      ListNode* temp=this->next;
      delete this;
      return temp;
}

ListNode* ListNode::remove(int position)
{
      if(position==0)
            return remove();
      ListNode* temp=this;
      for(int i=0;i<position&&temp->next!=nullptr;i++)
            temp=temp->next;
      if(temp->next==this)
      {
            temp->prev->next=this;
            this->prev=temp->prev;
      }
      else
      {
            temp->prev->next=temp->next->next;
            temp->next->prev=temp;
      }
      return this;
}