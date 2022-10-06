#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void remove_duplicates(char data[],int length) {
    int left = 0;

    if(length <= 1) {
        return;
    }
    for(int current_char = 0;current_char<length;current_char++) {
        if(data[current_char] != data[left]) {
            left++;
            data[left] = data[current_char];
        }
    }
    data[left+1] = '\0';
    cout<<data<<endl;
    // return;
}

int main() {
    char str[1000];
    int length = sizeof(str)/sizeof(char);
    cin.getline(str,length);
    remove_duplicates(str,length);
    return 0;
}
