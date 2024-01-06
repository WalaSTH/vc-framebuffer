readme2

# Introducción al Laboratorio segundo de Sistemas Operativo

### Grupo:

Virtualized, nombrado así en honor a la técnica empleada por los sistemas operativos.

### Integrantes:

Conformado por

- Leonardo Torres, (leo.torres@mi.unc.edu.ar)
- Matías Scantamburlo, (matias.scantamburlo@mi.unc.edu.ar)
- Maciel Salguero, (maciel.salguero@mi.unc.edu.ar)

# Desarrollo

En este laboratorio se trabajo para resolver 4 tareas:

1.  Implementar en console.c una función vgainit() y llamarla al inicio del sistema.
2.  Extender console.c con funciones que nos permitan cambiar de modo texto/gráfico
3.  Implementar una syscall modeswitch que hace el cambio de modo (texto/gráfico) y plotpixel(int x, int y, int color) que pinte un pixel en pantalla
4.  Hagan su propio programa de usuario que genere algún dibujo por pantalla

A continuación describiremos que se hizo en cada Tarea, los problemas que surgieron y cómo se solucionaron.

## Tarea 1:

En esta primera Tarea nos topamos con la gran cantidad de archivos de extención .h, que no sabíamos bien para que se usaban y puede esto nos haya perdido un poco. El programa **vgainit()** fue facil de implementar, usamos el que nos dierón de ejemplo y unicamente cambiamos los valores, utilizando un traductor de lenguaje natural a *xuser*. Ahora se nos complico un poco la forma de ejecutarlo en el main y la primera que se nos ocurrio fue crear un archivo console.h donde estuvise nuestra función, esto si bien anduvo quedo muy feo, por lo que después de buscar un poco encontramos el archivo def.h, ya incluido en el main.c, y ahí colocamos la llamada a **vgainit()**.

## Tarea 2
En esta parte del laboratorio básicamente se tenía que implementar las funciones que nos permitieran pasar de un modo a otro, lo cual es una parte fundamental del trabajo ya que en esto recaen todas las consignas siguientes.
 
Problemas que surgieron:
Este enunciado nos trajo bastantes problemas ya que al principio estuvimos muy perdidos y no sabíamos cómo encarar el problema. Pasamos por un periodo de lectura e investigación sobre el funcionamiento de vga y el código de xv6 con el fin de poder afianzarnos más y ver si surgían ideas, si bien esto fue fundamental para todo el resto del laboratorio, en este ejercicio luego de dicho periodo seguiamos sin avanzar. Lo decisivo en este punto fue la ayuda brindada por la cátedra en el enunciado, para ser especifico:
“Cambiar de modo implica setear valores particulares en los registros del dispositivo. Para esto es importante tener una referencia de los puertos (ver Puertos VGA en las referencias abajo) Y la super ayuda se encuentra acá: http://files.osdev.org/mirrors/geezer/osd/graphics/modes.c ”
 Una vez empezado a encarar el problema teniendo esto en cuenta todo se facilitó, lo único que tuvimos que hacer fue adaptar el código para xv6, esto fue:
   
  + Ajustar el estilo del código para que quede bien con el estilo utilizado en xv6
 
 + Utilizar las funciones outb e inb de xv6
 
 + Elegir los segmentos de código que nos interesaba i.e los modos 320x200x256 (modo gráfico 13h) y g_80x25_text (modo texto).

## Tarea 3
En este punto se nos pedia modularizar lo visto en la tarea II, implementado así las syscall modeswitch y plotpixel. 
Para esto y antes que nada creamos los archivos modeswitch.c, a donde trasladomos lo visto en la tarea II con el fin de modularlo y plotpixel.c, donde implementamos la función utilizando la información dada en el enunciado y la llamada a **P2V()**
En este momento es cuando se complico un poco, ya que tuvimos que aprender como agregar una llamada al sistema. Por lo tanto nos pusimos a rastrear como estaban implementadas las demás syscalls, en que archivos estaban definidas, donde se declaraban los objetos y demás. Una vez visto esto, hicimos la prueba agregando los .c y .o en Makefile y los prototipos en defs.h
En el medio agregamos al modeswitch.c una función para que limpiase toda la basura que quedaba del modo texto. A los días nos dimos cuenta que había una mejor forma de agregar las syscalls así que quitamos lo hecho y agregamos los extern int, [SYS_modeswitch] y [SYS_plotpixel] al archivo syscall.c y agregamos los define en el syscall.h


## Tarea 4: Recreando Zelda de NES (y sufriendo en el intento)

Para la parte cuatro se nos dio la libertad de ser creativos con el modo grafico, y una de las ideas mas tentativas es la de hacer alguna especie de juego interactivo. La primera idea que se nos vino a la cabeza fueron los clasicos de Nintendo como Pokemon o Mario, pero uno que más nos llamó la atencion fué el The Legend of Zelda. Así nació entonces la idea de recrear, en lo posible, la aventura del juego original de NES.
Graficos:

