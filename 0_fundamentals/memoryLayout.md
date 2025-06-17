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
big-endian: 0x12 0x34 x56 0x78 (0x12 takes the lower address)
```
