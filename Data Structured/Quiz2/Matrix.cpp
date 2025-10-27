#include  <iostream>
#include  <vector>
#include  <string>
using namespace std;

int main() {
    int m,n,data;
    cin>>m>>n;
    int arr[m][n] ;
    for(int i = 0 ;i < m ; i++){
        for (int j = 0; j < n; j++)
        {
            cin>>data;
            arr[i][j] = data;
        }
    }
    int columnSums[1000] = {0};
    int sum = arr[0][0] + arr[1][1] + arr[2][2];
    for(int i = 0 ;i < m ; i++){
        int row = 0;
        for (int j = 0; j < n; j++)
        {
            cout<<arr[i][j]<<" ";            
            row += arr[i][j];                
            columnSums[j] +=  arr[i][j];
        }
        cout<<"||"<<" ";
        cout<<row<<endl;
        
    }
    int columnSum ;
    cout << "-------------------" << endl;
    
    for (int j = 0; j < n; j++) {
        cout << columnSums[j]  << " ";
        columnSum += columnSums[j];
    }
    cout <<" "<<columnSum<< endl;
    cout << endl;
    return 0;
}