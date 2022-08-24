/**
Calendar - 년과 달을 입력하면 해당 달력을 출력하는 프로그램
author : June Park 
*/

#include <iostream>
#include <string>

using namespace std;

static int yyyy,mm;
static int mdays[] = {0,31,28,31,30,31,30,31,31,30,31,30,31} ;
static string date[] = {"Sun", "Mon", "Tue", "Wed", "Thu","Fri","Sat"};
 
void printMenu();
int setdays(int,int);//해당 년월의 총 날짜수 리턴 
bool isLeap(int);
int getFirstDay(int,int) ;//해당 월의 1일이 몇요일인지 리 

/**
Get input from user -> we then knows how many days are in at that month
Then, we need to know where 1st lands on weekdays
*/
int main(){
	printMenu(); 
	int days = setdays(yyyy,mm);

	return 0;
		
}

/**
printMenu() : get year and month 
*/
void printMenu(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cout<<"[Select Year] "<<endl;
	cin>>yyyy;
	
	cout<<"\n[Select Month] "<<endl;
	cin>>mm;
	
	cout<<"\n============================="<<endl;
	cout<<"\t"<<yyyy<<"년	"<<mm<<" 월"<<endl;
	cout<<"============================="<<endl;
}

/**
setdays(년,월) : 해당 년월의 일수를 반환한 
*/
int setdays(int year, int month){
	if(isLeap(year) && month == 2 ) return 29;
	else return mdays[month];
}

/**
isLeap(년) : 1 - 윤년, 0 - 윤년X 
*/
bool isLeap(int year){
	if((year%4)==0 && (year %100)!=0 || (year%400) ==0) {
		mdays[2] = 29; //윤년으로 변경 
		return true};
	else return false;
}

int getFirstDay(int year, int month){

} 
