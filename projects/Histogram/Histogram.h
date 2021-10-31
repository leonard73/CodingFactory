#ifndef __HISTOGRAM_H__
#define __HISTOGRAM_H__
#include <stdint.h>
typedef struct IMAGE_8BIT_Histogram_t
{
          uint32_t Cur_HistogramTBL[256];
          uint32_t Ref_HistogramTBL[256];
          uint32_t Cum_HistogramTBL[256];
          uint32_t Total_Pixel_NUM;
          uint32_t ImageChannelNB;
          uint32_t ImagePixelWidth;
          uint32_t ImagePixelHeight;
          uint8_t* input_pixel_addr;
          uint8_t* output_pixel_addr;
          void cal_Cur_HistogramTBL();
          void cal_Cum_HistogramTBL();
          void log_Cur_HistogramTBL();
          void log_Cum_HistogramTBL();
          void do_lut_by_Cum_HistogramTBL();
          void draw_Cur_HistogramTBL();
          void draw_Cum_HistogramTBL();
          // void Ref_HistogramTBL();
          // void Cum_HistogramTBL();
}IMAGE_8BIT_Histogram;

#endif //__HISTOGRAM_H__