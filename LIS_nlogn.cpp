//Program to compute Longest Increasing Subsequence in nlogn time
#include<bits/stdc++.h>
using namespace std;
//CeilSearch return the index of next greater element than ele
int ceilSearch(vector<int> arr,vector<int> aux,int n,int first,int last,int ele){

    int left = first;   //Left index I
    int right = last;   //Right index
    //cout<<first<<" "<<last<<" "<<ele<<endl;
    //If ele is less than the leftmost element than next greater element is the arr[left]
    if(ele < arr[aux[left]]){
        //cout<<ele<<" is less than "<<arr[aux[left]]<<endl;
        return left;
    }

    //If ele is greater than the rightmost element than there is no next greater element
    if(ele>arr[aux[right]])
        return -1;

    //Check for next greater element in the array
    while(left<right){

        //Mid of the array
        int mid = left+(right-left)/2;

        //if arr[mid] is greater than ele than next greater element is either arr[mid]
        //or present in the left subarray
        if(ele < arr[aux[mid]]){
            if(mid-1>=left && arr[aux[mid-1]]<ele){
                //cout<<ele<<" is less than "<<arr[aux[mid]]<<endl;
                return mid;
            }
            else
                right = mid-1;
        }
        //if arr[mid] is less than ele than next greater element is either arr[mid]
        //or present in the right subarray
        else{
            if(mid+1<=right && arr[aux[mid+1]]>ele){
                //cout<<ele<<" is less than "<<arr[aux[mid+1]]<<endl;
                return mid+1;
            }
            else
                left = mid+1;
        }
    }
}

int computeLIS(vector<int> arr,int n){
    int lisLen = 1;
    vector<int> res(n,-1);
    vector<int> aux;

    aux.push_back(0);

    for(int i=1;i<n;i++){
        int ind = ceilSearch(arr,aux,aux.size(),0,aux.size()-1,arr[i]);
        //cout<<ind<<endl;
        if(ind == -1){
            res[i] = aux[aux.size()-1];
            //cout<<ind<<" no  "<<res[i]<<endl;
            aux.push_back(i);
            lisLen++;
        }
        else{
            aux[ind] = i;
            //cout<<ind<<" "<<aux[ind]<<" yes "<<aux[ind-1]<<endl;
            if(ind!=0)
            res[i] = aux[ind-1];
        }
    }
    int x = n-1;
    while(x!=-1){
        cout<<arr[x]<<" ";
        x = res[x];
    }
    cout<<endl;
    return lisLen;
}
using namespace std;
int main(){
    //n is the size of the input array
    int n;
    cin>>n;
    //arr in the input array
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];

    //computeLIS calculate LIS in the given array
    cout<<computeLIS(arr,n);
}
