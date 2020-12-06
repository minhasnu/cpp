
   


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




  void plotIt() {
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
    decayPara = map(abs(velocityAvg), 0.00001, 0.1, 0, 255);
    if(n>bufferSize)
    println(n);
   outputhue[n] = hue;
   outputdecay[n] = decayPara;
      }
    }
  }
}
