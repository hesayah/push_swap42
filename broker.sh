#!/bin/bash

valgrind \
	--leak-check=full \
	--show-leak-kinds=all \
	--show-reachable=yes \
	--track-origins=yes \
	--log-file=valerr \
	--supprimate=readline
	"$@"