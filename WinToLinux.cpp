
#include "WinToLinux.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <sys/stat.h>

void _splitpath(char *path, char *drive, char *dir, char *fname, char *ext)
{
	char *p_whole_name;

	if (drive)
	{
		drive[0] = '\0';
	}

	if (NULL == path || strlen(path) == 0)
	{
		if (dir)
		{
			dir[0] = '\0';
		}
		if (fname)
		{
			fname[0] = '\0';
		}
		if (ext)
		{
			ext[0] = '\0';
		}

		return;
	}

	if ('/' == path[strlen(path) - 1])
	{
		if (dir)
		{
			strcpy(dir, path);
		}
		if (fname)
		{
			fname[0] = '\0';
		}
		if (ext)
		{
			ext[0] = '\0';
		}
		return;
	}

	char fname1[_MAX_FNAME];
	char ext1[_MAX_EXT];
	p_whole_name = rindex(path, '/');
	if (NULL != p_whole_name)
	{
		p_whole_name++;
		_split_whole_name(p_whole_name, fname1, ext1);

		if (dir)
		{
			snprintf(dir, p_whole_name - path + 1, "%s", path);
		}
	}
	else
	{
		_split_whole_name(path, fname1, ext1);
		if (dir)
		{
			dir[0] = '\0';
		}
	}
	if (fname)
	{
		strcpy(fname, fname1);
		strcpy(ext, ext1);
	}
}

static void _split_whole_name(char *whole_name, char *fname, char *ext)
{
	char *p_ext;

	p_ext = rindex(whole_name, '.');
	if (NULL != p_ext)
	{
		strcpy(ext, p_ext);
		snprintf(fname, p_ext - whole_name + 1, "%s", whole_name);
	}
	else
	{
		ext[0] = '\0';
		strcpy(fname, whole_name);
	}
}

errno_t _makepath(char * _PathResult, const char* _Drive, const char* _Dir, const char* _Filename, const char* _Ext)
{
	if (!_PathResult || !_Drive || !_Dir || !_Filename || !_Ext)
	{
		return 1;
	}

	_PathResult[0] = 0;
//	strncat(_PathResult, _Drive, 2);
	if (_Dir[0] != '/')
	{
		strcat(_PathResult, "/");
	}
	strcat(_PathResult, _Dir);
	if (_Dir[strlen(_Dir) - 1] != '/')
	{
		strcat(_PathResult, "/");
	}
	if (_Filename[0] == '/')
	{
		_Filename ++;
	}
	strcat(_PathResult, _Filename);
	if (_Ext[0] != '.')
	{
		strcat(_PathResult, ".");
	}
	strcat(_PathResult, _Ext);
	return 0;
}

errno_t _makepath_s(char * _PathResult, size_t _SizeInWords, const char* _Drive, const char* _Dir, const char* _Filename, const char* _Ext)
{
	if (!_PathResult || !_Drive || !_Dir || !_Filename || !_Ext)
	{
		return 1;
	}
	int nMaxCharCount = _SizeInWords - 1;
	_PathResult[0] = 0;
	//strncat(_PathResult, _Drive, nMaxCharCount);
	//if (strlen(_PathResult) >= nMaxCharCount)
	//{
	//	return 1;
	//}
	if (_Dir[0] != '/')
	{
		strncat(_PathResult, "/", nMaxCharCount - strlen(_PathResult));
		if (strlen(_PathResult) >= nMaxCharCount)
		{
			return 1;
		}
	}
	strncat(_PathResult, _Dir, nMaxCharCount - strlen(_PathResult));
	if (strlen(_PathResult) >= nMaxCharCount)
	{
		return 1;
	}
	if (_Dir[strlen(_Dir) - 1] != '/')
	{
		strncat(_PathResult, "/", nMaxCharCount - strlen(_PathResult));
		if (strlen(_PathResult) >= nMaxCharCount)
		{
			return 1;
		}
	}
	if (_Filename[0] == '/')
	{
		_Filename ++;
	}
	strncat(_PathResult, _Filename, nMaxCharCount - strlen(_PathResult));
	if (strlen(_PathResult) >= nMaxCharCount)
	{
		return 1;
	}
	if (_Ext[0] != '.')
	{
		strncat(_PathResult, ".", nMaxCharCount - strlen(_PathResult));
		if (strlen(_PathResult) >= nMaxCharCount)
		{
			return 1;
		}
	}
	strncat(_PathResult, _Ext, nMaxCharCount - strlen(_PathResult));
	if (strlen(_PathResult) >= nMaxCharCount)
	{
		return 1;
	}
	return 0;
}

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
)
{
	if (drive)
	{
		drive[0] = 0;
	}
	if (path == NULL || wcslen(path) == 0)
	{
		if (dir)
		{
			dir[0] = 0;
		}
		if (fname)
		{
			fname[0] = 0;
		}
		if (ext)
		{
			ext[0] = 0;
		}
		return;
	}
	char szPath[MAX_PATH];
	char szDir[_MAX_DIR];
	char szFname[_MAX_FNAME];
	char szExt[_MAX_EXT];
	setlocale(LC_ALL, "");
	wcstombs(szPath, path, MAX_PATH);
    _splitpath(szPath, NULL, szDir, szFname, szExt);
	if (dir)
	{
		mbstowcs(dir, szDir, _MAX_DIR);
	}
	if (fname)
	{
		mbstowcs(fname, szFname, _MAX_FNAME);
	}
	if (ext)
	{
		mbstowcs(ext, szExt, _MAX_EXT);
	}
}

