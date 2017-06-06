#ifndef STDIO_MACRO_H_
#define STDIO_MACRO_H_
 
#include <stdio.h>
 
#ifndef __STRICT_ANSI__
#   define SWPRINTF(_DstBuf_, _MaxCnt_, _Format_, ...) swprintf(_DstBuf_, _MaxCnt_, _Format_, ##__VA_ARGS__)
#   define VSWPRITEF(_DstBuf_, _MaxCnt_, _Format_, _ArgList_) vswprintf(_DstBuf_, _MaxCnt_, _Format_, _ArgList_)
#else
#   define SWPRINTF(_DstBuf_, _MaxCnt_, _Format_, ...) swprintf(_DstBuf_, _Format_, ##__VA_ARGS__)
#   define VSWPRINTF(_DstBuf_, _MaxCnt_, _Format_, _ArgList_) vswprintf(_DstBuf_, _Format_, _ArgList_)
#endif
 
#if (defined _MSC_VER)
 
#   if (_MSC_VER >= 1400)
#       define  snprintf(_DstBuf_, _MaxCnt_, _Format_, ...)      _snprintf(_DstBuf_, _MaxCnt_, _Format_, ##__VA_ARGS__)
#       define snwprintf(_DstBuf_, _MaxCnt_, _Format_, ...)     _snwprintf(_DstBuf_, _MaxCnt_, _Format_, ##__VA_ARGS__)
#       define  snscanf(_SrcBuf_, _MaxCnt_, _Format_, ...)       _snscanf(_SrcBuf_, _MaxCnt_, _Format_, ##__VA_ARGS__)
#       define snwscanf(_SrcBuf_, _MaxCnt_, _Format_, ...)      _snwscanf(_SrcBuf_, _MaxCnt_, _Format_, ##__VA_ARGS__)
#   else
#       define  snprintf(_DstBuf_, _MaxCnt_, _Format_, ...)      sprintf(_DstBuf_, _Format_, ##__VA_ARGS__)
#       define snwprintf(_DstBuf_, _MaxCnt_, _Format_, ...)     SWPRINTF(_DstBuf_, _MaxCnt_, _Format_, ##__VA_ARGS__)
#       define  snscanf(_SrcBuf_, _MaxCnt_, _Format_, ...)       sscanf(_SrcBuf_, _Format_, ##__VA_ARGS__)
#       define snwscanf(_SrcBuf_, _MaxCnt_, _Format_, ...)      swscanf(_SrcBuf_, _Format_, ##__VA_ARGS__)
#   endif
 
#else
 
#   if (!defined __GNUC__) || (__GNUC__ < 3)
#       define  snprintf(_DstBuf_, _MaxCnt_, _Format_, ...)              sprintf(_DstBuf_, _Format_, ##__VA_ARGS__)
#       define snwprintf(_DstBuf_, _MaxCnt_, _Format_, ...)             SWPRINTF(_DstBuf_, _MaxCnt_, _Format_, ##__VA_ARGS__)
#       define  vsnprintf(_DstBuf_, _MaxCnt_, _Format_, _ArgList_)       vsprintf(_DstBuf_, _Format_, _ArgList_)
#       define vsnwprintf(_DstBuf_, _MaxCnt_, _Format_, _ArgList_)      VSWPRINTF(_DstBuf_, _MaxCnt_, _Format_, _ArgList_)
 
#       define  snscanf(_SrcBuf_, _MaxCnt_, _Format_, ...)       sscanf(_SrcBuf_, _Format_, ##__VA_ARGS__)
#       define snwscanf(_SrcBuf_, _MaxCnt_, _Format_, ...)      swscanf(_SrcBuf_, _Format_, ##__VA_ARGS__)
#   endif
 
