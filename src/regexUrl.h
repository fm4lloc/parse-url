/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Author: Fernando Magalhães (Fm4lloc) <fm4lloc@gmail.com>
 *
 */

#ifndef REGEXURL_H_
#define REGEXURL_H_

/* Code index */
#define 	SCHEME 		(2)
#define 	AUTHORITY 	(4)
#define 	USERINFO 	(6)
#define 	USERNAME 	(7)
#define 	PASSWORD 	(9)
#define 	HOST		(10)
#define 	PORT 		(13)
#define 	PATH 		(14)
#define 	FILENAME 	(17)
#define 	QUERY 		(19)
#define 	FRAGMENT 	(21)

/* Scheme */
#define SCHEME_ER 		"^(([^:/?#]+):)?"

/* Host */
#define HOSTNAME_ER		"[^:/?#@]*"
#define IPV6REF_ER		"\\[([0-9a-fA-F:]+)\\]"

#define HOST_ER			"(" IPV6REF_ER "|" HOSTNAME_ER ")"
#define PORT_ER			"(:([0-9]+))?"

#define HOSTPORT_ER	HOST_ER PORT_ER

/* User Information and Authority */
#define	USERNAME_ER		"([^:/?#@]*)"
#define PASSWORD_ER		"(:([^:/?#@]*))?"

#define USERINFO_ER		"((" USERNAME_ER PASSWORD_ER ")@)?"

#define AUTHORITY_ER	"(//("  USERINFO_ER HOSTPORT_ER "))?"

/* Path */
#define PATH_ER			"([^?#]*)"
#define FILENAME_ER		"(/([^?#]*))"

#define HIER_PART_ER	"(" PATH_ER FILENAME_ER ")?"

/* Query and fragments */
#define QUERY_ER		"(\\?([^#]*))?"
#define FRAGMENT_ER		"(#(.*))?$"

/* URL */
#define URL_ER			SCHEME_ER AUTHORITY_ER HIER_PART_ER QUERY_ER FRAGMENT_ER

#endif /* REGEXURL_H_ */
