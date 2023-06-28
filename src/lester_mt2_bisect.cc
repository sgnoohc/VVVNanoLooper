#include "lester_mt2_bisect.h"

namespace Lester {

bool ellipsesAreDisjoint(const EllipseParams & e1, const EllipseParams & e2){
     if (e1==e2){
	 return false;
     }
     const double coeffLamPow3 = e1.det;
     const double coeffLamPow2 = e1.lesterFactor(e2);
     const double coeffLamPow1 = e2.lesterFactor(e1);
     const double coeffLamPow0 = e2.det;

     if (fabs(coeffLamPow3) >= fabs(coeffLamPow0)) {
       return __private_ellipsesAreDisjoint(coeffLamPow3, coeffLamPow2, coeffLamPow1, coeffLamPow0);
     }
     else{
       return __private_ellipsesAreDisjoint(coeffLamPow0, coeffLamPow1, coeffLamPow2, coeffLamPow3);
     }
}

bool __private_ellipsesAreDisjoint(const double coeffLamPow3, const double coeffLamPow2, const double coeffLamPow1, const double coeffLamPow0) {

  if(coeffLamPow3==0){
    throw 1;
  }

  const double a = coeffLamPow2 / coeffLamPow3;
  const double b = coeffLamPow1 / coeffLamPow3;
  const double c = coeffLamPow0 / coeffLamPow3;

#ifdef LESTER_DEEP_FIDDLE
  {
    const double thing1 = -3.0*b + a*a;
    const double thing2 = -27.0*c*c + 18.0*c*a*b + a*a*b*b - 4.0*a*a*a*c - 4.0*b*b*b;
    std::cout
      << (thing1>0) << " && " << (thing2>0) << " && [[ " << (a>=0) << " " << (3.0*a*c + b*a*a - 4.0*b*b<0)  << " ] or "
      << "[ " << (a< 0)   << " ] =("<< ((a >= 0 /*&& thing1 > 0*/ && 3.0*a*c + b*a*a - 4.0*b*b< 0 /*&& thing2 > 0*/) ||
                                 (a <  0 /*&& thing1 > 0*/                                 /*&& thing2 > 0*/)) << ")] " << (
          ( (a >= 0 && thing1 > 0 && 3.0*a*c + b*a*a - 4.0*b*b< 0 && thing2 > 0) ||
                                 (a <  0 && thing1 > 0                                 && thing2 > 0))

          ) << std::endl;
  }
#endif

  const double thing1 = -3.0*b + a*a;
  if (thing1<=0) return false;
  const double thing2 = -27.0*c*c + 18.0*c*a*b + a*a*b*b - 4.0*a*a*a*c - 4.0*b*b*b;
  if (thing2<=0) return false;

  // ans true means ellipses are disjoint:
  const bool ans = ( (a >= 0 /*&& thing1 > 0*/ && 3.0*a*c + b*a*a - 4.0*b*b< 0 /*&& thing2 > 0*/) ||
                     (a <  0 /*&& thing1 > 0*/                                 /*&& thing2 > 0*/));
  return ans;

}

}

void myversion(){

  std::cout << "Version is : 2014_11_13" << std::endl;

}

double MT(double px1, double px2, double py1, double py2, double m1 , double m2){
  double E1 = sqrt(px1*px1+py1*py1+m1*m1);
  double E2 = sqrt(px2*px2+py2*py2+m2*m2);
  double Msq = (E1+E2)*(E1+E2)-(px1+px2)*(px1+px2)-(py1+py2)*(py1+py2);
  if (Msq < 0) Msq = 0;
  return sqrt(Msq);
}

std::pair <double,double>  ben_findsols(double MT2, double px, double py, double visM, double Ma, double pxb, double pyb, double metx, double mety, double visMb, double Mb){

  std::pair <double,double> sols;

  double Pt = sqrt(px*px+py*py);
  double E = sqrt(Pt*Pt+visM*visM);
  double M = MT2;
  double E2 = E*E;
  double M2 = M*M;
  double M4 = M2*M2;
  double Ma2 = Ma*Ma;
  double Ma4 = Ma2*Ma2;
  double px2 = px*px;
  double py2 = py*py;
  double px4 = px2*px2;
  double py4 = py2*py2;
  double py3 = py2*py;
  double E4 = E2*E2;
  double TermA = E2*px-M2*px+Ma2*px-px2*px-px*py2;
  double TermB = -2.*px*py;
  double TermSqy0 = E4*E2-2.*E4*M2-2.*E4*Ma2-2.*E4*px2-2.*E4*py2+E2*M4-2.*E2*M2*Ma2+2.*E2*M2*px2+2.*E2*M2*py2+E2*Ma4+2.*E2*Ma2*px2-2.*E2*Ma2*py2+E2*px4+2.*E2*px2*py2+E2*py4;
  double TermSqy1 = -4.*E4*py+4.*E2*M2*py-4.*E2*Ma2*py+4.*E2*px2*py+4.*E2*py3;
  double TermSqy2 = -4.*E4+4.*E2*px2+4.*E2*py2; 

  double myx = 0.;
  double myy = 0.;
  if (TermSqy1*TermSqy1-4.*TermSqy0*TermSqy2 < 0){

  }
  else{
    double sol1 = (-TermSqy1 - sqrt(TermSqy1*TermSqy1-4.*TermSqy0*TermSqy2))/(2.*TermSqy2);
    double sol2 = (-TermSqy1 + sqrt(TermSqy1*TermSqy1-4.*TermSqy0*TermSqy2))/(2.*TermSqy2);
    double low = sol1;
    double high = sol2;
    if (low > high){
      low = sol2;
      high = sol1;
    }

    double myclose = 99999999.;
    for (double metpy = low; metpy<=high; metpy+=(high-low)/10000.){
      double metpx = -(TermB*metpy+TermA-sqrt(TermSqy0+TermSqy1*metpy+TermSqy2*metpy*metpy))*0.5/(E2-px2);
      double metpx2 = -(TermB*metpy+TermA+sqrt(TermSqy0+TermSqy1*metpy+TermSqy2*metpy*metpy))*0.5/(E2-px2);
      double mt1a = MT(px,metpx,py,metpy,visM,Ma);
      double mt1b = MT(px,metpx2,py,metpy,visM,Ma);
      double metpxb = metx-metpx;
      double metpx2b = metx-metpx2;
      double mt2a = MT(pxb,metpxb,pyb,mety-metpy,visMb,Mb);
      double mt2b = MT(pxb,metpx2b,pyb,mety-metpy,visMb,Mb);
      if (fabs(mt1a-mt2a) < myclose){
        myclose = fabs(mt1a-mt2a);
        myy = metpy;
        myx = metpx;
      }
      if (fabs(mt1b-mt2b) < myclose){
        myclose = fabs(mt1b-mt2b);
        myy = metpy;
        myx = metpx2;
      }
    }
  }

  sols.first = myx;
  sols.second = myy;

  return sols;

}
