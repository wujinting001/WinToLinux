#ifndef __WTYPES_H__
#define __WTYPES_H__

#include <stddef.h>
#include <cwchar>
#include <stdint.h>

typedef float                    FLOAT;
typedef char                     CHAR;
typedef char                     TCHAR, *PTCHAR;
typedef unsigned char            UCHAR;
typedef int                      BOOL;
typedef unsigned long             DWORD;
typedef DWORD                    *LPDWORD;
typedef unsigned short           WORD;
typedef unsigned char            BYTE;
typedef unsigned char            byte;
typedef BYTE*                    PBYTE;
typedef BYTE*                    LPBYTE;
typedef unsigned long            ULONG;
typedef int                      LONG;
typedef void*                    LPVOID;
typedef long long                LONGLONG;
typedef long                     LPARAM;
typedef long                     WPARAM;
//typedef long long                __int64;
//typedef int                      __int32;
//typedef short                    __int16;
//typedef char                     __int8;
#define __int64                  long long
#define __int32                  int
#define __int16                  short
#define __int8                   char
typedef long long                __time64_t;
typedef wchar_t                  WCHAR;
typedef unsigned int             DWORD_PTR;
typedef size_t                   SIZE_T;
typedef unsigned int             UINT;
typedef int                      INT;
typedef double                   DOUBLE;
typedef long long                INT64;
typedef unsigned long long       UINT64;
typedef unsigned int             UINT32;
typedef void*                    HINSTANCE;
typedef LONGLONG                 REFERENCE_TIME;
typedef char                     *NPSTR, *LPSTR, *PSTR;
typedef const char               *LPCTSTR;
typedef LPSTR                    PTSTR, LPTSTR, PUTSTR, LPUTSTR;
typedef wchar_t*                 LPWSTR;
typedef short                    SHORT;
typedef unsigned short           USHORT;
typedef unsigned short           u_short;
typedef int*                     PLONG;
typedef int                      HRESULT;
typedef const wchar_t            *LPCWSTR, *PCWSTR;
typedef const char               *LPCSTR, *PCSTR;
typedef unsigned long            ULONG_PTR, *PULONG_PTR;
typedef void                     *PVOID;
typedef void                     *HANDLE;
typedef unsigned long long       ULONGLONG;
typedef uint64_t                 DWORDLONG;
typedef DWORDLONG                *PDWORDLONG;
typedef DWORD                    COLORREF;

#ifdef __cplusplus
    #define EXTERN_C    extern "C"
#else
    #define EXTERN_C    extern
#endif
#define OUT
#define IN
#define far
#define near
#define FAR          far
#define NEAR         near
#define VOID         void
#define WINAPI       __attribute__((stdcall))
#define CALLBACK     __attribute__((stdcall))
#define _stdcall     __attribute__((stdcall))
#define __stdcall    __attribute__((stdcall))
#define __cdecl      __attribute__((cdecl))
#define STDMETHODCALLTYPE       __stdcall
#define STDMETHODIMP            HRESULT STDMETHODCALLTYPE
#define STDMETHODIMP_(type)     type STDMETHODCALLTYPE

#define STDAPI       extern "C" HRESULT STDMETHODCALLTYPE
#define THIS_
#define THIS         void
#define PURE         = 0

#define _HRESULT_TYPEDEF_(_sc) ((HRESULT)_sc)
#define E_POINTER              _HRESULT_TYPEDEF_(0x80004003L)
#define DECLARE_HANDLE(name) struct name##__{int unused;}; typedef struct name##__ *name
DECLARE_HANDLE(HBITMAP);
DECLARE_HANDLE(HMONITOR);
DECLARE_HANDLE(HDC);
DECLARE_HANDLE(HKEY);
typedef HKEY *PHKEY;

typedef struct _OVERLAPPED {
    ULONG_PTR Internal;
    ULONG_PTR InternalHigh;
    union {
        struct {
            DWORD Offset;
            DWORD OffsetHigh;
        } DUMMYSTRUCTNAME;
        PVOID Pointer;
    } DUMMYUNIONNAME;

    HANDLE  hEvent;
} OVERLAPPED, *LPOVERLAPPED;

