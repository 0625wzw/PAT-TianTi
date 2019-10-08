#include <iostream>
#include <math.h>
/*
L1-006. 连续因子
一个正整数N的因子中可能存在若干连续的数字。例如630可以分解为3*5*6*7，其中5、6、7就是3个连续的数字。给定任一正整数N，要求编写程序求出最长连续因子的个数，并输出最小的连续因子序列。
输入格式：
输入在一行中给出一个正整数N（1<N<231）。
输出格式：
首先在第1行输出最长连续因子的个数；然后在第2行中按“因子1*因子2*……*因子k”的格式输出最小的连续因子序列，其中因子按递增顺序输出，1不算在内。
输入样例：
630
输出样例：
3
5*6*7
*/
/*
分析思路：阶乘的思想，2的31次方是在12到13的阶乘之间，所以我们可以得到
最大的连续数序是12个数字，又因为1不计算在内，故需11个，
我们采用暴力的思想，让他从2，3，4...sqrt(N)开始乘，连着11位，10位，1位
即连续乘11位时分别为：

2 3 4 5 6 7 8 9 10 11 12相乘

3 4 5 6 7 8 9 10 11 12 13相乘

...

连续乘10位时分别为：

2 3 4 5 6 7 8 9 10 11相乘

3 4 5 6 7 8 9 10 11 12相乘

...

一直到只有一位相乘时，
*/
using namespace std;

int main()
{
    long long int N;
    cin >> N;
    long long int prd = 0;
    int start = 0,len = 0;//prd为连续乘积，start为序列开始，len为序列长度
    for (int i = 2; i < sqrt(N); i++){
        prd = 1;
        for (int j = i;j*prd <= N ; j++){
                prd*=j;
            if (N%prd ==0&&j-i+1>len)//如果当前乘积为N的因子且长度大于上次长度，更新长度
            {
                 start = i;
                len = j-i+1;

            }
        }
    }
    if (start == 0){
        start = N;
        len = 1;
    }
    cout << len << endl;
    cout << start;//让序列第一个元素先打出来
    for (int i = start+1; i < start+len;i++)
          cout << "*" <<i;

    return 0;
}