#   define  printf_s(_Format_, ...)                      printf(_Format_, ##__VA_ARGS__)
#   define wprintf_s(_Format_, ...)                     wprintf(_Format_, ##__VA_ARGS__)
#   define  _printf_l(_Format_, _Locale_, ...)           printf(_Format_, ##__VA_ARGS__)
#   define _wprintf_l(_Format_, _Locale_, ...)          wprintf(_Format_, ##__VA_ARGS__)
#   define  _printf_s_l(_Format_, _Locale_, ...)         printf(_Format_, ##__VA_ARGS__)
#   define _wprintf_s_l(_Format_, _Locale_, ...)        wprintf(_Format_, ##__VA_ARGS__)
#   define  vprintf_s(_Format_, _ArgList_)                  vprintf(_Format_, _ArgList_)
#   define vwprintf_s(_Format_, _ArgList_)                 vwprintf(_Format_, _ArgList_)
#   define  _vprintf_p(_Format_, _ArgList_)                 vprintf(_Format_, _ArgList_)
#   define _vwprintf_p(_Format_, _ArgList_)                vwprintf(_Format_, _ArgList_)
#   define  _vprintf_s_l(_Format_, _Locale_, _ArgList_)     vprintf(_Format_, _ArgList_)
#   define _vwprintf_s_l(_Format_, _Locale_, _ArgList_)    vwprintf(_Format_, _ArgList_)
#   define  _vprintf_p_l(_Format_, _Locale_, _ArgList_)     vprintf(_Format_, _ArgList_)
#   define _vwprintf_p_l(_Format_, _Locale_, _ArgList_)    vwprintf(_Format_, _ArgList_)
 
#   define  fprintf_s(_Stream_, _Format_, ...)                   fprintf(_Stream_, _Format_, ##__VA_ARGS__)
#   define fwprintf_s(_Stream_, _Format_, ...)                  fwprintf(_Stream_, _Format_, ##__VA_ARGS__)
#   define  _fprintf_p(_Stream_, _Format_, ...)                  fprintf(_Stream_, _Format_, ##__VA_ARGS__)
#   define _fwprintf_p(_Stream_, _Format_, ...)                 fwprintf(_Stream_, _Format_, ##__VA_ARGS__)
#   define  _fprintf_s_l(_Stream_, _Format_, _Locale_, ...)      fprintf(_Stream_, _Format_, ##__VA_ARGS__)
#   define _fwprintf_s_l(_Stream_, _Format_, _Locale_, ...)     fwprintf(_Stream_, _Format_, ##__VA_ARGS__)
#   define  _fprintf_p_l(_Stream_, _Format_, _Locale_, ...)      fprintf(_Stream_, _Format_, ##__VA_ARGS__)
#   define _fwprintf_p_l(_Stream_, _Format_, _Locale_, ...)     fwprintf(_Stream_, _Format_, ##__VA_ARGS__)
#   define  vfprintf_s(_Stream_, _Format_, _ArgList_)                vfprintf(_Stream_, _Format_, _ArgList_)
#   define vfwprintf_s(_Stream_, _Format_, _ArgList_)               vfwprintf(_Stream_, _Format_, _ArgList_)
#   define  _vfprintf_p(_Stream_, _Format_, _ArgList_)               vfprintf(_Stream_, _Format_, _ArgList_)
#   define _vfwprintf_p(_Stream_, _Format_, _ArgList_)              vfwprintf(_Stream_, _Format_, _ArgList_)
#   define  _vfprintf_s_l(_Stream_, _Format_, _Locale_, _ArgList_)   vfprintf(_Stream_, _Format_, _ArgList_)
#   define _vfwprintf_s_l(_Stream_, _Format_, _Locale_, _ArgList_)  vfwprintf(_Stream_, _Format_, _ArgList_)
#   define  _vfprintf_p_l(_Stream_, _Format_, _Locale_, _ArgList_)   vfprintf(_Stream_, _Format_, _ArgList_)
#   define _vfwprintf_p_l(_Stream_, _Format_, _Locale_, _ArgList_)  vfwprintf(_Stream_, _Format_, _ArgList_)
 
