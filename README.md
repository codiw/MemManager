# MemManager
The goal of this project is to simulate the C heap manager which is used to allocate and deallocate dynamic memory.
The “heap” is a large pool of memory set aside by the runtime system for a program to use for dynamic variables.

The two main heap manager functions are: 
  - malloc, used to satisfy a request for a specific number of consecutive bytes
  - free, used to make allocated blocks available for future malloc requests (i.e., return them to the pool of available memory).

Our simulation uses an initially allocated large block of unsigned chars as our memory pool for dynamic allocation (the heap).
As memory is allocated (by calls to malloc) and deallocated (by calls to free), the heap will be made up of consecutive blocks of memory
that are either available for allocation (free) or currently allocated. We will use an array of unsigned char (bytes) as our 
pool of allocatable bytes.This is allocated by the MemoryManager constructor yo keep track of the allocated and available blocks of 
memory, we will use a doubly-linked list of blocknodes which will use header and trailer nodes.Each blocknode "manages" a 
single block of consecutive blocks in the memory pool•In addition to the usual next and prev pointers, a blocknode will have the
following attributes:
  
  blocksize - the number of bytes in the block
  blockptr - the address of the first byte of the block
  free - a Boolean flag
