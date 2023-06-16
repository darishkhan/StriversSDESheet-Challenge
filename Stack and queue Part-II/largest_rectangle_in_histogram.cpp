 #include<bits/stdc++.h>
 int largestRectangle(vector < int > & heights) {
   // Write your code here.
   int n =heights.size();
   vector<int> left(n, -1);
   vector<int> right(n, n);
   stack<int> s;
   s.push(0);
   for(int i=1;i<n;i++)
   {
     if(s.empty()) 
     {
       s.push(i);continue;
     }
    if(heights[s.top()]>=heights[i])
    {
      while((heights[s.top()]>=heights[i]))
      {
        s.pop();
        if(s.empty()) break;
      }
      if(!s.empty()) left[i]=s.top();
    }
    else left[i]=s.top();
    s.push(i);
   }
   while(!s.empty()) s.pop();
   s.push(n-1);
   for(int i=n-2;i>=0;i--)
   {
     if(s.empty()) 
     {
       s.push(i);continue;
     }
    if(heights[s.top()]>=heights[i])
    {
      while((heights[s.top()]>=heights[i]))
      {
        s.pop();
        if(s.empty()) break;
      }
      if(!s.empty()) right[i]=s.top();
    }
    else right[i]=s.top();
    s.push(i);
   }
  //  for(int i=0;i<n;i++) cout<<left[i]<<" ";
  //  cout<<"\n";
  //  for(int i=0;i<n;i++) cout<<right[i]<<" ";
  //  cout<<"\n";
  int mx=-1;
  for(int i=0;i<n;i++)
  {
    mx=max(mx, heights[i]*(right[i]-left[i]-1));
    // cout<<heights[i]*(right[i]-left[i]-1)<<' ';
  }
   return mx;

 }
