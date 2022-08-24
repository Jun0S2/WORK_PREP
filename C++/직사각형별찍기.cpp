#include <iostream>

/**
author : June Park
date : 08/24/2022
url : https://school.programmers.co.kr/learn/courses/30/lessons/12969
*/

using namespace std;

void solution(int n, int m);//

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N,M;
	cin>>N>>M;
	solution(N,M);
	return 0;
}

void solution(int n, int m){
	int i,j;
	for( i =0 ; i< m ; i++ ){
		for( j = 0 ; j< n ;j++)
		{
			cout<<"*";
		}
		cout<<endl;
	}
	return;
}
