class Solution(object):
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        ret=[];
        for i in range(n):
            temp=i+1;
            if temp%3==0 and temp%5==0:
                ret.append("FizzBuzz");
            elif temp%3==0:
                ret.append("Fizz");
            elif temp%5==0:
                ret.append("Buzz");
            else:
                ret.append(str(temp));
        return ret;