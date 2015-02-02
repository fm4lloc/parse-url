/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Author: Fernando Magalhães (Fm4lloc) <fm4lloc@gmail.com>
 *
 */

#ifndef PARSEURL_H_
#define PARSEURL_H_

#include <regex.h>
#include "regexUrl.h"

typedef struct
{
	char *url;
	regmatch_t *pmatch;
} urlComponents;

char *getComponent (urlComponents *comp, const int component);
int parseUrl (urlComponents *comp, char *url);
void freeComponents (urlComponents *comp);

#endif /* PARSEURL_H_ */
