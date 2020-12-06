import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import peasy.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class mandel extends PApplet {

//<>// //<>//


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

public void setup() {
  
  
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




public void draw() {
  background(0);
  n = 0;
     dx = (3-(3.0f/1000)*cam.getPosition()[2])/2;
     dy = (2-(2.0f/1000)*cam.getPosition()[2])/2;
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

   


public class mandelPlot extends Thread  {
  float xLower, yLower, xUpper, yUpper;
  int bufferSize;
   float[] outputhue ;
  float[] outputdecay;


 
  
  mandelPlot(float xl,float xu,float yl,float yu,int bs){
    this.xLower = xl;
    this.xUpper = xu;
    this.yLower = yl;
    this.yUpper = yu;
    this.bufferSize = bs;
    this.outputhue =  new float[bs+1000];
    this.outputdecay = new float[bs+1000];
    
    
  }




  public void plotIt() {
    //outputhue = new float[bufferSize];
    //outputdecay = new float[bufferSize];
       n = 0;
       w = xUpper-xLower+1;
    for (ii = xLower; ii <= xUpper; ii = ii + w/sqrt(bufferSize)) {

      for (jj = yLower; jj <= yUpper; jj = jj + w/sqrt(bufferSize)) {

        n++;
        hue = outputhue[n];
        decayPara = outputdecay[n];
        colorMode(HSB, 255, 255, 255);
        stroke(hue, 225, decayPara);

        //pushMatrix();
        // translate(width/2, height/2);
        //point(scale*ii, scale*jj,decayPara/10);  
        point(scale*ii, scale*jj);  

       // popMatrix();
      }
    }
  }




 public void run() {
   
 
  


      w = xUpper-xLower+1;
    for (ii = xLower; ii <= xUpper; ii = ii + w/sqrt(bufferSize)) {

      for (jj = yLower; jj <= yUpper; jj = jj + w/sqrt(bufferSize)) {


        n++;
        a = ii;
        b = jj;
        //find square + c
        cx = a;
        cy = b;

        dist = mag(a, b);
        boolmaxIter = false;
        maxIter = 0;
        for (i = 1; i < iter; i++) {
          A = sq(a) - sq(b) + cx;  
          B = 2*a*b + cy;
          dist = mag(A, B);
          distDiff = dist - prevDist;
          prevDist = dist;
          velocity += distDiff;

          a = A;
          b = B;

          if (dist < 2 && i == (iter-1)) 
            maxIter = i;
          if (dist > 2 && boolmaxIter == false) {
            maxIter = i;
            boolmaxIter = true;
            break;
          }
        }
    velocityAvg = velocity/(iter-1);
    hue = map(maxIter, 0, iter, 0, 225);
    decayPara = map(abs(velocityAvg), 0.00001f, 0.1f, 0, 255);
    if(n>bufferSize)
    println(n);
   outputhue[n] = hue;
   outputdecay[n] = decayPara;
      }
    }
  }
}
  public void settings() {  size(900, 600, P3D); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "mandel" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
