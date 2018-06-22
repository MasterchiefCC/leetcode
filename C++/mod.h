#ifndef MOD_H
#define MOD_H
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
#include <limits.h>
#include <cmath> 
#include <list> 
#include <bitset> 
#include <iomanip> 
#include <numeric> 
#include <functional> 
#include <sstream>
#include <unordered_set>
#include <unordered_map>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
	int val;
	ListNode*next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
#endif //MOD_H