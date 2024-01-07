/// \file BigMath.h
/// \author Jack Meng
/// \brief A program to implement big numbers using a linked list.
/// \date 2024-01-07


#pragma once

#include <cstdint>
#include <cstring>
#include <iostream>

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
            BigMath* getNext();
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

BigMath* BigMath::getNext()
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
      BigMath* result=nullptr;
      BigMath* current=nullptr;
      BigMath* a=this;
      BigMath* b=(BigMath*)&n;
      I8 c=0;
      while(a!=nullptr||b!=nullptr)
      {
            I8 sum=c;
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
      BigMath* result=nullptr;
      BigMath* current=nullptr;
      BigMath* a=this;
      BigMath* b=(BigMath*)&n;
      I8 c=0;
      while(a!=nullptr||b!=nullptr)
      {
            I8 diff=c;
            if(a!=nullptr)
            {
                  diff+=a->getDigit();
                  a=a->getNext();
            }
            if(b!=nullptr)
            {
                  diff-=b->getDigit();
                  b=b->getNext();
            }
            c=diff/10;
            if(result==nullptr)
            {
                  result=new BigMath(diff%10,nullptr);
                  current=result;
            }
            else
            {
                  current->setNext(new BigMath(diff%10,nullptr));
                  current=current->getNext();
            }
      }
      if(c>0)
            current->setNext(new BigMath(c,nullptr));
      return *result;
}

BigMath makeBigMath(STR number)
{
      BigMath* head=nullptr;
      BigMath* current=nullptr;
      I32 i=0;
      while(number[i]!='\0')
      {
            if(head==nullptr)
            {
                  head=new BigMath(number[i]-'0',nullptr);
                  current=head;
            }
            else
            {
                  current->setNext(new BigMath(number[i]-'0',nullptr));
                  current=current->getNext();
            }
            i++;
      }
      return *head;
}

STR collateBigMath(BigMath const& number)
{
      STR result="";
      BigMath* current=(BigMath*)&number;
      while(current!=nullptr)
      {
            result=(CHAR)(current->getDigit()+'0')+result;
            current=current->getNext();
      }
      return result;
}
