#!/bin/bash

number=0 ; \
	limit=`ls -1q ft_colle*.c | wc -l` ; \
	while [[ $$number -lt $$limit ]] ; do \
		printf "$(MKFLE)${PRCS_CLR}>> Compiling ft_colle0$$number.c ..."; \
		$(CC) $(CFLAGS) -o colle0$$number $(SRCS) main.c ft_colle0$$number.c 2> errors; \
		if [[ -s errors ]]; then \
			printf "${SCSS_CLR} OK.\n"; \
		else \
			printf "${ERR_CLR} Failed.\n"; \
			break; \
		fi ; \
		((number = number + 1)) ; \
  done ; \
	if [[ $$number -eq $$limit ]]; then \
		printf "$(MKFLE)${SCSS_CLR}>> Compilation done.\n"; \
	fi ;