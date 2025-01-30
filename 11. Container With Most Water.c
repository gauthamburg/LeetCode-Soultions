int maxArea(int* height, int heightSize) 
{
    int left = 0;
    int right = heightSize - 1;
    int max_area = 0;
    
    while (left < right) {
        int current_height = (height[left] < height[right]) ? height[left] : height[right];
        int width = right - left;
        int area = current_height * width;
        
        if (area > max_area) {
            max_area = area;
        }
        
        // Move the pointer with the smaller height
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    return max_area;
}