#ifndef __MM__
#define __MM__

#include <iostream>
#include <sstream>
#include "blocknode.h"

using namespace std;

class MemoryManager
{
  public:
   MemoryManager(unsigned int memtotal);
   unsigned char * malloc(unsigned int request);
   void free(unsigned char * ptr2block);
   void showBlockList();
   
  private:
   blocknode *header;
   blocknode *trailer;
   unsigned int memsize;
   unsigned char *baseptr;

   void mergeForward(blocknode *p);
   void mergeBackward(blocknode *p);
   void splitBlock(blocknode *p,unsigned int chunksize);
};

#endif
