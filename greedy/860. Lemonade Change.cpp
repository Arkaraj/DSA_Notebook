class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for(int b: bills) {
            if(b == 5) five++;
            else if(b == 10) ten++, five--;
            else {
                if(ten>0) ten--, five--; // -15
                else five-=3;
            }
            // five can be -ve then its false
            if(five<0) return false; 
        }
        return true;
    }
};