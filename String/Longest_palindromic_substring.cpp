string longestPalinSubstring(string str)
{
    // Write your code here.
    int n = str.size(), maxl=0, start=-1;
    for(int k=0;k<n;k++)
    {
        int i=k, j=k;
        while(i>=0 and j<n)
        {
            if(str[i]==str[j])
            {
                if(maxl<j-i+1)
                {
                    maxl=j-i+1;
                    start=i;
                }
                i--;j++;
            }
            else break;
        }

        i=k, j=k+1;
        while(i>=0 and j<n)
        {
            if(str[i]==str[j])
            {
                if(maxl<j-i+1)
                {
                    maxl=j-i+1;
                    start=i;
                }
                i--;j++;
            }
            else break;
        }
    }
    return str.substr(start, maxl); 
}
