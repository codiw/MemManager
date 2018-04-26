// Programmer: Codi Whittaker
// Last modification date: Febrauary 24, 18

#include <cassert>
#include <iostream>
#include "MemoryManager.h"

MemoryManager::MemoryManager(unsigned int memtotal)
{
   memsize = memtotal; // size of the "heap"
   baseptr = new unsigned char[memsize]; // allocate the heap
   // create empty blocknode list
   header = new blocknode();
   trailer = new blocknode();
   header->next = trailer;
   trailer->prev = header;
   // create blocknode to represent the entire heap
   blocknode *  originalBlocknode = new blocknode(memsize,baseptr,true);  
   header->insertAfter(originalBlocknode);
}

void MemoryManager::showBlockList() 
{
   blocknode *tmp = header->next;
   while(tmp->next != trailer) {
      cout << tmp << "->";
      tmp = tmp->next;
   }
   cout << tmp << "\n\n";
}

void MemoryManager::splitBlock(blocknode *p, unsigned int chunksize)
{
	//create temp block and pass information
	//call insertAfter
	//set free to false 
	//set blocksize to chunksize

	blocknode *temp = new blocknode(p->blocksize - chunksize, p->blockptr + chunksize, true);
	p->insertAfter(temp);
	p->free = false; 
	p->blocksize = chunksize; 
}
	

unsigned char * MemoryManager::malloc(unsigned int request)
{
	/*while != trailer
	if blocksize == free && free == true
	  set free to false
	  return blockptr
	else 
   if free == true && blocksize > request
	splitBlock()
	return blockptr
   next
  return null*/

	blocknode* curr = header->next;
	while (curr != trailer)
	{
		if (curr->free == true && curr->blocksize == request)
		{
			curr->free = false;
			return curr->blockptr;
		}
		else if (curr->free == true && curr->blocksize > request)
		{
			splitBlock(curr, request);
			return curr->blockptr;
		}
		curr = curr->next;
	}
	return nullptr;
}

void MemoryManager::mergeForward(blocknode *p)
{	
	if (p->next->free)
	{
		p->blocksize += p->next->blocksize;
		p->deleteNext();
	}
}

void MemoryManager::mergeBackward(blocknode *p)
{ 
	if (p->prev->free)
	{
		p->blocksize += p->prev->blocksize;
		p->deletePrevious();
	}
}

void MemoryManager::free(unsigned char *ptr2block)
{
	/*while != trailer
	if blockptr == ptr2block
	  set free to true
	  mergeForward()
	  mergeBackward()
	  return 
	next
	*/

	blocknode* curr = header->next;
	while (curr != trailer)
	{
		if (curr->blockptr == ptr2block)
		{
			curr->free = true;
			mergeForward(curr);
			mergeBackward(curr);
			return;
		}
		curr = curr->next;
	}
}


