//<>// //<>//
import peasy.*;

PeasyCam cam;

float a, b, A, B, scale, hue, cx, cy;
int i, j, n;

float ii, jj;
int iter ;
float dist, prevDist;
float distDiff;
int noPoints;
float w,dx,dy,xTrans,yTrans;
float velocity, velocityAvg;
float decayPara;

float[][] ouputValues;
int bufferNo = 100000;
boolean boolmaxIter;
int maxIter;
mandelPlot m = new mandelPlot(-2,1,-1,1,bufferNo);
 
 //xUpper = 1;
 //   xLower = -2;
 //   yUpper = 1;
 //   yLower = -1;

void setup() {
  
  size(900, 600, P3D);
  //size(1800, 1200, P3D);

  cam = new PeasyCam(this, 1000);
  cam.lookAt(-300,0,0);
  cam.setMinimumDistance(-10000);
  cam.setMaximumDistance(2000);
  background(0);
  boolmaxIter = false;


  iter = 50;




  a = 0;
  b = 0;
  A = B = 0;
  i = 0;
  n = 0;


  scale = height;
  velocity = 0;
  //m.findValues();
  
  
}




void draw() {
  background(0);
  n = 0;
     dx = (3-(3.0/1000)*cam.getPosition()[2])/2;
     dy = (2-(2.0/1000)*cam.getPosition()[2])/2;
     //xTrans =(cam.getPosition()[2]/3000)*(cam.getPosition()[0]+300);
     //yTrans =(cam.getPosition()[2]/3000)*cam.getPosition()[1];
     xTrans = (cam.getPosition()[0]+300)/600 ;
     yTrans = (cam.getPosition()[1])/600 ;
 
 // println(cam.getPosition());
  m.xLower = -2+dx + xTrans;
  m.xUpper = 1-dx +  xTrans;
  m.yLower = -1+dy + yTrans;
  m.yUpper = 1-dy +yTrans;
  //m.xLower = -2+xTrans;
  //m.xUpper =  1+xTrans;
  //m.yLower = -1+yTrans;
  //m.yUpper =  1+yTrans;
   m.run();
   m.plotIt();
  // m.start();

     

 
 
    
  


}
