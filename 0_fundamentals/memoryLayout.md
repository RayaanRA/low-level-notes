# Memory Layout
Computer memory is conceptually laid out as an organized sequence of addressable bytes. Each byte in memory has a unique address that can be directly accessed by the CPU.  

Bytes in memory represent something, whether they be integers, floats, or characters. Each data type can take up a different amount of bytes in memory. Note that these sizes can vary depending on programming language and system architecture.

## Endianness
Describes how computers organize bytes in terms of byte order. There are two main types of endianness:

**Little-endian**  
The most common ordering of bytes where they are stored in order of least to most significant. The least significant being the first or lower address.

**Big-endian**  
The opposite order of little-endian. Bytes are stored in order of most to least significant.  

Example:  
```
0x12345678 (hexadecimal, two digits is one byte)

little-endian: 0x78 0x56 0x34 0x12 (0x78 takes the lower address)
big-endian: 0x12 0x34 0x56 0x78 (0x12 takes the lower address)
```

## Storing and Accessing Data

The amount of memory in a computer is fixed, and memory has "slots" that store a fixed number of bits, usually 1 byte. 

For data larger than 8 bits (1 byte), more memory slots are needed back-to-back (contiguous).

### Pointers
As mentioned earlier, each slot in memory has an address to be easily accessed by the CPU. The memory address of some data can be stored in another slot of memory, which is then called a pointer.

### Reading Memory
Since certain data types can take up a different amount of bytes in memory, it is important for the CPU to know how many bytes to read for a particular instruction. This is given by the program, written by the programmer.


![Visualization of computer memory](https://www.cs.emory.edu/~cheung/Courses/255/Syllabus/4-intro/FIGS/memory01b.gif)