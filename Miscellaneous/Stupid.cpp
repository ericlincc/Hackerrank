#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int N , M;	
int P[M];

void plusone(int& newwork, int newE){
	
	//find max element
	int maxele;
	int newworkt[M];
	
	
	maxele = newworkt[0];
	
	
}

void newmin(int& newminn, int& newworkk){
	
}

int main(){

	cin >> N >> M;

	for(int i=0; i < M ; i++){
		cin >> P[i];
	}
	
	int work[M];
	for(int i=0; i < M; i++){
		work[i] = 0;
	}
	
	int curmin;
	work[0] = N;
	int workt[M];
	for(int i=0; i < M; i++){
		workt[i] = P[i] * work[i];
	}
	
	
	
	
		
	
	
	
	return 0;
}
