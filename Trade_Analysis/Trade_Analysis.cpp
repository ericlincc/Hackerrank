#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>

using namespace std;

const long long module = (1000000000 + 7);

long long update( long long L, long long L_1, long long a_k){
	long long NEW;
	NEW = (L + (a_k % module) * L_1) % module;
	return NEW;
}

int main() {
	int n;
	cin >> n;
	long long a[n];
	for( int i = 0; i <= n-1 ; i++){ cin >> a[i];}
	long long G[n][2];
	memset(G, 0, sizeof( G[0][0] ) * n * 2);
	
	for( int k = 0; k <= n-1; k++){
		for( int j = 0; j <= n-1; j++){ G[j][0] = G[j][1] ;}
		for( int j = 0; j <= k; j++){
			if( (k == 0) ){ 			G[0][1] = a[0];	}
			else if( (j == 0) ){		G[0][1] = (G[0][0] + a[k]) % module ; }
			else {						G[j][1] = update(G[j][0], G[j-1][0], a[k]);}		
		}
	}
	long long GS = 0;
	for( int i = 0; i <= n-1; i++){ GS = (GS + ((i+1) * G[i][1]) % module) % module; }
	cout << GS << endl;
	return 0;
}
