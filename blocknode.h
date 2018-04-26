#ifndef _BLOCKNODE_
#define _BLOCKNODE_

#include <iostream>

using namespace std;

struct blocknode {
   unsigned int blocksize;
   bool free;
   unsigned char *blockptr;
   blocknode *prev;
   blocknode *next;
   blocknode(unsigned int sz = 0, unsigned char * p= nullptr, bool f = false,
	     blocknode *before=nullptr, blocknode *after=nullptr) : blocksize(sz), blockptr(p), free(f), prev(before),next(after) {};
   void insertAfter(blocknode *newbnode);
   void insertBefore(blocknode *newbnode);
   void deletePrevious();
   void deleteNext();
};

ostream& operator << (ostream&, blocknode *);

#endif
