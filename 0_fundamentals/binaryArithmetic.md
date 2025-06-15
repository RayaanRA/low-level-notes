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

## Two's Complement Representation
The most common method of representation for signed integers.  
The bit with the greatest value is used to represent the sign (+/-) of the number.  
1 = Negative  
0 = Positive  
```
0110 = +6
1010 = -6
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