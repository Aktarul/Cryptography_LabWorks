#include<bits/stdc++.h>
using namespace std;

int main()
{
    char mess[100], OTP[100], cipher[100];

    cout<<"Enter plain text: ";
    gets(mess);                     //input plain text
    cout<<"\nEnter Key of Pad: ";
    gets(OTP);                      //key of one time pad

    int len = strlen(mess);         //length of plain text

    cout<<"\nEncrypted text: ";

    for(int i = 0 ; i < len ; i++ ){
        printf("%c",(((mess[i] - 64) + (OTP[i] - 64)) % 26)+64);        // (plain text char + pad char) % 26
                                                        // 64 added to show output in character

    //printf("\n%d=%c + %d=%c = %d=%c",mess[i],mess[i],OTP[i],OTP[i],(((mess[i] - 64) + (OTP[i] - 64)) % 26)+64,(((mess[i] - 64) + (OTP[i] - 64)) % 26)+64);

    }

    cout<<endl;

    return 0;
}

/**
INPUT:
ONETIMEPAD
TBFRGFARFM
*/
