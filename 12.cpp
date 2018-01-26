class Solution {
public:
    string intToRoman(int num) {
        string ret;

        int temp=num/1000;
        for(int i=0; i<temp; ++i)ret+='M';
        num%=1000;
        if(num/900){
            ret+="CM";
            num-=900;
        }
        
        temp=num/500;
        for(int i=0; i<temp; ++i)ret+='D';
        num%=500;
        if(num/400){
            ret+="CD";
            num-=400;
        }
        
        temp=num/100;
        for(int i=0; i<temp; ++i)ret+='C';
        num%=100;
        if(num/90){
            ret+="XC";
            num-=90;
        }
        
        temp=num/50;
        for(int i=0; i<temp; ++i)ret+='L';
        num%=50;
        if(num/40){
            ret+="XL";
            num-=40;
        }
        
        temp=num/10;
        for(int i=0; i<temp; ++i)ret+='X';
        num%=10;
        if(num==9){
            ret+="IX";
            return ret;
        }
        
        temp=num/5;
        for(int i=0; i<temp; ++i)ret+='V';
        num%=5;
        if(num==4){
            ret+="IV";
            return ret;
        }
        
        for(int i=0; i<num; ++i)ret+='I';

        return ret;
    }
};