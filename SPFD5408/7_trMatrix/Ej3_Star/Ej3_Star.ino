#include <SPFD5408_Adafruit_GFX.h>    // Core graphics library
#include <SPFD5408_Adafruit_TFTLCD.h> // Hardware-specific library
#include <BasicLinearAlgebra.h>
#include <Robotic2Duino.h>

//Arduino UNO Pin Definition 
#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0
#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

// Assign human-readable names to some common 16-bit color values:
#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

//Declaracion objeto TFT
Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

int width, height;

//Rotation Matrix
Pose2D P(0,0,0);

void setup() {
  Serial.begin(9600);
  tft.begin(0x9341); // SDFP5408

  tft.setRotation(0); 
  tft.fillScreen(WHITE);

  tft.setTextSize(2);
  tft.setTextColor(BLACK);
  
  width = tft.width();
  height = tft.height();

  P.move(se2(width/4, height/2,0));
  trplot(P.m,40,BLACK, '0',0);

  int l = 45;
  float angle = 144;
  
  for (int i = 0; i<15; i++){
  
    float x0 = P.m(0,2);
    float y0 = P.m(1,2);
    P.move(se2(l,0 ,angle));
    //trplot(P.m,40,GREEN, ' ',0);
    Serial.print("Pose: ");
    Serial << P.m;
    Serial.println();
    float xf = P.m(0,2);
    float yf = P.m(1,2);
    tft.drawLine(x0, y0, xf , yf , BLACK);
  }
}


void loop() {

}

void trplot(Matrix<3, 3, float> T, int size, uint16_t color,char label, int dir ){

  int inv_x = 1;
  int inv_y = 1;
  if ((dir == 1 ) || (dir == 2)){
    inv_y = -1;
  }

  if ((dir == 2 ) || (dir == 3)){
    inv_x = -1;
  }
      
  tft.drawLine(T(0,2), T(1,2), (T(0,2) + (inv_x)*T(0,0)*size) , (T(1,2) + (inv_y)*T(1,0)*size), color);
  tft.drawLine(T(0,2), T(1,2), (T(0,2) + (inv_x)*T(0,1)*size) , (T(1,2) + (inv_y)*T(1,1)*size) , color);
  tft.drawChar((T(0,2) + (inv_x)*T(0,0)*size- 5), T(1,2) + (inv_y)*T(1,0)*size -15,'x',color,WHITE, 1);
  tft.drawChar((T(0,2) + (inv_x)*T(0,1)*size-15), T(1,2) + (inv_y)*T(1,1)*size -5,'y',color,WHITE, 1);
  tft.drawChar(T(0,2)-5, T(1,2) + -5,label,color,WHITE, 1);
}

//repeticiones, lado linea, angulo 
void rotateLine(){
  
  };
/*void rotateLine(uint8_t n, float star_l, float angle){
  int width=160;
  int height=128;
  float v1[N];      // This is a the first point of the square
  float v2[N];      // This is a the second point of the square
 
  float w1[N];
  float w2[N];
  for (int i = 0; i < N; i++){
    w1[i] = 0.0f;  
    w2[i] = 0.0f; 
  }
  
  float v_p[N];
  v_p[0]=0;
  v_p[1]=0;
  v_p[2]=1;
  
  float v_x[N];
  v_x[0]=30;
  v_x[1]=0;
  v_x[2]=1;
  
  float v_y[N];
  v_y[0]=0;
  v_y[1]=30;
  v_y[2]=1;
  
  float aux_p[N];
  float aux_x[N];
  float aux_y[N];
  
  v1[0]=0;
  v1[1]=0;
  v1[2]=1;
  
  v2[0]=0;
  v2[1]=star_l;
  v2[2]=1;
  
  float tx = width/2;
  float ty = height/2-star_l/2;
  float angle_i = 72;
  float ang2rad=360/PI;
  
  rot[0][0]= cos(angle_i/ang2rad);
  rot[0][1]= sin(angle_i/ang2rad);
  rot[0][2]= tx;
  rot[1][0]= -sin(angle_i/ang2rad);
  rot[1][1]= cos(angle_i/ang2rad);
  rot[1][2]= ty;
*/
  /*rot[0][0]= 0;
  rot[0][1]= 0;
  rot[0][2]= tx;
  rot[1][0]= 0;
  rot[1][1]= 0;
  rot[1][2]= ty;*/
  
  //Debug Axis
  /*Matrix.Multiply((float*)rot,(float*)v_p,N,N,1,(float*)aux_p);
  tft.drawLine(tx,ty,aux_p[0],aux_p[1],0xFFFF);
  Matrix.Multiply((float*)rot,(float*)v_x,N,N,1,(float*)aux_x);
  tft.drawLine(aux_p[0],aux_p[1],aux_x[0],aux_x[1],0x07E0); // Green Color
  Matrix.Multiply((float*)rot,(float*)v_y,N,N,1,(float*)aux_y);
  tft.drawLine(aux_p[0],aux_p[1],aux_y[0],aux_y[1],0xF800); // Blue Color*/
/*
  //Inicializacion del punto
  Matrix.Multiply((float*)rot,(float*)v2,N,N,1,(float*)w2);
  
  //Para realizar este ejercicio moviendo el punto central, tenemos que establecer una nueva referencia, desde la cual se va a mover, en lugar de utilizar el origen de la esquina superior izquierda.
  int divs = n;
  Serial.print("Angulo: \t ");
  Serial.println(angle);
    
  for (int i=0; i<divs; i++) {
    float ang2rad=360/(2*PI);
    
    
    aux[0][0]= cos(angle/ang2rad);
    aux[0][1]= sin(angle/ang2rad);
    aux[0][2]= 0;
    aux[1][0]= -sin(angle/ang2rad);
    aux[1][1]= cos(angle/ang2rad);
    aux[1][2]= star_l;
    
    Matrix.Multiply((float*)rot,(float*)aux,N,N,N,(float*)newMatrix);
    w1[0]=w2[0];
    w1[1]=w2[1];
    w1[2]=w2[2];
    Matrix.Multiply((float*)newMatrix,(float*)v2,N,N,1,(float*)w2);
    tft.drawLine(w1[0],w1[1],w2[0],w2[1],0xFFFF);

    rot[0][0]= newMatrix[0][0];
    rot[0][1]= newMatrix[0][1];
    rot[0][2]= newMatrix[0][2];
    rot[1][0]= newMatrix[1][0];
    rot[1][1]= newMatrix[1][1];
    rot[1][2]= newMatrix[1][2];
    
    //Debug Axis
    Matrix.Multiply((float*)rot,(float*)aux,N,N,N,(float*)newMatrix);
    aux_p[0]=w2[0];
    aux_p[1]=w2[1];
    aux_p[2]=w2[2];
    Matrix.Multiply((float*)newMatrix,(float*)v_p,N,N,1,(float*)aux_p);
    //tft.drawLine(tx,ty,aux_p[0],aux_p[1],0xFFFF);
    Matrix.Multiply((float*)newMatrix,(float*)v_x,N,N,1,(float*)aux_x);
    tft.drawLine(aux_p[0],aux_p[1],aux_x[0],aux_x[1],0x07E0); // Green Color
    Matrix.Multiply((float*)newMatrix,(float*)v_y,N,N,1,(float*)aux_y);
    tft.drawLine(aux_p[0],aux_p[1],aux_y[0],aux_y[1],0x001F); // Blue Color
    
    //Matrix.Print((float*)rot,N,N,"rot");
    //Matrix.Print((float*)w,N,1,"w");
    
  }
}
*/

