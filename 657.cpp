#include "mod.h"

class Solution {
public:
    bool judgeCircle(string moves) {
        int Y=0, X=0;
        for(int a=0; a<moves.size(); a++){
            switch(moves[a]){
                case 'R': X++; break;
                case 'L': X--; break;
                case 'U': Y--; break;
                case 'D':Y++; break;
                default: break;
            }
        }
        return !Y&!X;
    }
};