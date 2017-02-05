#include <SPI.h>  
#include <Adafruit_GFX.h>     // Core graphics library
#include <Adafruit_ST7735.h>  // Hardware-specific library
#include <Robo2Duino.h>       // Robotic Matrix transformations library

// These definitions map display functions to the Adduino UNO display header pins
#define sclk 15
#define mosi 16
#define cs   7
#define dc   6
#define rst  5
    
// Assign human-readable names to some common 16-bit color values:
  #define BLACK 0x0000
  #define WHITE 0xFFFF
  #define BLUE 0x001F
  #define GREEN   0x07E0
  #define YELLOW 0xFFE0 
  #define RED     0xF800
  #define BROWN 0x99AA66
  #define CYAN    0x07FF
  #define MAGENTA 0xF81F

//Declaracion objeto TFT
Adafruit_ST7735 tft = Adafruit_ST7735(cs, dc, rst);

int width, height;

void setup() {
  Serial.begin(9600);
  tft.initR(INITR_BLACKTAB); // Tab Label for ST7735 TFT Screen (INITR_GREENTAB 0x0, INITR_REDTAB 0x1, INITR_BLACKTAB 0x2)

  tft.setRotation(0); 
  tft.fillScreen(WHITE);

  tft.setTextSize(2);
  tft.setTextColor(BLACK);
  
  width = tft.width();
  height = tft.height();

  Matrix<3,3,float> T = se2(width/2,height/2,30);
  Serial << T;
  Serial.println();
  
  Point2D p(-50,0); 
  p.move(T); 
  
  tft.drawLine(T(0,2), T(1,2), p.x , p.y , BLUE);
  serialPoint(p);

  float side = 200;

  //Inversion de los ejes de dibujo. Por defecto adelante es el eje positivo de x e izquierda es el eje positivo de y
  //p.setInv(0,1);

  //Definicion de punto inicial y final de la recta
  Point2D p0 = p;
  Point2D pf ;
  p.move(-50,100);
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

