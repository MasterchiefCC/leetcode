#include "mod.h"
class MyCalendarThree {
    map<int,int>buffer;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        buffer[start]++;
        buffer[end]--;
        int cnt=0;
        int ret=0;
        for(map<int, int>::iterator mit=buffer.begin(); mit!=buffer.end(); mit++)
            ret=max((cnt+=mit->second, cnt), ret);
        return ret;
    }
};