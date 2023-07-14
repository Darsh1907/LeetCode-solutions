int maxArea(int* height, int heightSize){
    int i = 0;
    int j = heightSize-1;
    
    int curr = 0;
    int result = 0;
    
    while(i<j){
        curr=(j-i)*fmin(height[i], height[j]);
        result = fmax(result, curr);
        if(height[i]<=height[j]) i++;
        else j--;
    }

    return result;
}