#include <bits/stdc++.h>
using namespace std;

#define PI          acos(-1.0)
#define EPS         1e-6
#define Z(x)        fabs(x)<EPS
#define E(x,y)      Z(x-y)
#define RAD(x)      (x)*PI/180
#define PRE(x)      ((x)==0?n-1:x-1)
#define NEX(x)      ((x)==n-1?0:x+1)
int dcmp(double x) { return x > EPS ? 1: x < -EPS ? -1 : 0; }
struct point {
    double  x,y;
    point(double x=0, double y=0) : x(x), y(y) {}
    point(const point &p) : x(p.x), y(p.y)    {}
    bool operator <  (const point &p) const { return (x<p.x)||(E(x,p.x) && y < p.y );}
    bool operator == (const point &p) const { return E(x,p.x)&&E(y,p.y);    }
    point operator + (const point &p) const { return point(x+p.x , y + p.y);}
    point operator - (const point &p) const { return point(x-p.x , y - p.y);}
    point operator * (double c) const { return point(x*c,y*c);}
    point operator / (double c) const { return point(x/c,y/c);}
    void input(){scanf("%lf %lf",&x,&y);}
};

double dot(point p,point q){ return p.x * q.x + p.y * q.y;}
double cross(point p,point q) {return p.x*q.y - p.y*q.x;}
double sqdist(point p,point q) {return dot(p-q , p-q);}
double dist(point p,point q)  { return sqrt(sqdist(p,q));}
double mag(point p) {return sqrt(p.x*p.x+p.y*p.y);}
double angle(point a,point b) { return acos(dot(a,b)/mag(a)/mag(b));}

// rotate a point cross or CW around the origin
point rotccw90(point p){return point(-p.y,p.x);}
point rotcw90(point p)   {return point(p.y,-p.x);}
point rotccw(point p,double ang) {return point(p.x*cos(ang) - p.y*sin(ang) , p.x*sin(ang) + p.y * cos(ang));}

// project point c onto line through a and b
point PPL (point a,point b,point c){return a + (b-a)* dot(c-a,b-a) / dot(b-a,b-a);}

// project point c onto line segment through a and b
point PPS(point a, point b, point c) {
    double r = dot(b-a,b-a);
    if (fabs(r) < EPS) return a;
    r = dot(c-a, b-a)/r;
    if (r < 0) return a;
    if (r > 1) return b;
    return a + (b-a)*r;
}
// determine if lines from a to b and c to d are parallel or collinear
bool IsLP(point a, point b, point c, point d) {
    return fabs(cross(b-a, c-d)) < EPS;
}

bool IsLC(point a, point b, point c, point d) {
    return IsLP(a, b, c, d)
    && fabs(cross(a-b, a-c)) < EPS
    && fabs(cross(c-d, c-a)) < EPS;
}
// Checks if p lies on the segment connection ab
bool onSegment(point a, point b, point p)
{
    return Z(cross(a-p,b-p)) && dot(a-p,b-p) < 0;
}
// determine if line segment from a to b intersects with
// line segment from c to d
bool SGIN(point a, point b, point c, point d) {
    if (IsLC(a, b, c, d)) {
        if (sqdist(a, c) < EPS || sqdist(a, d) < EPS ||
            sqdist(b, c) < EPS || sqdist(b, d) < EPS) return true;
        if (dot(c-a, c-b) > 0 && dot(d-a, d-b) > 0 && dot(c-b, d-b) > 0)
            return false;
        return true;
    }
    if (cross(d-a, b-a) * cross(c-a, b-a) > 0) return false;
    if (cross(a-c, d-c) * cross(b-c, d-c) > 0) return false;
    return true;
}


point LLIN(point a, point b, point c, point d) {
    b=b-a; d=c-d; c=c-a;
    return a + b*cross(c, d)/cross(b, d);
}

// compute center of circle given three points
point CCC(point a, point b, point c) {
    b=(a+b)/2;
    c=(a+c)/2;
    return LLIN(b, b+rotcw90(a-b), c, c+rotcw90(a-c));
}

