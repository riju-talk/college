#include<iostream>
#include<string>

using namespace std;

int main(){
    int num;
    cin >> num;
    for(int i=0;i<num;i++){
        string word;
        cin >> word;
        if(word.length()<=10){
            cout << word << endl;
        }
        else{
            cout << word[0] << word.length()-2 << word[word.length()-1] << endl;
        }
    }
    return 0;
}