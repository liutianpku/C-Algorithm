#include<stdio.h>
#include<string.h>
using namespace std;
void add_long(char a[], char b[], int sum[]){
    int indexa = strlen(a) - 1;
    int indexb = strlen(b) - 1;
    int index = 1001;
    while(indexa>=0 || indexb>=0){
        if(indexa>=0&&indexb>=0){
            int tmp = (a[indexa] - '0') + (b[indexb] - '0') + sum[index];
            sum[index] = tmp%10;
            sum[index-1] = tmp/10;
            indexa--;
            indexb--;
            index--;
        }
        else{
            if(indexa>=0){
                int tmp = (a[indexa] - '0') + 0 + sum[index];
                sum[index] = tmp%10;
                sum[index-1] = tmp/10;
                indexa--;
                indexb--;
                index--;
            }
            if(indexb>=0){
                int tmp = (b[indexb] - '0') + 0 + sum[index];
                sum[index] = tmp%10;
                sum[index-1] = tmp/10;
                indexa--;
                indexb--;
                index--;
            }
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int cnt = 0;
    char a[1005],b[1005];
    int sum[1005];
    while(n--){
        cnt++;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(sum,0,sizeof(sum));
        scanf("%s %s",a,b);
        add_long(a,b,sum);
        printf("Case %d:\n%s + %s = ",cnt,a,b);
        bool flg = 0;
        for(int i=0;i<1002;i++){
            if(sum[i]!=0){
                flg = 1;
            }
            if(flg){
                printf("%d",sum[i]);
            }
        }
        if(!flg)
            printf("0");
        printf("\n");
        if(n)
            printf("\n");
    }
    return 0;
}
