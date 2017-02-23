class Solution {
public:
    int findComplement(int num) {
        int numberForClearLeadZero = ~0; //用来消除前导0
        while(num & numberForClearLeadZero)
            numberForClearLeadZero <<= 1;
        return ~numberForClearLeadZero & ~num;         
    }
    //5是101，取反变成11111111010
    //利用numberForClearLeadZero消去前导的这些111就是问题的关键
};