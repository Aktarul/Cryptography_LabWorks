#include<bits/stdc++.h>
using namespace std;

void tran_decr(char* mes, int len);     //declaring decryption function

int main()
{
    char mes[1000];
    int choice;
    cout<<"\nEnter cipher text: ";
    gets(mes);                          //taking cipher text input
    int len = strlen(mes);              //calculating length of text

    cout<<"\n\n\t1. Single Transposition Decryption \t2.Double Transposition Decryption\nChoice: ";
    cin>>choice;

    tran_decr(mes, len);            //single transposition decryption

    if(choice==2) tran_decr(mes, len);  //double transposition decryption

    cout<<"\nDecrypted plain text: ";
    for(int i=0; i< len ; i++){
        cout<<mes[i];                   //printing decrypted text
    }

    return 0;
}

void tran_decr(char* mes, int len)
{
    char str[1000];
    strcpy(str, mes);           //copying encrypted code to str[]

    int width, rem=0, height,k=0;

    cout<<"Width: ";
    cin>>width;                 //taking decryption width

    rem = len % width;          //calculating reminder elements of last row
    //cout<<"reminder: "<<rem<<endl;
    height = len / width;       //calculating height of the matrix
    //cout<<"height: "<<height<<endl;


    for(int i = 0; i < height+1 ; i++){
        int rem2 = rem;
        for(int j=i ; j<len ; j = j + height){
            //cout<<"i= "<<i<<" j= "<<j<<" "<<j+1<<". "<<str[j]<<endl;
            mes[k] = str[j];            //decrypting by moving elements to mes one by one
            k++;
            if(rem2) {                  //if there is a reminder then j will increase
                j++;  rem2--;
            }
            if((rem2==0) && (i==height)) break;     //last row and last element detection
        }
    }

    return;
}