La parte de graficos se divide en dos secciones a implementar: El mapa y los sprites. Para el mapa iba a ser muy util una herramienta que nos permitiera crear escenarios con rapidez y facilidad, y así aparece el modulo tiles.h/c, que contiene funciones (implementadas como syscalls) que sirven para crear mapas. (./img/rock.png)

Lo primero es dibujar una roca como esta, que aparece en todo el mapa del juego. Se dibuja imitando la orignal, aunque esta simplificada para acelerar el trabajo. Para dibujarla utilizamos syscalls creadas anteriormente para la parte 3. Lo siguiente, es tener una funcion que pueda dibujar en pantalla una matriz de estas rocas, dando origen a la funcion void rock_bottom_matrix(int pos_x, int pos_y, int wide, int height, int color) Que dadas una posicion x,y, un ancho y un alto, y un color dibuja una matriz de estas rocas en la deseada posicion, con las deseadas dimensiones. (./img/matrix.png)

Lo mismo ocurre para otros dibujos relacionados con el escenario, como lo son los arboles y otra roca que que tiene una curvatura. Teniendo estas funciones, la tarea de crear un escenario que recree los originales en The Legend of Zelda (o incluso nuevos escenarios) es bastante sencilla, puesto que el juego no tiene una geometría muy compleja, y los colores de los mapas varian entre verde, rojo y azul.

Sprites: Para los sprites la tarea era recrear al personaje de Link (y enemigos) de la mejor manera posible. Una de las dificultades fue el tamaño, ya que no queríamos un personaje que quedara muy chiquito en el mapa, ni muy grande. La otra cuestion fue cómo implementar dicho sprite. La solucion final fue utilizar un array que contenga la informacion de dónde dibujar cada pixel, y de que color. Como los personajes se mueven en el escenario, es necesario crear sprites para las animaciones. En el caso de Link se necesitaron dos para cada posicion a la que se enfrentase (arriba, abajo, izquierda y derecha) siendo un total de ocho sprites para que pudiera dirigirse en los cuatro sentidos, de manera que tuviera una animacion de caminar al hacerlo. Como nuestra idea origial era hacer un juego interesante y más completo, idea que no ha podido concretarse debido al tiempo, pensamos que sería muy buena idea la creacion de un tipo abstracto de dato "Personaje" (o "Character" en ingles)

### TAD Character

Con la siguiente estructura en mente: struct character_s { int sprites[MAX_SPRITES][MAX_SPRITE_SIZE]; //Este elemento ha sido descartado int spriteCounter[4]; int pos_x;int pos_y; }; diseñamos el TAD Character, donde en sprites se encontraría el arreglo con la informacion para dibujar al personaje (algo que ha sido removido de la entrega final, más sobre esto adelante.) un counter que sirve para elegir un correcto sprite a la hora de moverse y tener así una animacion, y las posiciones x e y en la pantalla. Y con los operaciones como: Crear un nuevo personaje dado unos sprites y unas posiciones, pintar un personaje en pantalla, obtener la posicion de un personaje dado, y funciones para mover a un personaje en la pantalla luego de recibir un input y chequeando que no se colisione con el escenario. Este TAD se encuentran en el modulo character.h/c y ha sido de gran utilidad a la hora de programar el codigo principal del juego, ayudando ademas su la legibilidad. Sin embargo debido a que el trabajo se ha relentizado considerablemente debido pequeños problemas que tardamos tiempo en solucionar, y al deadline, no hemos podido concretar nuestra primer idea. Como finalmente solo ibamos a mover a Link en el escenario (y no a otros personajes como iban a ser diferentes enemigos), terminamos recortando este TAD y quitamos el elemento sprites, dejando una version "hardcodeada" y que siempre trabaja con el unico personaje que llegamos a implementar. Aun así, el TAD character con su estructura y funciones ayuda bastante a la sencillez con la que podemos programar el codigo principal del juego, y es una herramienta que junto con las funciones del modulo tiles.h/c para crear mapas, nos peritió realizar un primer acercamiento a nuestra idea original con facilidad, que deja la puerta abierta para futuros progresos.

## Puntos estrella
+ Todo lo que implementaron puede ser modularizado de una manera más delicada. Teniendo en cuenta que son funciones para un mismo dispositivo pueden estar en un mismo archivo vga.{c,h}
Para este ejercicio creamos las carpetas vga.c y vga.h, como se nos indico y fuimos creando y adecuando lo trabajado para que pudiece de dicha forma estar implementado y definido en estos archivos  

+ agregar una nueva syscall: 
**plotrectangle(int x1, int y1, int x2, int y2, int color)** 
para dibujar rectángulos en la pantalla.
Lo primero que hicimos fue crear el archivo plotrectangle.c donde implementamos la función mediante la utilización de dos for´s y al igual que como hicimos inicialmente en la tarea III, lo incluimos en defs.h y Makefile. Aunque después cambiamos y lo colocamos en syscall.{c,h}.

+ Recuperar las fuentes que se pierden cuando pasamos de modo gráfico a texto.
Para este punto nos basamos más que nada en lo que estaba escrito en la ayuda. Solo intuimos los pequeños cambios, esto sería, usar las syscalls que vienen en xv6 como inb y outb
