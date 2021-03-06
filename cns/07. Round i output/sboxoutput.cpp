/*
lab 7
Program: SBOX output key generator
Author: Gangadhara Shetty P J
*/
#include<bits/stdc++.h>
using namespace std;

string key, previous;
int permute[]={
    16,7,20,21,29,12,28,17,
    1,15,23,26,5,18,31,10,
    2,8,24,14,32,27,3,9,
    19,13,30,6,22,11,4,25
};
int sbox[][4][16]={
    {
		{14,4,13,1,2,15,11,8 ,3,10,6,12,5,9,0,7},
		{0,15,7,4,14,2,13,1 ,10,6,12,11,9,5,3,8},
		{4,1,14,8,13,6,2,11 ,15,12,9,7,3,10,5,0},
		{15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
	},
    {
		{15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},
		{3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
		{0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},
		{13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}
	},
    {
		{10, 0, 9,14, 6, 3, 15, 5, 1, 13, 12, 7,11, 4, 2,8},
		{13, 7, 0, 9, 3, 4,  6, 10, 2, 8, 5, 14,12, 11,15,1},
		{13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10,14,7},
		{1, 10, 13,0, 6, 9,  8, 7, 4, 15, 14,3, 11, 5, 2, 12}
    },
    {
		{7, 13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},
		{13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
		{10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},
		{3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}
    },
    {
		{2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},
		{14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
		{4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},
		{11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}
    },
    {
		{12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},
		{10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
		{9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},
		{4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}
    },
    {
		{4,11,5,14,15,0,8,13,3,12,9,7,5,10,6,1},
		{13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
		{1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},
		{6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}
    },
    {
		{13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},
		{1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
		{7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},
		{2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}
    }
};
void findPermutation()
{
    string key1="";
    for(int i=0;i<32;i++)
        key1 += key[permute[i]-1];
    key=key1;
}
int main()
{
    unsigned long long hexkey;
    string key1, str = "";
	cout<<"Enter a 48 bit input key in hex: ";
	cin>>hex>>hexkey;

	key=bitset<48>(hexkey).to_string();
	
	cout<<"Enter a 64 bit key in hex: ";
    cin>>hex>>hexkey;
	previous=bitset<64>(hexkey).to_string();
	
    for(int i=0, sb=0;i<48;i+=6, sb++){
        string row = "", col = "";
        row= row+key[i]+key[i+5];
        col= col+key[i+1]+key[i+2]+key[i+3]+key[i+4];
		int rowval = (int)bitset<2>(row).to_ulong();
		int colval = (int)bitset<4>(col).to_ulong();
        string tempKey = bitset<4>(sbox [sb] [rowval ] [colval] ).to_string();
		cout<<"SBOX  "<< sb + 1 <<" OUTPUT: "<<tempKey<<endl;
		key1+=tempKey;
    }
	
    key=key1;
	findPermutation();

	for(int i=0;i<32;i++)
		if(key[i]==previous[i]) key[i]='0';
		else key[i]='1';
	cout<<"S-BOX OUTPUT: "<<hex<< (int)bitset<32>(key).to_ulong()<<endl;
}

/*
OUTPUT
------
Enter a 48 bit input key in hex: 6117ba866527
Enter a 64 bit key in hex: cc00ccfff0aaf0aa
SBOX  1 OUTPUT: 0101
SBOX  2 OUTPUT: 1100
SBOX  3 OUTPUT: 1000
SBOX  4 OUTPUT: 0010
SBOX  5 OUTPUT: 1011
SBOX  6 OUTPUT: 0101
SBOX  7 OUTPUT: 1001
SBOX  8 OUTPUT: 0111
S-BOX OUTPUT: ef4a6544

*/