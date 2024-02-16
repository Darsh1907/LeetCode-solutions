/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
*/

int peakElement(MountainArray& mountainArr, int s, int e) {
    int mid;
    while (e > s) {
        mid = s+(e-s)/2;
        if(mountainArr.get(mid + 1) > mountainArr.get(mid)) s = mid + 1;
        else e = mid;
    }
    return e;
}

int BS_for_left(int target, MountainArray& mountainArr, int s, int e) {
    int ele = -1;
    int mid;
    int mountainArr_mid;
    while (e >= s){
        mid = s + (e-s)/2;
        mountainArr_mid = mountainArr.get(mid);
        if(mountainArr_mid == target){
            ele = mid;
            e = mid-1;
        }
        else if (mountainArr_mid > target) e = mid -1;
        else s = mid + 1;
    }
    return ele;
}

int BS_for_right(int target, MountainArray& mountainArr, int s, int e) {
    int ele = -1;
    int mid;
    int mountainArr_mid;
    while (e >= s){
        mid = s + (e-s)/2;
        mountainArr_mid = mountainArr.get(mid);
        if(mountainArr_mid == target){
            ele = mid;
            s = mid+1;
        }
        else if (mountainArr_mid > target) s = mid + 1;
        else e = mid -1;
    }
    return ele;
}

class Solution {
public:
    int findInMountainArray(int target, MountainArray& mountainArr) {
        int size = mountainArr.length();
        int peak = peakElement(mountainArr, 0, size-1);
        int firstLine = BS_for_left(target, mountainArr, 0, peak);
        if(firstLine != -1) return firstLine;
        return BS_for_right(target, mountainArr, peak+1, size-1);
    }
};