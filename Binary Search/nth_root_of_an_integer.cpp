int NthRoot(int n, int m) {
  // Write your code here.
  if(m==1) return 1;
  int l = 2, r=m, mid;
  while(l<r)
  {
    mid=(l+r)/2;
    if(pow(mid, n)==m) return mid;
    else if(pow(mid, n)<m) l=mid+1;
    else r=mid-1;
  }
  if(l==r)
  {
    if(pow(l,n)==m) return l;
  }
  return -1;

}
