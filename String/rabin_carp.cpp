vector<int> stringMatch(string &str, string &pat) {
    // Write your code here
    int k = pat.size();
    vector<int> ans;
    for(int i=0;i<str.size();i++)
    {
        if(str.substr(i, k)==pat) ans.push_back(i);
    }
    return ans;
}
