bool isRectangleOverlap(int* r1, int r1Size, int* r2, int r2Size) {
    return (r1[0]<r2[2] && r2[0]<r1[2]) && (r1[1]<r2[3] && r2[1]<r1[3]);
}