#include <SPFD5408_Adafruit_GFX.h>    // Core graphics library
#include <SPFD5408_Adafruit_TFTLCD.h> // Hardware-specific library
#include <BasicLinearAlgebra.h>
#include <Robo2Duino.h>               // Robotic Matrix transformations library

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

//Set Pose Matrix P
  Pose2D P(0,0,0);
  
void setup() {
  Serial.begin(9600);
  tft.begin(0x9341); // SDFP5408

  tft.setRotation(0); 
  tft.fillScreen(WHITE);

  tft.setTextSize(2);
  tft.setTextColor(GREEN);
  
  width = tft.width();
  height = tft.height();

}


void loop() {

  //Calculamos aleatoriamente los parametros de entrada para la funcion estrella
  //Cambiar limite minimo y maximo para restringir las formas
  long dx = random (80, width/2);

  //Si cambiamos el angulo menores de 40 o mayores de 180 salen angulos muy  abiertos
  long dg = random (40, 180);
  //Numero de iteraciones de cada linea
  long nn = random (10, 150);
  
  //Iniciamos la referencia en una pocicion fija en cada iteracion para centrarlo. 
  P.m = se2(width/2 - dx/2, height/2,0);
 //trplot(P.m,40,GREEN, '0',0);
 
  //Dibujamos la estrella
  star(dx,dg, nn);
  delay(2000);
  tft.fillScreen(WHITE);
}

//Crea una estrella definida con la longitud de un lado, el angulo de giro y el numero de repeticiones
void star(int l, int angle, int n){

  Serial << "Longitud: " << l << " Angulo: " << angle << " n_rep: " << n << "\n";
  for (int i = 0; i< n ; i++){
  
    float x0 = P.m(0,2);
    float y0 = P.m(1,2);
    P.move(se2(l,0 ,angle));
    
    float xf = P.m(0,2);
    float yf = P.m(1,2);
    tft.drawLine(x0, y0, xf , yf , GREEN);

    //Descomentar para visualizar cada referencia repectiva en cada punto
    //trplot(P.m,40,YELLOW, ' ',0);
    Serial.print("Pose: ");
    Serial << P.m;
    Serial.println();
  }
}

void trplot(Matrix<3, 3, float> T, int size, uint16_t color,char label, int dir ){

  int inv_x = 1;
  int inv_y = 1;
  if ((dir == 1 ) || (dir == 2)){
    inv_y = -1;
  }

  if ((dir == 2 ) || (dir == 3)){
    inv_x = -1;
  }
      
  tft.drawLine(T(0,2), T(1,2), (T(0,2) + (inv_x)*T(0,0)*size) , (T(1,2) + (inv_y)*T(1,0)*size), color);
  tft.drawLine(T(0,2), T(1,2), (T(0,2) + (inv_x)*T(0,1)*size) , (T(1,2) + (inv_y)*T(1,1)*size) , color);
  tft.drawChar((T(0,2) + (inv_x)*T(0,0)*size- 5), T(1,2) + (inv_y)*T(1,0)*size -15,'x',color,WHITE, 1);
  tft.drawChar((T(0,2) + (inv_x)*T(0,1)*size-15), T(1,2) + (inv_y)*T(1,1)*size -5,'y',color,WHITE, 1);
  tft.drawChar(T(0,2)-5, T(1,2) + -5,label,color,WHITE, 1);
}