#   define  sprintf_s(_DstBuf_, _SizeInBytes_, _Format_, ...)                    snprintf(_DstBuf_, _SizeInBytes_, _Format_, ##__VA_ARGS__)
#   define swprintf_s(_DstBuf_, _SizeInWords_, _Format_, ...)                   snwprintf(_DstBuf_, _SizeInWords_, _Format_, ##__VA_ARGS__)
#   define  _sprintf_p(_DstBuf_, _MaxCnt_, _Format_, ...)                        snprintf(_DstBuf_, _MaxCnt_, _Format_, ##__VA_ARGS__)
#   define _swprintf_p(_DstBuf_, _MaxCnt_, _Format_, ...)                       snwprintf(_DstBuf_, _MaxCnt_, _Format_, ##__VA_ARGS__)
#   define  _sprintf_l(_DstBuf_, _Format_, _Locale_, ...)                        sprintf(_DstBuf_, _Format_, ##__VA_ARGS__)
#   define _swprintf_l(_DstBuf_, _MaxCnt_, _Format_, _Locale_, ...)             snwprintf(_DstBuf_, _MaxCnt_, _Format_, ##__VA_ARGS__)
#   define __swprintf_l(_DstBuf_, _MaxCnt_, _Format_, _Locale_, ...)            snwprintf(_DstBuf_, _MaxCnt_, _Format_, ##__VA_ARGS__)
#   define  _sprintf_s_l(_DstBuf_, _SizeInBytes_, _Format_, _Locale_, ...)       snprintf(_DstBuf_, _SizeInBytes_, _Format_, ##__VA_ARGS__)
#   define _swprintf_s_l(_DstBuf_, _SizeInWords_, _Format_, ...)                snwprintf(_DstBuf_, _SizeInWords_, _Format_, ##__VA_ARGS__)
#   define  _sprintf_p_l(_DstBuf_, _MaxCnt_, _Format_, _Locale_, ...)            snprintf(_DstBuf_, _MaxCnt_, _Format_, ##__VA_ARGS__)
#   define _swprintf_p_l(_DstBuf_, _MaxCnt_, _Format_, _Locale_, ...)           snwprintf(_DstBuf_, _MaxCnt_, _Format_, ##__VA_ARGS__)
#   define  vsprintf_s(_DstBuf_, _SizeInBytes_, _Format_, _ArgList_)             snprintf(_DstBuf_, _SizeInBytes_, _Format_, _ArgList_)
#   define vswprintf_s(_DstBuf_, _SizeInWords_, _Format_, _ArgList_)            snwprintf(_DstBuf_, _SizeInWords_, _Format_, _ArgList_)
#   define  _vsprintf_p(_DstBuf_, _MaxCnt_, _Format_, _ArgList_)                 vsnprintf(_DstBuf_, _MaxCnt_, _Format_, _ArgList_)
#   define _vswprintf_p(_DstBuf_, _MaxCnt_, _Format_, _ArgList_)                vsnwprintf(_DstBuf_, _MaxCnt_, _Format_, _ArgList_)
#   define  _vsprintf_l(_DstBuf_, _Format_, _Locale_, _ArgList_)                 vsprintf(_DstBuf_, _Format_, _ArgList_)
#   define _vswprintf_l(_DstBuf_, _MaxCnt_, _Format_, _Locale_, _ArgList_)      vsnwprintf(_DstBuf_, _MaxCnt_, _Format_, _ArgList_)
#   define __vswprintf_l(_DstBuf_, _MaxCnt_, _Format_, _Locale_, _ArgList_)     vsnwprintf(_DstBuf_, _MaxCnt_, _Format_, _ArgList_)
#   define  _vsprintf_p_l(_DstBuf_, _MaxCnt_, _Format_, _Locale_, _ArgList_)     vsnprintf(_DstBuf_, _MaxCnt_, _Format_, _ArgList_)
#   define _vswprintf_p_l(_DstBuf_, _MaxCnt_, _Format_, _Locale_, _ArgList_)    vsnwprintf(_DstBuf_, _MaxCnt_, _Format_, _ArgList_)
 
