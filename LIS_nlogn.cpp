//Program to compute Longest Increasing Subsequence in nlogn time
#include<bits/stdc++.h>
using namespace std;
//CeilSearch return the index of next greater element than ele
int ceilSearch(vector<int> arr,vector<int> aux,int n,int first,int last,int ele){

    int left = first;   //Left index I
    int right = last;   //Right index
   
    //If ele is less than the leftmost element than next greater element is the arr[left]
    if(ele < arr[aux[left]]){
        return left;
    }

    //If ele is greater than the rightmost element than there is no next greater element
    if(ele>arr[aux[right]])
        return -1;

    //Check for next greater element in the array
    while(left<right){

        //Mid of the array
        int mid = left+(right-left)/2;

        //if arr[aux[mid]] is greater than ele than next greater element is either arr[mid]
        //or present in the left subarray
        if(ele < arr[aux[mid]]){
            if(mid-1>=left && arr[aux[mid-1]]<ele){
                return mid;
            }
            else
                right = mid-1;
        }
        //if arr[aux[mid]] is less than ele than next greater element is either arr[mid]
        //or present in the right subarray
        else{
            if(mid+1<=right && arr[aux[mid+1]]>ele){
                return mid+1;
            }
            else
                left = mid+1;
        }
    }
}

int computeLIS(vector<int> arr,int n){
    int lisLen = 1;
    vector<int> res(n,-1); //Res stores the indexes of the resultant LIS
    vector<int> aux;    //Aux stores the last index for the Subsequence of length i

    aux.push_back(0);   //Push the first element

    for(int i=1;i<n;i++){
        //get the upper bound for element arr[i] from aux array
        int ind = ceilSearch(arr,aux,aux.size(),0,aux.size()-1,arr[i]); 
        
        //if no upper bound found
        if(ind == -1){
            //Update the res array 
            res[i] = aux[aux.size()-1];
            //insert new index and increase the length
            aux.push_back(i);
            lisLen++;
        }
        else{
            //Update the aux array as new element is found for same index in aux array
            aux[ind] = i;
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
