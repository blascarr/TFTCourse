// Touch screen library with X Y and Z (pressure) readings as well
// as oversampling to avoid 'bouncing'

//#include <stdint.h>
#include <SPFD5408_Adafruit_GFX.h>    // Core graphics library
#include <SPFD5408_Adafruit_TFTLCD.h> // Hardware-specific library
#include <SPFD5408_TouchScreen.h>

// These are the pins for the shield!
//Estos son los pines que definen el modo de conexion de las resistencias de la pantalla tactil
#define YP A1  // must be an analog pin, use "An" notation!
#define XM A2  // must be an analog pin, use "An" notation!
#define YM 7   // can be a digital pin
#define XP 6   // can be a digital pin

//Hay que calibrar primero este parametro para hacer que funcione este ejemplo. 
#define MINPRESSURE 400
#define MAXPRESSURE 1000
#define MINX_VALUE 20
#define MINY_VALUE 20

#define TS_MINX 30
#define TS_MINY 100
#define TS_MAXX 420
#define TS_MAXY 215

// For better pressure precision, we need to know the resistance
// between X+ and X- Use any multimeter to read it
// For the one we're using, its 300 ohms across the X plate
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

// LCD Pin

#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4 // Optional : otherwise connect to Arduino's reset pin

// Assign human-readable names to some common 16-bit color values:
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

int width, height;

void setup(void) {
  Serial.begin(9600);

  tft.reset();
  tft.begin(0x9341);
  tft.setRotation(0); 

  width = tft.width() - 1;
  height = tft.height() - 1;

  Serial.println(F("TFT LCD test"));

  tft.fillScreen(YELLOW);
}

void loop(void) {

  //Para obtener los datos de presion en la pantalla tactil se ha de utilizar la clase TSPoint
  //TSPoint es el detector de presion sobre cada uno de los pixeles y que se activa en el momento que la pantalla detecta una diferencia de presion
  TSPoint p = ts.getPoint();

  //Este objeto nos permite conocer 3 datos. Las coordenadas x e y donde se ejerce la presion y la presion aplicada sobre ella.
  //Obtenemos la presion que se encuentra entre los dos limites definidos anteriormente

  //En la libreria SPFD5408 se ha de sustituir el valor de y por el de z
  
  //Mostramos por monitor serie los valores de las coordenadas donde se ejerce presion
  if (p.y > MINPRESSURE && p.y < MAXPRESSURE && p.x > MINX_VALUE && p.z > MINY_VALUE) {
     Serial.print("X = "); Serial.print(p.x);
     Serial.print("\tY = "); Serial.print(p.z);
     Serial.print("\tPressure = "); Serial.print(p.y);
     Serial.print("\tPixel X = ");Serial.print(mapXValue(p));
     Serial.print("\tPixel Y = ");Serial.println(mapYValue(p));
  }// a point object holds x y and z coordinates

}

//Mapea el valor del eje X cuando se toca un punto y lo identifica con su posicion a lo ancho
uint16_t mapXValue(TSPoint p) {

  uint16_t x = map(p.x, TS_MINX, TS_MAXX, 0, tft.width());

  //Correct offset of touch. Manual calibration
  //x+=1;
  
  return x;

}

//Mapea el valor del eje Y cuando se toca un punto y lo identifica con su posicion a lo alto

uint16_t mapYValue(TSPoint p) {

  uint16_t y = map(p.z, TS_MINY, TS_MAXY, 0, tft.height());

  //Correct offset of touch. Manual calibration
  //y-=2;

  return y;
}
