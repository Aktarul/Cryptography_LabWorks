#include<bits/stdc++.h>
using namespace std;

int main()
{
    char mess[100], OTP[100];

    cout<<"Enter cipher text: ";
    gets(mess);                     // input cipher text


    ifstream fileIn( "Rec_OTP.txt" );          //opening  sender One Time Pad
    fileIn >> OTP;                          //taking all contents from file to OTP[]
    fileIn.close();

    cout<<"\nOne time pad from file: "<<OTP<<endl;      //printing OTP

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

    int pad_len = strlen(OTP);

    //cout<<"OTP before change: "<<OTP<<endl;

    for(int i = 0; i <= pad_len - len ; i++){
        OTP[i] = OTP[i + len];                  // deleting used characters
    }

    //cout<<"OTP after change: "<<OTP<<endl;

    ofstream fileOut( "Rec_OTP.txt" );              // writing the rest of content into file
    fileOut << OTP;
    fileOut.close();

    cout<<endl;

    return 0;
}
