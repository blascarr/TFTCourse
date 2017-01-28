# TFTHexel
PixelArt graphics library for TFT Displays based on Hexels format to draw with several grid frames.

The library use different polygons in order to stablish different grids to draw in different formats:
<ul>
<li> Hexels</li>
<li> Trixels</li>
<li> Pixels</li>
</ul>

This differents interpretations on graphics allow us to create hexel in order to create 3D models on a 2D TFT Display with a different interpretation on depth figures.

This library need also:
<ul>
  <li>Adafruit_GFX.h</li>
</ul>

Arduino Board read image information from SD card with a <a href="/src/examples/hexelSD">.csv</a> exported from <a href="http://www.marmoset.co/hexels">Marmoset - Hexels 2</a> program.


<p align="center">
  <img  src="/src/HexelGrid/Hexel1.png" width="200"/>
  <img  src="/src/HexelGrid/Hexel2.png" width="200"/>
  <img  src="/src/HexelGrid/Hexel3.png" width="200"/>
  <img  src="/src/HexelGrid/Hexel4.png" width="200"/>
</p>

Hexel grid class is based on geometric triangles ordered in columns and rows with the following structure: 

<p align="center">
  <img  src="/src/HexelGrid/HexelGridPoints.jpg" width="250"/>
  <img  src="/src/HexelGrid/Hexel4Grid.jpg" width="250"/>
  <img  src="/src/HexelGrid/Hexel4Grid_Xtended.jpg" width="250"/>
</p>

<p align="center">
  <img  src="/src/HexelGrid/Hexel4Grid_module.jpg" width="250"/>
  <img  src="/src/HexelGrid/Hexel4Grid_Sectors.jpg" width="250"/>
  <img  src="/src/HexelGrid/Hexel4Grid_triangles.jpg" width="250"/>
</p>

![Temple Aqualung](img/Temple_Aqualung.png)

<p align="center">
  <img  src="/src/HexelGrid/Earth.png" width="250"/>
  <img  src="/src/HexelGrid/DinoHexel.png" width="250"/>
  <img  src="/src/HexelGrid/LagoonCastle.png" width="250"/>
</p>

This library has been tested with large variety TFT Screens. 

For more info, check TFTCanvas Library for different support

<p>
#define <b>SD_CS</b>    #  // Chip select line for SD card
<br>
#define <b>TFT_CS</b>  #  // Chip select line for TFT display
<br>
#define <b>TFT_DC</b>   #  // Data/command line for TFT
<br>
#define <b>TFT_RST</b>  #  // Reset line for TFT (or connect to +5V)
</p>


If you use another board, you can change your pins in <b>config.h</b>.

![Creatice Commons Licence](img/icon_cc.png)
