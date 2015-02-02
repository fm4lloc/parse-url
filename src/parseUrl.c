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
#include <regex.h>
#include <string.h>

#include "parseUrl.h"

char *getComponent (urlComponents *comp, const int component)
{
	char *out = NULL;
	regmatch_t *pmatch = &comp->pmatch[component];
    	size_t len = pmatch->rm_eo - pmatch->rm_so;

	if (!(out = (char *) malloc (sizeof (char) * len+1)))
		return NULL;

	memcpy (out, comp->url + pmatch->rm_so, len);
	out[len] = '\0';

	return out;
}

/**
 * parseUrl:
 * This function parses and extracts the components of the URL.
 *
 * @comp: pointer to type UriComponents.
 * @url: The source string.
 *
 * returns integer != 0 in case of error.
 */
int parseUrl (urlComponents *comp, char *url)
{
	regex_t preg;
	reg_errcode_t err;
	regmatch_t *pmatch;
	size_t nmatch;

	if (( err = regcomp (&preg, URL_ER, REG_EXTENDED)) != REG_NOERROR)
		return err;

	nmatch = preg.re_nsub + 1;
	pmatch = (regmatch_t *) malloc (sizeof (regmatch_t) * nmatch);

	if ((err = regexec (&preg, url, nmatch , pmatch, 0 )) != REG_NOERROR)
	{
		free (pmatch);
		return err;
	}

	comp->pmatc	= pmatch;
	comp->url	= url;

	regfree (&preg);
	return 0;
}

/**
 * freeComponents:
 * This function frees the memory allocated by parseUrl ().
 *
 * @comp: pointer to UriComponents.
 *
 */
void freeComponents (urlComponents *comp)
{
	free (comp->pmatch);
	return;
}
