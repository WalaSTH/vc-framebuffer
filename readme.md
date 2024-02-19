# Introduction to the Laboratory of Operating Systems

### Group:

Virtualized, named after the OS technique of virtualization.

### Members:

- Leonardo Torres, (leo.torres@mi.unc.edu.ar)
- Matías Scantamburlo, (matias.scantamburlo@mi.unc.edu.ar)
- Maciel Salguero, (maciel.salguero@mi.unc.edu.ar)

# Developement

In this laboratory, work was done to solve 4 tasks:

1.  Implement the vgainit() function in console.c and call it at the beginning of the system.

2.  Extend console.c with functions that allow us to switch between text/graphic modes.

3.  Implement a syscall modeswitch that switches between modes (text/graphic) and plotpixel(int x, int y, int color) that paints a pixel on the screen.

4.  Create your our user program that generates some drawing on the screen.

Next, we will describe what was done in each task, the problems that arose, and how they were solved.

## Task 1:

Implementing the vgainit() program was easy; we used the example provided to us and only changed the values, using a natural language to xuser translator. However, we had some difficulty figuring out how to execute it in the main function. Our initial solution was to create a console.h file where our function would be, which, although it worked, looked messy. After some searching, we found the def.h file already included in the main.c, where we placed the vgainit() call, which solved the issue.

## Task 2

In this part of the laboratory, the main task was to implement functions that would allow us to switch between modes, which is a fundamental part of the work since all subsequent tasks rely on this.

Problems encountered:
This task brought about several challenges as we were initially quite lost and unsure how to approach the problem. We went through a period of reading and researching about VGA functionality and xv6 code to better understand and see if any ideas would emerge. While this groundwork was crucial for the rest of the lab, we still found ourselves stuck on this exercise even after this period. The breakthrough came with the guidance provided by the course staff in the statement, specifically:
"To switch modes involves setting particular values in the device's registers. For this, it is important to have a reference to the ports (see VGA Ports in the references below). And the real help is here: http://files.osdev.org/mirrors/geezer/osd/graphics/modes.c"
Once we started approaching the problem with this in mind, everything became clearer. All we had to do was adapt the code for xv6, which involved:

- Adjusting the code style to match the style used in xv6.

- Utilizing the outb and inb functions from xv6.

- Selecting the code segments that were of interest to us, i.e., the 320x200x256 (graphics mode 13h) and g_80x25_text (text mode).

## Task 3

At this point, we were asked to modularize what we had seen in task II, implementing the syscall modeswitch and plotpixel. To do this, we first created the modeswitch.c file, where we transferred what we had seen in task II in order to modularize it, and plotpixel.c, where we implemented the function using the information provided in the statement and the call to P2V().

At this moment, things got a little complicated as we had to learn how to add a system call. Therefore, we started tracing how other syscalls were implemented, in which files they were defined, where the objects were declared, and so on. Once we understood this, we tested by adding the .c and .o files in the Makefile and the prototypes in defs.h.

In the meantime, we added a function to modeswitch.c to clean up all the garbage left from the text mode. After a few days, we realized that there was a better way to add the syscalls, so we removed what we had done and added the extern int, [SYS_modeswitch], and [SYS_plotpixel] to the syscall.c file and added the defines in the syscall.h file.

## Task 4: Recreating NES Zelda (and struggling in the process)

For the fourth part, we were given the freedom to be creative with the graphics mode, and one of the most tempting ideas was to create some kind of interactive game. The first idea that came to mind was classic Nintendo games like Pokemon or Mario, but one that particularly caught our attention was The Legend of Zelda. Thus, the idea of recreating, as much as possible, the adventure of the original NES game was born.

Graphics:

The graphics part is divided into two sections to implement: The map and the sprites. For the map, it would be very useful to have a tool that allows us to create scenarios quickly and easily, and thus the tiles.h/c module appears, which contains functions (implemented as syscalls) that serve to create maps. (./img/rock.png)

The first step is to draw a rock like this one, which appears throughout the game map. It is drawn imitating the original, although simplified to speed up the work. To draw it, we used syscalls created earlier for part 3. Next, we need a function that can draw a matrix of these rocks on the screen, giving rise to the function void rock_bottom_matrix(int pos_x, int pos_y, int wide, int height, int color) which, given an x, y position, a width and a height, and a color, draws a matrix of these rocks at the desired position, with the desired dimensions. (./img/matrix.png)

The same applies to other drawings related to the scenario, such as trees and another rock with a curvature. With these functions, the task of creating a scenario that recreates the original ones in The Legend of Zelda (or even new scenarios) is quite simple, since the game does not have very complex geometry, and the colors of the maps vary between green, red, and blue.

Sprites: For the sprites, the task was to recreate the character of Link (and enemies) as best as possible. One of the difficulties was the size, as we did not want a character that would be too small or too large on the map. The other issue was how to implement such a sprite. The final solution was to use an array that contains the information of where to draw each pixel and what color. As the characters move in the scenario, it is necessary to create sprites for the animations. In the case of Link, two sprites were needed for each position he faced (up, down, left, and right), totaling eight sprites so he could move in all four directions, thus having a walking animation while doing so. Since our original idea was to create a more interesting and complete game, an idea that could not be realized due to time constraints, we thought it would be a very good idea to create an abstract data type "Character".

### TAD Character

With the following structure in mind:

```
struct character_s {
    int pos_x;
    int pos_y;
    int spriteCounter[4];
};
```

We designed the ADT (Abstract Data Type) Character, where in sprites would be the array with the information to draw the character (which has been removed from the final delivery, more on this later), a counter that helps to choose the correct sprite when moving, and the x and y positions on the screen. With operations such as: creating a new character given some sprites and positions, drawing a character on the screen, obtaining the position of a given character, and functions to move a character on the screen after receiving input and checking for collisions with the scenario. This ADT is found in the module character.h/c and has been very useful when programming the main game code, also aiding its readability.

However, since the work has been considerably slowed down due to small problems that took time to solve, and due to the deadline, we have not been able to finalize our initial idea. Since ultimately we were only going to move Link on the stage (and not other characters as they were going to be different enemies), we ended up cutting this ADT and removing the sprites element, leaving a "hardcoded" version that always works with the only character we managed to implement. Still, the character ADT with its structure and functions greatly aids the simplicity with which we can program the main game code and is a tool that, along with the functions of the tiles.h/c module to create maps, allowed us to make an initial approach to our original idea with ease, leaving the door open for future progress.

### Zelda Result

![](https://github.com/WalaSTH/vc-framebuffer/blob/master/image/zeldaDemo.gif)

## Extra points

Everything we implemented can be modularized in a more delicate manner. Considering that these are functions for the same device, they can be in a single file vga.{c,h}. For this exercise, we created the folders vga.c and vga.h, as indicated, and we were creating and adjusting the work so that it could be implemented and defined in these files in this way.

- agregar una nueva syscall:
  **plotrectangle(int x1, int y1, int x2, int y2, int color)**
  to draw rectangles on the screen.
  The first thing we did was create the file plotrectangle.c where we implemented the function using two for loops, and just like we did initially in task III, we included it in defs.h and Makefile. However, later on, we changed it and placed it in syscall.{c,h}.

- Recover the fonts lost when switching from graphics mode to text mode.
  For this, we primarily relied on what was written in the documentation. We mainly inferred the minor changes, which involved using the syscalls provided in xv6 such as inb and outb.
