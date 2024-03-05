/**
 * @file ParenthesesMatch.h
 * @author Jack Meng
 * @brief Demonstrates some basics with stack
 * @date 2024-2-6
 */

#include <iostream>
#include <fstream>
#include <string>

#define STR std::string

constexpr const char* outFile="result.txt";
const STR PAREN="([{<)]}>";

template<typename T>
/**
 * @brief A node in a singly linked list
 */
class LLNode
{
public:
      /**
       * @brief The data stored in the node
       */
      T data;
      /**
       * @brief The next node in the list
       */
      LLNode* next;
      /**
       * @brief Construct a new LLNode object
       *
       * @param data The data to be stored in the node
       * @param next The next node in the list
       */
      LLNode(T data,LLNode* next) : data(data),next(next)
      {}
};

template<typename T>
/**
 * @brief A stack implemented with a singly linked list
 */
class Stack
{
private:
      /**
       * @brief The top of the stack (the first node)
       */
      LLNode<T>* top;
public:
      /**
       * @brief Construct a new Stack object
       *
       * @param data The data to be stored in the first node
       */
      Stack(T data) : top(new LLNode<T>(data,nullptr))
      {}

      /**
       * @brief Destroy the Stack object
       */
      ~Stack()
      {
            while(top!=nullptr)
            {
                  LLNode<T>* temp=top;
                  top=top->next;
                  delete temp;
            }
      }

      /**
       * @brief Push a new node onto the stack
       *
       * @param data The data to be stored in the new node
       */
      void push(T data)
      {
            LLNode<T>* temp=new LLNode<T>(data,top);
            top=temp;
      }

      /**
       * @brief Pop the top node off the stack
       *
       * @return STR The data from the top node
       */
      T pop()
      {
            if(top==nullptr)
                throw std::out_of_range("Stack is empty");
            LLNode<T>* temp=top;
            top=top->next;
            T data=temp->data;
            delete temp;
            return data;
      }

      /**
       * @brief Peek at the top node of the stack
       *
       * @return STR The data from the top node
       */
      T peek()
      {
            if(top==nullptr)
                throw std::out_of_range("Stack is empty");
            return top->data;
      }

      /**
       * @brief Check if the stack is empty
       *
       * @return true If the stack is empty
       * @return false If the stack is not empty
       */
      bool isEmpty()
      {
            return top==nullptr;
      }
};

namespace ParenMatch
{
      /**
       * @brief Check if the parentheses in a string are balanced or not (using a stack). The parentheses are () [] {} <>
       *
       * @param data The string to check
       * @return true If the parentheses are balanced
       * @return false If the parentheses are not balanced
       */
      bool checkParen(STR data)
      {
            Stack<int>* s=new Stack<int>(-1);
            for(int i=0;i<data.length();i++)
            {
                  int index=PAREN.find(data[i]);
                  if(index!=STR::npos)
                  {
                        if(index<4)
                              s->push(index);
                        else if(s->pop()!=index%4)
                              return false;
                  }
            }
            return s->peek()==-1||s->isEmpty();
      }
}

int main(void)
{
      STR fName;
      // get the file name and other stuffs
      std::cout<<"Enter file name: ";
      std::cin>>fName;
      std::ifstream file(fName);
      if(!file.is_open())
      {
            std::cout<<"Error opening file"<<std::endl;
            return -1;
      }
      else
      {
            // ok lets ball
            int i=0;
            std::ofstream out(outFile);
            if(!out.is_open())
            {
                  std::cout<<"Error opening file"<<std::endl;
                  return -1;
            }
            else
            {
                  //im tired so this part just reads the file and writes the result to another file and things (idek what im saying anymore)
                  STR line="";
                  out<<std::boolalpha;
                  while(std::getline(file,line))
                  {
                        out<<i<<": "<<ParenMatch::checkParen(line)<<std::endl;
                        i++;
                  }
                  out.close();
                  file.close();
            }
      }
}