#   define  _snprintf(_DstBuf_, _MaxCnt_, _Format_, ...)                                 snprintf(_DstBuf_, _MaxCnt_, _Format_, ##__VA_ARGS__)
#   define _snwprintf(_DstBuf_, _MaxCnt_, _Format_, ...)                                snwprintf(_DstBuf_, _MaxCnt_, _Format_, ##__VA_ARGS__)
#   define  _snprintf_c(_DstBuf_, _MaxCnt_, _Format_, ...)                               snprintf(_DstBuf_, _MaxCnt_, _Format_, ##__VA_ARGS__)
#   define  _snprintf_s(_DstBuf_, _SizeInBytes_, _MaxCnt_, _Format_, ...)                snprintf(_DstBuf_, _MaxCnt_, _Format_, ##__VA_ARGS__)
#   define _snwprintf_s(_DstBuf_, _SizeInWords_, _MaxCnt_, _Format_, ...)               snwprintf(_DstBuf_, _MaxCnt_, _Format_, ##__VA_ARGS__)
#   define  _snprintf_l(_DstBuf_, _MaxCnt_, _Format_, _Locale_, ...)                     snprintf(_DstBuf_, _MaxCnt_, _Format_, ##__VA_ARGS__)
#   define _snwprintf_l(_DstBuf_, _MaxCnt_, _Format_, _Locale_, ...)                    snwprintf(_DstBuf_, _MaxCnt_, _Format_, ##__VA_ARGS__)
#   define  _snprintf_s_l(_DstBuf_, _SizeInBytes_, _MaxCnt_, _Format_, _Locale_, ...)    snprintf(_DstBuf_, _MaxCnt_, _Format_, ##__VA_ARGS__)
#   define _snwprintf_s_l(_DstBuf_, _SizeInWords_, _MaxCnt_, _Format_, _Locale_, ...)   snwprintf(_DstBuf_, _MaxCnt_, _Format_, ##__VA_ARGS__)
#   define  vsnprintf_s(_DstBuf_, _MaxCnt_, _Format_, _ArgList_)                                 vsnprintf(_DstBuf_, _MaxCnt_, _Format_, _ArgList_)
#   define  _vsnprintf_c(_DstBuf_, _MaxCnt_, _Format_, _ArgList_)                                vsnprintf(_DstBuf_, _MaxCnt_, _Format_, _ArgList_)
#   define   _vsnprintf_s(_DstBuf_, _SizeInBytes_, _MaxCnt_, _Format_, _ArgList_)                vsnprintf(_DstBuf_, _MaxCnt_, _Format_, _ArgList_)
#   define  _vsnwprintf_s(_DstBuf_, _SizeInWords_, _MaxCnt_, _Format_, _ArgList_)               vsnwprintf(_DstBuf_, _MaxCnt_, _Format_, _ArgList_)
#   define   _vsnprintf_l(_DstBuf_, _MaxCnt_, _Format_, _Locale_, _ArgList_)                     vsnprintf(_DstBuf_, _MaxCnt_, _Format_, _ArgList_)
#   define  _vsnwprintf_l(_DstBuf_, _MaxCnt_, _Format_, _Locale_, _ArgList_)                    vsnwprintf(_DstBuf_, _MaxCnt_, _Format_, _ArgList_)
#   define  _vsnprintf_c_l(_DstBuf_, _MaxCnt_, _Format_, _Locale_, _ArgList_)                    vsnprintf(_DstBuf_, _MaxCnt_, _Format_, _ArgList_)
#   define   _vsnprintf_s_l(_DstBuf_, _SizeInBytes_, _MaxCnt_, _Format_, _Locale_, _ArgList_)    vsnprintf(_DstBuf_, _MaxCnt_, _Format_, _ArgList_)
#   define  _vsnwprintf_s_l(_DstBuf_, _SizeInWords_, _MaxCnt_, _Format_, _Locale_, _ArgList_)   vsnwprintf(_DstBuf_, _MaxCnt_, _Format_, _ArgList_)
 
#   define  scanf_s(_Format_, ...)                   scanf(_Format_, ##__VA_ARGS__)
#   define wscanf_s(_Format_, ...)                  wscanf(_Format_, ##__VA_ARGS__)
#   define  _scanf_l(_Format_, _Locale_, ...)        scanf(_Format_, ##__VA_ARGS__)
#   define _wscanf_l(_Format_, _Locale_, ...)       wscanf(_Format_, ##__VA_ARGS__)
#   define  _scanf_s_l(_Format_, _Locale_, ...)      scanf(_Format_, ##__VA_ARGS__)
#   define _wscanf_s_l(_Format_, _Locale_, ...)     wscanf(_Format_, ##__VA_ARGS__)
 
