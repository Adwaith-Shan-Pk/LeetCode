// Last updated: 4/22/2026, 12:22:58 AM
int missingNumber(int* nums, int numsSize) {
    int xor = numsSize;  // include n

    for (int i = 0; i < numsSize; i++) {
        xor ^= i ^ nums[i];
    }

    return xor;
}