
bool isPal(string &s, int n)
{
	int i=0;
	while(i<n-i-1)
	{
		if(s[i]!=s[n-i-1]) return false;
		i++;
	}
	return true;
}
int minCharsforPalindrome(string str) {
	// Write your code here.
	int n=str.size();
	int i=n-1;
	for(i=n-1;i>=0;i--)
	{
		if(isPal(str, i+1)) break;
	}
	return n-i-1;
	
}
