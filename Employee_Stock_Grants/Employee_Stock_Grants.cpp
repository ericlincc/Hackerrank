#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int N;

int check( int pos, int Rating[], int Min[]){
	for( int i = max( 0, pos - 10); i <= min( N-1, pos + 10); i++){
		if((Rating[pos] > Rating[i]) && (Min[pos] <=  Min[i])){
			return 1;
		}
	}
	return 0;
}

int main() {
	cin >> N;
	int rating[N], MIN[N], NOTOK[N];
	int current, newcurrent;
	for( int i = 0; i < N; i++){ cin >> rating[i] ;}
	for( int i = 0; i < N; i++){ cin >> MIN[i] ;}
	for( int i = 0; i < N; i++){ NOTOK[i] = check( i, rating,  MIN) ; }   //CHECK ALL
	bool success = false;
	bool NEARBYOK;
	//cout << NOTOK[0];
	
	
	while((success == false)){
		current = 0;
		while( (NOTOK[current] == 0) && (current <= N-1)){ current++ ;}
		if((current == N-1) && (NOTOK[current] == 0)) {
			success = true;
			continue;
		}
		for( int i = max( 0, current - 10); i <= min( N-1, current + 10); i++){
			if((rating[current] > rating[i]) && (MIN[current] <=  MIN[i])){
				MIN[current] = MIN[i] +1;
			}
		}
		NEARBYOK = false;
		while(NEARBYOK == false){
			newcurrent = max( 0, current - 10);
			while( newcurrent <= min( N-1, current + 10) && check( newcurrent, rating,  MIN) == 0){
				if(newcurrent == min( N-1, current + 10)){NEARBYOK = true;}
				newcurrent++;
			}	
			if((NEARBYOK == false)){
				current = newcurrent;
				for( int i = max( 0, current - 10); i <= min( N-1, current + 10); i++){
					if((rating[current] > rating[i]) && (MIN[current] <=  MIN[i])){
						MIN[current] = MIN[i] +1;
					}
				}
			}
		}
		for( int i = 0; i <= N; i++){ NOTOK[i] = check( i, rating, MIN) ; } //CHECK ALL
		int sum = 0;
		for( int i = 0; i <= N; i++){ sum = sum + NOTOK[i] ;}
		if((sum == 0)){ success = true ;}
	}
	
	int sum = 0;
	for( int i = 0; i < N; i++){ sum = sum + MIN[i] ;}
	cout << sum;
	return 0;
}
