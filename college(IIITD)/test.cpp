#include<iostream>

using namespace std;

int main(){
    int max[3][3]={{4,5,67},{8,90,39},{900,100,450}};
    for(int i=0;i<=2;i++){
        for(int j=0;j<=2;j++){
            cout << max[i][j] << " ,";
        }
        cout << endl;
    }
    return 0;
}