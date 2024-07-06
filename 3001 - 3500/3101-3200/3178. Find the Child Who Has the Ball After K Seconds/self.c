int numberOfChild(int n, int k) {
    int side = k/(n-1); // represents how much times the ball is passed from start to end in any direction
    int rem = k - side*(n-1); //  how many steps are remaining from any one end point
    // check if the remaining steps are to be covered from 1st point or nth point.
    // if side is even, you need to cover rem steps from the 1st pos
    if(side%2 == 0) return rem; 
    // else cover rem steps from the nth pos
    return n-rem-1;
}