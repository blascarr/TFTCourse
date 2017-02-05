#include <BasicLinearAlgebra.h>
#include <Robo2Duino.h>

/*Matrix<3,3, float> rotation(float angle){
  float ang2rad=180/PI;
  float arrayRot[3][3] = {{cos(angle/ang2rad),sin(angle/ang2rad),0},{-sin(angle/ang2rad),cos(angle/ang2rad)},{0,0,1}};
  Matrix <3, 3, float> m (arrayRot);
  return m;
}*/

Matrix<3,3> trans(float px , float py ){
    
  float transM[3][3] = {{1,0,0},{0,1,0},{px, py,1}};
  Matrix <3,3> m (transM);
  return m;
}


void setup() {
  Serial.begin(9600);
  Matrix<3,3,float> A;
  float arrayA[3][3] = {{3.25,5.67,8.67},{4.55,7.23,9.00},{2.35,5.73,10.56}};
  A = arrayA;
  int arr[] = {1,2,3};
  int* newarr= fillarr (arr);

  Serial.println(newarr[0]);
  Serial.println(newarr[1]);
  Serial.println(newarr[2]);
  Matrix <1,3,int > v (*newarr);
  Matrix<3,3,float> M =rot2tr(90);

  //Translacion en 2 y en 1
  Matrix <3,3,float > p = trans (2,1);
  //Serial << A;
  /*Serial << M;
  Serial.println();
  Serial << p;
  Serial.println();
  Serial <<M*p;*/
  
  Serial << p;
  Serial.println();
  
  Matrix<3,3,float> T1 = se2(1,2,30);
  Serial.print("T1:   ");
  Serial << T1;
  Serial.println();

  Matrix<3,3,float> T2 = se2(2,1,0);
  Serial.print("T2:   ");
  Serial << T2;
  Serial.println();
  
  Matrix<3,3,float> T3 = T1*T2;
  Serial.print("T3:   ");
  Serial << T3;
  
}

void loop() {
  
}

int *fillarr( int arr[] ) { // arr "decays" to type int *
    return arr;
}

float *floatarr( float arr[] ) { // arr "decays" to type int *
    return arr;
}


