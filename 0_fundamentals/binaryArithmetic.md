# Binary Arithmetic

## Unsigned vs. Signed Integers
A signed integer is a 32-bit datum[^1] that contains an integer in a range from a very small negative number to a very large positive number.

An unsigned integer is the same, but rather the range only includes nonnegative numbers, allowing for bigger positive numbers.

The signed integer is represented in twos complement notation.
```c
unsigned int unsignedInteger;
signed int signedInteger;
```

[^1]: a piece of information.

## Signed Magnitude Representation
A method of representation for signed integers.  
The bit with the greatest value is used to represent the sign (+/-) of the number.  
1 = Negative  
0 = Positive  
```
0110 = +6
1010 = -6
```

## Two's Complement
A method of representation for signed integers.
Unlike signed magnitude, the most significant bit is used both as a sign indicator and as a contributor to the entire number, as a negative one.
The two's complement is found by first finding the one's complement (flipping each bit), then adding 1 to that result.

Example:
```
0111 (7)
1000 (one's complement)
1001 (two's complement)
8421 (bit placement)
-8 + 0 + 0 + 1 = -7
```

Practice:
```
01100 (12)
10011 (one's complement)
10100 (two's complement)
16 8 4 2 1
-16 + 0 + 4 + 0 + 0 = -12
```
## Bit Addition, Subtraction, and Overflow Behavior
### Bit Addition
Behaves similarly to decimal addition:  
```
0 + 0 = 0
0 + 1 = 1
1 + 0 = 1
1 + 1 = 10
```
Example:  
```
  10  
+ 11
-----  
 101  
```
Practice:  
```
  11  
+ 01
-----  
 100 (correct)

 1010  
+  11
-----  
 1101 (correct)
```

### Bit Subtraction
