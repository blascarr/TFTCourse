#include <SPI.h>  
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library

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
  tft.setTextSize(1);
  tft.setTextColor(BLACK);
  
  width = tft.width();
  height = tft.height();
  
  //Una linea recta requiere de 4 parametros. Posicion inicial, longitud y color
  // Posicion en X --> Direccion horizontal (De izquierda a derecha)
  // Posicion en Y --> Direccion vertical (De arriba a abajo)
  // Longitud --> Distancia en pixeles
  // Color --> En hexadecimal

  // Crear una escala con intervalos cada 10 pixeles en las dos direcciones
  // Para ello, vamos a crear primero una cruz por toda la pantalla
  // Y encima de ellas unas marcas con unas lineas de 10 pixeles de longitud

  // Dibujamos la linea horizontal pasante
  tft.drawFastHLine(0, height/2 , width, BLACK);
  // Dibujamos la linea vertical pasante
  tft.drawFastVLine(width/2, 0 , height, BLACK);

  int interval = 10;
  int length = 10;
  int x = width/2 - length/2;
  int y = height/2 - length/2;

  //Se dibujan las lineas horizontales indicadores de cada intervalo
  for(int i ; i < height/interval; i++ ){
    
    tft.drawFastHLine(x, i*interval , length, BLACK);
    tft.setCursor(x+20, i*interval);
    tft.println(i);
  }
  
  //Se dibujan las lineas verticales indicadoras del intervalo
  for(int i ; i < width/interval; i++ ){
    
    tft.drawFastVLine(i*interval, y , length, BLACK);
    tft.setCursor(i*interval, y +20);
    tft.println(i);
  }

}

void loop() {

}
