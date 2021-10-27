#include "Histogram.h"
#include <iostream>
#define LOG_STR_VALUE(S,V) std::cout<<S<<V<<std::endl;
#define LOG_HIST_TBL_ID(S,ID,V,TOTAL_NB) std::cout<<S<<" 's value: "<<ID<<" : NUM is "<<V<<" Ratio is "<<((float)V*100/((float)TOTAL_NB))<<" %"<<std::endl;
#define CHANNEL_BGR_RED___OFFSET (2)
#define CHANNEL_BGR_BLUE__OFFSET (1)
#define CHANNEL_BGR_GREEN_OFFSET (0)
void IMAGE_8BIT_Histogram::log_Cur_HistogramTBL()
{
          for(int i=0;i<256;++i)
          {
                    LOG_HIST_TBL_ID("Cur_HistogramTBL",i,this->Cur_HistogramTBL[i],this->Total_Pixel_NUM*this->ImageChannelNB);
          }
}
void IMAGE_8BIT_Histogram::log_Cum_HistogramTBL()
{
          for(int i=0;i<256;++i)
          {
                    LOG_HIST_TBL_ID("Cum_HistogramTBL",i,this->Cum_HistogramTBL[i],this->Total_Pixel_NUM*this->ImageChannelNB);
          }
}
void IMAGE_8BIT_Histogram::cal_Cur_HistogramTBL()
{
          uint32_t width  = this->ImagePixelWidth;
          uint32_t height = this->ImagePixelHeight;
          uint32_t pixel_nb = this->Total_Pixel_NUM;
          uint8_t  *pixel_array = this->input_pixel_addr;
          // step1 memset 0x0000 for the table
          for(int i=0;i<256;i++)
          {
                    this->Cur_HistogramTBL[i]=0;
          }
          // step2 get number of pixels for each value(0~255)
          for(int i=0;i<pixel_nb*3;++i)
          {
                   this->Cur_HistogramTBL[(pixel_array[i])] ++;
          }
}
void IMAGE_8BIT_Histogram::cal_Cum_HistogramTBL()
{
          uint32_t monotic_number = 0;
          for(int i=0;i<256;i++)
          {
                    monotic_number+=this->Cur_HistogramTBL[i];
                    this->Cum_HistogramTBL[i] = monotic_number;
          }
}
void IMAGE_8BIT_Histogram::do_lut_by_Cum_HistogramTBL()
{
          uint32_t width  = this->ImagePixelWidth;
          uint32_t height = this->ImagePixelHeight;
          uint32_t pixel_nb = this->Total_Pixel_NUM;
          uint8_t  *pixel_array  = this->input_pixel_addr;
          uint8_t  *output_array = this->output_pixel_addr;
          uint8_t newLUT[256];
          for(int i=0;i<256;i++)
          {
                    newLUT[i] = (uint8_t)(this->Cum_HistogramTBL[i] * 255 /this->Total_Pixel_NUM*this->ImageChannelNB);
          }
          for(int i=0;i<pixel_nb*3;++i)
          {
                    output_array[i] = newLUT[pixel_array[i]];
          }         
}
