# Bitwise Operations
**Definition**  
Bitwise operations are a set of operations done on a binary string that compares and manipulates the individual bits.  

## Bitwise AND
For two inputs, each bit will be compared and will return 1 only if both bits are 1.

| A | B | Output |  
| :-: | :-: | :-: |  
| 0 | 0 | 0 |  
| 0 | 1 | 0 |
| 1 | 0 | 0 |  
| 1 | 1 | 1 |   

## Bitwise OR
Returns 1 if either input includes a 1.

| A | B | Output |  
| :-: | :-: | :-: |  
| 0 | 0 | 0 |  
| 0 | 1 | 1 |
| 1 | 0 | 1 |  
| 1 | 1 | 1 |

## Bitwise XOR
Returns 1 only if one input contains a 1.

| A | B | Output |  
| :-: | :-: | :-: |  
| 0 | 0 | 0 |  
| 0 | 1 | 1 |
| 1 | 0 | 1 |  
| 1 | 1 | 0 |

## Bitwise NOT
Takes one input and inverts each bit of the binary string.

| A | Output |  
| :-: | :-: |  
| 0 | 1 |  
| 1 | 0 |

## Bit shifting
Given a binary string and a number `n`, the left bit shift will shift the binary string `n` bits to the left, and the right shift will shift the binary string to the right. If the data type of the binary string has a fixed byte length, then in left shifts, the most significant bit (MSB) is discarded, and the least significant bit (LSB) is discarded in right shifts.

```
1100
↓
1000 (Left shift 1, assuming fixed-width and unsigned)
```
If the input is signed and negative, the bit shift may insert a 1 when  necessary, but this is not universal.

## Use cases
### Masking
Masking is the act of applying a mask to a value. A mask defines which bits to preserve and which to clear. 
```
Mask:  00001111
Value: 01010101
```
The placement of the 0s in the mask shows that the lower 4 bits are to kept, and the method of doing this is with the bitwise AND operation which yields the lower 4 bits:
```
00001111
01010101
---------
00000101
0000-0101
```
### Setting, Clearing, and Toggling
Setting: 0 → 1  
Clearing: 1 → 0  
Toggling: 1 → 0 or 0 → 1  

To set a bit, the bitwise OR operation is needed with a bit mask that only contains 1 in the position of the bit to be set, and 0 in every other position. The OR operation will with the specified bit mask will only change the bit when its position is the value 0.  

---

To clear a bit, the bitwise AND operation is needed with a bit mask that only contains 0 in the position of the bit to be cleared, and 1 in every other position. The AND operation is used because it will retain both 0s and 1s, while only changing the bit that has the value 0 and is the position for the bit mask. 

---

To toggle a bit, the bitwise XOR operation is needed with a bit mask that only contains 1 in the position of the bit to be toggled, and 0 in every other position. The XOR operation is used because this operation does nothing when XORing with 0, but is able to flip a bit.

## Symbols in C
```
& (AND)
| (OR)
^ (XOR)
~ (NOT)
```




