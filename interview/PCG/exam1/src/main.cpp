#include <iostream>
using namespace std;

#define N 9

// 编写一个在1,2 , .... 9(顺序不能变)数字之间插入+或-或什么都不插入，使得计算结果总是100的程序。
// 并输出所有的可能性。例如:1+2+34-5+67-8+9=100

// 思路
// 用数组a存放1～9的整数，用字符数组op存放插入的运算符，op[i]表示在a[i]!!!!!!!之前!!!!!!!!插入的运算符。
// 采用回溯法产生和为100的表达式，op[i]只能取值+、-或者空格（不同于上一个示例，这里是三选一）。设计函数：
// fun(op，sum，prevadd，a，i)
// 其中：sum记录考虑整数a[i]时前面表达式计算的整数和（初始值为a[0]），prevadd记录前面表达式中的一个数值
// （初始值为a[0]），i从1开始到9结束，如果sum=100，得到一个解
void fun(char op[], int sum, int prevadd, int a[], int i) {
	// 扫描完所有位置
    if(i == N) 
    { 
        if(sum == 100) 
        {
			cout << a[0];
			for(int j = 1; j < N; j++) 
            {
				if(op[j] != ' ') 
                	cout << op[j];
				cout << a[j];
			}
			cout << "=100" << endl;
		}
		return;
	}

    // 位置i插入+
	op[i] = '+'; 
	sum += a[i]; // 计算结果
	fun(op, sum, a[i], a, i + 1); // 继续处理下一个位置
	sum -= a[i]; // 回溯

    // 位置i插入-
	op[i] = '-'; 
	sum -= a[i]; // 计算结果
	fun(op, sum, -a[i], a, i + 1); // 继续处理下一个位置 注意 preadd = -a[i] !!!!!!
	sum += a[i]; // 回溯

    // 位置i插入空格，代表和前面的合并
	op[i] = ' '; 
	sum -= prevadd; // 先减去前面的元素值，因为前面的数已经当作一个独立的数加过一次，现在要与当前数合并来加入
    // 计算合并的数
	int cur = prevadd > 0 ? prevadd * 10 + a[i] : prevadd * 10 - a[i];
	sum += cur; // 加上合并的数
	fun(op, sum, cur, a, i + 1); // 继续处理下一个位置
	sum -= cur; // 回溯
	sum += prevadd;  // 回溯
}

int main() {
	int a[N];
	char op[N]; //op[i]表示在位置i插入运算符
	for(int i = 0; i < N; i++)
	 	a[i] = i + 1;
	fun(op, a[0], a[0], a, 1); // 初始把a[0]当作第一个加入的数
	return 0;
}