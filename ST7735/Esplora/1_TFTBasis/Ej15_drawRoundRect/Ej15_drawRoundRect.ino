#include <SPI.h>  
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library

// These definitions map display functions to the Adduino UNO display header pins
#define sclk 15
#define mosi 16
#define cs   7
#define dc   0
#define rst  1
    
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
  tft.initR(INITR_BLACKTAB); // Tab Label for ST7735 TFT Screen (INITR_GREENTAB 0x0, INITR_REDTAB 0x1, INITR_BLACKTAB 0x2);

  tft.setRotation(0); 
  tft.fillScreen(WHITE);

  tft.setTextSize(2);
  tft.setTextColor(BLACK);
  
  width = tft.width();
  height = tft.height();

  // Un rectangulo con aristas redondeadas sirve para crear el modo boton. Requiere de 7 parametros. Posicion inicial, anchura, altura, radio y color
  // Posicion en X --> Direccion horizontal (De izquierda a derecha)
  // Posicion en Y --> Direccion vertical (De arriba a abajo)
  // Anchura --> Distancia en pixeles
  // Altura --> Distancia en pixeles
  // Color --> En hexadecimal

  // Hay que dibujar un boton con un texto en su interior. Para ello haremos un rectangulo redondeado de 100 pixeles de anchura y 40 de altura y un radio de 8 situado en el centro de la pantalla
  // El boton tendra un borde de un color diferente a su relleno
  int w = 100;
  int h =40;
  int radius = 8;
  
  int x = width/2 - w/2;
  int y = height/2 - h/2;
  
  //Crear boton
  
  tft.fillRoundRect(x,y,w,h,radius,YELLOW);
  tft.drawRoundRect(x,y,w,h,radius,BLUE);

  tft.setCursor(x,y);
  tft.println("Boton");
}


void loop() {

}
