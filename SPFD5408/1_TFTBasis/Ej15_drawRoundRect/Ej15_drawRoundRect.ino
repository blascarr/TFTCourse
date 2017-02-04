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
  
  tft.fillRoundRect(x,y,w,h,radius,GREEN);
  tft.drawRoundRect(x,y,w,h,radius,BLUE);

  tft.setCursor(x,y);
  tft.println("Boton");
}


void loop() {

}