int GetPrivateProfileStringW(
	wchar_t* lpAppName,
	wchar_t* lpKeyName,
	wchar_t* lpDefaut,
	wchar_t* lpReturnedString,
	int   nSize,
	wchar_t* lpFileName)
{
#if 0
    if(lpAppName == NULL || lpKeyName == NULL
        || lpDefaut == NULL || lpReturnedString == NULL
        || lpFileName == NULL)
    {
        return 0;
    }
    int ret = 0;
    char *pReturnedString = (char*)malloc(nSize);

    char *pAppName = (char*)malloc(wcslen(lpAppName));
    wcstombs(pAppName, lpAppName, wcslen(lpAppName));

    char *pKeyName = (char*)malloc(wcslen(lpKeyName));
    wcstombs(pKeyName, lpKeyName, wcslen(lpKeyName));

    char *pDefaut = (char*)malloc(wcslen(lpDefaut));
    wcstombs(pDefaut, lpDefaut, wcslen(lpDefaut));

    char *pFileName = (char*)malloc(wcslen(lpFileName));
    wcstombs(pFileName, lpFileName, wcslen(lpFileName));

    if(GetPrivateProfileString(pAppName, pKeyName, pDefaut, pReturnedString,
    nSize, pFileName) == nSize)
    {
        ret = nSize;
    }
    mbstowcs(lpReturnedString, pReturnedString, nSize);

    free(pReturnedString);
    free(pAppName);
    free(pKeyName);
    free(pDefaut);
    free(pFileName);

    return ret;
#endif
    return 0;
}

void Sleep(DWORD dwMilliseconds)
{
	usleep(dwMilliseconds*1000);
}

DWORD timeGetTime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
    return (tv.tv_sec*1000 + tv.tv_usec/1000);
}

/*
文件拷贝函数
返回值 0 - 失败  非 0 - 成功
*/
#define BUFFER_SIZE 512
BOOL CopyFile(char* lpExistingFileName,char* lpNewFileName,BOOL bFailIfExists )
{
    FILE *fp_src, *fp_dest;
    char buffer[BUFFER_SIZE];
    int lenR, lenW;

    if(bFailIfExists)
    {
        if(access(lpNewFileName, 0) == 0)
        {
            printf("The file '%s' is alread exist! \n", lpNewFileName);
            return 0;
        }
    }
    if ((fp_src = fopen(lpExistingFileName, "r")) == NULL)
    {
        printf("The file '%s' can not be opened! \n", lpExistingFileName);
        return 0;
    }
    if ((fp_dest = fopen(lpNewFileName, "w")) == NULL)
    {
        printf("The file '%s' can not be opened! \n", lpNewFileName);
        fclose(fp_src);
        return 0;
    }

    memset(buffer, 0, BUFFER_SIZE);
    while ((lenR = fread(buffer, 1, BUFFER_SIZE, fp_src)) > 0)
    {
        if ((lenW = fwrite(buffer, 1, lenR, fp_dest)) != lenR)
        {
            printf("Write to file '%s' failed!\n", lpNewFileName);
            fclose(fp_src);
            fclose(fp_dest);
            return 0;
        }
        memset(buffer, 0, BUFFER_SIZE);
    }

    fclose(fp_src);
    fclose(fp_dest);
    return 1;
}

