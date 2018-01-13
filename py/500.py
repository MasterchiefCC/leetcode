class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        keyboard=["qwertyuiop","asdfghjkl", "zxcvbnm" ];
        ret=[];
        for i in words:
            for line in keyboard:
                lower=i.lower();
                if set(lower).issubset(set(line)):
                    ret.append(i);
        return ret;


        