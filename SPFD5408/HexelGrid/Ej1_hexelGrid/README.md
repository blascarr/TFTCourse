# Ej1 HexelGrid

Se va a crear una malla en la que se definiran por columnas una malla triangular con una relacion entre las dimensiones de cada triangulo para crear un efecto tridimensional, denominado <a href="https://es.wikipedia.org/wiki/Proyecci%C3%B3n_isom%C3%A9trica">proyección isometrica.</a>


<img  src="/src/HexelGrid/Hexel4Grid_Xtended.jpg" />

<p align="center">
	<img  src="/src/HexelGrid/Bayer_pattern.png" width="300"/>
	<img  src="/src/HexelGrid/Bayer_patterngray.png" width="300"/>
	
</p>


En este ejercicio 
Si cambiamos el valor de columnas a un número muy grande por ejemplo a 100; podremos observar que deja de dibujar triángulos en un momento dado.

Esto se debe a que tenemos un problema de redondeo.

Los pixeles por muy pequeños que sean no se pueden acceder con decimales, por lo que a la hora de determinar cuantos pixeles corresponden a una columna. 
Si dividimos 240 pixeles; que es el ancho de la pantalla entre 100, tendremos 2,4 pixeles por cada columna.

Como no se puede dibujar 0,4 pixeles, ya que no es un sistema continuo, tenemos que elegir entre dibujar 2 o 3 pixeles por columna.
Lo que nos daría la opción de dibujar 200 píxeles, que se queda corto o 300 pixeles, que es demasiado y no albergaría las 100 columnas.

¿Cuál sería la solución?


¿Puedes encontrar el número de columnas en los que ya no apreciaremos cada uno de los triangulos?




