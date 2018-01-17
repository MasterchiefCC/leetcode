class Solution(object):
    def calPoints(self, ops):
        """
        :type ops: List[str]
        :rtype: int
        """
        ret=[];
        for i in range(len(ops)):
            if ops[i]=='+':
                ret.append(sum(ret[-2:]));
            elif ops[i]=='C':
                del ret[-1];
            elif ops[i]=='D':
                if ret:
                    ret.append(ret[-1]*2);
            else:
                ret.append(int(ops[i]));
        return sum(ret);
            
                
