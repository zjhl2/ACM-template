float
32   位
6~7  位有效数字
-3.4*10^38～+3.4*10^38   范围
double
64
15~16
-1.7*10^-308~1.7*10^308
long double
128/
18~19
-1.2*10^-4932~1.2*10^4932


当数据范围大于1e12的计算几何绝对是高精度

double 尾数52位，可以用int_52来判断精度问题，
        意思是double可以精确表示1e15以内的整数