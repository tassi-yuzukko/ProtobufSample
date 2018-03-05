#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "amessage.pb-c.h"
#include "AMessageDeserialize.h"
#define MAX_MSG_SIZE 1024

static size_t
read_buffer(unsigned max_length, uint8_t *out, const char* filename)
{
	size_t cur_len = 0;
	size_t nread;
	FILE* fp;

	fopen_s(&fp, filename, "rb");
	if (fp == NULL) {
		fprintf(stderr, "failed to read file.");
		goto END;
	}

	while ((nread = fread(out + cur_len, 1, max_length - cur_len, fp)) != 0)
	{
		cur_len += nread;
		if (cur_len == max_length)
		{
			fprintf(stderr, "max message length exceeded\n");
			exit(1);
		}
	}

END:
	fclose(fp);

	return cur_len;
}


BOOL AMessageDeserialize()
{
	AMessage *msg;

	// Read packed message from standard-input.
	uint8_t buf[MAX_MSG_SIZE];
	size_t msg_len = read_buffer(MAX_MSG_SIZE, buf, "test.txt");

	// Unpack the message using protobuf-c.
	msg = amessage__unpack(NULL, msg_len, buf);
	if (msg == NULL)
	{
		fprintf(stderr, "error unpacking incoming message\n");
		return FALSE;
	}

	// display the message's fields.
	printf("Received: a=%d  b=%d \n", msg->a, msg->b);  // required field

	// Free the unpacked message
	amessage__free_unpacked(msg, NULL);
	return TRUE;
}