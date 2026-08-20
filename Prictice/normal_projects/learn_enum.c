#include<stdio.h>

enum coordinate_type { RECTANGULAR, POLAR };
struct complex_struct {
	enum coordinate_type t;
	double a, b;
};

struct complex_struct make_from_real_img(double x, double y)
{
	struct complex_struct z;
	z.t = RECTANGULAR;
	z.a = x;
	z.b = y;
	return z;
}

struct complex_struct make_from_mag_ang(double r, double A)
{
	struct complex_struct z;
	z.t = POLAR;
	z.a = r;
	z.b = A;
	return z;
}

double real_part(struct complex_struct z){
    if(z.t != 0){
        printf("为了避免较大误差，仅接受直角坐标构建的复数。\n");
        return;
    }
    return z.a;
}

double imag_part(struct complex_struct z){
    if(z.t != 0){
        printf("为了避免较大误差，仅接受直角坐标构建的复数。\n");
        return;
    }
    return z.b;
}

double magnitude(struct complex_struct z){
    if(z.t == 0){
        printf("为了避免较大误差，仅接受极坐标构建的复数。\n");
        return;
    }
    return z.a;
}

double angle(struct complex_struct z){
    if(z.t == 0){
        printf("为了避免较大误差，仅接受极坐标构建的复数。\n");
        return;
    }
    return z.b;
}
