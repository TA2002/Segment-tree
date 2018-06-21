//
//  
//  
//  Created by Tarlan Askaruly.
//  Copyright (c) 2018 Tarlan Askaruly. All rights reserved.
//
#include <bits/stdc++.h>             
using namespace std;
long long n, m, l, r, a[200001], t[400000];
void build(int v, int L, int R){
	if(L == R){
    	t[v] = a[L];  
    	return;
  	}
  	int mid = (L + R) / 2;
  	build(v * 2, L, mid);
  	build(v * 2 + 1, mid + 1, R);
  	t[v] = t[v * 2] + t[v * 2 + 1];
}

long long get_sum(int v, int L, int R, int l, int r){
  	if(l <= L && R <= r){
    	return t[v];
  	}
  	if(R < l || L > r){
    	return 0;     
  	}
  	int mid = (L + R) / 2;
  	return get_sum(v * 2, L, mid, l, r) + get_sum(v * 2 + 1, mid + 1, R, l, r);
}

int main(){
	freopen("sum2.in", "r", stdin);
	freopen("sum2.out", "w", stdout);
	cin >> n;
  	for(int i = 1; i <= n; i++){
    	cin >> a[i];
  	}
  	build(1, 1, n);
  	cin >> m;
  	for(int i = 1; i <= m; i++){
    	cin >> l >> r;
    	cout << get_sum(1, 1, n, l, r) << endl;
  	}
  return 0;	
}
