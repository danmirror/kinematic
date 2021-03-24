#include <stdio.h>
#include<math.h>

int main(){
    //  Length of links in cm
    float Length_a= 5.2;
    float Length_b = 6.9;
    float Length_c = 6.8;
    float pi = 3.14159265359;

    // #Desired Position of End effector
    int px = 10;
    int  py = 3;

    int angle = 90;

    //initial angle
    float angle1;
    float angle2;
    float angle3;
    float angleSum; 

    float radAngleSum;
    float radAngle1;
    float rad1;
    float radAngle2;
    float rad2;

    float wx,wy ;
    float delta,theta_1,theta_2 ;
    
    //degre to radian
    radAngleSum = (angle*pi)/180;

    // Equations for Inverse kinematics
    wx =px - Length_c*cos(radAngleSum);
    wy = py - Length_c*sin(radAngleSum);
    printf("%f \n", wx);
    printf("%f \n \n", wy);
    delta = pow(wx,2) + pow(wy,2);

    radAngle2 =(delta -pow(Length_a,2) - pow(Length_b,2)) /(2*Length_a*Length_b);
    rad2 = sqrt(1-pow(radAngle2,2)) ; //elbow down
    theta_2 = atan2(rad2, radAngle2);

    rad1= ((Length_a+Length_b* radAngle2 )*wy - Length_b*rad2*wx)/delta;
    radAngle1=  ((Length_a+Length_b* radAngle2 )*wx + Length_b*rad2*wy )/delta;
    theta_1 = atan2(rad1,radAngle1);

    angle1= (theta_1*180)/pi;
    angle2= (theta_2*180)/pi;
    angle3= angle-angle1-angle2;

    printf("%f \n ", angle1);
    printf("%f \n", angle2);
    printf("%f \n", angle3);
}