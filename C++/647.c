int  isPalindrome(char*s, int size){
    int half_size=size/2;
    for(int a=0; a<half_size; a++){
        if(s[a]!=s[size-1-a])return 0;
    }
    return 1;
}
int countSubstrings(char* s) {
    int len=1, cnt=0;
    while(1){
        char*begin=s;
        while(1){
            cnt=isPalindrome(begin, len)?cnt+1:cnt;
            if(*(begin+len)==0)break;
            else begin++;
        }
        if(*(s+len)==0)break;
        len++;
    }
    return cnt;
}