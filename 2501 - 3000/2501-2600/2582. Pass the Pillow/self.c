int passThePillow(int n, int time) {
    int side = time/(n-1); // represents how much times the pillow is passed from start to end in any direction
    int rem = time - side*(n-1); //  how many steps are remaining from any one end point
    // check if the remaining steps are to be covered from 1st point or nth point.
    // if ur side is even, you need to cover rem steps from 1st pos
    if(side%2 == 0) return rem+1; 
    // else cover rem steps from nth pos
    return n-rem;
}