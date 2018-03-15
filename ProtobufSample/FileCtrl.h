#pragma once

#include<Windows.h>

#define MAX_MSG_SIZE  1024

BOOL SaveFile(void*, size_t, const char*);
void* LoadFile(size_t*, const char*);