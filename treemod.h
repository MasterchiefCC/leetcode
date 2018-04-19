#include <iostream> 
#include <stdio.h> 
#include <algorithm> 
#include <vector> 
#include <deque> 
#include <cassert> 
#include <queue> 
#include <stack> 
#include <set> 
#include <map> 
#include <cstdio> 
#include <string> 
#include <utility> 
#include <cmath> 
#include <list> 
#include <bitset> 
#include <iomanip> 
#include <functional> 
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };