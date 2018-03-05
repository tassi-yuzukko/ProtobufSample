#pragma once

#include <stdio.h>
#include "AMessageSerialize.h"
#include "AMessageDeserialize.h"

int main(int argc, const char * argv[])
{
	AMessageSerialize(argc, argv);
	AMessageDeserialize();

	system("pause");

	return 0;
}