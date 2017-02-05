#include <SPI.h>
#include <SD.h>
 
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

#define SD_CS 8

void setup() {
  Serial.begin(9600);
  
  tft.initR(INITR_BLACKTAB); // Tab Label for ST7735 TFT Screen (INITR_GREENTAB 0x0, INITR_REDTAB 0x1, INITR_BLACKTAB 0x2);

  tft.fillScreen(BLUE);
  tft.setRotation(1);
  
  tft.setTextSize(2);
  tft.setTextColor(YELLOW);
  
  // Para abrir los datos de la tarjeta solo hay que 
  if (!SD.begin(SD_CS)) {
    
    progmemPrintln(PSTR("Card failed")); // Useful for SPI TFT Screens
    tft.println("Card Failed");
    return;
  }

  tft.println("Card Ready");
  tft.setCursor(0,30);

  String filename= "Arduino";
  char* filecharname= "imagen.txt";
  
  if (SD.exists(filename)){
    tft.println("Filename exists: ");
    tft.println();
    
    File myFile = SD.open(filename);
    
    tft.print(filename);
    if(myFile.isDirectory()){
      tft.println(" is a Directory");
    }else{
      tft.println(" is a File");
    }
    myFile.close();
  }else{
    tft.println("Folder does not exists");
  }
  
  tft.println();

  if (SD.exists(filecharname)){
    tft.println("Filename exists: ");
    tft.println();
    
    File myFile = SD.open(filecharname);
    tft.print(filecharname);
    
    if(myFile.isDirectory()){
      tft.println(" is a Directory");
    }else{
      tft.println(" is a File");
    }
    myFile.close();
  }else{
    tft.println("Folder does not exists");
  }
  
}

void loop() {

}


void progmemPrint(const char *str) {
  char c;
  while(c = pgm_read_byte(str++)) Serial.print(c);
}

void progmemPrintln(const char *str) {
  progmemPrint(str);
  Serial.println();
}

