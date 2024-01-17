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
    I64 digit;
    /**
     * @brief Ptr to next digit or BigMath object (b/c of linked list)
     */
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
    void setNext(BigMath*);
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
{
    return digit;
}

BigMath* BigMath::getNext() const
{
    return next;
}

void BigMath::setDigit(I64 digit)
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
    I64 carry=0;
    // add corresponding digits
    while(a!=nullptr||b!=nullptr||carry!=0)
    {
        I64 sum=carry;
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
        // carry over the digit if necessary
        carry=sum/10;
        if(res==nullptr)
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

bool lessThan(BigMath &a,BigMath &b)
{
    // check if b is less than a
    BigMath* currA=&a;
    BigMath* currB=&b;
    while(currA!=nullptr&&currB!=nullptr)
    {
        if(currA->getDigit()<currB->getDigit())
            return true;
        else if(currA->getDigit()>currB->getDigit())
            return false;
        currA=currA->getNext();
        currB=currB->getNext();
    }
    return currA==nullptr&&currB!=nullptr;
}

BigMath BigMath::operator-(BigMath const& n)
{
    BigMath* res=new BigMath(0,nullptr);
    BigMath* curr=res;
    BigMath* a=copyList(this);
    BigMath* b=copyList((BigMath*)&n);
    // subtract corresponding digits
    while(a!=nullptr||b!=nullptr)
    {
        curr->setDigit(a->getDigit()-b->getDigit());
        if(a!=nullptr)
            a=a->getNext();
        if(b!=nullptr)
            b=b->getNext();
        curr->setNext(new BigMath(0,nullptr));
        curr = curr->getNext();
    }
    trim(res);
    curr=res;
    // carry over the negative sign if necessary
    while(curr!=nullptr)
    {
        curr->setNegative(true);
        // if the current digit is negative, carry over the negative sign
        if(curr->getDigit()<0&&curr->getNext()!=nullptr)
        {
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
    for(I64 i=number.length()-2;i>=0;i--)
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


// main function for testing code
I32 main(void)
{
    // upper case formatting bc i always code like this and makes the code stand out
    STR ___USERE;
    LOOP
    {
        STR a,b;
    GET("Enter first positive integer: ",a)
        GET("Enter second positive integer: ",b)
        BigMath n1=makeBigMath(a);
    BigMath n2=makeBigMath(b);
    BigMath res={0,nullptr};
    STR op;
    GET("Add or subtract? (+/-): ",op)
        if(op=="+")
            res=n1+n2;
        else if(op=="-")
            res=n1-n2;
    PRINT((op=="+"?"Sum = ":"Difference = ")+collateBigMath(res))
        GET("\nDo another? (y/n): ",___USERE)
        if(___USERE!="Y"||___USERE!="y")break;
    }
}