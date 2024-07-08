

The editorial for this question on Leetcode is too detailed 
Go ahead and read it

This answer also gives some solutions
https://stackoverflow.com/questions/1309263/rolling-median-algorithm-in-c/11228573#11228573

We can use segment trees - pain to implement but good

Then there's order statistic trees = which are available in C++ - these are tailor made for this problem kinda

What are they? do we need to know for interviews? likely not.

But do read up what segment trees are.

SEGMENT ->
The second idea uses a segment tree which is O(ln N) for insert/deletions/queries but is more 
flexible. Best of all the "N" is the size of your data range. So if your rolling median has a window of a 
million items, but your data varies from 1..65536, then only 16 operations are required per movement of the rolling
window of 1 million!!

AVL Trees->

Self-balancing Binary Search Trees (like an AVL Tree) have some very interesting properties. 
They maintain the tree's height to a logarithmic bound. Thus inserting a new element has reasonably good time 
performance. The median always winds up in the root of the tree and/or one of its children. Solving this problem 
using the same approach as Approach 3 but using a Self-balancing BST seems like a good choice. 
Except the fact that implementing such a tree is not trivial and prone to errors.

Why reinvent the wheel? Most languages implement a multiset class which emulates such behavior. 
The only problem remains keeping track of the median elements. That is easily solved with pointers! 2

We maintain two pointers: one for the lower median element and the other for the higher median element. 
When the total number of elements is odd, both the pointers point to the same median element 
(since there is only one median in this case). When the number of elements is even, the pointers point to 
two consecutive elements, whose mean is the representative median of the input.

AVL Tutorial -> https://www.youtube.com/watch?v=jDM6_TnYIqE&ab_channel=AbdulBari

We can use multisets to solve the problem because they emulate AVLs. Why?

Because - in a multiset -
Insertion of Elements- O(log N)
Accessing Elements – O(log N)
Deleting Elements- O(log N)

MUTLISET -> https://www.geeksforgeeks.org/multiset-in-cpp-stl/

CODE ->

Approach ->

We maintain two pointers: one for the lower median element and the other for the higher median element. 
When the total number of elements is odd, both the pointers point to the same median element (since there is 
only one median in this case). When the number of elements is even, the pointers point to two consecutive 
elements, whose mean is the representative median of the input.

Algorithm

Two iterators/pointers lo_median and hi_median, which iterate over the data multiset.

While adding a number num, three cases arise:

The container is currently empty. Hence we simply insert num and set both pointers to point to this element.

The container currently holds an odd number of elements. This means that both the pointers currently point to the
 same element.

If num is not equal to the current median element, then num goes on either side of it. Whichever side it goes, the
 size of that part increases and hence the corresponding pointer is updated. For example, if num is less than the 
 median element, the size of the lesser half of input increases by 1 on inserting num. Thus it makes sense to 
 decrement lo_median.
If num is equal to the current median element, then the action taken is dependent on how num is inserted into 
data. NOTE: In our given C++ code example, std::multiset::insert inserts an element after all elements of equal 
value. Hence we increment hi_median.
The container currently holds an even number of elements. This means that the pointers currently point to 
consecutive elements.

If num is a number between both median elements, then num becomes the new median. Both pointers must point to it.
Otherwise, num increases the size of either the lesser or higher half of the input. We update the pointers accordingly.
 It is important to remember that both the pointers must point to the same element now.
Finding the median is easy! It is simply the mean of the elements pointed to by the two pointers lo_median and hi_median.

Few more details about multiset - 
https://stackoverflow.com/questions/46555103/what-is-the-difference-between-multisetint-greaterint-ms1-and-multiset

class MedianFinder {
    multiset<int> data;
    multiset<int>::iterator lo_median, hi_median;

public:
    MedianFinder() {
    }

    void addNum(int num)
    {
        const size_t n = data.size();   // store previous size

        data.insert(num);               // insert into multiset

        if (!n) {
            // no elements before, one element now
            lo_median = hi_median = data.begin();
        }
        else if (n & 1) {
            // odd size before (i.e. lo == hi), even size now (i.e. hi = lo + 1)

            if (num < *lo_median)       // num < lo
                lo_median--;
            else                        // num >= hi
                hi_median++;            // insertion at end of equal range
        }
        else {
            // even size before (i.e. hi = lo + 1), odd size now (i.e. lo == hi)

            if (num > *lo_median && num < *hi_median) {
                lo_median++;                    // num in between lo and hi
                hi_median--;
            }
            else if (num >= *hi_median)         // num inserted after hi
                lo_median++;
            else                                // num <= lo < hi
                lo_median = --hi_median;        // insertion at end of equal range spoils lo
        }
    }

    double findMedian()
    {
        return ((double) *lo_median + *hi_median) * 0.5;
    }
};