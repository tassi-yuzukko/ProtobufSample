#pragma once

#include <stdio.h>
#include "repeated.pb-c.h"
#include "FileCtrl.h"

#define INNER_NUM (10)
#define FILENAME "repeated.dat"

void SetRepeated(const char* filename)
{
	CMessage msg = CMESSAGE__INIT;
	Inner **inner;
	int i;
	void* buf;
	size_t size;

	msg.n_c = INNER_NUM;
	msg.c = malloc(sizeof(Inner*) * msg.n_c);

	inner = malloc(sizeof(Inner*) * INNER_NUM);
	for (i = 0; i < INNER_NUM; i++)
	{
		inner[i] = malloc(sizeof(Inner));
		inner__init(inner[i]);
		inner[i]->a = i;
		inner[i]->b = i * i;
	}

	msg.c = inner;

	size = cmessage__get_packed_size(&msg);
	buf = malloc(size);
	cmessage__pack(&msg, buf);

	SaveFile(buf, size, filename);

	free(buf);
}

void GetRepeated(const char* filename)
{
	CMessage* msg;
	void* buf = NULL;
	size_t size;
	int i;

	buf = LoadFile(&size, filename);

	msg = cmessage__unpack(NULL, size, buf);

	for (i = 0; i < msg->n_c; i++)
	{
		fprintf(stderr, "a:[%d], b[%d]", msg->c[i]->a, msg->c[i]->b);
	}

	cmessage__free_unpacked(msg, NULL);

	free(buf);
}

int main(int argc, const char * argv[])
{
	SetRepeated(FILENAME);
	GetRepeated(FILENAME);

	system("pause");

	return 0;
}