#pragma once

#include <cstdint>
#include <cstring>
#include <iostream>

using namespace std;

// we do some funny
typedef int32_t I32;
typedef int8_t I8;
#define CHAR char
typedef string STR;

class BigMath
{
      private:
            I8 digit;
            BigMath *next;
      public:
            BigMath(I8,BigMath*);
            I8 GetDigit();
            BigMath* GetNext();
            void SetDigit(I8);
            void SetNext(BigMath*);
            BigMath operator+(BigMath const&);
            BigMath operator-(BigMath const&);
};

BigMath::BigMath(I8 digit,BigMath *next)
{
      this->digit=digit;
      this->next=next;
}

I8 BigMath::GetDigit()
{
      return digit;
}

BigMath* BigMath::GetNext()
{
      return next;
}

void BigMath::SetDigit(I8 digit)
{
      this->digit=digit;
}

void BigMath::SetNext(BigMath *next)
{
      this->next=next;
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
                  sum+=a->GetDigit();
                  a=a->GetNext();
            }
            if(b!=nullptr)
            {
                  sum+=b->GetDigit();
                  b=b->GetNext();
            }
            c=sum/10;
            if(result==nullptr)
            {
                  result=new BigMath(sum%10,nullptr);
                  current=result;
            }
            else
            {
                  current->SetNext(new BigMath(sum%10,nullptr));
                  current=current->GetNext();
            }
      }
      if(c>0)
            current->SetNext(new BigMath(c,nullptr));
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
                  diff+=a->GetDigit();
                  a=a->GetNext();
            }
            if(b!=nullptr)
            {
                  diff-=b->GetDigit();
                  b=b->GetNext();
            }
            c=diff/10;
            if(result==nullptr)
            {
                  result=new BigMath(diff%10,nullptr);
                  current=result;
            }
            else
            {
                  current->SetNext(new BigMath(diff%10,nullptr));
                  current=current->GetNext();
            }
      }
      if(c>0)
            current->SetNext(new BigMath(c,nullptr));
      return *result;
}

BigMath JMParse(STR number)
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
                  current->SetNext(new BigMath(number[i]-'0',nullptr));
                  current=current->GetNext();
            }
            i++;
      }
      return *head;
}

STR JMCollate(BigMath const& number)
{
      STR result="";
      BigMath* current=(BigMath*)&number;
      while(current!=nullptr)
      {
            result=(CHAR)(current->GetDigit()+'0')+result;
            current=current->GetNext();
      }
      return result;
}
