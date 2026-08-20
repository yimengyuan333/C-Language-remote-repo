#include<stdio.h>
#include<math.h>
double solve_distance(double x1,double y1,double x2,double y2){
    double mid_cal = 0;
    mid_cal = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
    double distance = sqrt(mid_cal);
    return distance;
}
double solve_area(double diameter){
    double area = 0;
    double radius = diameter / 2;
    area = 3.1415926 * radius * radius;
    return area;
}
int main(void){
    double distance = 0;
    double area = 0;
    printf("Please enter two coordinates.\n");
    double x1 = 0;
    double y1 = 0;
    double x2 = 0;
    double y2 = 0;
    scanf("%lf",&x1);
    scanf("%lf",&y1);
    scanf("%lf",&x2);
    scanf("%lf",&y2);
    distance = solve_distance(x1,y1,x2,y2);
    printf("the distance between a1 and a2 is %.3f .\n",distance);
    printf("the area of this circle(diameter is the distance between a1 and a2 .)is %.3f .\n",solve_area(distance));
    return 0;
}