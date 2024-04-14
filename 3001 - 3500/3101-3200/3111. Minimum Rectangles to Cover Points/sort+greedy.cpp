int minRectanglesToCoverPoints(vector<vector<int>>& A, int w) {
    sort(A.begin(), A.end());
    int res = 0, last = -1;
    for (auto& a: A)
        if (a[0] > last)
            res++, last = a[0] + w;
    return res;
}