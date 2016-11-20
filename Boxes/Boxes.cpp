#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int N;
int w, l, h;


int basetoarea(int nww, int nll){
	int nhh;	
	int area;
	int W, L, H;
	
	if( nww < 1 || nll < 1 ){
		area = 0;
		return 0;
	}
	
	
	if(N % ( nww * nll ) == 0){
		nhh = N / ( nww * nll );
	}
	else{
		nhh = (N - ( N % ( nww * nll ) ) ) / ( nww * nll ) + 1;
	}
	


	
	W = nww * w;
	L = nll * l;
	H = nhh * h;
	
	area = 2 * ( W * L + L * H + H * W );
	
	if(area < 0){
		area = 0;
	}
	if( W < 1 || L < 1 || H < 1 ){
		area = 0;
	}
	
	
	return area;
}

  
int main() {
    

    cin >> N;
    cin >> w >> l >> h;
    
    if(N == 1){
		cout << 2 * ( w * l + l * h + h * w);
		return 0;
	}
    
    
    
    
    long long int volume;
    volume = N*w*l*h;
    int cube;
    for(long long int i=1; i*i*i*w*l*h < volume; i++){
		cube = (int) i;
    }
    

    int nw, nl;
    
    
    if( cube % w == 0){
		nw = cube / w;
	}
	else{
		nw = (cube - (cube%w)) / w + 1;
    }
    
    
    if( cube % l == 0){
		nl = cube / l;
	}
	else{
		nl = (cube - (cube%l)) / l + 1;
    }
      
    
	int j; 
	
	int curmin;
	curmin = basetoarea( nw , nl );
	
    for(int i = -nw + 1; i < 1000 - nw ; i++){

		j = 0;
		while( basetoarea(nw+i,nl+j) > basetoarea(nw+i, nl+j+1)){
			j++;
		} 
		

		if( basetoarea(nw + i, nl +j) < curmin && basetoarea(nw + i, nl +j) != 0){
			curmin = basetoarea(nw + i, nl + j);
		}
		
	}
	
	cout << curmin << endl;
	
	/*
	cout << cube << endl;
	cout << w << endl;
	cout << N << endl;
	cout << nw << endl;
	cout << j << endl;
	*/
    
    return 0;
}

