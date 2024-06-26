RABIN CARP - 
Concept ->

Text string - ccaxyzabcd

Pattern to search in text - abc

If we assign a digit to each letter - lets keep it simple and a=1, b=2 etc..

Then the rabin carp method says

For every pattern - (in our case - 3 letter pattern) - use a hash function to find its value

Lets Take a simple hash function - basic addition

Then abc would be 1 + 2 + 3

Now in the full string text - in every window of size 3 - calculate that window ka hash - called ROLLING HASH checking

Also - when moving from window 1 to window 2 - jsut subtract char 1 value of window 1 and add char 3 value of window 3 - 
this way it is an O(1) operation when moving windows and calculating the new hash value

If the hash is same - (addition of digits) - then it COULD be a potential match

Manually confirm it by comparing each letter.


------------------------------------------------------------------------------------------------------------

SPURIOUS HITS ->

There might not be a match as well

For eg - cca and dba - both strings ka hash value is same - because  3 + 3 + 1 === 4 + 2 + 1

We will know only in manual character checking - that they are unequal strings

But this is bad - 

------------------------------------------------------------------------------------------------------------

COMPLEXITY ->
TEXT of - size N
Pattern to find in text - Size M

If no spurious hits -  O(N-M+1)

WORST CASE - If all suprious hits - O(MN)

------------------------------------------------------------------------------------------------------------

BETTER HASH FUNC - suggested by Rabin - 

kind of like doing decimal number system value

a b c

If base = 10
1*10^2 + 2*10^1 + 3*10^0

Rabin suggests to keep the base as the number of characters expected in the system

Eg - If only  small alphabets are expected - total 26 - keep 26 base

abc 
1*26^2 + 2*26^1 + 3*26^0

In ASCII - total 127 characters are there

------------------------------------------------------------------------------------------------------------

ROLLING HASH -

To optimise on the changing hash value and its re calculation everytime

We do this - 

if text is
ccacca

window 1 - cca
window 2 - cac

When moving from window 1 to 2 - we have to subtract the value given by first c in 1. and then add the value given by third c in 2.

From complete hash value of CCA - subtract 3*26^2

Then multiply this value by base i.e multiple by 26

Then add value of third c in window 2 (base 26 power 0)

This way - this is a quick operation


------------------------------------------------------------------------------------------------------------

Remember how to handle overflow

we can get very large values

So do a mod

If it is a 32 bit data type (int) - then mod by 2^31 - because 1 bit is sign bit

Depends totally on the language and the data type we select


