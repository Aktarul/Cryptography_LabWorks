#include<bits/stdc++.h>
using namespace std;

int main()
{
    char mess[100], OTP[100], cipher[100];

    cout<<"Enter the plain text: ";
    cin>>mess;              // taking input of message

    ifstream fileIn( "Sender_OTP.txt" );          //opening  sender One Time Pad
    fileIn >> OTP;                          //taking all contents from file to OTP[]
    fileIn.close();

    cout<<"\nOne time pad from file: "<<OTP<<endl;      //printing OTP


    int len = strlen(mess);

    cout<<"\nEncrypted text: ";

    for(int i = 0 ; i < len ; i++ ){
        printf("%c",(((mess[i] - 64) + (OTP[i] - 64)) % 26)+64);        // (plain text char + pad char) % 26
                                                        // 64 added to show output in character
    //printf("\n%d=%c + %d=%c = %d=%c",mess[i],mess[i],OTP[i],OTP[i],(((mess[i] - 64) + (OTP[i] - 64)) % 26)+64,(((mess[i] - 64) + (OTP[i] - 64)) % 26)+64);

    }

    int pad_len = strlen(OTP);

    //cout<<"OTP before change: "<<OTP<<endl;

    for(int i = 0; i <= pad_len - len ; i++){
        OTP[i] = OTP[i + len];                  // deleting used characters
    }

    //cout<<"OTP after change: "<<OTP<<endl;

    ofstream fileOut( "Sender_OTP.txt" );              // writing the rest of content into file
    fileOut << OTP;
    fileOut.close();

    cout<<endl;

    return 0;
}

/**
INPUT:
BANGLADESHISABEAUTIFULCOUNTRY

INITIAL OTP:
WOTKNOUTZATPJMTUKUVIRFAXJVRWDBCVGVVGSKNBKNMYGISLJZKNIAYFEFJAMQIARZZJ
*/