BOOL CopyFileW(wchar_t* lpExistingFileName,wchar_t* lpNewFileName,BOOL bFailIfExists )
{
	if (!lpExistingFileName || !lpNewFileName)
	{
		return FALSE;
	}
	char szExistingFileName[MAX_PATH];
	char szNewFileName[MAX_PATH];
	setlocale(LC_ALL, "");

	wcstombs(szExistingFileName, lpExistingFileName, MAX_PATH);
	wcstombs(szNewFileName, lpNewFileName, MAX_PATH);

	return CopyFile(szExistingFileName, szNewFileName, bFailIfExists);
}
BOOL DeleteFile(char* lpFileName)
{
    return remove(lpFileName);
}
BOOL DeleteFileW(wchar_t* lpFileName)
{
	if (!lpFileName)
	{
		return FALSE;
	}
	char szFileName[MAX_PATH];
	setlocale(LC_ALL, "");

	wcstombs(szFileName, lpFileName, MAX_PATH);
    return DeleteFile(szFileName);
}

BOOL WriteFile(
    HANDLE in_hFile,
    char *in_pui8Buffer,
    int in_nBufferSize,
    DWORD* lpNumberOfBytesWritten,
	void* lpOverlapped )

{
    long long fd = (long long)in_hFile;
    size_t size = 0;
    size = write((int)fd, in_pui8Buffer, in_nBufferSize);
    if(lpNumberOfBytesWritten)
    {
        *lpNumberOfBytesWritten = (DWORD)size;
        return TRUE;
    }
    return FALSE;
}

HANDLE CreateFile(
	LPCTSTR lpFileName,
	DWORD dwDesiredAccess,
	DWORD dwShareMode,
	LPSECURITY_ATTRIBUTES lpSecurityAttributes,
	DWORD dwCreationDisposition,
	DWORD dwFlagsAndAttributes,
	HANDLE hTemplateFile
)
{
    HANDLE handle = NULL;
    handle = (HANDLE)open(lpFileName,O_RDWR|O_CREAT,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
    return handle;
}

HANDLE CreateFileW(
	wchar_t* lpFileName,
	DWORD dwDesiredAccess,
	DWORD dwShareMode,
	LPSECURITY_ATTRIBUTES lpSecurityAttributes,
	DWORD dwCreationDisposition,
	DWORD dwFlagsAndAttributes,
	HANDLE hTemplateFile
)
{
    if(lpFileName == NULL)
    {
        return NULL;
    }
    char filename[MAX_PATH] = {0};
    if (wcstombs(filename, lpFileName, MAX_PATH))
    {
        return CreateFile(filename, dwDesiredAccess, dwShareMode,
        lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
    }
    return NULL;
}

int create_multi_dir(const char *path)
{
    int i, len;
    len = strlen(path);
    char dir_path[len+1];
    dir_path[len] = '\0';

    strncpy(dir_path, path, len);

    for (i = 0; i < len; i++)
    {
        if (dir_path[i] == '/' && i > 0)
        {
            dir_path[i]='\0';
            if (access(dir_path, F_OK) < 0)
            {
                if (mkdir(dir_path, 0755) < 0)
                {
                    return -1;
                }
            }
            dir_path[i]='/';
        }
    }

    return 0;
}

DWORD WINAPI SetFilePointer(
 HANDLE hFile,
 LONG lDistanceToMove,
 PLONG lpDistanceToMoveHigh,
 DWORD dwMoveMethod
)
{
    long long fd = (long long)hFile;
    return lseek((int)fd, lDistanceToMove, dwMoveMethod);
}

int MultiByteToWideChar(
	UINT CodePage,
	DWORD dwFlags,
	const char* lpMultiByteStr,
	int cchMultiByte,
	wchar_t* lpWideCharStr,
	int cchWideChar
	)

{
	setlocale(LC_ALL, "");
	if (!lpWideCharStr || cchWideChar == 0)
	{
		return mbstowcs(NULL, lpMultiByteStr, 0);
	}
	else
	{
		return mbstowcs(lpWideCharStr, lpMultiByteStr, cchWideChar);
	}

}

int WideCharToMultiByte(
	UINT CodePage,
	DWORD dwFlags,
	const wchar_t* lpWideCharStr,
	int cchWideChar,
	char* lpMultiByteStr,
	int cchMultiByte,
	const char* lpDefaultChar,
	BOOL* pfUsedDefaultChar
	)

{
	setlocale(LC_ALL, "");
	if (pfUsedDefaultChar)
	{
		*pfUsedDefaultChar = FALSE;
	}

	if (!lpWideCharStr || cchWideChar == 0)
	{
		return wcstombs(NULL, lpWideCharStr, 0);
	}
	else
	{
		return wcstombs(lpMultiByteStr, lpWideCharStr, cchMultiByte);
	}

}

int get_rdtsc()
{
  asm("rdtsc");
}
