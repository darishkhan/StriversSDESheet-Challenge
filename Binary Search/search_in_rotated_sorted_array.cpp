int gl=-1;
int search(int* arr, int n, int key) {
    // Write your code here.
    if(gl==-1)
    {
        int l=0, r=n-1, mid;
        while(l<r)
        {
        mid=(l+r)/2;
        if(arr[mid]>arr[r]) l=mid+1;
        else r=mid;
        }
        gl=l;
    }
    // cout<<l<<" ";
    int l=gl, r=n-1, mid;
    if(l==0)
    {
        while(l<r)
        {
            mid=(l+r)/2;
            if(arr[mid]==key) return mid;
            else if(arr[mid]<key) l=mid+1;
            else r=mid-1;
        }
        if(arr[l]==key) return l;
        return -1;
    }
    if(key>arr[r])
    {
        r=l-1;
        l=0;
    }
    while(l<r)
    {
        mid=(l+r)/2;
        if(arr[mid]==key) return mid;
        else if(arr[mid]<key) l=mid+1;
        else r=mid-1;
    }
    if(arr[l]==key) return l;
    return -1;
}
