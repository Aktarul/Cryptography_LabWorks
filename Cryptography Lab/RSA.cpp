#include <bits/stdc++.h>
using namespace std;

//Calculating if a number is prime or not
int power(int x, unsigned int y, int p) //function called by millerTest()
{
	int res = 1;
	x = x % p;

	while (y > 0)
	{
		if (y & 1)
			res = (res*x) % p;

		y = y>>1;
		x = (x*x) % p;
	}
	return res;
}

bool miillerTest(int d, int n)  // primality test algorithm
{
	int a = 2 + rand() % (n - 4);

	int x = power(a, d, n);

	if (x == 1 || x == n-1)
	return true;

	while (d != n-1)
	{
		x = (x * x) % n;
		d *= 2;

		if (x == 1)	 return false;
		if (x == n-1) return true;
	}

	return false;
}

bool isPrime(int n, int k)      // isPrime function
{
	if (n <= 1 || n == 4) return false;
	if (n <= 3) return true;

	int d = n - 1;
	while (d % 2 == 0)
		d /= 2;

	for (int i = 0; i < k; i++)
		if (miillerTest(d, n) == false)
			return false;

	return true;
}


// Calculating if two numbers are relatively prime or not
int gcd(int a, int b) {         //gcd function
    int t;
    while(b != 0){
        t = a;
        a = b;
        b = t%b;
    }
    return a;
}

bool relativelyPrime(int a, int b) {        //relativelyPrime function
    return gcd(a,b) == 1;
}


void genPK()                    //generate public key
{
    int k = 4;

	srand((unsigned)time(0));       // calling srand()

    int p = (rand() % 100) + 100;          //obtaining p
	while(true){
        if(isPrime(p,k)){
            cout<<"p = "<<p<<endl;
            break;
        }
        else p = (rand() % 100) + 10;
	}

	int q = (rand() % 100) + 100;          // obtaining q
	while(true){
        if(isPrime(q,k)){
            cout<<"q = "<<q<<endl;
            break;
        }
        else q = (rand() % 100) + 10;
	}

	int n = p * q ;    //calculating n
	cout<<"n = "<<n<<endl;

    int e = rand() % 100;          // obtaining encrypt key
	while(true){
        if(relativelyPrime(e , (p-1)*(q-1))){       //checking if e and (p-1)(q-1) are relatively Prime
            cout<<"Encryption key: "<<e<<endl;
            break;
        }
        else e = rand() % 100;                     //if not relatively prime the generate e again
	}


    int c = 1;
    float d =(float) (1 + (c * (p-1) * (q-1))) / e ;            //calculating decrypt key

    while(true){
        float x = fmod(d,1);                            //checking if d containing fractions
        if(!x) break;                                   //if not break
        else {
            c++;                     //if d is not integer increment c and calculate d again
            d =(float) (1 + (c * (p-1) * (q-1))) / e ;
        }

    }
    cout<<"Decryption key: "<<d<<endl;
}

int calculation( int c, int d, int n )      // work out c^d mod n
{
   int value = 1;
   while( d > 0 )
   {
      value *= c;
      value %= n;
      d--;
   }
   return value;
}

void Encrypt()
{
    char str[100];
    int key, n, len, c;

    cout<<"\nEnter Message: ";
    cin>>str;

    len = strlen(str);

    cout<<endl<<"Your message: "<<str<<endl<<"Size: "<<len<<endl;

    cout<<"\nEnter n: ";
    cin>>n;


    cout<<"\nEnter encrypt key:";
    cin>>key;

    long double bigInt;
    for(int i = 0 ; i < len ; i = i + 1){

        c = (int)str[i];

        c = calculation(c, key, n);

        printf("%d ",c);
    }
    printf("\n");
}


void Decrypt()
{
    int c,n,key, i = 0, value;
    char temp = 'a';

    cout<<"\nEnter n: ";
    cin>>n;

    cout<<"\nEnter decrypt key: ";
    cin>>key;

    cout<<"\nEnter message: ";
    while(temp!= '\n'){
        scanf("%d%c", &c, &temp);
        value = calculation(c, key, n);

        printf("%c",value);
    }

    printf("\n\n");
}


int main()
{
    printf("\n\t1. Generate public key\t\t2. Encrypt\n\t3. Decrypt data\t\t\t4. Exit\n");
    char choice;
    cout<<"\nChoice: ";
    cin>>choice;

    system("CLS");

    if(choice == '1'){
        genPK();
    }
    else if(choice == '2'){
        Encrypt();
    }
    else if(choice == '3'){
        Decrypt();
    }
    else if(choice == '4'){
        return 0;
    }

    else{
        cout<<"Enter your choice again"<<endl;
    }

    main();

}

