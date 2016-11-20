#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int W, H, N;
    
bool finalcheck(int& w, int& h){
	double Wl, Hl, wl, hl;
	Wl = (double) W;
	Hl = (double) H;
	wl = (double) w;
	hl = (double) h;
	
	if( (w * h > W * H) || ( w + h > W + H)){
		return 0;
	}
	
	else if( w * w < W * W + H * H ){
		double xsq; 
		double hmax;
		xsq = Wl - sqrt( ( Wl * Wl * wl * wl ) / ( Wl * Wl + Hl * Hl ) );
		hmax = sqrt( ( 1 + W * W / ( H * H ) ) * xsq ) ;
		if( hl < hmax ){
			return 1;
		}
	}
	else{
		return 0;
	}
	return 0;
}
int main() {

    int w =0, h =0, r = 0;
    
    
    string shape;
    
    cin >> W >> H;
    cin >> N ;
    bool result[N];
    
    if( W < H ){
		int trans;
		trans = H;
		H = W;
		W = trans;
	}
    
    
    for(int i = 0; i < N; i++){
		cin >> shape;
		
		if( shape == "R" ){
			cin >> w >>h;
			
			if( w < h ){
				int transs;
				transs = h;
				h = w;
				w = transs;
			}
    
			
			if( w <= W && h <= H){
				result[i] = 1;
				continue;
			}
			else if( w <= H && h <= W ){
				result[i] = 1;
				continue;
			}
			else{
				result[i] = finalcheck( w , h);
			}	
			}
			
		else if( shape == "C" ){
			cin >> r;
			if( 2 * r <= W && 2 * r <= H){
				result[i] = 1;
			}
			
			/*
			double pi;
			pi = atan(1) * 4;
			double rl, Wl, Hl;
			rl = (double) r;
			Wl = (double) W;
			Hl = (double) H;
			if( 2 * pi * rl < 2 * ( Wl + Hl ) ){
				result[i] = 1;
			}
			*/
			
			
			}
			
		else{
			cout << "Wrong input";
			return 0;
		}
    }
    
    //cout << shape << w << h << r;
    
    
    
    for(int i = 0; i < N; i++){
		if(result[i] == 1){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
    
    
    return 0;
}
