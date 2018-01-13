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
typedef long long ll;
typedef pair <int, int> ii;
typedef vector <ll> vi;
typedef long double ld;
typedef set <int> ::iterator sit;
typedef map <int, int> ::iterator mit;
typedef vector <int> ::iterator vit;
#define fi first
#define se second
#define pb push_back
#define forn(i, n)for ( int i = 1; i <= n; i++ )
#define fore(i, n )for ( int i = 0; i <n; i++ )

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ret;
        int cnt=0;
        int len=nums.size();
        int start=0, end=len-1;
        while(start<end&&cnt<3){
            cnt=nums[start]!=nums[start+1]?(ret.push_back(nums[start]),--start, cnt+1):cnt;
            cnt=nums[end]!=nums[end-1]?(ret.push_back(nums[end]), ++end, cnt+1):cnt;
            start+=2;
            end-=2;
        }
        if(start==end)ret.push_back(nums[start]);
        return ret;
    }
};