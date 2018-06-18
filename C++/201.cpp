#include "mod.h"
class Solution {
 public:
  int rangeBitwiseAnd(int m, int n) {
    int mask = INT_MAX; 
    while ( (m & mask ) != (n & mask ) ) {
      mask <<= 1; 
    }
    return m & mask; 
  }
}; 