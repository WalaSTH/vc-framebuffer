#include "vga.h"
#include "types.h"
#include "x86.h"
#include "memlayout.h"

static void 
write_regs(uchar *regs)
{
  uint i;

/* write MISCELLANEOUS reg */
  outb(VGA_MISC_WRITE, *regs);
  regs++;
/* write SEQUENCER regs */
  for(i = 0; i < VGA_NUM_SEQ_REGS; i++)
  {
      outb(VGA_SEQ_INDEX, i);
      outb(VGA_SEQ_DATA, *regs);
      regs++;
  }
/* unlock CRTC registers */
  outb(VGA_CRTC_INDEX, 0x03);
  outb(VGA_CRTC_DATA, inb(VGA_CRTC_DATA) | 0x80);
  outb(VGA_CRTC_INDEX, 0x11);
  outb(VGA_CRTC_DATA, inb(VGA_CRTC_DATA) & ~0x80);
/* make sure they remain unlocked */
  regs[0x03] |= 0x80;
  regs[0x11] &= ~0x80;
/* write CRTC regs */
  for(i = 0; i < VGA_NUM_CRTC_REGS; i++)
  {
    outb(VGA_CRTC_INDEX, i);
      outb(VGA_CRTC_DATA, *regs);
      regs++;
  }
/* write GRAPHICS CONTROLLER regs */
  for(i = 0; i < VGA_NUM_GC_REGS; i++)
  {
      outb(VGA_GC_INDEX, i);
      outb(VGA_GC_DATA, *regs);
      regs++;
  }
/* write ATTRIBUTE CONTROLLER regs */
  for(i = 0; i < VGA_NUM_AC_REGS; i++)
  {
      (void)inb(VGA_INSTAT_READ);
      outb(VGA_AC_INDEX, i);
      outb(VGA_AC_WRITE, *regs);
      regs++;
  }
/* lock 16-color palette and unblank display */
  (void)inb(VGA_INSTAT_READ);
  outb(VGA_AC_INDEX, 0x20);
}

/*video_toggle will toggle between 13h mode and text mode.
13h mode is activated when called with a positve value on enable
text mode is activated when called with enable set to 0.*/
void 
modeswitch(int enable)
{
  //VGA REGISTER DUMPS FOR VARIOUS GRAPHICS MODES//
  /* 256-color */   
  uchar g_320x200x256[] =
  {
  /* MISC */
      0x63,
  /* SEQ */
      0x03, 0x01, 0x0F, 0x00, 0x0E,
  /* CRTC */
      0x5F, 0x4F, 0x50, 0x82, 0x54, 0x80, 0xBF, 0x1F,
      0x00, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x9C, 0x0E, 0x8F, 0x28,    0x40, 0x96, 0xB9, 0xA3,
      0xFF,
  /* GC */
      0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x05, 0x0F,
      0xFF,
  /* AC */
      0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
      0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
      0x41, 0x00, 0x0F, 0x00,    0x00
  };

  /*Text mode*/
  uchar g_80x25_text[] =
  {
  /* MISC */
    0x67,
  /* SEQ */
    0x03, 0x00, 0x03, 0x00, 0x02,
  /* CRTC */
    0x5F, 0x4F, 0x50, 0x82, 0x55, 0x81, 0xBF, 0x1F,
    0x00, 0x4F, 0x0D, 0x0E, 0x00, 0x00, 0x00, 0x50,
    0x9C, 0x0E, 0x8F, 0x28, 0x1F, 0x96, 0xB9, 0xA3,
    0xFF,
  /* GC */
    0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x0E, 0x00,
    0xFF,
  /* AC */
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x14, 0x07,
    0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,
    0x0C, 0x00, 0x0F, 0x08, 0x00
  };
  if(enable == 1 ){
    /* Turn 256-color on */
    write_regs(g_320x200x256);

    /* 	Clean the "garbage" painting all black */
    for(unsigned int i = 0;i<320;++i)
      for(unsigned int j = 0;j<200;++j)
        plotpixel(i,j,0);
  }
  
  else{
    /* Disable 13h mode and turn text-mode */
    write_regs(g_80x25_text);
  }
}

//////////////
//Plotpixel and plotrectangle
/////////////

void
plotpixel(int x, int y, char color)
{
  int position = 0xA0000 + x + (y * 320);
  *(char *)P2V(position) = color;
}


void
plotrectangle(int x1,int y1,int x2,int y2,char color){
  for(int i = x1; i < (x2); ++i ){
    for(int j = y1; j < (y2); ++j){
      plotpixel(i,j,color);
    }
  }
}

