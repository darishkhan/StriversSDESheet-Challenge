string reverseString(string &str){
	// Write your code here.
	vector<string> v;
	string s;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]==' ')
		{
			if(s.size()>0) v.push_back(s);
			s="";
			continue;
		}
		s+=str[i];
	}	
	if(s.size()>0) v.push_back(s);
	reverse(v.begin(), v.end());
	s="";
	for(i:v)
	{
		s+=i;
		s+=' ';
	}
	s.pop_back();
	return s;

}
