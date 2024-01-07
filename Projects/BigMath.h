/// \file BigMath.h
/// \author Jack Meng
/// \brief A program to implement big numbers using a linked list.
/// \date 2024-01-07


#pragma once

#include <cstdint>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef int32_t I32;
typedef int8_t I8;
typedef char CHAR;
typedef string STR;

class BigMath
{
      private:
            I8 digit;
            BigMath *next;
      public:
            BigMath(I8,BigMath*);
            I8 getDigit();
            BigMath* getNext() const;
            void setDigit(I8);
            void setNext(BigMath*);
            BigMath operator+(BigMath const&);
            BigMath operator-(BigMath const&);
};

BigMath::BigMath(I8 digit,BigMath *next)
{
      this->digit=digit;
      this->next=next;
}

I8 BigMath::getDigit()
{
      return digit;
}

BigMath* BigMath::getNext() const
{
      return next;
}

void BigMath::setDigit(I8 digit)
{
      this->digit=digit;
}

void BigMath::setNext(BigMath *next)
{
      this->next=next;
}

BigMath BigMath::operator+(BigMath const& n)
{
    BigMath* res=nullptr;
    BigMath* curr=nullptr;
    BigMath* a=this;
    BigMath* b =(BigMath*)&n;
    I8 carry=0;
    while (a!=nullptr||b!=nullptr||carry!=0)
    {
        I8 sum=carry;
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
        carry=sum/10;
        if (res==nullptr)
        {
            res=new BigMath(sum%10,nullptr);
            curr=res;
        }
        else
        {
            curr->setNext(new BigMath(sum%10,nullptr));
            curr=curr->getNext();
        }
    }
    return *res;
}

BigMath BigMath::operator-(BigMath const& n)
{
    BigMath* res=nullptr;
    BigMath* curr=nullptr;
    BigMath* a=this;
    BigMath* b=(BigMath*)&n;
    I8 borrow=0;
    while (a!=nullptr||b!=nullptr||borrow!=0)
    {
        I8 diff=borrow;
        if (a!=nullptr)
        {
            diff+=a->getDigit();
            a=a->getNext();
        }
        if (b!=nullptr)
        {
            diff-=b->getDigit();
            b=b->getNext();
        }
        borrow=diff<0?-1:0;
        if (res==nullptr)
        {
            res=new BigMath((diff+10)%10,nullptr);
            curr=res;
        }
        else
        {
            curr->setNext(new BigMath((diff+10)%10,nullptr));
            curr=curr->getNext();
        }
    }
    return *res;
}

BigMath makeBigMath(STR number)
{
      BigMath* head=nullptr;
      BigMath* curr=nullptr;
      I32 i=0;
      while(number[i]!='\0')
      {
            if(head==nullptr)
            {
                  head=new BigMath(number[i]-'0',nullptr);
                  curr=head;
            }
            else
            {
                  curr->setNext(new BigMath(number[i]-'0',nullptr));
                  curr=curr->getNext();
            }
            i++;
      }
      return *head;
}

STR collateBigMath(BigMath const& number)
{
      STR res="";
      BigMath* curr=(BigMath*)&number;
      while(curr!=nullptr)
      {
            res=(CHAR)(curr->getDigit()+'0')+res;
            curr=curr->getNext();
      }
      return res;
}
