#include<bits/stdc++.h>
using namespace std;

int main()
{
    char mess[100], OTP[100];

    cout<<"Enter cipher text: ";
    gets(mess);                     // input cipher text
    cout<<"\nEnter Key of Pad: ";
    gets(OTP);                      // input key of one time pad

    int len = strlen(mess);         //length of cipher text

    cout<<"\nDecrypted text: ";

    for(int i = 0 ; i < len ; i++ ){
        if(mess[i] - OTP[i] <= 0){                  //checking if the value is negative
            printf("%c", (mess[i] - OTP[i])+26+64);     //if negative then 26 will be added
                                                        // 64 added to show output in character

            //printf("\n%d=%c %d=%c = %d=%c",mess[i],mess[i],OTP[i],OTP[i],(mess[i] - OTP[i])+26+64,(mess[i] - OTP[i])+26+64);

        }
        else {
            printf("%c",(mess[i] - OTP[i])+64);         //if positive then simply subtraction
            //printf("\n%d=%c %d=%c = %d=%c",mess[i],mess[i],OTP[i],OTP[i],(mess[i] - OTP[i])+64,(mess[i] - OTP[i])+64);
        }
    }

    cout<<endl;

    return 0;
}

/**
INPUT:
IPKLPSFHGQ
TBFRGFARFM
*/
