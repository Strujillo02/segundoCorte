#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h> 
#endif

#define thesimpsons_width 104
#define thesimpsons_height 59
static unsigned char thesimpsons_bits[] = {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x32, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x02, 0x31, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x42, 0x21, 0x81, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x82, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x20, 0x63, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x31, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x38, 0xc0, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0xe0, 0xd1, 0x00, 0x00,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc1, 0x00,
   0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x81,
   0x31, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0x01, 0x00,
   0x01, 0x11, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x30, 0x80, 0x01,
   0x00, 0x01, 0x11, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00,
   0x03, 0x00, 0x01, 0x31, 0x0d, 0x04, 0x00, 0x00, 0x00, 0x00, 0x04, 0x01,
   0x00, 0x06, 0x00, 0x03, 0xe3, 0xf8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02,
   0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00,
   0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
   0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x08,
   0x00, 0x00, 0x20, 0x10, 0x1c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10,
   0x40, 0x00, 0x00, 0x20, 0x00, 0x18, 0x02, 0x00, 0x00, 0x08, 0x00, 0x00,
   0x08, 0x20, 0x18, 0x00, 0x20, 0x0c, 0x30, 0x06, 0x00, 0x00, 0x08, 0x08,
   0x08, 0x08, 0x21, 0x00, 0x00, 0x60, 0x08, 0x00, 0x0c, 0x00, 0x00, 0x08,
   0x04, 0x04, 0x04, 0x03, 0x00, 0x02, 0x40, 0x08, 0x00, 0x18, 0x00, 0x00,
   0x08, 0x04, 0x04, 0x04, 0x02, 0x00, 0x01, 0x40, 0x08, 0x00, 0x30, 0x10,
   0x00, 0x08, 0x04, 0x00, 0x84, 0x40, 0x88, 0x01, 0xc2, 0x08, 0x00, 0x60,
   0x00, 0x00, 0x08, 0x04, 0x00, 0x00, 0x40, 0x80, 0x00, 0xc3, 0x18, 0x00,
   0xc0, 0x01, 0x00, 0x08, 0x06, 0x00, 0x01, 0xc0, 0x80, 0x00, 0x83, 0x30,
   0x00, 0x80, 0x03, 0x00, 0x08, 0x42, 0x00, 0x01, 0x80, 0x41, 0x18, 0x02,
   0x60, 0x00, 0x00, 0x0e, 0x00, 0x08, 0xc2, 0x10, 0x03, 0x0f, 0x41, 0x10,
   0x02, 0xc0, 0x00, 0x00, 0x1c, 0x00, 0x08, 0xc2, 0x10, 0x07, 0x00, 0x40,
   0x18, 0x02, 0x80, 0x01, 0x00, 0x70, 0x00, 0x00, 0xc2, 0x17, 0x04, 0x10,
   0x40, 0x00, 0x00, 0x00, 0x01, 0x00, 0xc0, 0x01, 0x04, 0x02, 0x10, 0x0c,
   0x10, 0x60, 0x00, 0x71, 0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x02, 0x10,
   0x1c, 0x18, 0xc0, 0x80, 0xc1, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x04, 0x06,
   0x10, 0x00, 0x30, 0x80, 0x01, 0x03, 0x04, 0x00, 0x00, 0x00, 0x18, 0x0c,
   0x0c, 0x10, 0x00, 0xe0, 0x01, 0x1f, 0x00, 0x04, 0x00, 0x00, 0x02, 0x00,
   0x4c, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x01, 0x00, 0x00,
   0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x00, 0x04,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x80, 0xff, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };



U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);


void setup(void){
  u8g2.begin();
}

void loop(void){
  u8g2.clearBuffer();
  /*u8g2.setFont(u8g2_font_smart_patrol_nbp_tf);
  u8g2.drawStr(0, 10, "Hello World!");*/
  u8g2.drawXBM(0, 0, thesimpsons_width, thesimpsons_height, thesimpsons_bits);
  u8g2.sendBuffer();
  delay(1000);
}