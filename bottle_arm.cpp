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
  double angle[];
  b = sqrt(x*x+y*y);
  double tran[];
  tran[1] = pow(x,2)/pow(z,2);
  tran[2] = 2*(b*b+c*c-a*a-(2*z*pow(c,2))/z);
  tran[3] = sqrt(tran[1] - tran[2]);
  double x1 = 0.5*(x/z+tran[3]);
  double y1 = sqrt(c*c-x1*x1);
  angle[1] = asin(y1/x1)*180/3.14;
  tran[4] = sin(angle[1])*cos(x/z)+cos(angle[1])*sin(x/z);
  tran[5] = cos(angle[1])*cos(x/z)-sin(angle[1])*sin(x/z);
  angle[2] = asin(tran[4]*cos);
  
  
  
}
