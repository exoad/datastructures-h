/// \file BigMath.h
/// \author Jack Meng
/// \brief A program to implement big numbers using a linked list.
/// \date 2024-01-07

#ifndef BIGMATH_H
#define BIGMATH_H

#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

// yes
typedef int64_t I64;
typedef int I32;
typedef char CHAR;
typedef string STR;
using I32=int32_t;
using CHAR=char;
using STR=string;

// Personal marker
#define PRINT(MSG) cout<<MSG;
#define GET(MSG,X) cout<<MSG; \
                   cin>>X;
// This macro is for infinite loops
#define LOOP for(;;)
/**
 * @brief BigMath class which represents a big number using a linked list.
 */
class BigMath
{
      private:
            /**
             * @brief The current digit held
             */
            /**
             * @brief Ptr to next digit or BigMath object (b/c of linked list)
             */
            I32 digit;
            BigMath *next;
            /**
             * @brief Whether the number is negative or not
             */
            bool negative=false;
      public:
            /**
             * @brief Construct a new Big Math object
             */
            BigMath(I64,BigMath*);
            /**
             * @brief Set the Negative object
             */
            void setNegative(bool);
            /**
             * @brief Check if the number is negative
             * @return true if negative
             * @return false if positive
             */
            bool isNegative();
            /**
             * @brief Get the Digit object
             * @return I64
             */
            I64 getDigit();
            /**
             * @brief Get the Next object
             * @return BigMath*
             */
            BigMath* getNext() const;
            /**
             * @brief Set the Digit object
             */
            void setDigit(I64);
            /**
             * @brief Set the Next object
             */
            /**
             * @brief Perform addition on two BigMath objects
             * @return BigMath
             */
            BigMath operator+(BigMath const&);
            /**
             * @brief Perform subtraction on two BigMath objects
             * @return BigMath
             */
            BigMath operator-(BigMath const&);
            /**
             * @brief Copy a BigMath object
             * @return BigMath* pointer to the new BigMath object
             */
            BigMath* copyList(BigMath*);
            /**
             * @brief Gets the last element of a BigMath object
             * @return BigMath* pointer to the last element
             */
            BigMath* ptrLast(BigMath*);
            /**
             * @brief Gets the second last element of a BigMath object
             * @return BigMath* pointer to the second last element
             */
            BigMath* ptrSecLast(BigMath*);
};

BigMath::BigMath(I64 digit,BigMath *next)
{
      this->digit=digit;
      this->next=next;
}

BigMath* BigMath::ptrSecLast(BigMath* arg)
{
      BigMath* curr=arg;
      while(curr->getNext()!=arg->ptrLast(arg))
            curr=curr->getNext();
      return curr;
}

BigMath* BigMath::ptrLast(BigMath* arg)
{
      BigMath* curr=arg;
      // traverse to the last element
      while(curr->getNext()!=nullptr)
            curr=curr->getNext();
      return curr;
}

BigMath* BigMath::copyList(BigMath* arg)
{
      // copy the list
      return arg->getNext()==nullptr?new BigMath(arg->getDigit(),nullptr):new BigMath(arg->getDigit(),copyList(arg->getNext()));
}

void BigMath::setNegative(bool negative)
{
      this->negative=negative;
}

bool BigMath::isNegative()
{
      return negative;
}

I64 BigMath::getDigit()
BigMath::BigMath(I32 digit,BigMath *next):digit(digit),next(next)
{}

I32 BigMath::getDigit()
{
      return digit;
}

BigMath* BigMath::getNext() const
{
      return next;
}

void BigMath::setDigit(I32 d)
{
      this->digit=d;
}

void BigMath::setNext(BigMath *n)
{
      this->next=n;
}

