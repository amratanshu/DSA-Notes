#include<math.h>
int NthRoot(int n, int m) {
  // Write your code here.
  if (m == 1)
    return 1;

  int low = 1;
  int high = m;

  while (low <= high) {
    int mid = low + (high - low)/2;
    double result = pow(mid, n);

    if (result == (double)m)
      return mid;
    
    if (result < (double) m) {
      low = mid + 1;
    }

    if (result > (double) m)
      high = mid - 1;

  }
  return -1;
}


