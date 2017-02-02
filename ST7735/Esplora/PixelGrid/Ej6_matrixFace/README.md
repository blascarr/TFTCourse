<h1>MatrixFace</h1>

Vamos a crear distintos modulos matriciales para crear una cara dentro de nuestra pantalla.

Existiran 5 partes que son:
<ul>
	<li><b>Eye_i</b> --> Ojo izquierdo --> Matriz 5x5 </li>
	<li><b>Eye_d</b> --> Ojo derecho --> Matriz 5x5 </li>
	<li><b>Brow_i</b> --> Pestaña izquierda --> Matriz 5x5 </li>
	<li><b>Brow_d</b> --> Pestaña derecha --> Matriz 5x5 </li>
	<li><b>Mouth</b> --> Boca --> Matriz 6x7 </li>
</ul>

<a href="src/PixelGrid">
	<img src="/src/PixelGrid/Standard Face.png">
</a>


Cada una de estas matrices se enuentra referenciada en diferentes posiciones dentro de la pantalla, que se indica por el numero de filay columna donde se empieza a dibujar la matriz. 

Para ello crearemos un desplazamiento en filas y en columnas tal y como se indica en la figura
<ul>
	<li><b>Eye_i</b> --> (X , Y) --> ( 5, 3) </li>
	<li><b>Eye_d</b> --> (X , Y) --> ( 5, 13)  </li>
	<li><b>Brow_i</b> --> (X , Y) --> ( 0, 3)  </li>
	<li><b>Brow_d</b> --> (X , Y) --> ( 0, 13) </li>
	<li><b>Mouth</b> --> (X , Y) --> ( 10, 7) </li>
</ul>

<p align="center">
	<img src="/src/PixelGrid/CG_Origin_FaceTemplate.png">
</p>

Dentro de nuestro programa declararemos los colores de cada una de estas matrices y las dibujaremos referenciándolas debidamente por filas y columnas.

* <i>Se puede activar o desactivar la visualización de la malla, estableciendo la variable <b>gridDebug</b> a <b>false</b></i>