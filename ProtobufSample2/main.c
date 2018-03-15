#pragma once

#include <stdio.h>
#include <Windows.h>
#include "st.pb-c.h"

#define FILE_NAME "serialize_data.dat"

BOOL OutputFile(void*, size_t, const char*);

int main(int argc, const char * argv[])
{
	St test_st = ST__INIT;	// イニシャルの呪文
	St__T t = ST__T__INIT;
	void *buf;				// シリアライズ用バッファ
	size_t size;			// シリアライズのサイズ

	// 値を設定
	test_st.a = 100;
	test_st.b = "tashima";
	t.x = -1;
	t.y = 2;
	test_st.child = &t;

	size = st__get_packed_size(&test_st);

	// パッキング
	buf = malloc(size);
	st__pack(&test_st, buf);

	// シリアライズ
	OutputFile(buf, size, FILE_NAME);

	system("pause");

	return 0;
}

BOOL OutputFile(void* data, size_t size, const char* filename)
{
	HANDLE hFile;
	DWORD dwWriteSize;

	hFile = CreateFile(filename,
		GENERIC_WRITE,
		0,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);

	return WriteFile(hFile, data, size, &dwWriteSize, NULL);
}

