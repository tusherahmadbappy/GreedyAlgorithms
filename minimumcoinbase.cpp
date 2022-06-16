#include <iostream>
#include<vector>
using namespace std;

void findMin(int deno[],int value,int num)
{
    // Initialize result in vector
    int count=0;
    vector<int> ans;

    // Traverse through all denomination
    for (int i = num - 1; i >= 0; i--) {

        while (value >= deno[i]) {
            value -= deno[i];
            ans.push_back(deno[i]);
        }
    }

    // Print result
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << "  ";
        count++;
    }

    cout<<endl<<"Enter the total minimum number of array is: "<<count<<endl;

}


int main()
{
    int n = 93,num,temp,i,j,value,arr[50];
    cout<<"Enter the total number of array: ";
    cin>>num;

    for(i=1;i<=num;i++)
    {
        cout<<"Number of index[ "<<i<<" ] is: ";
        cin>>arr[i];
    }
    cout<<"Enter the total amount: ";
    cin>>value;
    for(int i=1;i<=num;i++)
    {
        for(j=i+1;j<=num;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;

            }
        }
    }
    cout << "Following is minimal number of change for " << n << ": ";
    findMin(arr,value,num);

    return 0;

}