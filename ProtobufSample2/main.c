#pragma once

#include <stdio.h>
#include <Windows.h>
#include "st.pb-c.h"

#define FILE_NAME "serialize_data.dat"

#define DICT_NUM 10

BOOL OutputFile(void*, size_t, const char*);

static char* TABLE[DICT_NUM] =
{
	"aaaaaa",
	"bbbbb",
	"cccc",
	"dddd",
	"eeee",
	"ffff",
	"ggggggg",
	"hhhhhhhhhh",
	"iiiiiii",
	"jjjjj",
};

int main(int argc, const char * argv[])
{
	St test_st = ST__INIT;	// �C�j�V�����̎���
	St__T t = ST__T__INIT;
	void *buf;				// �V���A���C�Y�p�o�b�t�@
	size_t size;			// �V���A���C�Y�̃T�C�Y
	int i;

	// �l��ݒ�
	test_st.a = 100;
	test_st.b = "tashima";
	t.x = -10000;
	t.y = 123456789;
	t.z = 9999;
	test_st.child = &t;
	test_st.c = 123;
	test_st.d = TRUE;
	test_st.n_dict = DICT_NUM;
	test_st.dict = malloc(sizeof(St__DictEntry*) * DICT_NUM);

	for (i = 0; i < DICT_NUM; i++)
	{
		test_st.dict[i] = malloc(sizeof(St__DictEntry));
		st__dict_entry__init(test_st.dict[i]);
		test_st.dict[i]->key = TABLE[i];
		test_st.dict[i]->value = i;
	}

	size = st__get_packed_size(&test_st);

	// �p�b�L���O
	buf = malloc(size);
	st__pack(&test_st, buf);

	// �V���A���C�Y
	OutputFile(buf, size, FILE_NAME);

	for (i = 0; i < DICT_NUM; i++) {
		free(test_st.dict[i]);
	}

	free(test_st.dict);

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

