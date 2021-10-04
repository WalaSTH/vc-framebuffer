#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "vga.h"
#include "tiles.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_modeswitch(void){
	int enable;
	argint(0,&enable);
	modeswitch(enable);
	return 0;
}

int
sys_plotpixel(void){
	int a,b,c;
	argint(0,&a);
	argint(1,&b);
	argint(2,&c);
	plotpixel(a,b,c);
	return 0;
}

int
sys_plotrectangle(void){
	int x1,y1,x2,y2,color;
	argint(0,&x1);
	argint(1,&y1);
	argint(2,&x2);
	argint(3,&y2);
	argint(4,&color);
	plotrectangle(x1,y1,x2,y2,color);
	return 0;
}

//tiles.c

int
sys_rock_tile_matrix(void){
  int pos_x, pos_y, wide, height, color;
  argint(0,&pos_x);
  argint(1,&pos_y);
  argint(2,&wide);
  argint(3,&height);
  argint(4,&color);
  rock_tile_matrix(pos_x, pos_y, wide, height, color);
  return 0;
}

int
sys_rock_bottom_matrix(void){
  int pos_x, pos_y, wide, height, color;
  argint(0,&pos_x);
  argint(1,&pos_y);
  argint(2,&wide);
  argint(3,&height);
  argint(4,&color);
  rock_bottom_matrix(pos_x, pos_y, wide, height, color);
  return 0;
}

int
sys_tree_tile_matrix(void){
  int pos_x, pos_y, wide, height, color;
  argint(0,&pos_x);
  argint(1,&pos_y);
  argint(2,&wide);
  argint(3,&height);
  argint(4,&color);
  tree_tile_matrix(pos_x, pos_y, wide, height, color);
  return 0;
}

int 
sys_getch(void){
  return getch();
}

int sys_get_color(void){
    int x, y;
    argint(0,&x);
    argint(1,&y);
    return get_color(x,y);
}