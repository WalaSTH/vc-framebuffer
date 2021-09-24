#include "types.h"
#include "defs.h"
#include "param.h"
#include "traps.h"
#include "spinlock.h"
#include "sleeplock.h"
#include "fs.h"
#include "file.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "x86.h"

void
plotpixel(int x, int y, int color)
{
  int position = 0xA0000 + x + (y * 320);
  *(int *)P2V(position) = color;
}

