#include <stdio.h>
#include <stdlib.h>
#include "formatSDK.h"
#include "Histogram.h"
#define DEMO_READ_BMP_PATH "../../data/splash.bmp"
#define DEMO_SAVE_BMP_PATH "output.bmp"
#define ORIGINAL_DATA_LENGTH_BYTES (128)
unsigned char data[ORIGINAL_DATA_LENGTH_BYTES];
void xvisio_quiz1_histogramAll(IMAGE_8BIT_Histogram * quiz1_hist_parameter_ptr);
IMAGE_8BIT_Histogram global_quiz1_hist_parameter;
int main()
{
    printf("This is Image Histogram demo project\n");

    /* init thirdparty libformatsdk class */
    formatSDK::BMP_DATA bmp_load_data;
    formatSDK::bmpCtl   bmpCTL_obj =  formatSDK::bmpCtl(formatSDK::bmpCtl::bmpMode_ReadBMP);
    /* load bmp bgr data into  bmp_load_data's pixel_raw_array */
    {
        bmpCTL_obj.read_bmp_file(DEMO_READ_BMP_PATH,bmp_load_data);
        bmpCTL_obj.log_bmp_header_info();
    }
    
    {
        global_quiz1_hist_parameter.ImageChannelNB   = bmp_load_data.bmp_header_struct.bmp_info_struct.bmpInfo_bitcount>>3;
        global_quiz1_hist_parameter.ImagePixelWidth  = bmp_load_data.bmp_header_struct.bmp_info_struct.bmpInfo_width;
        global_quiz1_hist_parameter.ImagePixelHeight = bmp_load_data.bmp_header_struct.bmp_info_struct.bmpInfo_height;
        global_quiz1_hist_parameter.Total_Pixel_NUM  = global_quiz1_hist_parameter.ImagePixelWidth * global_quiz1_hist_parameter.ImagePixelHeight;
        global_quiz1_hist_parameter.input_pixel_addr = (uint8_t*) (&(bmp_load_data.pixel_raw_array[0]));
        
        /* XVISIO_QUESTION1 : PLEASE INIT <global_quiz1_hist_parameter> OF THE SAME MEMEORY SAPCE OF <input_pixel_addr>*/
        global_quiz1_hist_parameter.output_pixel_addr= (uint8_t*) malloc(global_quiz1_hist_parameter.Total_Pixel_NUM * 3 * sizeof(uint8_t));
        /* set parameters finished, call <xvisio_quiz1_histogramAll> */
        xvisio_quiz1_histogramAll(&global_quiz1_hist_parameter);
        /* XVISIO_QUESTION1 : PLEASE FREE <global_quiz1_hist_parameter> */
                bmpCTL_obj.save_bgr_bmp(    DEMO_SAVE_BMP_PATH,
                                    global_quiz1_hist_parameter.output_pixel_addr,
                                    bmp_load_data.bmp_header_struct.bmp_info_struct.bmpInfo_width,
                                    bmp_load_data.bmp_header_struct.bmp_info_struct.bmpInfo_height
                                );
        free(global_quiz1_hist_parameter.output_pixel_addr);

    }

    {
        bmpCTL_obj.read_bmp_file(DEMO_SAVE_BMP_PATH,bmp_load_data);
        bmpCTL_obj.log_bmp_header_info(); 
    }

    {
        global_quiz1_hist_parameter.ImageChannelNB   = bmp_load_data.bmp_header_struct.bmp_info_struct.bmpInfo_bitcount>>3;
        global_quiz1_hist_parameter.ImagePixelWidth  = bmp_load_data.bmp_header_struct.bmp_info_struct.bmpInfo_width;
        global_quiz1_hist_parameter.ImagePixelHeight = bmp_load_data.bmp_header_struct.bmp_info_struct.bmpInfo_height;
        global_quiz1_hist_parameter.Total_Pixel_NUM  = global_quiz1_hist_parameter.ImagePixelWidth * global_quiz1_hist_parameter.ImagePixelHeight;
        global_quiz1_hist_parameter.input_pixel_addr = (uint8_t*) (&(bmp_load_data.pixel_raw_array[0]));
        
        /* XVISIO_QUESTION1 : PLEASE INIT <global_quiz1_hist_parameter> OF THE SAME MEMEORY SAPCE OF <input_pixel_addr>*/
        global_quiz1_hist_parameter.output_pixel_addr= (uint8_t*) malloc(global_quiz1_hist_parameter.Total_Pixel_NUM * 3 * sizeof(uint8_t));
        /* set parameters finished, call <xvisio_quiz1_histogramAll> */
        xvisio_quiz1_histogramAll(&global_quiz1_hist_parameter);
        /* XVISIO_QUESTION1 : PLEASE FREE <global_quiz1_hist_parameter> */
                bmpCTL_obj.save_bgr_bmp(    DEMO_SAVE_BMP_PATH,
                                    global_quiz1_hist_parameter.output_pixel_addr,
                                    bmp_load_data.bmp_header_struct.bmp_info_struct.bmpInfo_width,
                                    bmp_load_data.bmp_header_struct.bmp_info_struct.bmpInfo_height
                                );
        free(global_quiz1_hist_parameter.output_pixel_addr);        
    }
    /* save bmp output */
    {

    }

//     set_const_channels_bgr( bmp_load_data.pixel_raw_array,
//                             bmp_load_data.bmp_header_struct.bmp_info_struct.bmpInfo_width,
//                             bmp_load_data.bmp_header_struct.bmp_info_struct.bmpInfo_height,
//                             RED___CHANNEL,
//                            150);
    system("pause");

}
void xvisio_quiz1_histogramAll(IMAGE_8BIT_Histogram * quiz1_hist_parameter_ptr)
{
    // log_current_Histogram_Table();
    quiz1_hist_parameter_ptr->cal_Cur_HistogramTBL();
    // quiz1_hist_parameter_ptr->log_Cur_HistogramTBL();
    quiz1_hist_parameter_ptr->cal_Cum_HistogramTBL();
    // quiz1_hist_parameter_ptr->log_Cum_HistogramTBL();
    quiz1_hist_parameter_ptr->do_lut_by_Cum_HistogramTBL();
    quiz1_hist_parameter_ptr->draw_Cur_HistogramTBL();
    quiz1_hist_parameter_ptr->draw_Cum_HistogramTBL();
}