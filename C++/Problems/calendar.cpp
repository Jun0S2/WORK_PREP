/**
Calendar - 년과 달을 입력하면 해당 달력을 출력하는 프로그램
author : June Park 
*/

#include <iostream>
#include <string>

using namespace std;

/** global variables */
static int yyyy,mm; 													/* input year, input month */
static int mdays[] = {31,28,31,30,31,30,31,31,30,31,30,31} ;			/* days in month		   */
static string date[] = {"Sun", "Mon", "Tue", "Wed", "Thu","Fri","Sat"}; /* weekdays				   */
 
/** functions */
void userInput(); 						/* Get User Input */
int setdays(int,int);					/* Return how many days are in input month (w. leap 처리) */
bool isLeap(int);						/* Return true if leap, else false */
int getFirstDay(int,int) ;				/* Return what date is the first day of the user selected month */
void printCalendar(int,int); 			/* Print calendar */
void simulate(); 						/* Get User Input and print calendar */
bool loop(); 							/* Used to create loop until user wants to stop*/


int main(){
	while(loop()){
		cin.clear();
		simulate();
	}
	return 0;
}

bool loop(){
	bool contLoop = true;
	char qc;
	
	while(true){
		
		cout<<"Press 'q' to quit or 'c' to continue: ";
		cin>>qc;
		if(qc != 'q' && qc != 'c') continue;
		else if (qc=='q') return false;
		else return true;
	}
}

void simulate() {
	userInput(); 
	int days = setdays(yyyy,mm);
	printCalendar(getFirstDay(yyyy,mm),mm);
}


void userInput(){
	
	cout<<"[Select Year] "<<endl;
	cin>>yyyy;
	
	cout<<"\n[Select Month] "<<endl;
	cin>>mm;
}


int setdays(int year, int month){
	if(isLeap(year) && month == 2 ) {
		mdays[1] = 29;
		return 29;
	}
	
	else if(month ==2 ) { mdays[1] = 28; }
	return mdays[month];	
}

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

void printCalendar(int start,int month){
	int c;
		
	cout<<"\n=================================="<<endl;
	cout<<"\t"<<yyyy<<"   년	"<<mm<<" 월"<<endl;
	cout<<"=================================="<<endl;

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
	cout<<endl<<"=================================="<<endl;
}
