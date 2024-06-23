// Reference: NeetCode - https://www.youtube.com/watch?v=ZI2z5pq0TqA

int max(int a,int b) {if(a>=b) return a; return b;}

int trap(int* height, int heightSize) {
    int l = 0, r = heightSize-1;
    int leftMax = height[l], rightMax = height[r];
    int res = 0;
    while(l < r) {
        if(leftMax<=rightMax) {
            l++;
            leftMax = max(leftMax, height[l]);
            res += leftMax - height[l];
        }
        else {
            r--;
            rightMax = max(rightMax, height[r]);
            res += rightMax - height[r];
        }
    }
    return res;
}