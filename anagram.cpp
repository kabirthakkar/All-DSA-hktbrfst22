#include<bits/stdc++.h>

using namespace std;

bool checkAnagram(string a ,string b){
    int arr[26]={0};
    int brr[26]={0};
    if(a.length()!=b.length())return false;

    for(int i=0;i<a.length();i++)arr[a[i]]++;
    for(int i=0;i<b.length();i++)brr[b[i]]++;

   
    for(int i=0;i<26;i++){
        if(arr[i]!=brr[i])return false;
    }
    return true;
}
int main(){
    string a,b;
    cout<<"Enter the 2 string "<<endl;
    cin>>a>>b;
    if(checkAnagram(a,b))cout<<"The strings are anagramic"<<endl;
    else cout<<"The strings aren't anagramic"<<endl;
}