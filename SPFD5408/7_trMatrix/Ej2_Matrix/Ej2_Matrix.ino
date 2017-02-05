#include <SPFD5408_Adafruit_GFX.h>    // Core graphics library
#include <SPFD5408_Adafruit_TFTLCD.h> // Hardware-specific library
#include <BasicLinearAlgebra.h>
#include <Robotic2Duino.h>

//Arduino UNO Pin Definition 
#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0
#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

// Assign human-readable names to some common 16-bit color values:
#define BLACK   0x0000
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
  
  float x = width/2;
  float y = height/2;
  float angle =30;
  
  Pose2D P0 (-2,1,-30);
  Serial.print ("This: ");
  P0.print();

  
  Pose2D G0 (1,2,30);
  
  Matrix<3, 3, float> P1 =se2(5,6,15);
  Matrix<3, 3, float> P2 =se2(-2,1,-30);

  P0.move(P1);
  P0.print();

  P0.move(P2);
  P0.print();

  G0.move(P2*P1);
  G0.print();
}

void loop() {
  
}

