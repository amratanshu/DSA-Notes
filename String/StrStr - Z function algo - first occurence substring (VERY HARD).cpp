This solution is O(m*n)

This can be done in way better methods - of O(N) as well - using z function or KMP

Will read about them later.

Naive approach - 
class Solution {
public:
    int strStr(string haystack, string needle) {
        //keep checking window by window

        if (haystack.length() < needle.length())
            return -1;

        int n = needle.length();

        //got to move by windows of size n

        for (int i=0;i<=haystack.length() - n;i++) {
            if (haystack.substr(i, n) == needle)
                return i;
        }

        return -1;

    }
};


Better approach for this problem ->

Z FUNCTION - happens in Linear time

Z function calculates the Z Array in Linear time

What is Z Array ->

For a string

a a b x c a a b x c a a b x a a b x

Z[i] = is the max number of elements starting with i and going to the right of the string - which is the prefix 
of the complete string as well

Z[0] = 0 by default - it has no meaning kinda

So - 
 a a b x a a b x c a a b x a a b x
[0 1 0 0 4 1 0 0 0 8 ... etc]

4 wala element se starting string - is a a b c
prefix is also a a b c

Watch video to understand more - https://www.youtube.com/watch?v=CpZh4eF8QBw&t=803s&ab_channel=TusharRoy-CodingMadeSimple

How to calculate this Z array in linear time?

When we are at z = 4 wala index and moving ahead - we know that - a a b x -- is x tak ek window hai 
jo prefix me bhi tha same to same

Toh - z = 4 hai - islie next 4 elements same hi honge

Hence - we can just copy the z value from prefix..


CAVEAT - can we always copy? NO

If some z value in the z box/z window is so much that it touches the end of the window 

Then that means - is se bhi zyada elements ho sakte hain - z window ke baad - which are equal

So we have to go ahead and check the fresh new elements as well - which are just after this window

See examples to see how this is working


------------------------------------------------------------------------------------------------------------

But what now?

How to solve the problem we have ??

Pattern - abc
text - pasfabcpqr

Concatenate pattern + text using a special symbol

abc$pasfabcpqr

Now calculate the z array of this 

pattern length = 3

Whereever u find z[i] = 3 - that index is our answer - because us index ke 3 characters aagey tak prefix available hai

and prefix to pattern hi hai !!

So - z array calculation will take O(len of big concatenated string) = O(M+N)

Space - O(M+N) - just storing the Z function

------------------------------------------------------------------------------------------------------------

Code samajh nahi aya -
https://www.youtube.com/watch?v=CpZh4eF8QBw&t=803s&ab_channel=TusharRoy-CodingMadeSimple

Better code -> https://www.youtube.com/watch?v=pcL05iQHRsk&ab_channel=BharatKhanna


class Solution {
public:
    vector<int> calculateZFunction(string s) {
        vector<int> z (s.length(), 0);
        int n = s.length();
        int left = 0; //pointer for left window
        int right = 0; //pointer for right window

        
        for (int i=1;i<n;i++) {
            if (i < right) { 
                z[i] = z[i-left]; //simply copy
                
                //if i is in the range of some previous z window
                //handle case of z[i] reaching for characters beyond the right of the z window
                if (i + z[i] > right) {
                    z[i] = right - i; //restrict this value for now - we wil match extra chars and increment it baad m
                }
            } 

            //matching characters beyond the z window i.e s[i + z[i]] index wale (matching with the prefix i.e s[z[i]] index wale)
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i] ++;
            }

            //update lef and right - if they hae gone beyond - means we have to update the new window
            if (i + z[i] > right) {
                left = i;
                right = i + z[i];
            }
        }

        return z;
       
    }


    int strStr(string haystack, string needle) {
        //chalo z function use kar lete hain (O(M+N)) time calculation

        string big;

        for (char c: needle) {
            big += c;
        }

        big += '$';

        for (char c: haystack) {
            big += c;
        }

        //big is our format now - abc$xyabcazxc
        vector<int> z = calculateZFunction(big);
        for(int i = needle.length()+ 1; i<big.length(); i++) {
            if (z[i] == needle.length())
                return i - needle.length() - 1;
        }
        return -1;

    }
};
