/* 
 * CS:APP Data Lab 
 * 
 * Lucy Li, lucyyutingli
 * 
 * bits.c - Source file with your solutions to the project.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the project by
editing the collection of functions in this source file.

CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function.

/*
 * STEP 2: Modify the following functions according to the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest checker to verify that your solutions produce
 *      the correct answers.
 */


#endif

/************************************************ 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
	/*If the number is negative, creates a number that is all 1's, and if positive, a number that is all 0's. We then add ~ of this number
	(which will be 0 or -1) to the XOR of the original x, and the number. This will either inverse the x if it's negative, or leave it alone. 
	If the number was originally positive, then the ~number and 1 will add to create zero, leaving it alone. If not, then adding the 1 will 
	change the number into the correct form. */
  return ~(x>>31) + (x^(x>>31)) + 1;
}

/************************************************ 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
	/*Singles out both signs for x and y, then the sign of their addition result. It then checks if x and y have the same sign. If they do,
	an integer will be true, if not, it will be false. Then you compare to the sign of the result to x. You then & the two, to see if 
	they are the same or not. If they are, then you will receive false because that means the sign of the result of x + y and the sign of x
	were different, when x and y's signs were the same. */
  int a = (x>>31)&0x1;
  int b = (y>>31)&0x1;
  int c = (((x+y)>>31)&0x01);
  int d = !(a^b);
  int e = a^c;

  return !(e&d);

}

/************************************************ 
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) {
	/* I used a mask where all the even bits were set. I XOR'd that result with my original mask, showing me if they were equal. If they were equal,
	the code returns 0, and I ! it because we want them being the same to be true.*/
  int a = (((((((0x0|0x55)<<8)|0x55)<<8)|0x55)<<8)|0x55);
  int b = a&x;
  int c = b^a;
  return !c;
}

/************************************************
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  return ((x|((~x)+1))>>31)+1;
}

/************************************************
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {

int a, b, c, d, final, almost, c1, c2, c3, c4, new, totalbit, FF1, sixt, sixts;

	int mask = 1;
    mask = ((mask<<16)|mask);
    // printf("mask16 %x\n\n", mask);
    mask = ((mask<<8)|mask);
    // printf("mask8 %x\n\n", mask);
    mask = ((mask<<4)|mask);
    // printf("mask4 %x\n\n", mask);
  
     a = x&mask;
     b = x&(mask<<1);
     b = b>>1;
     c = x&(mask<<2);
     c = c>>2;
     d = x&(mask<<3);
     d = d>>3&(~((0x1<<31)>>2));

    totalbit = a+b+c+d;

    FF1 = ((0xFF<<8)|0xFF);
    sixt = (totalbit>>16)&FF1;
    sixts = totalbit&FF1;
    new = sixt+sixts;

    c1 = (new>>12)&0xF;
    c2 = (new>>8)&0xF;
    c3 = (new>>4)&0xF;
    c4 = new&0xF;

    almost = c1+c2+c3+c4;

    final = almost;

	return final;
}


/************************************************
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
    return ((~x)&(~y));
}

/************************************************
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {

  int neight = n<<3;
  int meight = m<<3;
  int nhole = ~(0xFF<<neight);
  int mhole = ~(0xFF<<meight);
  int xwhole = mhole&(x&nhole);
  int nthb = (((x>>neight)&0xFF)<<meight);
  int mthb = (((x>>meight)&0xFF)<<neight);

  return ((xwhole|nthb)|mthb);

}

/************************************************ 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
	int a = !!x;
	int b = ~(a)+1;
	int c = y&b;
	int d = z&(~b);
	return c|d;
}

/************************************************
 * ezThreeFourths - multiplies by 3/4 rounding toward 0,
 *   Should exactly duplicate effect of C expression (x*3/4),
 *   including overflow behavior.
 *   Examples: ezThreeFourths(11) = 8
 *             ezThreeFourths(-9) = -6
 *             ezThreeFourths(1073741824) = -268435456 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int ezThreeFourths(int x) {
  int mult = ((x<<1)+x);
  int m = (mult>>31)&3;
  return (mult+m)>>2;
}

/************************************************ 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
	int a = (32+((~n)+1));
  return !(((x<<a)>>a)^x);
}

/************************************************
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  return (x>>((0xF^(3&(~n)))<<3))&0xFF;
}

/************************************************ 
 * greatestBitPos - return a mask that marks the position of the
 *               most significant 1 bit. If x == 0, return 0
 *   Example: greatestBitPos(96) = 0x40
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Rating: 4 
 */
int greatestBitPos(int x) {
	int a = x;
	int a1 = a>>1|a;
	int b = a1>>2|a1;
	int c = b>>4|b;
	int d = c>>8|c;
	int e = d>>16|d;
	
	int f = x&e;
	int g = (f>>31);
	int h = 0x1<<31;
	int i = h&g;
	int result = (~e>>1)&e;
	int j = ~g&result;
	
	return j|i;
}

/************************************************
 * implication - return x -> y in propositional logic - 0 for false, 1
 * for true
 *   Example: implication(1,1) = 1
 *            implication(1,0) = 0
 *   Legal ops: ! ~ ^ |
 *   Max ops: 5
 *   Rating: 2
 */
int implication(int x, int y) {
  return ((!x)|(!!y));
}

/************************************************ 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int a = x+(~0x30+1);
  int xless = !(a>>31);
  int b = 0x39+(~x+1);
  int xgreater = !(b>>31);
  return xless & xgreater;
}

/************************************************ 
 * isEqual - return 1 if x == y, and 0 otherwise 
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {
  return !(x^y);
}

/************************************************
 * isLess - if x < y  then return 1, else return 0 
 *   Example: isLess(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLess(int x, int y) {
	// 0 < y-x, meaning y-x must be positive
	int a = (y+(~x+1));
	int b = (x>>31)&0x1;
    int c = (y>>31)&0x1;
    int d = (a >> 31)&1;
    int equals = !(x^y);
    int negXposY = ((b^0)&(c^1));
    int posXnegY = ((b^1)&(c^0));

    return (!equals & !d & !posXnegY) | negXposY;
}

/************************************************
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
  return !(x>>31);
}

/************************************************
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x) {
	 int a = x&(x+~0);
	 int b = !a;
	 int pos = !(x>>31);
	 int zero = !!(x^0);
	 return b & pos & zero; 
}

/************************************************
 * isTmin - returns 1 if x is the minimum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmin(int x) {
  int a = x+x;
  int b = !a;
  int c = !!x;
  return b&c;
}

/************************************************
 * minusOne - return a value of -1 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void) {
  return ~0;
}

/************************************************
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateLeft(int x, int n) {
  int a = (x>>(32+(~n+1)));
  int FF = ~0x0;
  int c = a&(~(FF<<n));
  int d = (x<<n)|c;
  return d;
}

/************************************************
 * satMul2 - multiplies by 2, saturating to Tmin or Tmax if overflow
 *   Examples: satMul2(0x30000000) = 0x60000000
 *             satMul2(0x40000000) = 0x7FFFFFFF (saturate to TMax)
 *             satMul2(0x60000000) = 0x80000000 (saturate to TMin)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int satMul2(int x) {
	int tmin = (0x1)<<31;
	int tmax = ~tmin;	

	int a = x<<1;
	int b = (x^a)>>31;
	return ((tmax +(1&(x>>31)))&b) | (a&~b);

}