BigMath BigMath::operator+(BigMath const& n)
{
    BigMath* res=nullptr;
    BigMath* curr=nullptr;
    BigMath* a=this;
    BigMath* b =(BigMath*)&n;
    I64 carry=0;
    // add corresponding digits
    while (a!=nullptr||b!=nullptr||carry!=0)
    {
        I64 sum=carry;
        if (a!=nullptr)
        {
            sum+=a->getDigit();
            a=a->getNext();
        }
        if (b!=nullptr)
        {
            sum+=b->getDigit();
            b=b->getNext();
        }
        // carry over the digit if necessary
        carry=sum/10;
        if (res==nullptr)
        {
            // create the first node
            res=new BigMath(sum%10,nullptr);
            curr=res;
        }
        else
        {
            // add a new node
            curr->setNext(new BigMath(sum%10,nullptr));
            curr=curr->getNext();
        }
    }
    return *res;
=======
      BigMath* result=nullptr;
      BigMath* current=nullptr;
      BigMath* a=this;
      BigMath* b=(BigMath*)&n;
      I32 c=0;
      while(a!=nullptr||b!=nullptr)
      {
            I32 sum=c;
            if(a!=nullptr)
            {
                  sum+=a->getDigit();
                  a=a->getNext();
            }
            if(b!=nullptr)
            {
                  sum+=b->getDigit();
                  b=b->getNext();
            }
            c=sum/10;
            if(result==nullptr)
            {
                  result=new BigMath(sum%10,nullptr);
                  current=result;
            }
            else
            {
                  current->setNext(new BigMath(sum%10,nullptr));
                  current=current->getNext();
            }
      }
      if(c>0)
            current->setNext(new BigMath(c,nullptr));
      return *result;
>>>>>>> faec63ecc8b672e86b7add5f05bfe60fb26c5222
}

/**
 * @brief Trim the BigMath object by removing leading zeroes
 * @param arg  BigMath object to trim
 */
static inline void trim(BigMath* arg)
{
      while(arg->ptrLast(arg)!=arg&&arg->ptrLast(arg)->getDigit()==0)
      {
            delete arg->ptrLast(arg);
            arg->ptrSecLast(arg)->setNext(nullptr);
      }
}

BigMath BigMath::operator-(BigMath const& n)
{
<<<<<<< HEAD
    BigMath* res=new BigMath(0,nullptr);
    BigMath* curr=res;
    BigMath* a=copyList(this);
    BigMath* b=copyList((BigMath*)&n);
    // subtract corresponding digits
    while (a!=nullptr||b!=nullptr)
    {
        curr->setDigit(a->getDigit()-b->getDigit());
        if(a!=nullptr)
=======
    BigMath* res=nullptr;
    BigMath* curr=nullptr;
    BigMath* a=this;
    BigMath* b=(BigMath*)&n;
    I32 borrow=0;
    while (a!=nullptr||b!=nullptr||borrow!=0)
    {
        I32 diff=borrow;
        if (a!=nullptr)
        {
            diff+=a->getDigit();
>>>>>>> faec63ecc8b672e86b7add5f05bfe60fb26c5222
            a=a->getNext();
        if(b!=nullptr)
            b=b->getNext();
        curr->setNext(new BigMath(0, nullptr));
        curr = curr->getNext();
    }
    trim(res);
    curr=res;
    // carry over the negative sign if necessary
    while (curr!=nullptr)
    {
        // if the current digit is negative, carry over the negative sign
        if(curr->getDigit()<0&&curr->getNext()!=nullptr)
        {
            curr->setNegative(true);
            curr->setDigit(curr->getDigit()+10);
            curr=curr->getNext();
            curr->setDigit(curr->getDigit()-1);
        }
        else
        {
            // if the current digit is negative and there is no next digit, carry over the negative sign
            curr=curr->getNext();
        }
    }
    // remove leading zeroes
    trim(res);
    return *res;
}

/**
 * @brief Create a BigMath object from a string
 * @param number string to convert
 * @return BigMath BigMath object
 */
BigMath makeBigMath(STR number)
{
    BigMath* head = new BigMath(number[number.length()-1]-'0',nullptr);
    BigMath *curr=head;
    // stores the number in reverse order in the linked list
    for (I64 i=number.length()-2;i>=0;i--)
    {
        curr->setNext(new BigMath(number[i]-'0',nullptr));
        curr=curr->getNext();
    }
    return *head;
}

/**
 * @brief Collate a BigMath object into a string
 * @param number BigMath object to collate
 * @return STR string representation of BigMath object
 */
STR collateBigMath(BigMath const& number)
{
      STR res="";
      BigMath* curr=(BigMath*)&number;
      bool isNegative=curr->isNegative();
      while(curr!=nullptr)
      {
            // aggregate the number in reverse order
            res=to_string(abs(curr->getDigit()))+res;
            curr=curr->getNext();
      }
      return isNegative?"-"+res:res;
}


#endif
