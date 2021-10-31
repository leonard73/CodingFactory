#include <iostream>
#include <stdint.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#ifdef _COMPLIE_LINUX_
#include <sys/time.h>
#define mingw_gettimeofday (gettimeofday)
#endif
#define DEFAULT_TAYLOR_LEVEL_NUM  (32)
#define LOOP_N_TIMES              (1024*32)
#define LOG_LINE_STR(S) std::cout<<S<<std::endl
#define LOG_LINE_STR_INT(S,I) std::cout<<S<<I<<std::endl
double do_taylor_sin(double rad);
double do_taylor_sin_opt(double rad);
#define RATIO_PI_DIVID_180              ((M_PI/180.0F))
#define DEG_MATH_H_ARCSIN(X)            (asin(X)*180/M_PI)
#define VAL_MATH_H_SIN_RAD(X)           (sin(X))
#define VAL_MATH_H_SIN_DEG(X)           (sin((double)X*RATIO_PI_DIVID_180))
#define VAL_TAYLOR_SIN_RAD(X)           (do_taylor_sin(X))
#define VAL_TAYLOR_SIN_DEG(X)           (do_taylor_sin((double)X*RATIO_PI_DIVID_180))
#define VAL_TAYLOR_SIN_OPT_RAD(X)       (do_taylor_sin_opt(X))
#define VAL_TAYLOR_SIN_OPT_DEG(X)       (do_taylor_sin_opt((double)X*RATIO_PI_DIVID_180))
double do_taylor_sin(double rad)
{
    double ret = (double)rad;
    double rad_pow_acc=(double)rad;
    double denominator_acc=1;
    for(unsigned int i=1;i<DEFAULT_TAYLOR_LEVEL_NUM;++i)
    {
        rad_pow_acc*=(-1.0)*rad*rad;
        denominator_acc*= (double)(2 * i )*(double)(2 * i +  1);
        double numerator   = rad_pow_acc;
        double denominator = denominator_acc;
        ret  +=  (numerator/denominator);
    }
    return (double)ret;
}
double do_taylor_sin_opt(double rad)
{
    double ret = (double)rad;
    double rad_pow_acc=(double)rad;
    double denominator_acc=1;
    double rad_2 =  rad*rad;
    for(unsigned int i=1;i<DEFAULT_TAYLOR_LEVEL_NUM;++i)
    {
        rad_pow_acc*=(-1.0)*rad_2;
        denominator_acc*= (double)(i*i*4+2*i);
        double numerator   = rad_pow_acc;
        double denominator = denominator_acc;
        ret  +=  (numerator/denominator);
    }
    return (double)ret;
}
#define LOOPN(X) for(int k=0;k<LOOP_N_TIMES;++k)  {   X }
int main(int argc,char * argv[])
{
    struct timeval startTc,endTc;
    int64_t ticksCount;
    struct timezone timez;
    LOG_LINE_STR("Methematic Functions Demo!");
    double degree_input = atof(argv[1]);
    LOG_LINE_STR_INT("degree_input is : ",degree_input);
    //test sinf
    LOG_LINE_STR("#############################");
    LOG_LINE_STR("STEP1: DO MATH_H SIN FUNCTION");
    mingw_gettimeofday (&startTc, &timez);
    LOG_LINE_STR_INT("TEST sinf:             ",VAL_MATH_H_SIN_DEG(degree_input));
    mingw_gettimeofday (&endTc, &timez);
    ticksCount = (endTc.tv_sec-startTc.tv_sec)*1000000 + endTc.tv_usec-startTc.tv_usec;
    LOG_LINE_STR_INT("Latency Us:            ",ticksCount);
    LOG_LINE_STR("#############################");
    LOG_LINE_STR("STEP2: DO TAYLOR SIN FUNCTION");
    mingw_gettimeofday (&startTc, &timez);
    LOOPN(VAL_TAYLOR_SIN_DEG(degree_input););
    mingw_gettimeofday (&endTc, &timez);
    LOG_LINE_STR_INT("TEST Taylor sinf:      ",VAL_TAYLOR_SIN_DEG(degree_input));
    ticksCount = (endTc.tv_sec-startTc.tv_sec)*1000000 + endTc.tv_usec-startTc.tv_usec;
    LOG_LINE_STR_INT("Latency Us:            ",ticksCount);
    LOG_LINE_STR("#############################");
    LOG_LINE_STR("STEP3: DO TAYLOR SIN FUNCTION (OPT)");
    mingw_gettimeofday (&startTc, &timez);
    LOOPN(VAL_TAYLOR_SIN_OPT_DEG(degree_input););
    mingw_gettimeofday (&endTc, &timez);
    LOG_LINE_STR_INT("TEST Taylor sinf(opt): ",VAL_TAYLOR_SIN_OPT_DEG(degree_input));
    ticksCount = (endTc.tv_sec-startTc.tv_sec)*1000000 + endTc.tv_usec-startTc.tv_usec;
    LOG_LINE_STR_INT("Latency Us:            ",ticksCount);
    LOG_LINE_STR("#############################");
    system("pause");
}