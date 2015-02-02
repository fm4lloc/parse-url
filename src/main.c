/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Author: Fernando Magalhães (Fm4lloc) <fm4lloc@gmail.com>
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "parseUrl.h"

int main (int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf (stderr, "usage: %s url\nexample:"
			"\n%s 'https://foo:bar@zaz.com:12/go/en/p.php?a=b&c=d%%20pong#2'\n\n", argv[0], argv[0]);
		return EXIT_SUCCESS;
	}

	urlComponents comp;
	char *str = NULL;
	int i;
	
	int codes[] = {
			SCHEME,   AUTHORITY,
			USERINFO, USERNAME,
			PASSWORD, HOST,
			PORT,     PATH ,
			FILENAME, QUERY,
			FRAGMENT,
	};

	char *componentsName[] = {
			"+SCHEME",       "+AUTHORITY",
			" +USERINFO",    "  -USERNAME",
			"  -PASSWORD",   " -HOST",
			" -PORT",        "  +PATH" ,
			"   -FILENAME" , "   -QUERY",
			"   -FRAGMENT",
	};

	if (parseUrl (&comp, argv[1]))
	{
		fprintf (stderr, "invalid URL!\n");
		return EXIT_FAILURE;
	}

	for (i = 0; i <= 10; i++)
	{
		str = getComponent (&comp, codes[i]);
		printf ("%s: %s\n", componentsName[i], str);
		free (str);
	}

	freeComponents (&comp);
	return EXIT_SUCCESS;
}
