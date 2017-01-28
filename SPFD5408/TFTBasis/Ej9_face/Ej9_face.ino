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
  tft.fillScreen(GREEN);

  width = tft.width();
  height = tft.height();

  //Un rectangulo requiere de 5 parametros. Posicion --> Esquina superior izquierda
  // Posicion en X --> Direccion horizontal (De izquierda a derecha)
  // Posicion en Y --> Direccion vertical (De arriba a abajo)
  // Anchura --> Distancia en pixeles
  // Altura --> Distancia en pixeles
  // Color --> En hexadecimal

  //Dibujar una cara con dos cuadrados y un rectangulo debajo
  
    //Dibujar dos cuadrados en linea en el centro de la pantalla de 50 pixeles de lado con una separacion de 30 pixeles
  
    // Dimensiones del rectangulo
    int lsize = 60;
    int space = 50;
    
    // Posicion del primer cuadrado
    int x1 = width/2 - lsize - space/2;
    int y1 = height/2 - lsize /2;
  
    uint16_t color1 = RED;
    
    tft.fillRect(x1, y1, lsize, lsize, color1);
  
    // Posicion del segundo cuadrado
    int x2 = width/2 +space/2;
    int y2 = height/2 - lsize /2;
  
    uint16_t color2 = RED;
    
    tft.fillRect(x2, y2, lsize, lsize, color2);

   // Dibujar rectangulo debajo de 150 pixeles de largo y 30 de ancho a una distancia de 40 pixeles de los ojos

   tft.fillRect(width/2-150/2, y1+lsize+40, 150, 30, color2);
}

void loop() {

}
