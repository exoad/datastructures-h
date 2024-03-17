#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <cctype>
#include <algorithm>

#define STR std::string

constexpr const char* outFile="result.txt";

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
    LLNode(T data,LLNode* next): data(data),next(next)
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
    Stack(T data): top(new LLNode<T>(data,nullptr))
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
     * @brief Peeks the top of the stack and accesses the pointer to the node itself
     *
     * @return the top of the stack (literally the node itself, not the value)
     */
    LLNode<T>* peekNode()
    {
        if(top==nullptr)
            throw std::out_of_range("Stack is empty on peekNode()");
        return top;
    }

    /**
     * @brief Pop the top node off the stack
     *
     * @return STR The data from the top node
     */
    T pop()
    {
        if(top==nullptr)
            throw std::out_of_range("Stack is empty on pop()");
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
            throw std::out_of_range("Stack is empty peek()");
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

inline bool isNumber(STR& s)
{
   if(s.empty()||!isdigit(s[0])&&s[0]!='-'&&s[0]!='+')
    return false;
   char* x;
   strtol(s.c_str(),&x,10);
   return (*x==0);
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
        std::cout<<"Error opening file "<<std::endl;
        return -1;
    }
    else
    {
        std::ofstream out(outFile);
        if(!out.is_open())
        {
            std::cout<<"Error opening file "<<std::endl;
            return -1;
        }
        else
        {
            STR line="";
            while(std::getline(file,line))
            {
                std::stringstream bruh(line);
                STR token="";
                Stack<int>* myStackOfNuts=new Stack<int>(0);
                while(bruh>>token)
                {
                    std::cout<<"Token: "<<token<<" is digit "<<(isNumber(token)==0?"false":"true")<<std::endl;
                    if(isNumber(token))
                        myStackOfNuts->push(atoi(token.c_str()));
                    else
                    {
                        if(token=="+")
                        {
                            int a=myStackOfNuts->pop();
                            int b=myStackOfNuts->pop();
                            myStackOfNuts->push(a+b);
                        }
                        else if(token=="-")
                        {
                            int a=myStackOfNuts->pop();
                            int b=myStackOfNuts->pop();
                            myStackOfNuts->push(b-a);
                        }
                        else if(token=="*")
                        {
                            int a=myStackOfNuts->pop();
                            int b=myStackOfNuts->pop();
                            myStackOfNuts->push(a*b);
                        }
                        else if(token=="/")
                        {
                            int a=myStackOfNuts->pop();
                            int b=myStackOfNuts->pop();
                            myStackOfNuts->push(b/a);
                        }
                        else if(token=="%")
                        {
                            int a=myStackOfNuts->pop();
                            int b=myStackOfNuts->pop();
                            myStackOfNuts->push(b%a);
                        }
                        else if(token=="!")
                        {
                            int base=myStackOfNuts->pop();
                            int p=1;
                            for(int i=1;i<=base;i++)
                                p*=i;
                            myStackOfNuts->push(p);
                        }
                        else if(token=="^")
                        {
                            int a=myStackOfNuts->pop();
                            int b=myStackOfNuts->pop();
                            myStackOfNuts->push(pow(b,a));
                        }
                    }
                }
                out<<line<<": "<<myStackOfNuts->peek()<<std::endl;
            }
        }
    }
}