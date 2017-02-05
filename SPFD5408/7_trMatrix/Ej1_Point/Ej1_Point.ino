#include <SPFD5408_Adafruit_GFX.h>    // Core graphics library
#include <SPFD5408_Adafruit_TFTLCD.h> // Hardware-specific library
#include <BasicLinearAlgebra.h>
#include <Robo2Duino.h>

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

void setup() {
  Serial.begin(9600);
  tft.begin(0x9341); // SDFP5408

  tft.setRotation(0); 
  tft.fillScreen(WHITE);

  tft.setTextSize(2);
  tft.setTextColor(BLACK);
  
  width = tft.width();
  height = tft.height();

  Matrix<3,3,float> T = se2(width/2,height/2,30);
  Serial << T;
  Serial.println();
  
  Point2D p(30,0); 
  p.move(T); 
  
  tft.drawLine(T(0,2), T(1,2), p.x , p.y , BLUE);
  serialPoint(p);

  float side = 40;

  //Inversion de los ejes de dibujo. Por defecto adelante es el eje positivo de x e izquierda es el eje positivo de y
  //p.setInv(0,1);

  //Definicion de punto inicial y final de la recta
  Point2D p0 = p;
  Point2D pf ;
  p.move(20,20);
  pf = p; 
  serialPoint(pf);
  tft.drawLine(p0.x, p0.y, pf.x , pf.y , BLACK);

  p0=pf;
  pf.fwd(side); 
  serialPoint(pf);
  tft.drawLine(p0.x, p0.y, pf.x , pf.y , BLACK);

  p0=pf;
  pf.right(side); 
  serialPoint(pf);
  tft.drawLine(p0.x, p0.y, pf.x , pf.y , BLACK);

  p0=pf;
  pf.back(side); 
  serialPoint(pf);
  tft.drawLine(p0.x, p0.y, pf.x , pf.y , BLACK);

  p0=pf;
  pf.left(side); 
  serialPoint(pf);  
  tft.drawLine(p0.x, p0.y, pf.x , pf.y , BLACK);
}


void loop() {

}

void serialPoint(Point2D p){
  Serial.print("Coordenada x: ");
  Serial.print(p.x);
  Serial.print(" Coordenada y: ");
  Serial.println(p.y);
  Serial.println();
}

