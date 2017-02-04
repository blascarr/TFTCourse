#include <SPI.h>
#include <SD.h>

// *** SPFD5408 change -- Begin
#include <SPFD5408_Adafruit_GFX.h>    // Core graphics library
#include <SPFD5408_Adafruit_TFTLCD.h> // Hardware-specific library
#include <SPFD5408_TouchScreen.h>

// *** SPFD5408 change -- End

// The control pins for the LCD can be assigned to any digital or
// analog pins...but we'll use the analog pins as this allows us to
// double up the pins with the touch screen (see the TFT paint example).
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

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

#define SD_CS 10

void setup() {
  Serial.begin(9600);
  
  tft.begin(0x9341); // SDFP5408
  tft.fillScreen(BLUE);
  tft.setRotation(1);
  
  tft.setTextSize(2);
  tft.setTextColor(CYAN);
  
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

