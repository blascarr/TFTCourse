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
Matrix<3,3,float> Trans;
Matrix<3,3,float> Rot;
Matrix<3,3,float> C;
Matrix<3,3,float> D;

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
  
  Trans = trans2tr (x,y);
  Serial.print(" Trans: ");
  Serial << Trans;
  Serial.println();
  trplot(Trans,40, BLACK,0);
  
  Rot = rot2tr(angle);
  Serial.print(" Rot: ");
  Serial << Rot;
  Serial.println();
  trplot(Rot,40, YELLOW,0);
  //Si se cambia el orden del producto nos crea una matriz diferente
  //No es lo mismo aplicar una rotacion primero y despues desplazar, que un desplazamiento y despues rotar.
  //Por defecto, siempre se traslada primero, y despues rotamos. Por lo que la ultima matriz guardada esta dispuesta en una nueva orientacion.
  
  Matrix<3,3> A = Trans*Rot;
  Serial.print(" A = Trans*Rot: ");
  Serial << A;
  Serial.println();
  trplot(A,40, GREEN,0);
  
  //Cambiamos el orden de transformacion
  Matrix<3,3> B = Rot*Trans;
  Serial.print(" B = Rot*Trans: ");
  Serial << B;
  Serial.println();
  trplot(B,40, BLUE,0);
  
  //Matriz de comprobacion
  C = se2(x,y,angle);
  Serial.print(" C: se2(x,y,angle) ");
  Serial << C;
  Serial.println();

  //Uso de la clase Pose2D
  Pose2D D (x,y,angle);
  Serial.print(" Pose 2D --> D: ");
  Serial << D.m;
  Serial.println();
}

void loop() {
  
}

void trplot(Matrix<3, 3, float> T, int size, uint16_t color, int dir ){

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
  
}
