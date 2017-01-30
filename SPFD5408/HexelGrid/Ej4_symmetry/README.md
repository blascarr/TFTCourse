# Ej4 Symmetry

En este ejercicio vamos a dar una solución a un problema de simetría.

Es posible que en función de la configuración que se nos proponga para crear la malla, deberemos de pensar cuándo se utilizan la submalla con una configuración invertida dispuesta en filas y en columnas de forma repetida.

<p align="center">
	<img  src="/src/HexelGrid/HexelGridPointsPP.png" width="300"/>
</p>

Para ello, vamos a valorar cuáles son las coordenadas de cada uno de los triángulos y cómo podemos hacer que éstos se modifiquen con el menor número de cambios.

En el ejercicio anterior vimos que las coordenadas de los puntos erán los siquientes.

<p align="center">
	<img  src="/src/HexelGrid/HexelGridPoints.png" width="300"/>
</p>
    tft.drawTriangle(   0, 0, w/3, h , 0, h, color);
    tft.drawTriangle(   0, 0, w/2, h/2 , w/3, h, color);
    tft.drawTriangle(   0, 0, 2*w/3, 0 , w/2, h/2, color);
    
    tft.drawTriangle(   w, h, 2*w/3, 0, w, 0 , color);
    tft.drawTriangle(   w, h, w/2, h/2, 2*w/3, 0 , color);
    tft.drawTriangle(   w, h, w/3, h , w/2, h/2 , color);
    

Si creamos el 
<p align="center">
	<img  src="/src/HexelGrid/HexelGridPoints_Inv.png" width="300"/>
</p>

    
    tft.drawTriangle(   0, h, w/3, 0 , 0, 0, color);	//Solo cambia el parámetro 2,4,6
    tft.drawTriangle(   0, h, w/2, h/2 , w/3, 0, color);	//Solo cambia el parámetro 2, 6
    tft.drawTriangle(   0, h, 2*w/3, h , w/2, h/2, color);	//Solo cambia el parámetro 2,4
    tft.drawTriangle(   w, 0, 2*w/3, h, w, h , color);	//Solo cambia el parámetro 2, 4 y 6
    tft.drawTriangle(   w, 0, w/2, h/2, 2*w/3, h , color);	//Solo cambia el parámetro 2,6
    tft.drawTriangle(   w, 0, w/3, 0 , w/2, h/2 , color);	//Solo cambia el parámetro 2,4

En definitiva solo ha cambiado el valor de altura de 0 a h.

La mejor solución es valorar cuáles son los parámetros modificados y hacer el cambio mediante el uso de un vector de coordenadas.

PX[] = {0,w/3, w/2, 2*w/3, w};
PY[]= {0,h/2, h}; 

En caso de querer invertir esta submalla accederemos a las coordenadas de la siguiente manera:

PX[] = {0,w/3, w/2, 2*w/3, w};
PY[]= {h,h/2, 0}; 

*h/2 evidentemente permanece invariable.