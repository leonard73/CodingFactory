#ifndef __HUFFMAN_H__
#define __HUFFMAN_H__
typedef struct HuffmanData_t
{
          unsigned int Huffman_LUT_Size;
          unsigned char * Huffman_LookUpTBL;
}HuffmanData;
typedef struct HuffmanCoding_t
{
          unsigned int Huffman_LUT_Size;
          unsigned int * HistogramTBL;
}HuffmanCoding;


#endif //__HUFFMAN_H__