/**
Calendar - 년과 달을 입력하면 해당 달력을 출력하는 프로그램
author : June Park 
*/

#include <iostream>
#include <string>

using namespace std;

static int yyyy,mm;
static int mdays[] = {31,28,31,30,31,30,31,31,30,31,30,31} ;
static string date[] = {"Sun", "Mon", "Tue", "Wed", "Thu","Fri","Sat"};
 
void printMenu();
int setdays(int,int);//해당 년월의 총 날짜수 리턴 
bool isLeap(int);
int getFirstDay(int,int) ;//해당 월의 1일이 몇요일인지 리 
void printCalendar(int,int);

/**
Get input from user -> we then knows how many days are in at that month
Then, we need to know where 1st lands on weekdays
*/
int main(){
	printMenu(); 
	int days = setdays(yyyy,mm);
	printCalendar(getFirstDay(yyyy,mm),mm);
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
	
	cout<<"\n=================================="<<endl;
	cout<<"\t"<<yyyy<<"   년	"<<mm<<" 월"<<endl;
	cout<<"=================================="<<endl;
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
	if((year%4)==0 && (year %100)!=0 || (year%400) ==0) return true;
	else return false;
}

int getFirstDay(int year, int month){
	int i, total_days=0;
	
	//1년 ~ year -1년도 일수 
	for(i=1; i<year; i++){
		if(isLeap(i)) total_days+=366; //윤년 
		else total_days+=365;
	}

	// 해당 월까지 누적일 
	for(i=0; i<month-1; i++){
		total_days+=mdays[i];
	}
	
	//올해가 윤년인 경우
	if(month>2 && isLeap(year)) total_days++; 
	total_days++;
	
	return total_days%7;  
} 

/**
첫날이 몇요일인지 주어짐 
만일, 첫날이 5라면 금요일 
*/
void printCalendar(int start,int month){
	int c;
	for(  c = 0 ; c<7; c++){
		cout<<date[c]<<"  ";
	}
	cout<<endl;
	
	int i;//공백 
	for(i = 0 ; i< start ; i++){
		cout<<"     "; 	
	 }
	int j , cnt=0;//숫자
	 
	for(j = start; j<mdays[month-1]+start; j++){ //start부터 시작했기때문에, 끝에 start만큼 더 숫자써야함 
		if(j%7==0) cout<<endl;
		++cnt;
		if(cnt<10)cout<<"  "<<cnt<<"  "; 
		else cout<<" "<<cnt<<"  ";
		
	} 
}
