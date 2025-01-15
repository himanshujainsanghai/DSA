class Solution {
public:
    int minimizeXor(int num1, int num2) {
        // Find the number of set bits in num2
        int setBits = __builtin_popcount(num2); // Built-in function to count set bits
        int bit = 31; // Start from the most significant bit
        int res = 0;

        // Set bits in `res` where `num1` has set bits, if possible
        while (bit >= 0 && setBits > 0) {
            if ((num1 & (1 << bit)) != 0) { // Check if bit is set in `num1`
                res |= (1 << bit); // Set the same bit in `res`
                setBits--;
            }
            bit--;
        }

        // If there are still bits to set, set them from the least significant bit
        bit = 0;
        while (setBits > 0 && bit < 32) {
            if ((num1 & (1 << bit)) == 0) { // Check if bit is not set in `num1`
                res |= (1 << bit); // Set this bit in `res`
                setBits--;
            }
            bit++;
        }

        return res;
    }
};
