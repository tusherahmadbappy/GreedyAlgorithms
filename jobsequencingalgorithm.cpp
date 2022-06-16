 #include <iostream>
 #include<string.h>

using namespace std;

int main()
{
    char id[10][10],t[10];
     int profit[10],dead_line[10];int maximum_profit=0,n,temp;
     cout<<"Enter Number Of Data: ";
     cin>>n;
     bool box[n];
     for(int i=0; i<n; i++){
        cout<<"Enter id,dead_line & profit: ";
        cin>>id[i]>>dead_line[i]>>profit[i];
     }

     for(int i=0; i<n-1; i++){
       for(int j=i+1; j<n; j++)

        if(profit[i]<profit[j]){
            

            temp = profit[i];
            profit[i] = profit[j];
            profit[j] = temp;

            temp = dead_line[i];
            dead_line[i] = dead_line[j];
            dead_line[j] = temp;

            strcpy(t,id[i]);
            strcpy(id[i],id[j]);
            strcpy(id[j],t);

         }
     }

      cout<<"After Sorting"<<endl;
       for(int i=0; i<n; i++){
          cout<<id[i]<<" "<<dead_line[i]<<" "<<profit[i]<<" "<<endl;
       }
       cout<<endl<<endl;
       memset(box,false,sizeof(box));
        for(int i=0; i<n; i++){
            for(int j=min(n,dead_line[i])-1; j>=0; j--){
                if(box[j]==false){
                    box[j]=true;
                    maximum_profit +=profit[i];
                    break;
                }
            }
        }
        cout<<"Maximum Profit: "<<maximum_profit<<endl;
    return 0;
}