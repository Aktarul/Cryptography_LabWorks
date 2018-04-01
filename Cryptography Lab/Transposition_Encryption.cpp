#include<bits/stdc++.h>
using namespace std;

void tran_encr(char* mes);      //declare function name

int main()
{
    char mes[1000];
    int choice;
    cout<<"\nEnter plain text: ";
    gets(mes);      //taking input message

    cout<<"\n\n\t1. Single Transposition \t2.Double Transposition\nChoice: ";
    cin>>choice;

    tran_encr(mes);     //single transposition  encryption

    if(choice==2) tran_encr(mes);       //double transposition encryption

    cout<<"\nCipher text: ";        // printing cipher text
    puts(mes);

}

void tran_encr(char* mes)
{
    char str[1000];
    strcpy(str, mes);           //copying plain text at str[]

    int width,len, rem, k = 0;
    cout<<"Enter width: ";
    cin>>width;                 //taking encrypting width

    len = strlen(mes);

    for(int i = 0; i < width ; i++){
        for( int j=i ; j<len ; j = j + width){
            mes[k] = str[j];                //encrypting data by moving elements to mes one by one
            k++;
        }
    }
    return 0;
}
