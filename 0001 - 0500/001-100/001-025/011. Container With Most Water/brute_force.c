// Brute Force approach. Not accepted by LeetCode

int maxArea(int* height, int heightSize){
    int result=0;
    int area=0;
    for(int i=0; i<heightSize; i++){
        for(int j=i+1; j<heightSize; j++){
            area = (j-i)*fmin(height[i], height[j]);
            if(area>result) result = area;
        }
    }
    return result;
}