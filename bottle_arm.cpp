#include "bottle_arm.h"
#include "math.h"

bottle::bottle1()
{
}
void bottle1::length(double a,double c)
{
}
void bottle1::coordinate(double x,double y,double z)
{
  double b;
  b = sqrt(x*x+y*y);
  double x1 = (x/z+sqrt(pow(x,2)/pow(z,2)-2*(b*b+c*c-a*a-(2*z*pow(c,2))/z))/2;
  double y1 = sqrt(c*c-x1*x1);
  
}