typedef union _timecode {
   struct {
	 WORD   wFrameRate;
	 WORD   wFrameFract;
	 DWORD  dwFrames;
	 };
   DWORDLONG  qw;
   } TIMECODE;

typedef TIMECODE *PTIMECODE;

typedef struct tagTIMECODE_SAMPLE
    {
    LONGLONG qwTick;
    TIMECODE timecode;
    DWORD dwUser;
    DWORD dwFlags;
    } 	TIMECODE_SAMPLE;

typedef TIMECODE_SAMPLE *PTIMECODE_SAMPLE;

typedef struct tagBITMAPINFOHEADER{
        DWORD      biSize;
        LONG       biWidth;
        LONG       biHeight;
        WORD       biPlanes;
        WORD       biBitCount;
        DWORD      biCompression;
        DWORD      biSizeImage;
        LONG       biXPelsPerMeter;
        LONG       biYPelsPerMeter;
        DWORD      biClrUsed;
        DWORD      biClrImportant;
} BITMAPINFOHEADER, *LPBITMAPINFOHEADER, *PBITMAPINFOHEADER;

typedef union _ULARGE_INTEGER {
    struct {
        DWORD LowPart;
        DWORD HighPart;
    } DUMMYSTRUCTNAME;
    struct {
        DWORD LowPart;
        DWORD HighPart;
    } u;
    ULONGLONG QuadPart;
} ULARGE_INTEGER;

typedef union _LARGE_INTEGER {
    struct {
        DWORD LowPart;
        LONG HighPart;
    } DUMMYSTRUCTNAME;
    struct {
        DWORD LowPart;
        LONG HighPart;
    } u;
    ULONGLONG QuadPart;
} LARGE_INTEGER;
typedef LARGE_INTEGER *PLARGE_INTEGER;

typedef struct tagSIZE
{
    LONG        cx;
    LONG        cy;
} SIZE, *PSIZE, *LPSIZE;

typedef struct tagRECT
{
    LONG    left;
    LONG    top;
    LONG    right;
    LONG    bottom;
} RECT, *PRECT, NEAR *NPRECT, FAR *LPRECT;

/*
 *  extended waveform format structure used for all non-PCM formats. this
 *  structure is common to all non-PCM formats.
 */
typedef struct tWAVEFORMATEX
{
    WORD        wFormatTag;         /* format type */
    WORD        nChannels;          /* number of channels (i.e. mono, stereo...) */
    DWORD       nSamplesPerSec;     /* sample rate */
    DWORD       nAvgBytesPerSec;    /* for buffer estimation */
    WORD        nBlockAlign;        /* block size of data */
    WORD        wBitsPerSample;     /* number of bits per sample of mono data */
    WORD        cbSize;             /* the count in bytes of the size of */
                                    /* extra information (after cbSize) */
} WAVEFORMATEX, *PWAVEFORMATEX, NEAR *NPWAVEFORMATEX, FAR *LPWAVEFORMATEX;

typedef struct _RGNDATAHEADER {
    DWORD   dwSize;
    DWORD   iType;
    DWORD   nCount;
    DWORD   nRgnSize;
    RECT    rcBound;
} RGNDATAHEADER, *PRGNDATAHEADER;

typedef struct _RGNDATA {
    RGNDATAHEADER   rdh;
    char            Buffer[1];
} RGNDATA, *PRGNDATA, NEAR *NPRGNDATA, FAR *LPRGNDATA;

typedef struct tagPOINT
{
    LONG  x;
    LONG  y;
} POINT, *PPOINT, NEAR *NPPOINT, FAR *LPPOINT;

typedef struct tagPALETTEENTRY {
    BYTE        peRed;
    BYTE        peGreen;
    BYTE        peBlue;
    BYTE        peFlags;
} PALETTEENTRY, *PPALETTEENTRY, FAR *LPPALETTEENTRY;





#endif
