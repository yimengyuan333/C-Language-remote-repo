#include<stdio.h>
#include<math.h>

struct rational
{
    int numerator;
    int denominator;
};

//还得先写个求最小公倍数的函数。
int explore_lcm(int a,int b){
    int max = a > b ? a : b;
    while(1){
        if(max % a == 0 && max % b == 0)
            return max;
        max++;
    }
}

int git_numberator(struct rational f){
    return f.numerator;
}

int git_deminator(struct rational f){
    return f.denominator;
}

struct rational fractions_add(struct rational f1,struct rational f2){
    int numberator_result = 0;
    int denominator_result = 0;
    
    if(f1.denominator == f2.denominator){
        numberator_result = f1.numerator + f2.numerator;
        denominator_result = f1.denominator;
        struct rational R = {numberator_result, denominator_result};
        return R;
    }

    else if(f1.denominator != f2.denominator){
        int lcm = explore_lcm(f1.denominator, f2.denominator);
        numberator_result = f1.numerator * (lcm / f1.denominator) + f2.numerator * (lcm / f2.denominator);
        denominator_result = lcm;
        struct rational R = {numberator_result, denominator_result};
        return R;
    }
}

struct rational fractions_sub(struct rational f1,struct rational f2){
    int numberator_result = 0;
    int denominator_result = 0;
    
    if(f1.denominator == f2.denominator){
        numberator_result = f1.numerator - f2.numerator;
        denominator_result = f1.denominator;
        struct rational R = {numberator_result, denominator_result};
        return R;
    }

    else if(f1.denominator != f2.denominator){
        int lcm = explore_lcm(f1.denominator, f2.denominator);
        numberator_result = f1.numerator * (lcm / f1.denominator) - f2.numerator * (lcm / f2.denominator);
        denominator_result = lcm;
        struct rational R = {numberator_result, denominator_result};
        return R;
    }
}

struct rational fractions_mul(struct rational f1,struct rational f2){
    int numberator_result = 0;
    int denominator_result = 0;
    numberator_result = f1.numerator * f2.numerator;
    denominator_result = f1.denominator * f2.denominator;
    struct rational R = {numberator_result,denominator_result};
    return R;
}

struct rational fractions_div(struct rational f1,struct rational f2){
    int numberator_result = 0;
    int denominator_result = 0;
    struct rational af_f2 = {f2.denominator,f2.numerator};
    return fractions_mul(f1,af_f2);
}

int main(void){
    struct rational f1 = {1,2};
    struct rational f2 = {1,3};
    printf("第一个分数的分子是%d，分母是%d。\n",git_numberator(f1),git_deminator(f1));
    printf("第二个分数的分子是%d，分母是%d。\n",git_numberator(f2),git_deminator(f2));
    struct rational result_add = fractions_add(f1,f2);
    printf("这两个分数的和是：%d/%d 。\n",result_add.numerator,result_add.denominator);
    struct rational result_sub = fractions_sub(f1,f2);
    printf("这两个分数的差是：%d/%d 。\n",result_sub.numerator,result_sub.denominator);
    struct rational result_mul = fractions_mul(f1,f2);
    printf("这两个分数的积是：%d/%d 。\n",result_mul.numerator,result_mul.denominator);
    struct rational result_div = fractions_div(f1,f2);
    printf("这两个分数的商是：%d/%d 。\n",result_div.numerator,result_div.denominator);
    return 0;
}