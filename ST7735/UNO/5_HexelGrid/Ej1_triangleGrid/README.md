# Ej1 HexelGrid

Se va a crear una malla en la que se definiran por columnas una malla triangular con una relacion entre las dimensiones de cada triangulo para crear un efecto tridimensional, denominado <a href="https://es.wikipedia.org/wiki/Proyecci%C3%B3n_isom%C3%A9trica">proyección isométrica.</a>

La proyección isométrica es una representación visual en dos dimensiones, en la que los tres ejes ortogonales principales, al proyectarse, forman ángulos de 120º, y las dimensiones paralelas a dichos ejes se miden en una misma escala.

Lo que queremos conseguir es que los objetos tengan un efecto tridimensional mediante la aplicación de una malla triangular y en lugar de definir una imagen por píxeles, vamos a crear <a href="https://trixel.io/">trixels </a>.


<img  src="/src/HexelGrid/HexelGrid_trianglesP.png" />

<p align="center">
	<img  src="/src/HexelGrid/Bayer_pattern.png" width="300"/>
	<img  src="/src/HexelGrid/Bayer_patterngray.png" width="300"/>
	
</p>

En este ejercicio hemos de definir las coordenadas de 3 puntos del triángulo.
<p align="center">
	<img  src="/src/HexelGrid/HexelGridPoints.png" width="300"/>
	<img  src="/src/HexelGrid/HexelGridPoints.png" width="300"/>
</p>

Si cambiamos el valor de columnas a un número muy grande por ejemplo a 50; podremos observar que deja de dibujar triángulos en un momento dado.
¿Qué ocurre si creamos la malla con 49 columnas? ¿Qué ocurre si creamos 48 columnas? ¿Qué diferencia podemos observar?

Esto se debe a que tenemos un problema de redondeo.

Los pixeles por muy pequeños que sean no se pueden acceder con decimales, por lo que a la hora de determinar cuantos pixeles corresponden a una columna, se produce un redondeo hacia el número más cercano que produce que muchos de los pixeles se queden desocupados. 

Si dividimos 240 pixeles; que es el ancho de la pantalla entre 50, tendremos 4,8 pixeles por cada columna.

Como no se puede dibujar 0,8 pixeles, ya que no es un sistema continuo, tenemos que elegir entre dibujar 4 o 5 pixeles por cada columna.
Lo que nos daría la opción de dibujar 220 píxeles, que se queda corto o 250 pixeles, que es demasiado y no albergaría las 50 columnas.

¿Cuál sería la solución?


¿Puedes encontrar el número de columnas en los que ya no apreciaremos cada uno de los triangulos?

