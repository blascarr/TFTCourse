#include <SPFD5408_Adafruit_GFX.h>    // Core graphics library
#include <SPFD5408_Adafruit_TFTLCD.h> // Hardware-specific library

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

  width = tft.width();
  height = tft.height();

  //Una linea recta requiere de 4 parametros. Posicion inicial, longitud y color
  // Posicion en X --> Direccion horizontal (De izquierda a derecha)
  // Posicion en Y --> Direccion vertical (De arriba a abajo)
  // Longitud --> Distancia en pixeles
  // Color --> En hexadecimal

  // Hay que crear una cruz con dos lineas horizontal y vertical que pase por el centro con una longitud de 100 pixeles
  
  int length = 100;
  int x = width/2 - length/2;
  int y = height/2 - length/2;

  // Dibujamos la linea horizontal 
  tft.drawFastHLine(x, height/2 , length, BLACK);
  // Dibujamos la linea vertical
  tft.drawFastVLine(width/2, y , length, BLACK);
  
}

void loop() {

}
