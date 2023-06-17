int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here
	int n = arr.size();
	int l=0, r=n-1, mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if(mid%2==0 and mid<n-1 and arr[mid]==arr[mid+1]) l=mid+2;
		else if(mid%2==0 and mid>0 and arr[mid]==arr[mid-1]) r=mid-2;
		else if(mid%2==0) break;
		else if(mid%2 and mid>0 and arr[mid]==arr[mid-1]) l=mid+1;
		else if(mid%2 and mid<n-1 and arr[mid]==arr[mid+1]) r=mid-1;
		else break;
	}
	mid=(l+r)/2;
	return arr[mid];

}
