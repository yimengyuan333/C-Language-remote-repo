#include<stdio.h>
#include<math.h>

int LCM(int a,int b){
    if(a > b){
        for(int i = b;i <= a*b;i++){
            if(i % a ==0&&i % b ==0)
                return i;
        }
    }
    if(b > a){
        for(int i = a;i <= a*b;i++){
            if(i % a ==0&&i % b ==0)
                return i;
        }
    }
    if(a == b)
        return a;
}

struct rational
{
    int numberator;
    int denominator;
}R1,R2;

struct rational rational_add(struct rational r1,struct rational r2){
    int lcm;
    struct rational result;
    if(r1.denominator != r2.denominator){
        lcm = LCM(r1.denominator,r2.denominator);
        r1.numberator = r1.numberator * (lcm/r1.denominator);
        r2.numberator = r2.numberator * (lcm/r2.denominator);
        result.denominator = lcm;
        result.numberator =r1.numberator + r2.numberator; 
    }
    else{
        result.denominator = r1.denominator;
        result.numberator = r1.numberator + r2.numberator;
    }
    return result;
}

struct rational rational_sub(struct rational r1,struct rational r2){
    int lcm;
    struct rational result;
    if(r1.denominator != r2.denominator){
        lcm = LCM(r1.denominator,r2.denominator);
        r1.numberator = r1.numberator * (lcm/r1.denominator);
        r2.numberator = r2.numberator * (lcm/r2.denominator);
        result.denominator = lcm;
        result.numberator = r1.numberator - r2.numberator;
    }
    else{
        result.denominator = r1.denominator;
        result.numberator = r1.numberator - r2.numberator;
    }
    return result;
}

struct rational rational_mux(struct rational r1,struct rational r2){
    struct rational result;
    result.denominator = r1.denominator * r2.denominator;
    result.numberator = r1.numberator * r2.numberator;
    return result;
}

struct rational rational_div(struct rational r1,struct rational r2){
    struct rational result;
    struct rational mid;
    mid.denominator = r2.numberator;
    mid.numberator = r2.denominator;
    result = rational_mux(r1,mid);
    return result;
}