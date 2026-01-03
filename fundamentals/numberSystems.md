# Number Systems 

A number system is a way of representing numbers, with each having a difference in their bases and sometimes symbols (hexadecimal letters).  

For example, the common decimal, or base 10, system grows by a power of 10 with each movement in place to the left.

```
2 = 2 * 10 ^ 0 = 2
20 = 2 * 10 ^ 1 + 0 * 10^0 = 20
```

Therefore, every number system's placement can be written as its base to the power of an increasing number starting at 0:
```
Decimal: 10 ^ 3  10 ^ 2  10 ^ 1  10 ^ 0
Binary:   2 ^ 3   2 ^ 2   2 ^ 1   2 ^ 0
```

This section will mainly cover hexadecimal numbers as decimal and binary have become familiar.

## Hexadecimal System
The hexadecimal number system is base 16, which is more than decimal. This means that the symbols (0-9) for the decimal system are not sufficient for the hexadecimal system. This is resolved by using the first 6 letters of the alphabet (A-F) which are in place of the decimal numbers 10-15.
```
Hexadecimal: 0 1 2 3 4 5 6 7 8 9  A  B  C  D  E  F
Decimal:     0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
```
The hexadecimal system adds 1 to the position on the left and resets to 0 after reaching F (15).

Example:  
What is 4B5 in decimal?
```
256 16 1 (hexadecimal placement)
4 * 256 + 11 * 16 + 5 = 1205 (decimal)
```

### Conversions

**Binary to Hexadecimal**  
Divide the binary number into groups of 4. If there is a remainder, add 0s on the left to create a group of 4. Convert each binary group of 4 to decimal, then hexadecimal. The digits in order form the hexadecimal number.

**Hexadecimal to Binary**  
Convert each hexadecimal digit to decimal, then convert each of those numbers into a 4 bit binary number. Combine them in order of the original hexadecimal to obtain the binary number.

### Importance of the Hexadecimal System
As the binary number system only includes two digits, numbers can become very long quickly, making it hard to work with and read. The hexadecimal system, being able to represent more digits than decimal in one digit, is much more compact, and very easy to convert back and forth between binary.

## Octal Number System
The octal number system is base 8, using the digits 0 to 7. It follows the same principle of positional value as binary, decimal, and hexadecimal systems.  
Example:      
What is 157 in decimal?  
```
1 * 64 + 5 * 8 + 7 = 111 (decimal)
```