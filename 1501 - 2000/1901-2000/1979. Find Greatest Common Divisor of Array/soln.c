// Recursive function to return gcd of a and b 
int gcd(int a, int b) { 
    // Everything divides 0 
    if (a == 0) return b; 
    if (b == 0) return a;
    // base case 
    if (a == b) return a;  
    // a is greater 
    if (a > b) return gcd(a - b, b); 
    return gcd(a, b - a); 
} 

int findGCD(int* nums, int numsSize) {
    int max = 0;
    int min = 1001;
    for(int i=0; i<numsSize; i++){
        if(nums[i]>max) max=nums[i];
        if(nums[i]<min) min=nums[i];
    }
    return gcd(max, min);
}