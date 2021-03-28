#ifndef LCD_H
#define LCD_H

#include <stdint.h>
#include "misc.h"
#include "colors.h"

#define ENABLE_PIXEL_HASH 0 // define to 0 to disable pixel hashing

typedef struct {
	uint32_t X, Y;
} PT_T;

/*** ***/

// Ported functions for common LCD API

/** Initialize the LCD
*/
 void LCD_Init(void);

/** Set pixel color
*/
 void LCD_Plot_Pixel(PT_T * pos, COLOR_T * color);

/** Refresh LCD from local MCU frame buffer
*/
 void LCD_Refresh(void);

/** Fill entire LCD with given color
*/
 void LCD_Fill_Buffer(COLOR_T * color);
/** Fill specified rectangle with given color
*/

/** Plot given byte of packed data at given position
*/
 void LCD_Plot_Packed_Pixels(uint8_t fill_byte, PT_T * pos);

/** Plot given byte of packed data at given position and next byte based on right-shift amount
*/
void LCD_Plot_Packed_Pixels_Unaligned(uint8_t fill_byte, uint8_t r_shift, PT_T * pos);


/*** ***/
// Need to port these
void LCD_Fill_Rectangle(PT_T * p1, PT_T * p2, COLOR_T * color);
uint32_t LCD_Start_Rectangle(PT_T * p1, PT_T * p2);
void LCD_Write_Rectangle_Pixel(COLOR_T * color, unsigned int count);
// AD Opt
void LCD_Write_Rectangle_Pixel_Components(uint8_t R, uint8_t G, uint8_t B); // __attribute__((always_inline));
// AD Opt
void LCD_Write_Rectangle_Quad_Pixel_Components(uint32_t * R, uint32_t * G, uint32_t * B);
void LCD_Write_Rectangle_N_Quad_Pixel_Components(uint32_t * R, uint32_t * G, uint32_t * B, int32_t N);
// void LCD_Write_Rectangle_Quad_Pixel_Components(QUAD_UINT8_t R, QUAD_UINT8_t G, QUAD_UINT8_t B);

/*** ***/
 
 void LCD_Set_BL(uint8_t on);
 void LCD_Set_Backlight_Brightness(uint32_t brightness_percent);
 void LCD_Text_Set_Colors(COLOR_T * foreground, COLOR_T * background);

 void LCD_Erase(void);
 
 void LCD_Text_Test(void);
 void LCD_Text_Init(uint8_t font_num);
 void LCD_Text_PrintChar(PT_T * pos, char ch);
 void LCD_Text_PrintStr(PT_T * pos, char * str);
 void LCD_Text_PrintStr_RC( uint8_t  row, uint8_t col, char *  str);

 void Graphics_Test(void);
 void LCD_Draw_Line(PT_T * p1, PT_T * p2, COLOR_T * color);
 void LCD_Draw_Circle(PT_T * p1, int radius, COLOR_T * color, int filled);


 void LCD_TS_Init(void);
 uint32_t LCD_TS_Read(PT_T * position);
 void LCD_TS_Blocking_Read(PT_T * position);
 void LCD_TS_Test(void);
 void LCD_TS_Calibrate(void);

 extern uint8_t G_LCD_char_width, G_LCD_char_height;
 extern uint32_t pixel_data_hash;
#endif