#   define  fscanf_s(_Stream_, _Format_, ...)                    fscanf(_Stream_, _Format_, ##__VA_ARGS__)
#   define fwscanf_s(_Stream_, _Format_, ...)                   fwscanf(_Stream_, _Format_, ##__VA_ARGS__)
#   define  _fscanf_l(_Stream_, _Format_, _Locale_, ...)         fscanf(_Stream_, _Format_, ##__VA_ARGS__)
#   define _fwscanf_l(_Stream_, _Format_, _Locale_, ...)        fwscanf(_Stream_, _Format_, ##__VA_ARGS__)
#   define  _fscanf_s_l(_Stream_, _Format_, _Locale_, ...)       fscanf(_Stream_, _Format_, ##__VA_ARGS__)
#   define _fwscanf_s_l(_Stream_, _Format_, _Locale_, ...)      fwscanf(_Stream_, _Format_, ##__VA_ARGS__)
 
#   define  sscanf_s(_SrcBuf_, _Format_, ...)                   sscanf(_SrcBuf_, _Format_, ##__VA_ARGS__)
#   define swscanf_s(_SrcBuf_, _Format_, ...)                  swscanf(_SrcBuf_, _Format_, ##__VA_ARGS__)
#   define  _sscanf_l(_SrcBuf_, _Format_, _Locale_, ...)        sscanf(_SrcBuf_, _Format_, ##__VA_ARGS__)
#   define _swscanf_l(_SrcBuf_, _Format_, _Locale_, ...)       swscanf(_SrcBuf_, _Format_, ##__VA_ARGS__)
#   define  _sscanf_s_l(_SrcBuf_, _Format_, _Locale_, ...)      sscanf(_SrcBuf_, _Format_, ##__VA_ARGS__)
#   define _swscanf_s_l(_SrcBuf_, _Format_, _Locale_, ...)     swscanf(_SrcBuf_, _Format_, ##__VA_ARGS__)
 
#   define  _snscanf(_SrcBuf_, _MaxCnt_, _Format_, ...)                  sscanf(_SrcBuf_, _Format_, ##__VA_ARGS__)
#   define _snwscanf(_SrcBuf_, _MaxCnt_, _Format_, ...)                 swscanf(_SrcBuf_, _Format_, ##__VA_ARGS__)
#   define  _snscanf_s(_SrcBuf_, _MaxCnt_, _Format_, ...)                sscanf(_SrcBuf_, _Format_, ##__VA_ARGS__)
#   define _snwscanf_s(_SrcBuf_, _MaxCnt_, _Format_, ...)               swscanf(_SrcBuf_, _Format_, ##__VA_ARGS__)
#   define  _snscanf_l(_SrcBuf_, _MaxCnt_, _Format_, _Locale_, ...)      sscanf(_SrcBuf_, _Format_, ##__VA_ARGS__)
#   define _snwscanf_l(_SrcBuf_, _MaxCnt_, _Format_, _Locale_, ...)     swscanf(_SrcBuf_, _Format_, ##__VA_ARGS__)
#   define  _snscanf_s_l(_SrcBuf_, _MaxCnt_, _Format_, _Locale_, ...)    sscanf(_SrcBuf_, _Format_, ##__VA_ARGS__)
#   define _snwscanf_s_l(_SrcBuf_, _MaxCnt_, _Format_, _Locale_, ...)   swscanf(_SrcBuf_, _Format_, ##__VA_ARGS__)
 
#   define fread_s(_DstBuf_, _DstSize_, _ElemSize_, _Cnt_, _File_) fread(_DstBuf_, _DstSize_, _ElemSize_, _Cnt_, _File_)
#   define   gets_s(_Buf_, _SizeInBytes_)     gets(_Buf_)
#   define _getws_s(_Buf_, _SizeInWords_)   _getws(_Buf)
 
#endif
 
#endif