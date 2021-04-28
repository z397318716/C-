#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        stack<int> st;
        int root = INT_MAX;
        for (int i = postorder.size() - 1; i >= 0; --i) {
            if (root < postorder[i])
                return false;
            while (!st.empty() && st.top() > root) {
                root = st.top();
                st.pop();
            }
            st.push(postorder[i]);
        }
        return true;
    }
};

int main() {


	return 0;
}