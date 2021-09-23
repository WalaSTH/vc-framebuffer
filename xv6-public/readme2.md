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

### Tarea 1:

En esta primera Tarea nos topamos con la gran cantidad de archivos de extención .h, que no sabíamos bien para que se usaban y puede esto nos haya perdido un poco. El programa **vgainit()** fue facil de implementar, usamos el que nos dierón de ejemplo y unicamente cambiamos los valores, utilizando un traductor de lenguaje natural a *xuser*. Ahora se nos complico un poco la forma de ejecutarlo en el main y la primera que se nos ocurrio fue crear un archivo console.h donde estuvise nuestra función, esto si bien anduvo quedo muy feo, por lo que después de buscar un poco encontramos el archivo def.h, ya incluido en el main.c, y ahí colocamos la llamada a **vgainit()**.
