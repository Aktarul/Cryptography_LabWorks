#include<bits/stdc++.h>
using namespace std;


int main()
{
    char str[100];
    int i=0;

    gets(str);      //taking input


    while(str[i]){
        if(str[i] >= 'A' && str[i] <= 'Z'){     //checking for uppercase letters
            str[i] = str[i] + 3;
            if(str[i] > 'Z') str[i] = str[i] - 26;
        }
        else if(str[i]>='a' && str[i]<='z'){    //checking for lowercase letters
            str[i] = str[i] + 3;
            if(str[i] > 'z') str[i] = str[i] - 26;
        }
        i++;
    }
    cout<<endl<<str<<endl;      //Encrypted output

    return 0;
}
