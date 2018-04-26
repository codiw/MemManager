#include "blocknode.h"
#include <cassert>
#include <iostream>
using namespace std;

ostream &operator << (ostream &out, blocknode *p)
{
  out << "[" << p->blocksize << ",";
  if (p->free)
    out << "free";
  else
    out << "allocated";
  out << "]";
  return out;
}

void blocknode::insertAfter(blocknode *newbnode)
{
   assert(next != nullptr); // not trailer node
   newbnode->prev = next->prev;
   newbnode->next = next;
   next = newbnode;
   newbnode->next->prev = newbnode;
}

void blocknode::insertBefore(blocknode *newbnode)
{
   assert(prev != nullptr); // not header node
   newbnode->next = prev->next;
   newbnode->prev = prev;
   prev = newbnode;
   newbnode->prev->next = newbnode;
}

   
void blocknode::deletePrevious()
{
   // not header and previous is not header
   assert(prev != nullptr && prev->prev != nullptr);
   blocknode * hold = prev;
   prev = hold->prev;
   prev->next = hold->next;
   delete hold;
}
   
void blocknode::deleteNext()
{
   // not trailer and next is not trailer
   assert(next != nullptr && next->next != nullptr);
   blocknode *hold = next;
   next = hold->next;
   next->prev = hold->prev;
   delete hold;
}
