class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // Sort the folder paths
        sort(folder.begin(), folder.end());
        vector<string> result;
        // Keep track of the last added folder
        string lastAdded;
        for (string& path : folder) {
            // If the last added folder is empty or the current path does not start with the last added path
            // and is not a direct subfolder of it
            if (lastAdded.empty() || path.find(lastAdded + "/") != 0) {
                result.push_back(path);
                lastAdded = path; // Update the last added folder
            }
        }
        return result;
    }
};