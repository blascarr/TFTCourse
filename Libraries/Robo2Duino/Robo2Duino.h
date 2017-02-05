/* Robotic2Duino
  Design and created by Blascarr

  Robotic2Duino
  Name    : Blascarr
  Description: Robotic2Duino.h
  version : 1.0

Robotic2Duino is a generic library useful for Advanced Robotics Applications.

This library is part of a educational course to learn C++ in practice in https://github.com/blascarr/Robotic2Duino Couser or http://www.blascarr.com/ webpage.

 *	
 *  This Library gives some helpful methods to manipulate transformation Matrix in order to create references
 *	With Robotic2Duino we can integrate different methods based on Matrix with BasicLinearAlgebra library
 *
 *	https://github.com/tomstewart89/BasicLinearAlgebra
 *
 *  Useful for Robotic Arms and TFT Screen https://github.com/blascarr/TFTCourse
 *Written by Adrian for Blascarr
 */

 #ifndef Robo2Duino_h
 #define Robo2Duino_h	
 	#define debug 0
 	#include "BasicLinearAlgebra.h"
	#include <stdarg.h>

	#if defined(ARDUINO) && ARDUINO >= 100
		#include "Arduino.h"
	#else
		#include "WProgram.h"
	#endif
 	
 	//Point 2D Class for reference
	class Point2D{
		public:
			
			float x, y;
			int inv_x=1; 
			int inv_y=1;
			uint16_t color;

			Point2D(void){
				x = y = 0;
			};

			Point2D(float x0, float y0){
				x = x0;
				y = y0;
				color = 0x000000;
			};

			Point2D(float x0, float y0, uint16_t color0){
				x = x0;
				y = y0;
				color = color0;
			};

			void Point2D::setInv(bool mx, bool my){
				if (mx) inv_x=-1;
				if (my) inv_y=-1;
			};

			void Point2D::move(float dx, float dy){
				Point2D::x = Point2D::x + inv_x*dx;
				Point2D::y = Point2D::y + inv_y*dy;
			};

			void Point2D::move(Matrix<3, 3, float> m){
				Point2D::move(m(0,2),0);
				Point2D::move(0,m(1,2));
			};

			void Point2D::fwd(float d){
				Point2D::move(d,0);
			};

			void Point2D::back(float d){
				Point2D::move(-d,0);
			};

			void Point2D::left(float d){
				Point2D::move(0,d);
			};

			void Point2D::right(float d){
				Point2D::move(0, -d);
			};
	};



 	float ang2rad=180/PI;
	
	//Multiply 3x3 matrix with a 3x1 ( 3x3 * 3x1 = 3x1 )  vector or Matrix or viceversa ( 1x3 * 3x3 = 1x3 ) 

 	Matrix<3,3> se2(float px , float py , float angle, bool inv = 1 ){
    
		float transM[3][3] = {{cos(angle/ang2rad),-sin(angle/ang2rad),px},{sin(angle/ang2rad),cos(angle/ang2rad),py},{0, 0,1}};
		Matrix <3,3> m (transM);
		return m;
	}

 	Matrix<2,2, float> rot(float angle){
		
		float arrayRot[2][2] = {{cos(angle/ang2rad),-sin(angle/ang2rad)},{sin(angle/ang2rad),cos(angle/ang2rad)}};
		Matrix <2, 2, float> m (arrayRot);
		return m;
	
	}

	Matrix<3,3, float> rot2tr(float angle){
		
		Matrix <3, 3, float> m = se2 (0, 0, angle);
		return m;
	
	}

	Matrix<3, 3, float> trans2tr( float px , float py ){
		
		Matrix <3, 3, float> m = se2 (px, py, 0);
		return m;
	
	}

	Point2D Mt2Pt ( Matrix<3, 3, float> m ){
		
		return Point2D (m(0, 2), m(1, 2));

	}

	Matrix<3, 3, float> Pt2Mt ( Point2D p ){
		return se2( p.x , p.y , 0 );

	}


	class Pose2D{

		public:

			Matrix<3, 3, float> m ;
			int inv_x=1; 
			int inv_y=1;

			Pose2D(void){
				m = se2(0,0,0);
			};

			Pose2D(float px , float py , float angle){
				m = se2(px, py, angle);
			};

			Pose2D::setInv(bool mx, bool my){
				if (mx) inv_x=-1;
				if (my) inv_y=-1;
			};

			Matrix<3, 3, float> Pose2D::move(Matrix<3, 3, float> m){
				Pose2D::m = Pose2D::m*m;
				return Pose2D::m;
			};

			Matrix<3, 3, float> Pose2D::fwd(float d){
				Pose2D::m = se2(d,0,0)*Pose2D::m;
				return Pose2D::m;
			};

			Matrix<3, 3, float> Pose2D::back(float d){
				Pose2D::m =se2(-d,0,0)*Pose2D::m;
				return Pose2D::m;
			};

			Matrix<3, 3, float> Pose2D::left(float d){
				Pose2D::m =se2(0,d,0)*Pose2D::m;
				return Pose2D::m;
			};

			Matrix<3, 3, float> Pose2D::right(float d){
				Pose2D::m = se2(0,-d,0)*Pose2D::m;
				return Pose2D::m;
			};

			Matrix<3, 3, float> Pose2D::turn(float angle){
				Pose2D::m = se2(0,0,angle)*Pose2D::m;
				return Pose2D::m;
			};

			Pose2D::print(){
				Serial.print(" Pose :  ");
				Serial << Pose2D::m;
				Serial.println();
				
			}
	};


	float distance(float x0, float y0, float xf, float yf){
		return sqrt(pow(xf-x0,2)+pow(yf-y0,2));
	}

	float distance(Point2D p0, Point2D pf){
		return sqrt(pow(pf.x-p0.x,2)+pow(pf.y-p0.y,2));
	}

	float distance(Pose2D P0, Pose2D Pf){
		return sqrt(pow(Pf.m(0,2) - P0.m(0,2),2)+pow(Pf.m(1,2) - P0.m(1,2),2));
	}

	class Link2D{


	};

#endif