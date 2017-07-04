/*
 * Copyright (C) 2017 francis_hao <francis_hao@126.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE, GOOD TITLE or
 * NON INFRINGEMENT.  See the GNU General Public License for more
 * details.
 *
 */
/*
 * This is the example in `man getopt`
 * The following trivial example program uses getopt() to handle two program options: 
 * -n, with no associated value; and -t val, which expects an associated value.
 *
 */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int flags, opt;
	int nsecs;
	int i;

	nsecs = 0;
	flags = 0;
	printf("first of all optind is %d\n", optind);
	printf("---at the begining,list argv value---\n");
	for (i=0; i<argc; i++){
		printf("argv[%u] is %s\n",i,argv[i]);
	}
	printf("-----------------------------\n");
	while ((opt = getopt(argc, argv, "nt:")) != -1) {
		printf("current optind is %d\n", optind);
		switch (opt) {
			case 'n':
				flags++;
				break;
			case 't':
				nsecs = atoi(optarg);
				flags++;
				break;
			default: /* '?' */
				fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n",
						argv[0]);
				exit(EXIT_FAILURE);
		}
	}
	printf("---at the end,list argv value---\n");
	for (i=0; i<argc; i++){
		printf("argv[%u] is %s\n",i,argv[i]);
	}
	printf("-----------------------------\n");
	printf("after all optind is %d\n", optind);

	printf("flags=%d; nsecs=%d\n", flags, nsecs);

	if (optind >= argc) {
		fprintf(stderr, "Expected argument after options\n");
		exit(EXIT_FAILURE);
	}

	printf("name argument = %s\n", argv[optind]);

	/* Other code omitted */

	exit(EXIT_SUCCESS);
}

