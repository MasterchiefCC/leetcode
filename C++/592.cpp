class Solution {
    void red(pair<int, int>&tempT){
        if(tempT.first==0){
            tempT.second=1;
            return;
        }
        int gcd=1;
        pair<int, int>temp=tempT;
        if(temp.first<0)temp.first=-temp.first;
        if(temp.second<0)temp.second=-second.second;
        for(int i=temp.first<=temp.second?temp.first:temp.second; i>=1; --i){
            if(temp.first%i==0&&temp.second%i==0){
                gcd=i;
                break;
            }
        }
        if(gcd==1)return;
        tempT.first/=gcd;
        tempT.second/=gcd;
    }
public:
    string fractionAddition(string expression) {
        vector<pair<int, int>>buffer;
        size_t pos=expression.find_first_of("/");
        int start=0;
        while(pos!=std::string::npos){
            int numer=stoi(expression.substr(start, pos-start));
            start=expression.find_first_of("+-", pos);
            int denom=start!=std::string::npos?stoi(expression.substr(pos+1, start-pos+1)):stoi(expression.substr(pos+1, expression.size()-pos));
            buffer.push_back(make_pair(numer, denom));
            pos=expression.find_first_of("/", pos+1);
        }

        stack<pair<int, int>>tempS;
        for(int i=buffer.size()-1; i>=0; --i)tempS.push(buffer[i]);
        while(tempS.size()!=1){
            pair<int, int>p1=tempS.top();
            tempS.pop();
            pair<int, int>p2=tempS.top();
            tempS.pop();
            if(p1.second!=p2.second){
                p1.first*=p2.second;
                p2.first*=p1.second;
                p1.second*=p2.second;
                p2.second=p1.second;
            }
            p1.first+=p2.first;
            red(p1);
            tempS.push(p1);
        }
        pair<int, int>temp=tempS.top();
        red(temp);
        string ret=to_string(tempS.top().first);
        ret+="/";
        ret+=to_string(tempS.top().second);
        return ret;
    }
};