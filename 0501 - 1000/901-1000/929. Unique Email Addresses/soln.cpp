#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int k=0;
        int flag=0;
        for(int i=0;i<emails.size();i++){
            flag=0;
            for(int j=0;j<emails[i].size();j++){
                if(emails[i][j]=='@') break;
                if(emails[i][j]=='.') emails[i].erase(j,1);
                else if(emails[i][j]=='+'){
                    flag=1;
                    k=j+1;
                    while(emails[i][k]!='@'){
                        k++;
                    }
                    emails[i].erase(j,(k-j));
                }
                if(flag==1) break;
            }
        }
        set <string> str(emails.begin(),emails.end());
        emails.clear();
        emails.assign(str.begin(),str.end());
        return emails.size();
    }
};

int main() {
    // Example usage
    Solution solution;
    vector<string> emails = {
        "test.email+alex@leetcode.com",
        "test.e.mail+bob.cathy@leetcode.com",
        "testemail+david@lee.tcode.com"
    };
    int uniqueEmails = solution.numUniqueEmails(emails);
    cout << "Number of unique emails: " << uniqueEmails << endl;
    
    return 0;
}