#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "amessage.pb-c.h"
#include "AMessageSerialize.h"

static void MyWriteFile(void const * buf, size_t len, const char* filename);

BOOL AMessageSerialize(int argc, const char * argv[])
{
	AMessage msg = AMESSAGE__INIT; // AMessage
	void *buf;                     // Buffer to store serialized data
	unsigned len;                  // Length of serialized data

	if (argc != 2 && argc != 3)
	{   // Allow one or two integers
		fprintf(stderr, "usage: amessage a [b]\n");
		return FALSE;
	}

	msg.a = atoi(argv[1]);
	msg.b = atoi(argv[2]);
	len = amessage__get_packed_size(&msg);

	buf = malloc(len);
	amessage__pack(&msg, buf);

	fprintf(stderr, "Writing %d serialized bytes\n", len); // See the length of message
	MyWriteFile(buf, len, "test.txt"); // Write to stdout to allow direct command line piping

	free(buf); // Free the allocated serialized buffer
	return TRUE;
}

static void MyWriteFile(void const * buf, size_t len, const char* filename)
{
	FILE* fp;

	fopen_s(&fp, filename, "wb");
	if (fp == NULL) {
		fprintf(stderr, "failed to write file.");
		goto END;
	}

	fwrite(buf, len, 1, fp);

END:
	fclose(fp);

	return;
}