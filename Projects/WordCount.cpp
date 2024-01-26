/**
 * @file WordCount.cpp
 * @author Jack Meng
 * @brief Count words in a file using a linkedlist
 * @date 2024-01-26
 */
#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cctype>
using STR=std::string;
using I32=int;
/**
 * @brief A very small and lightweight linkedlist ds
 */
class LNode
{
    public:
        /**
         * @brief Frequency that this word has been counted for
         */
        I32 freq;
        /**
         * @brief The word in question
         */
        STR word;
        /**
         * @brief The next node pointed to
         */
        LNode* next;
        /**
         * @brief Construct a new LNode object
         * @param freq frequency
         * @param word word
         * @param next next node
         */
        LNode(I32 freq,STR word,LNode* next):freq(freq),word(word),next(next)
        {}
        /**
         * @brief Destroy the LNode object
         */
        ~LNode()
        {if(next!=nullptr)delete next;}
};
I32 main(void)
{
      STR fileName; // read file to search for and ask user for the file
      std::cout<<"Enter file name: ";
      std::cin>>fileName;
      std::ifstream fin;
      fin.open(fileName);
      if(fin.is_open()) // initiates the reading process by making sure the file is opened properly
      {
        STR word; LNode* llist_head=nullptr; LNode* llist_tail=nullptr;
        while(fin>>word) // start looking thru the file
        {
            LNode* curr=llist_head; LNode* prev=nullptr;
            while(curr!=nullptr&&curr->word.size()==word.size()&&std::equal(word.begin(),word.end(),curr->word.begin(),[](char x,char y){return std::tolower(static_cast<char>(x))==std::tolower(static_cast<char>(y));})) // here we check if the read word has been looked at using a tolower ignore case implementation is kind of scuffed
            {
                prev=curr;
                curr=curr->next;
            }
            if(curr!=nullptr)curr->freq++;
            else
            {   // emplaces at the end of the list if the word was not found
                LNode* temp=new LNode(1,word,nullptr);
                prev!=nullptr?prev->next=temp:llist_head=temp;
                llist_tail=temp;
            }
        }
        std::ofstream fout; // write results to the result.txt file
        fout.open("result.txt",std::ios::trunc);
        if(fout.is_open())
        {
            LNode* curr=llist_head;
            while(curr!=nullptr) //generic loop thru linkedlist and print the prettified results to the file
            {
                fout<<curr->word<<"="<<curr->freq<<"\n";
                curr=curr->next;
            }
            fout.close(); // finalize
            std::cout<<"Wrote results to result.txt";
            return 0;
        }
        else
        { // error
            std::cout<<"Failed to write to result.txt";
            return 1;
        }
      }
      else
      { // error
        std::cout<<"The file "<<fileName<<" could not be opened";
        return 1;
      }
}