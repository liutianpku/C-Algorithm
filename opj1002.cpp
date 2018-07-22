#include <iostream>
#include <cstring>
#include<algorithm>
#include <stdio.h>
using namespace std;
int trans[27]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9};//此处的Q也要表示出来，所以有4个7
int num[100005]={0};
int f(char a)
{
    if(a>='0'&&a<='9') return a-'0';
    if(a>='a'&&a<='z') return trans[a-'a'];
    if(a>='A'&&a<='Z') return trans[a-'A'];
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        char ss[203];
        scanf("%s",ss);
        int len = strlen(ss);
        for(int j=0;j<len;j++){
            if(ss[j]!='-'){
                num[i] = num[i]*10+f(ss[j]);
            }
        }

    }
    sort(num,num+n);
    bool flg=0;
    int cnt=1;
    for(int i=0;i<n-1;i++){
        if(num[i]==num[i+1]){
            cnt++;
            flg=1;
        }
        else{
            if(cnt>1){
                printf("%03d-%04d %d\n",num[i]/10000,num[i]%10000,cnt);
                cnt=1;
            }
        }
    }
    if(cnt>1)  //如果只有两个电话号码且相同会有此处需要例外处理
        printf("%03d-%04d %d\n",num[n-1]/10000,num[n-1]%10000,cnt);
    if(!flg)
        printf("No duplicates.\n");
}
