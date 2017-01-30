# Ej2 HexelGrid

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

Ahora tendremos el problema de desplazar hacia abajo las columans pares, mientras que las impares deben de permanecer inmoviles.

Para ello utilizaremos la función módulo <b>"%"</b> por 2 evaluando el índice de cada columna. De esta manera, el resultado solo puede ser 0 ó 1 y con una simple multiplicación determinaremos que esa columna se ha de desplazar. 



Si ahora cambiamos el valor de columnas a un número muy grande por ejemplo a 50; observaremos que crea al final una fila de triángulos un poco coja.

Para solucionar este caso, solo añadiremos una fila más en el bucle.