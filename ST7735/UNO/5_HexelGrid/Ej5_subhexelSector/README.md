# Ej5 Symmetry

Este ejercicio trata de añadir una serie de parametros a nuestra funcion de 
Ya que hemos subdividido los triangulos en subhexel y podemos dibujarlos de forma invertida; vamos a desarrollar nuestra funcion para definir los subtriangulos en un conjunto de 4 zonas.

Estas zonas se denominan cuadrantes y lo que vamos a crear con ellos es una malla de subhexels para luego ordenarlos por filas y por columnas

Para ello, vamos a crear una función parecida a la de <a href="https://github.com/blascarr/TFTCourse/tree/master/ST7735/UNO/1_TFTBasis/Ej7_drawRect">drawRect</a>, y añadiremos a la anterior 4 parametros adicionales para poder determinar la posicion de inicio en X y en Y, la anchura, la altura y una condicion de inversion para que se cree el cuadrante.
  

<p align="center">
	<img  src="/src/HexelGrid/Hexel4Grid_Sectors.jpg" />
</p>

Una vez creados 4 cuadrantes, vamos a dividir nuestra pantalla TFT en tantas columnas como queramos para crear una malla completa, de la misma manera que hemos hecho en el ejercicio de <a href="https://github.com/blascarr/TFTCourse/tree/master/ST7735/UNO/5_HexelGrid/Ej2_hexelGrid"> hexelGrid</a>