//point in polygon(1-Strictly Interior,0-Strictly Exterior
bool PIPoly(const vector<point> &p, point q) {
    bool c = 0;
    for (int i = 0; i < p.size(); i++){
        int j = (i+1)%p.size();
        if (((p[i].y <= q.y && q.y < p[j].y) ||
             (p[j].y <= q.y && q.y < p[i].y)) &&
            q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
            c = !c;
    }
    return c;
}

// determine if point is on the boundary of a polygon
bool POPoly(const vector<point> &p, point q) {
    for (int i = 0; i < p.size(); i++)
        if (sqdist(PPS(p[i], p[(i+1)%p.size()], q), q) < EPS)
            return true;
    return false;
}

// compute intersection of line through points a and b with
// circle centered at c with radius r > 0
vector<point> CLIN(point a, point b, point c, double r) {
    vector<point> ret;
    b = b-a;
    a = a-c;
    double A = dot(b, b);
    double B = dot(a, b);
    double C = dot(a, a) - r*r;
    double D = B*B - A*C;
    if (D < -EPS) return ret;
    ret.push_back(c+a+b*(-B+sqrt(D+EPS))/A);
    if (D > EPS)
        ret.push_back(c+a+b*(-B-sqrt(D))/A);
    return ret;
}

// compute intersection of circle centered at a with radius r
// with circle centered at b with radius R
vector<point> CCIN(point a, point b, double r, double R) {
    vector<point> ret;
    double d = sqrt(sqdist(a, b));
    if (d > r+R || d+min(r, R) < max(r, R)) return ret;
    double x = (d*d-R*R+r*r)/(2*d);
    double y = sqrt(r*r-x*x);
    point v = (b-a)/d;
    ret.push_back(a+v*x + rotccw90(v)*y);
    if (y > 0)
        ret.push_back(a+v*x - rotccw90(v)*y);
    return ret;
}
// p = a + t * (b-a). find t.
double getT(point a, point dir, point p)
{
      if(dcmp(dir.x) == 0) return (p.y - a.y) / dir.y;
      return (p.x - a.x)/ dir.x;
}
// Gives area of a circle sector passing through a,b
double SectorArea(point r, point a, point b, double R)
{
      double ang = angle(a-r,b-r);
      return R*R*ang/2;
}
// Common area of a circle and and a segment(a,b)
double TRICA(point r, point a, point b, double R)
{
      double ra = dist(r, a) , rb = dist(r, b);
      if(ra < R + EPS && rb < R + EPS) return cross(a - r, b - r) / 2;
      if(dcmp(cross(a-r,b-r)) == 0) return 0;
      double rtos = dist(r, PPS(a,b,r));
      if(rtos > R - EPS) return SectorArea(r, a, b, R);
      vector< point > ins = CLIN(a,b,r,R);
      if(ins.size() < 2) return SectorArea(r, a, b, R);

      point ta = ins[0], tb = ins[1];
      double t1 = getT(a, b - a, ta) , t2 = getT(a, b-a, tb);
      if(t1 > t2) swap(ta, tb);

      if(ra < R + EPS) return cross(a - r, tb - r) / 2 + SectorArea(r, tb , b,R);
      if(rb < R + EPS) return cross(ta - r, b - r) / 2 + SectorArea(r , a, ta ,R);
      return cross(ta - r, tb - r) / 2 + SectorArea(r, a, ta, R) + SectorArea(r, tb, b,R);
}
// Simple polygon intersection area with a circle.
double SPICA(vector< point > &p, point r, double R )
{
      double ret = 0;
      int n = p.size();
      for(int i= 0; i < n; i ++) {
            int turn = dcmp(cross(p[i] - r, p[NEX(i)] -  r));
            if(turn > 0 ) ret += TRICA(r, p[i] , p[NEX(i)],R);
            else ret -= TRICA(r,p[NEX(i)], p[i],R);

      }
      return fabs(ret);

}
// This code computes the area or centroid of a (possibly nonconvex)
// polygon, assuming that the coordinates are listed in a clockwise or
// counterclockwise fashion.  Note that the centroid is often known as
// the "center of gravity" or "center of mass".

double ComputeSignedArea(const vector<point> &p) {
    double area = 0;
    for(int i = 0; i < p.size(); i++) {
        int j = (i+1) % p.size();
        area += p[i].x*p[j].y - p[j].x*p[i].y;
    }
    return area / 2.0;
}

double CAR(const vector<point> &p) {
    return fabs(ComputeSignedArea(p));
}
point ComputeCentroid(const vector<point> &p) {
  point c(0,0);
  double scale = 6.0 * ComputeSignedArea(p);
  for (int i = 0; i < p.size(); i++){
    int j = (i+1) % p.size();
    c = c + (p[i]+p[j])*(p[i].x*p[j].y - p[j].x*p[i].y);
  }
  return c / scale;
}

// centroid
point CCN(const vector<point> &p) {
    point c(0,0);
    double scale = 6.0 * ComputeSignedArea(p);
    for (int i = 0; i < p.size(); i++){
        int j = (i+1) % p.size();
        c = c + (p[i]+p[j])*(p[i].x*p[j].y - p[j].x*p[i].y);
    }
    return c / scale;
}

double myAngle(point a,point b)
{
    double ang = angle(a,b);
    if(dcmp(cross(a,b)) >= 0) return ang;
    return 2*PI - ang;
}
// tests whether or not a given polygon (in CW or cross order) is simple
bool IsSimple(const vector<point> &p) {
    for (int i = 0; i < p.size(); i++) {
        for (int k = i+1; k < p.size(); k++) {
            int j = (i+1) % p.size();
            int l = (k+1) % p.size();
            if (i == l || j == k) continue;
            if (SGIN(p[i], p[j], p[k], p[l]))
                return false;
        }
    }
    return true;
}

bool cw(const point &a, const point &b, const point &c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) < 0;
}
vector<point> convexHull(vector<point>& p) {
    int n = (int)p.size();
    if (n <= 1)
        return p;
    sort(p.begin(), p.end());
    int cnt = 0;
    vector<point> q(n * 2);
    for (int i = 0; i < n; q[cnt++] = p[i++])
        for (; cnt >= 2 && !cw(q[cnt - 2], q[cnt - 1], p[i]); --cnt)
            ;
    for (int i = n - 2, t = cnt; i >= 0; q[cnt++] = p[i--])
        for (; cnt > t && !cw(q[cnt - 2], q[cnt - 1], p[i]); --cnt)
            ;
    q.resize(cnt - 1 - (q[0] == q[1]));
    return q;
}
/*==============================================================================*/



