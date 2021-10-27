#include <stdio.h>
#include "formatSDK.h"
#include "huffman.h"
#define DEMO_READ_BMP_PATH "../../data/splash.bmp"
#define DEMO_SAVE_BMP_PATH "output.bmp"
#define ORIGINAL_DATA_LENGTH_BYTES (128)
unsigned char data[ORIGINAL_DATA_LENGTH_BYTES];
int main()
{
    printf("This is huffman demo project\n");
              formatSDK::bmpCtl   bmpCTL_obj =  formatSDK::bmpCtl(formatSDK::bmpCtl::bmpMode_ReadBMP);
    formatSDK::BMP_DATA bmp_load_data;
    bmpCTL_obj.read_bmp_file(DEMO_READ_BMP_PATH,bmp_load_data);
    bmpCTL_obj.log_bmp_header_info();
//     set_const_channels_bgr( bmp_load_data.pixel_raw_array,
//                             bmp_load_data.bmp_header_struct.bmp_info_struct.bmpInfo_width,
//                             bmp_load_data.bmp_header_struct.bmp_info_struct.bmpInfo_height,
//                             RED___CHANNEL,
//                            150);
    bmpCTL_obj.save_bgr_bmp( DEMO_SAVE_BMP_PATH,
                             bmp_load_data.pixel_raw_array,
                             bmp_load_data.bmp_header_struct.bmp_info_struct.bmpInfo_width,
                             bmp_load_data.bmp_header_struct.bmp_info_struct.bmpInfo_height);
}