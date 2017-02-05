#include <SPFD5408_Adafruit_GFX.h>    // Core graphics library
#include <SPFD5408_Adafruit_TFTLCD.h> // Hardware-specific library
#include <BasicLinearAlgebra.h>
#include <Robo2Duino.h>               // Robotic Matrix transformations library

//Arduino UNO Pin Definition 
#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0
#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

// Assign human-readable names to some common 16-bit color values:
#define BLACK   0x0000
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

void setup() {
  Serial.begin(9600);
  
  tft.begin(0x9341); // SDFP5408

  tft.setRotation(0); 
  tft.fillScreen(WHITE);

  width = tft.width();
  height = tft.height();
  
  float x = width/2;
  float y = height/2;
  float angle =30;

  Matrix<3, 3, float> P0 =se2(x,y,0);
  Matrix<3, 3, float> P1 =se2(25,30,15);
  Matrix<3, 3, float> P2 =se2(-15,15,-30);

  //Dibujamos la referencia P0 en el centro
  trplot(P0, 40, BLACK,'0',0);
  delay(500);
  trplot(P0*P1, 40, GREEN,'1',0);
  delay(500);
  trplot(P0*P2, 40, RED,'2',0);
  
  delay(500);
  // El resultado no es el mismo ya que e cmino a seguir depende de rotaciones que deben seguir un orden
  trplot(P0*P1*P2, 40, RED,'P',0);
  trplot(P2*P1*P0, 40, BLUE,'P',0);

  
  //Primer movimiento desde R0 hasta P1
  Pose2D R0 (x,y,30);
  R0.move(P1);
  R0.print();

  //Segundo movimiento desde P1 hasta P2
  R0.move(P2);
  R0.print();

  //Movmiento directo desde R0 hasta P2
  Pose2D G0 (x,y,30);
  G0.move(P1*P2);
  G0.print();

  //El resultado es el mismo. a P2*P1*P0 pero con un angulo girado de 30 grados
  trplot(G0.m, 40, GREEN,'G',0);
  trplot(R0.m, 40, YELLOW,'R',0);
  

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
