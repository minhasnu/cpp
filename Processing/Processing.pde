

float[][] squares;
float a,b,A,B,scale,distance,colour,cx,cy;
int i;
int iter ;
float[] distArray;
float[] distDiff;
int noPoints;
float velocity;
float decayPara;

void setup() {
    size(1000,1000);
    background(0);
    iter = 5;
    squares = new float[iter][2];
    distArray = new float[iter];
    distDiff = new float[iter-1];
    a = -0.8;
    b = 0.6;
    A = B = 0;
    i = 0;
    scale = 200;
    velocity = 0;
    //noLoop();
    
}


void draw() {
  noPoints = 0;

  while(noPoints < 10000){
    //background(0);
    stroke(255);
    line(0, height/2, width, height/2);
    line(width/2, 0, width/2, height);
     //a = -(mouseX-width/2)/scale;
     //b = -(mouseY-height/2)/scale;
    a = random(-2,2);
    b = random(-2,2);
    //find square + c
    cx = a;
    cy = b;
    squares[0][0] = a;
    squares[0][1] = b;
    distArray[0] = sqrt(sq(a)+sq(b));
    velocity = 0;
      for(i = 1; i < iter; i++) {
          A = sq(a) - sq(b) + cx;  
          B = 2*a*b + cy;
          squares[i][0] = A;
          squares[i][1] = B;
          distArray[i] = sqrt(sq(A)+sq(B));
          distDiff[i-1] = distArray[i] - distArray[i-1];
          velocity += distDiff[i-1];
          
          
          
          a = A;
          b = B;
      }
      velocity = velocity/(iter-1);
      //println(velocity);
         
           pushMatrix();
           translate(width/2,height/2);
           distance = sqrt(sq(squares[iter-1][0])+sq(squares[iter-1][1]));
          
           
           if(distance < 2){
               colour = map(distance,0,2,0,255);
               println(velocity);
               decayPara = map(velocity,-2,2,0,255);

               //println(colour);
               //stroke(decayPara,decayPara+colour,255-colour);
               stroke(decayPara);
               point(scale*squares[0][0],scale*squares[0][1]);  
               noPoints++;
               
           }else {
             //println("out");
             //stroke(225,0,0);
             //point(scale*squares[0][0],scale*squares[0][1]);
           
           }
           
           popMatrix();
    }
         
    
}
