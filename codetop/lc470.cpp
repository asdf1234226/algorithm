// 给定方法 rand7 可生成 [1,7] 范围内的均匀随机整数，试写一个方法 rand10 生成 [1,10] 范围内的均匀随机整数。

//rand7 -- [1,2...7]
//rand7调2次 -- [2,3,...14]，其中14只会出现7+7一次，3可以是1+2也可以是2+1,概率不等
//rand7-1  再+ rand7  能从1开始，但是还是解决不了10以下数字出现概率不等的问题
//加减法不适用，要改成乘法
//[0,1,2,3,4,5,6]*7===>[0,7,14...42], 后面集合是{1,2,3,4,5,6,7}
//(rand7()−1)∗7+rand7()

int rand10() {
    int num = (rand7()-1)*7+rand7();
    while (num>10)
    {
        num = (rand7()-1)*7+rand7();
    }
    return num;
    
}