#include <SPFD5408_Adafruit_GFX.h>    // Core graphics library
#include <SPFD5408_Adafruit_TFTLCD.h> // Hardware-specific library
#include <SPFD5408_TouchScreen.h>     // Touch library

// These are the pins for the shield!
#define YP A1  // must be an analog pin, use "An" notation!
#define XM A2  // must be an analog pin, use "An" notation!
#define YM 7   // can be a digital pin
#define XP 6   // can be a digital pin

#define MINPRESSURE 10
#define MAXPRESSURE 1000

short TS_MINX=50;
short TS_MINY=1000;
short TS_MAXX=500;
short TS_MAXY=1002;

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

// Button

Adafruit_GFX_Button btn;

uint16_t buttons_y = 0;
uint16_t width = 0;
uint16_t height = 0;

void setup() {
  Serial.begin(9600);

  tft.reset();
  tft.begin(0x9341);
  tft.setRotation(0);

  width = tft.width() - 1;
  height = tft.height() - 1;
  tft.fillScreen(WHITE);

  // Un boton requiere de 10 parametros. 
  // La pantalla sobre la que aparece
  // La posicion inicial
    //Posicion de referencia en X
    //Posicion de referencia en Y
  //Colores
    //Color del borde exterior
    //Color de relleno
    //Color del texto
  //Texto
    //Mensaje de texto
    //Numero de letras que contiene el mensaje

  // Como son muchos elementos a tener en cuenta, vamos a realizar una adaptacion del boton al texto que queremos escribir

  //Margenes del texto dentro del boton
  int margin_x=40;
  int margin_y=30;
  //Tamanio de texto dentro del boton
  int textSize = 2;
  
  char msg[] = "Button"; 
  //La anchura y la altura de texto es proporcional al tamaño de texto en 5 y 7 veces respectivamente
  int msg_w = sizeof(msg)*textSize*5;
  int msg_h = textSize*7;
  
  //Tamanio real del boton
  int btn_w = msg_w+2*margin_x;
  int btn_h = msg_h+2*margin_y;
  
  // Center of Button
  int d_x= 10;
  int d_y = 20;
  int btn_x = btn_w/2+d_x;
  int btn_y = btn_h/2+d_y;

  btn.initButton(&tft,btn_x,btn_y,btn_w,btn_h,GREEN,BLUE,YELLOW, msg, textSize);
  btn.drawButton(true);
}

void loop() {
  
}
