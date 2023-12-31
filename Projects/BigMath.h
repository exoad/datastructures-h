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
using I32=int32_t;
using CHAR=char;
using STR=string;

class BigMath
{
      private:
            I32 digit;
            BigMath *next;
      public:
            BigMath(I32,BigMath*);
            I32 getDigit();
            BigMath* getNext() const;
            void setDigit(I32);
            void setNext(BigMath*);
            BigMath operator+(BigMath const&);
            BigMath operator-(BigMath const&);
};

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
}

BigMath BigMath::operator-(BigMath const& n)
{
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
