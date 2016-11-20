#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
	string s = "";
	int N, K;
	getline( cin, s);
	N = s.size();
	K = N / 2;
	bool SAB[N], X[N], Y[N];
	for(int i = 0; i <= N-1; i++){	
		(s[i] == 'a') ?	 (SAB[i] = 1) :	(SAB[i] = 0) ;
	} 
	
	//~ bool current[N];
	//~ memset(current, 0, sizeof(current[0] * N));
	//~ for( int i = 0; i <= K-1; i++)	{ current[i] = 1 ;}
	//~ for( int j = 0; j <= N-1; j++){
		//~ for( int l = 0; l <= j; l++){
			//~ for( int k = 0; k <= l; k++){
				//~ current[k] = !current[k];
				//~ for(int m = 0; m <= N-1; m++){ cout << current[m] ;} 
			//~ }
			//~ cout << endl;
		//~ }
	
	//~ }
	
	
	
	
	//cout << s[0] << s[2];
	//for(int i = 0; i <= N-1; i++){ cout << SAB[i] ;} 
	//cout << n;
	return 0;
}
