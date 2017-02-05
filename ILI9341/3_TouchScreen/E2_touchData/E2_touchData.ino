#include <Adafruit_GFX.h>    // Core graphics library
#include <SPI.h>
#include <Wire.h>      // this is needed even tho we aren't using it
#include <Adafruit_ILI9341.h> // Hardware-specific library
#include <Adafruit_STMPE610.h>  // Touch library

// These are the pins for the shield!
#define YP A1  // must be an analog pin, use "An" notation!
#define XM A2  // must be an analog pin, use "An" notation!
#define YM 7   // can be a digital pin
#define XP 6   // can be a digital pin

#define MINPRESSURE 10
#define MAXPRESSURE 1000
#define MINX_VALUE 20
#define MINY_VALUE 20

short TS_MINX=50;
short TS_MINY=1000;
short TS_MAXX=500;
short TS_MAXY=1002;

// The STMPE610 uses hardware SPI on the shield, and #8
#define STMPE_CS 8

// The display also uses hardware SPI, plus #9 & #10
#define TFT_CS 10
#define TFT_DC 9

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


// For better pressure precision, we need to know the resistance
// between X+ and X- Use any multimeter to read it
// For the one we're using, its 300 ohms across the X plate
Adafruit_STMPE610 ts = Adafruit_STMPE610(STMPE_CS);

//Declaracion objeto TFT
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);


int width, height;

void setup(void) {
  Serial.begin(9600);

  tft.begin();  // Begin ILI9341
  tft.setRotation(0); 
  
  width = tft.width() - 1;
  height = tft.height() - 1;

  Serial.println(F("TFT LCD test"));

  tft.fillScreen(YELLOW);
}

void loop(void) {

  //Para obtener los datos de presion en la pantalla tactil se ha de utilizar la clase TSPoint
  //TSPoint es el detector de presion sobre cada uno de los pixeles y que se activa en el momento que la pantalla detecta una diferencia de presion
  TS_Point p = ts.getPoint();

  //Este objeto nos permite conocer 3 datos. Las coordenadas x e y donde se ejerce la presion y la presion aplicada sobre ella.
  //Obtenemos la presion que se encuentra entre los dos limites definidos anteriormente

  //En la libreria SPFD5408 se ha de sustituir el valor de y por el de z
  
  //Mostramos por monitor serie los valores de las coordenadas donde se ejerce presion
  if (p.y > MINPRESSURE && p.y < MAXPRESSURE && p.x > MINX_VALUE && p.z > MINY_VALUE ) {
     Serial.print("X = "); Serial.print(p.x);
     Serial.print("\tY = "); Serial.print(p.z);
     Serial.print("\tPressure = "); Serial.println(p.y);
     
  }// a point object holds x y and z coordinates

}
