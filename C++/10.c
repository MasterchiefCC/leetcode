int isMatch(char*s, char*p) {
	if (*s == 0&&*p==0)return 1;
	else if (*(p+1)== '*') {
		if(!isMatch(s, p+2)){
			if((*p==*s||*p=='.')&&*s!=0)return isMatch(++s,p);
		}
		else return 1;
	}
	else if ((*p==*s||*p=='.')&&*s!=0) {
		return isMatch(++s, ++p);
	}
	
	else if(*s!=*p&&*(p+1)=='*') return isMatch(s, p+2);
	return 0;
}