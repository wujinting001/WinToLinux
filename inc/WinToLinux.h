
#pragma once

#include <unistd.h>
#include <cwchar>
#include <memory.h>
#include <sys/time.h>
#include <errno.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include "stdio_macro.h"
#include "wtypes.h"

//#include "linux_ini_rw.h"
//#include "ErrorBase.h"
//#include "ObjBase.h"

#define __declspec(dllexport)
#define __declspec(dllimport)
#define interface struct
#define NULL 0
#define TRUE 1
#define FALSE 0
#define E_UNEXPECTED  0x8000FFFF
#define HWND   int
#define WINAPI
#define CLSCTX_INPROC_SERVER 0
#define __inline	inline
#define DECLARE_INTERFACE(iface) interface iface
#define CALLBACK
#define ASSERT(a)
//#define HANDLE      int
#define errno_t     int
#define MAX_PATH	 260
#define _MAX_PATH    260
#define _MAX_DRIVE   3
#define _MAX_DIR     256
#define _MAX_FNAME   256
#define _MAX_EXT     256
#define INFINITE     -1
#define WAIT_TIMEOUT -1
#define WAIT_OBJECT_0   0
#define E_FAIL         -1
#define EINVAL         -1
#define ENOSPC         0
#define _SH_DENYRW 0x10 /* deny read/write mode*/
#define _SH_DENYWR 0x20 /* deny write mode */
#define _SH_DENYRD 0x30 /* deny read mode */
#define _SH_DENYNO 0x40 /* deny none mode */
#define _SH_SECURE 0x80 /* secure mode */
#define O_BINARY 0
#define NO_ERROR 0
#define CP_ACP   0
#define CP_OEMCP 1
#define INVALID_HANDLE_VALUE NULL
#define MAKEWORD(a, b) ((WORD)(((BYTE)(((DWORD_PTR)(a)) & 0xff)) | ((WORD)((BYTE)(((DWORD_PTR)(b)) & 0xff))) << 8))
#define MAKE_HRESULT(sev,fac,code) \
    ((HRESULT) (((unsigned long)(sev)<<31) | ((unsigned long)(fac)<<16) | ((unsigned long)(code))) )
#define HIWORD(a) ( ( WORD ) ( ( ( DWORD )( a ) >> 16) & 0xFFFF ))
#define LOWORD(a) ((WORD)(((DWORD_PTR)(a)) & 0xffff))
#define SUCCEEDED(hr) (((HRESULT)(hr)>= 0))
#define FAILED(hr) (((HRESULT)(hr)) < 0)
#define S_OK       ((HRESULT)0L)
#define S_FALSE       ((HRESULT)1L)
#define NOERROR             0
#define ERROR_SUCCESS       0L
#define _HRESULT_TYPEDEF_(_sc) ((HRESULT)_sc)
#define E_NOINTERFACE          _HRESULT_TYPEDEF_(0x80004002L)
#define E_OUTOFMEMORY          _HRESULT_TYPEDEF_(0x8007000EL)
#define E_NOTIMPL              _HRESULT_TYPEDEF_(0x80004001L)
#define E_INVALIDARG           _HRESULT_TYPEDEF_(0x80070057L)
#define ResultFromScode(sc) ((HRESULT) (sc))

#define MAKEFOURCC(ch0, ch1, ch2, ch3)                              \
                ((DWORD)(BYTE)(ch0) | ((DWORD)(BYTE)(ch1) << 8) |   \
                ((DWORD)(BYTE)(ch2) << 16) | ((DWORD)(BYTE)(ch3) << 24 ))
/* MMIO macros */
#define mmioFOURCC(ch0, ch1, ch2, ch3)  MAKEFOURCC(ch0, ch1, ch2, ch3)

#ifdef CDV_TRANSCODER_EXPORTS
#define CDV_TRANSCODER_API __declspec(dllexport)
#else
#define CDV_TRANSCODER_API __declspec(dllimport)
#endif

#define UNREFERENCED_PARAMETER(P)          (P)
#define MAXIMUM_WAIT_OBJECTS  64

