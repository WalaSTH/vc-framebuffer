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
plotrectangle(int x1,int y1,int x2,int y2,int color){
  for(int i = x1; i < (x2 - x1); ++i ){
    for(int j = y1; j < (y2 - y1); ++j){
      plotpixel(i,j,color);
    }
  }
}
