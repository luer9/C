/**
0:zero, 1: one, 2:two, 3:three, 4:four, 5:five, 6:six, 
7:seven, 8:eight, 9:nine, 10:ten, 11:eleven,
 12:twelve, 13:thirteen, 14:fourteen, 15:fifteen,
  16:sixteen, 17:seventeen, 18:eighteen, 19:nineteen, 20:twenty¡£
¡¡¡¡30¶Á×÷thirty£¬40¶Á×÷forty£¬50¶Á×÷fifty¡£
*/ 
#include <iostream>
#include <cstring>
#include <string>
#include <map>
using namespace std;
map<int, string> mapp;
void init(){
	mapp[0] = "zero";
	mapp[1] = "one";
	mapp[2] = "two";
	mapp[3] = "three";
	mapp[4] = "four";
	mapp[5] = "five";
	mapp[6] = "six";
	mapp[7] = "seven";
	mapp[8] = "eight";
	mapp[9] = "nine";
	mapp[10] = "ten";
	mapp[11] = "eleven";
	mapp[12] = "twelve";
	mapp[13] = "thirteen"; mapp[14] = "fourteen"; mapp[15] = "fifteen";
	mapp[16] = "sixteen"; mapp[17] = "seventeen"; mapp[18] ="eighteen";
	mapp[19] = "nineteen"; mapp[20] = "twenty"; mapp[30] = "thirty";
	mapp[40] = "forty"; mapp[50] = "fifty";
	
	
}

int main(){
	
	int h, m;
	mapp.clear();
	cin >> h >> m;
	init();
	if(m == 0) {
		if(h>20 && h < 60) {
			int high = h / 10;
			int low = h % 10;
			cout << mapp[high*10] << " " << mapp[low]; 
		}else {
			cout << mapp[h];
		}
		cout << " o'clock" << endl;
	}else {
		if(h > 20 && h < 60) {
			int high = h / 10;
			int low = h % 10;
			cout << mapp[high*10] << " " << mapp[low]; 
		}else {
			cout << mapp[h];
		}
		if(m > 20 && m < 60) {
			int high = m / 10;
			int low = m % 10;
			cout <<" "<< mapp[high*10] << " " << mapp[low]; 
		}else {
			cout <<" "<< mapp[m];
		}
		cout << endl;
	}
	return 0;
} 
