#include<iostream>

using namespace std;
/*   有一4x4棋盘，上面有16枚双面棋子（一面为黑，一面为白），
	 当翻动一只棋子时，该棋子上下左右相邻的棋子也会同时翻面。
	 以b代表黑面，w代表白面，给出一个棋盘状态，
	 问从该棋盘状态开始，使棋盘变成全黑或全白，至少需要翻转多少步*/
bool qp[6][6];

int op(int num){//变成全1
    int cnt = 0;
    bool sp[6];
    bool mp[6][6];
    for(int i=1;i<5;i++)
        for(int j=1;j<5;j++)
            mp[i][j]=qp[i][j];

    for(int i=1;i<5;i++){
        sp[i] = num%2;
        num/=2;
    }
    for(int i=1;i<5;i++){
        if(sp[i]){
            mp[1][i] = !mp[1][i];
            mp[1][i-1] = !mp[1][i-1];
            mp[1][i+1] = !mp[1][i+1];
            mp[2][i] = !mp[2][i];
            cnt++;
        }
    }
    for(int i = 2;i<=4;i++){
        for(int j=1;j<=4;j++){
            if(!mp[i-1][j]){
                mp[i-1][j] = !mp[i-1][j];
                mp[i][j] = !mp[i][j];
                mp[i][j-1] = !mp[i][j-1];
                mp[i][j+1] = !mp[i][j+1];
                mp[i+1][j] = !mp[i+1][j];
                cnt++;
            }
        }
    }
    for(int i=1;i<=4;i++){
        if(!mp[4][i]) return 17;
    }
    return cnt;
}
int main(){
   for(int i=1;i<5;i++){
        for(int j=1;j<5;j++){
            char tmp;
            cin>>tmp;
            if(tmp=='b') qp[i][j] = 0;
            if(tmp=='w') qp[i][j] = 1;
        }
   }
   int min = 17;
   for(int i=0;i<16;i++){
       int tmp = op(i);
       if(tmp<min) min=tmp;
   }
   if(min==17) cout<<"Impossible"<<endl;
   else{
        for(int i=1;i<5;i++){
            for(int j=1;j<5;j++){
                qp[i][j] = !qp[i][j];
            }
        }
        for(int i=0;i<16;i++){
           int tmp = op(i);
           if(tmp<min) min=tmp;
        }
        cout<<min<<endl;
    }
   return 0;
}