typedef struct _SYSTEMTIME
{
	WORD wYear;
	WORD wMonth;
	WORD wDayOfWeek;
	WORD wDay;
	WORD wHour;
	WORD wMinute;
	WORD wSecond;
	WORD wMilliseconds;
}SYSTEMTIME;
typedef SYSTEMTIME* LPSYSTEMTIME;

typedef struct tagCOPYDATASTRUCT
{
	DWORD dwData;
	DWORD cbData;
	void* lpData;
} COPYDATASTRUCT;

typedef struct _SECURITY_ATTRIBUTES
{
    DWORD  nLength;
    LPVOID lpSecurityDescriptor;
    BOOL   bInheritHandle;
} SECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;

#define ZeroMemory(pAdr, size) memset(pAdr, 0, size)
#define RtlZeroMemory(addr, size) memset((addr), 0, (size))
#define stricmp(a, b)    strcasecmp(a, b)
#define _close(a) close(a)
#define _read(a,b,c) read(a,b,c)
#define _write(a,b,c) write(a,b,c)
#define strcpy_s(pDst, nSize, pSrc) strncpy(pDst, pSrc, nSize)
#define _access(a,b) access(a,b)
#define sprintf_s snprintf
#define _snwprintf_s(a, b, c, args...) swprintf(a, b, ##args)
//#define wcscpy_s(pDest, len, pSrc)  memcpy(pDest, pSrc, len*sizeof(wchar_t))
#define wcscpy_s(pDest, len, pSrc)  wcsncpy(pDest, pSrc, len)
//#define wcscat_s(a, b) strcat((char*)(a), (char*)(b))
#define strcat_s(a, b, c) strncat(a, c, b)
#define _snprintf_s(buf, bufsize, count, format, args...) \
		snprintf(buf, bufsize, format, ##args)
#define vsnprintf_s(buf, bufsize, count, format, args...)  \
	    vsnprintf(buf, bufsize, format, ##args)
#define _vsnwprintf_s(buf, count, max_size, format, args...) vswprintf(buf, max_size, format, ##args)
#define swprintf_s(_DstBuf_, _SizeInWords_, _Format_, ...)  swprintf(_DstBuf_, _SizeInWords_, _Format_, ##__VA_ARGS__)
#define _snprintf(_DstBuf_, _SizeInWords_, _Format_, ...)  snprintf(_DstBuf_, _SizeInWords_, _Format_, ##__VA_ARGS__)
//#define wcsrchr(p, c) (wchar_t *)strrchr((char *)p, (char)c)
#define closesocket(sid) close(sid)
#define WSAGetLastError() errno
#define ioctlsocket(a,b,c) ioctl(a,b,c)

#define VirtualAlloc(lpAddress, dwSize, AllocationType, Protect) \
		mmap(lpAddress, dwSize, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0)

#define VirtualFree(lpAddress, dwSize, dwFreeType) \
	munmap(lpAddress, dwSize)

#define GlobalFree(pAddr)   \
	if(pAddr != NULL)       \
		free(pAddr);        \
	pAddr = NULL;

#define GUID_NULL {0}
#define SAFERELEASEPTR(ptr)    {if(ptr){ptr->Release();ptr = NULL;};}
#define _mkdir(path) mkdir(path, 0755)
#define lstrcmpiW(a, b) wcscasecmp(a, b)
#define lstrlenW(a) wcslen(a)
#define lstrcpyW(a, b) wcscpy(a, b)
#define __rdtsc()  get_rdtsc()
#define CheckPointer(p,ret) {if((p)==NULL) return (ret);}
#define itoa(value, dst, radix) \
     if(radix == 8) \
     {\
         sprintf(dst, "%o", value);\
     }\
     else if(radix == 10) \
     {\
         sprintf(dst, "%d", value);\
     }\
     else if(radix == 16) \
     {\
         sprintf(dst, "%x", value);\
     }\
     else \
     {\
     }\

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/* need fix */
#define _wsopen_s(a,b,c,d,e) 0
#define LOG_MODULE_NOTIFY(a,b,c,d,e,f)
#define LOG_MODULE_NOTIFY_TEXT(a,b,c)
#define _lseeki64(a,b,c) 0
#define _telli64(a) 0
#define VERIFY(a)
#define _commit(a)
#define _waccess(a,b) 0
#define __stat64 stat64
#define _stat64 stat64
#define _wstat64 stat64
#define CoInitialize(a)
#define CoUninitialize()
#define LOG_MODULE_DEBUG(...)
#define SetEvent(a)
#define ResetEvent(a)
#define SAFEDELETEARRAY(a)
#define LCMapStringA(a,b,c,d,e,f)
#define OutputDebugStringA(a)
#define WaitForSingleObject(a, b) 0
#define LOG_MODULE_NOTIFY_ADD_FILE(a,b,c,d,e,f,g)
#define GetPrivateProfileIntA GetPrivateProfileInt
#define GetPrivateProfileStringA GetPrivateProfileString

typedef int CRITICAL_SECTION;
#define DuplicateHandle(...) 0

#define CreateEvent(a,b,c,d) 0
#define CloseHandle(a) 0
#define THREAD_PRIORITY_NORMAL 0
#define __uuidof(a) a
#define __RPC_USER
#define RPC_IF_HANDLE int
#define IRpcStubBuffer int
#define IRpcChannelBuffer int
#define PRPC_MESSAGE int*
#define IEnumMoniker int
#define __RPC_STUB
#define DECLSPEC_UUID(x)
#define DECLSPEC_NOVTABLE
#define MIDL_INTERFACE(x)   struct DECLSPEC_UUID(x)
#define IReferenceClock int
#define IBaseFilter int
#define IDirectDrawSurface7 int
#define AM_MEDIA_TYPE int
#define IMediaSample int

#define CoInitialize(...)
#define CoUninitialize(...)
//#define CoCreateInstance(...) 0
#define CP_UTF8 0
#define _wtoi atoi
#define NS_LOG_STRING_FORMAT(...)
#define NSD_SAFE_REPORT_ERROR_RETURN(a, b, c, d, e) return c
#define NS_LOG_WSTRING_FORMAT_ERROR_RETURN(a, b, c, d, e) return c
#define NSD_SAFE_REPORT_ERROR(...)
#define NS_LOG_WSTRING_FORMAT_ERROR(...)
#define NS_LOG_WSTRING_FORMAT(...)
#define NS_LOG_VIRTUAL_MEMORY_AVAILABLE(...)
//#define GetLastError(...) errno
#define HRESULT_FROM_WIN32(dwError) dwError

#define FILE_SHARE_READ 0
#define FILE_SHARE_WRITE 0
#define OPEN_EXISTING 0
#define FILE_FLAG_NO_BUFFERING 0
#define  FILE_FLAG_OVERLAPPED 0
#define CREATE_ALWAYS 0
#define GetFileSizeEx(a, b) 0
#define CP_THREAD_ACP 0
#define NS_NOERROR 0
#define WaitForMultipleObjects(...) 0
#define WAIT_FAILED -1
#define NsGetCPUSpeed(...) 2000

typedef void*                 IXMLDOMNodePtr;
typedef void*                 IXMLDOMDocumentPtr;
#define IXMLDOMDocument       void
#define IXMLDOMNode           void
#define IXMLDOMNodeList       void
#define IXMLDOMNodeListPtr    void*
#define BSTR                  WCHAR*
#define NODE_ELEMENT          0
#define GENERIC_WRITE         0
#define FILE_SHARE_READ       0
#define OPEN_ALWAYS           0
#define FILE_ATTRIBUTE_NORMAL 0
#define GENERIC_READ          0
#define FILE_BEGIN            SEEK_SET
#define FILE_CURRENT          SEEK_CUR
#define FILE_END              SEEK_END
/* need fix end*/
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

int get_rdtsc();
void _splitpath(char *path, char *drive, char *dir, char *fname, char *ext);
static void _split_whole_name(char *whole_name, char *fname, char *ext);
errno_t _makepath(char * _PathResult, const char* _Drive, const char* _Dir, const char* _Filename, const char* _Ext);
errno_t _makepath_s(char * _PathResult, size_t _SizeInWords, const char* _Drive, const char* _Dir, const char* _Filename, const char* _Ext);
void _wsplitpath_s(
   const wchar_t * path,
   wchar_t * drive,
   size_t driveNumberOfElements,
   wchar_t *dir,
   size_t dirNumberOfElements,
   wchar_t * fname,
   size_t nameNumberOfElements,
   wchar_t * ext,
   size_t extNumberOfElements
);
int GetPrivateProfileStringW(
	wchar_t* lpAppName,
	wchar_t* lpKeyName,
	wchar_t* lpDefaut,
	wchar_t* lpReturnedString,
	int   nSize,
	wchar_t* lpFileName);
int CreateMultiDir(const char *path);
void Sleep(DWORD dwMilliseconds);
DWORD timeGetTime();
BOOL CopyFile(char* lpExistingFileName,char* lpNewFileName,BOOL bFailIfExists );
BOOL CopyFileW(wchar_t* lpExistingFileName,wchar_t* lpNewFileName,BOOL bFailIfExists );
BOOL DeleteFile(const char* lpFileName);
BOOL DeleteFileW(wchar_t* lpFileName);
BOOL WriteFile(
	HANDLE in_hFile,
	char *in_pui8Buffer,
	int in_nBufferSize,
	DWORD* lpNumberOfBytesWritten,
	void* lpOverlapped );
HANDLE CreateFile(
	LPCTSTR lpFileName,
	DWORD dwDesiredAccess,
	DWORD dwShareMode,
	LPSECURITY_ATTRIBUTES lpSecurityAttributes,
	DWORD dwCreationDisposition,
	DWORD dwFlagsAndAttributes,
	HANDLE hTemplateFile
);
HANDLE CreateFileW(
	const wchar_t* lpFileName,
	DWORD dwDesiredAccess,
	DWORD dwShareMode,
	LPSECURITY_ATTRIBUTES lpSecurityAttributes,
	DWORD dwCreationDisposition,
	DWORD dwFlagsAndAttributes,
	HANDLE hTemplateFile
);

/*                 need complete start                   */
BOOL ReadFile(
    HANDLE hFile,                                    //文件的句柄
    LPVOID lpBuffer,                                //用于保存读入数据的一个缓冲区
    DWORD nNumberOfBytesToRead,    //要读入的字节数
    LPDWORD lpNumberOfBytesRead,    //指向实际读取字节数的指针
    LPOVERLAPPED lpOverlapped
    //如文件打开时指定了FILE_FLAG_OVERLAPPED，那么必须，用这个参数引用一个特殊的结构。
    //该结构定义了一次异步读取操作。否则，应将这个参数设为NULL
);

DWORD WINAPI SetFilePointerEx(
  HANDLE hFile,
  LARGE_INTEGER   liDistanceToMove,
  PLARGE_INTEGER  pliDistanceToMoveHigh,
  DWORD  dwMoveMethod
);
/*                 need complete end                     */

int create_multi_dir(const char *path);
#define MakeSureDirectoryPathExists(path) create_multi_dir(path)

DWORD WINAPI SetFilePointer(
 HANDLE hFile,
 LONG lDistanceToMove,
 PLONG lpDistanceToMoveHigh,
 DWORD dwMoveMethod
);

int MultiByteToWideChar(
	UINT CodePage,
	DWORD dwFlags,
	const char* lpMultiByteStr,
	int cchMultiByte,
	wchar_t* lpWideCharStr,
	int cchWideChar
	);

int WideCharToMultiByte(
	UINT CodePage,
	DWORD dwFlags,
	const wchar_t* lpWideCharStr,
	int cchWideChar,
	char* lpMultiByteStr,
	int cchMultiByte,
	const char* lpDefaultChar,
	BOOL* pfUsedDefaultChar
	);


