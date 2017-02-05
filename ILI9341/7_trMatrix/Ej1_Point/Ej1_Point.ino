#include <SPI.h>  
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ILI9341.h> // Hardware-specific library
#include <BasicLinearAlgebra.h>
#include <Robo2Duino.h>

#define TFT_CS   7
#define TFT_DC   6

// Assign human-readable names to some common 16-bit color values:
#define BLACK       0x0000      /*   0,   0,   0 */
#define NAVY        0x000F      /*   0,   0, 128 */
#define DARKGREEN   0x03E0      /*   0, 128,   0 */
#define DARKCYAN    0x03EF      /*   0, 128, 128 */
#define MAROON      0x7800      /* 128,   0,   0 */
#define PURPLE      0x780F      /* 128,   0, 128 */
#define OLIVE       0x7BE0      /* 128, 128,   0 */
#define LIGHTGREY   0xC618      /* 192, 192, 192 */
#define DARKGREY    0x7BEF      /* 128, 128, 128 */
#define BLUE        0x001F      /*   0,   0, 255 */
#define GREEN       0x07E0      /*   0, 255,   0 */
#define CYAN        0x07FF      /*   0, 255, 255 */
#define RED         0xF800      /* 255,   0,   0 */
#define MAGENTA     0xF81F      /* 255,   0, 255 */
#define YELLOW      0xFFE0      /* 255, 255,   0 */
#define WHITE       0xFFFF      /* 255, 255, 255 */
#define ORANGE      0xFD20      /* 255, 165,   0 */
#define GREENYELLOW 0xAFE5      /* 173, 255,  47 */
#define PINK        0xF81F

//Declaracion objeto TFT
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

int width, height;

void setup() {
  Serial.begin(9600);
  tft.begin(); // Begin ILI9341

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

