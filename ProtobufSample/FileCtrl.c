#pragma once

#include "FileCtrl.h"

BOOL SaveFile(void* data, size_t size, const char* filename)
{
	HANDLE hFile;
	DWORD dwWriteSize;
	BOOL ret;

	hFile = CreateFile(filename, GENERIC_WRITE, 0, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	ret = WriteFile(hFile, data, size, &dwWriteSize, NULL);

	CloseHandle(hFile);

	return ret;
}

void* LoadFile(size_t* size, const char* filename)
{
	HANDLE hFile;
	DWORD bufSize;
	void* buf;

	hFile = CreateFile(filename, GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	bufSize = GetFileSize(hFile, NULL);

	buf = malloc(bufSize);

	ReadFile(hFile, buf, bufSize, size, NULL);

	return buf;
}