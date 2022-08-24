#include <string>
#include <vector>
#include <map>

/**
08/25/2022
author : June Park
url : https://school.programmers.co.kr/learn/courses/30/lessons/118666?language=cpp
KAKAO 2022 LEVEL 1 문제

접근 방식 : map을 사용하여 각 설문의 점수를 더하고 높은 지표를 조합하여 리턴한다.
*/

using namespace std;
/*=====================전역변수========================*/
vector<int> score = {0,3,2,1,0,1,2,3};//매우 비동의~매우동의
map<char,int> result;

/*=====================함수목록========================*/
void init(); //초기화 함수
void updateScore(char, int); //X형에 N점을 추가한다
string mbti(); //성격 유형을 반환한다


string solution(vector<string> survey, vector<int> choices) {
    
    init(); //map을 초기화 한다
    char type1,type2; //점수를 더할 char 출력용
    
    for(int i = 0 ; i < survey.size(); i++) //문자에 점수를 더하는 루프
    {
        type1 = survey[i][0];
        type2 = survey[i][1];
        
        // cout<<"type 1 : "<<type1 << " type2 : "<<type2<<choices[i]<<endl;
        // cout<<score[choices[i]]<<endl;
        
        if(choices[i]==4)continue; /* 모르겠음 */
        else if (choices[i]>4) updateScore(type2, score[choices[i]]); /* 후자에 가산점 */
        else updateScore(type1, score[choices[i]]); /* 전자에 가산점*/
    }
    //for(auto i:result)cout<<i.first<<" "<<i.second<<endl; //확인용

    return mbti(); //점수를 조합해서 출력한다
}

string mbti(){
    string res; // 성격 유형 변수
    //1번 지표
    if(result['R'] >= result['T'])res += 'R';
    else res+='T';
    
    //2번 지표
    if(result['C']>=result['F'])res +='C';
    else res+='F';
    
    //3번 지표
    if(result['J']>=result['M'])res += 'J';
    else res+= 'M';
    
    //4번 지표
    if(result['A']>=result['N'])res += 'A';
    else res+= 'N';
    
    return res;
}

void updateScore(char x, int n){
    result[x] += n;
}

void init(){
    result.insert({'R',0});
    result.insert({'T',0});
    result.insert({'C',0});
    result.insert({'F',0});
    result.insert({'J',0});
    result.insert({'M',0});
    result.insert({'A',0});
    result.insert({'N',0});
}