// For integer Calculation
struct Pint{
    long long x,y;
    Pint(){}
    Pint(long long x,long long y):x(x),y(y){}
    bool operator<(const Pint &p) const { return x<p.x||(x==p.x&& y<p.y);}
    bool operator==(const Pint &p) const {return x==p.x && y==p.y; }
    Pint operator-(const Pint &p) const { return {x-p.x,y-p.y};           }
};
long long dot(Pint a,Pint b) { return a.x*b.x + a.y*b.y; }
long long cross(Pint a,Pint b) { return a.x*b.y - a.y*b.x;}
bool cw(const Pint &a, const Pint &b, const Pint &c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) < 0;
}
vector<Pint> convexHull(vector<Pint> &p)
{

    int n = (int)p.size();
    if (n <= 1)
        return p;
    sort(p.begin(), p.end());
    int cnt = 0;
    vector<Pint> q(n * 2);
    for (int i = 0; i < n; q[cnt++] = p[i++])
        for (; cnt >= 2 && !cw(q[cnt - 2], q[cnt - 1], p[i]); --cnt)
            ;
    for (int i = n - 2, t = cnt; i >= 0; q[cnt++] = p[i--])
        for (; cnt > t && !cw(q[cnt - 2], q[cnt - 1], p[i]); --cnt)
            ;
    q.resize(cnt - 1 - (q[0] == q[1]));
    return q;
}

double sq(double a) { return a*a; }
using vec = point;
int main() {
	double r,d,h;
	int t,cs = 0;
	cin >> t;
	while(t--) {
		cin >> r >> d >> h;
		double x = sqrt(r*r - sq(r-h));
		double y = sqrt(r*r - sq(r-d));
		double theta = atan(y / (r-d));
		vec ob = vec(r + x, h) - vec(r,r);
		vec oa = rotccw(ob,-2*theta);
		printf("Case %d: %.4lf\n",++cs, (vec(r,r) + oa).y);
	}
}
