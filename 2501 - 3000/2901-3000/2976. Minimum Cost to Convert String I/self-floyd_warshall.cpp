class Solution {
    void floyd_warshall(vector<vector<long long>>& matrix) {
		int n = 26;
		for(int k=0; k<n; k++) {
			for(int i=0; i<n; i++) {
				for (int j=0; j<n; j++) {
                    if(matrix[i][k]==LLONG_MAX || matrix[k][j]==LLONG_MAX);
					else matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
				}
			}
		}
	}
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> adj(26, vector<long long>(26, LLONG_MAX));
        for(int i=0; i<26; i++) adj[i][i]=0; // converting to the same character is set to 0.
        // modify adj based on the given costs
        for(int i=0; i<cost.size(); i++) {
            int ori = original[i] - 'a';
            int cha = changed[i] - 'a';
            if(adj[ori][cha] > cost[i]) adj[ori][cha] = cost[i];
        }
        // modify adj based on the Floyd Warshall algo
        floyd_warshall(adj);
        // Generate Result
        long long result = 0;
        for(int i=0; i<source.size(); i++) {
            int s = source[i] - 'a';
            int t = target[i] - 'a';
            if(adj[s][t] == LLONG_MAX) return -1;
            result += adj[s][t];
        }
        return result;
    }
};