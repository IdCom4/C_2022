# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idcornua <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 13:03:43 by idcornua          #+#    #+#              #
#    Updated: 2019/07/12 14:31:24 by idcornua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash

# DIRS
COMMON_DIR = ../common/
# COMMON FILES
SRCS += $(COMMON_DIR)/ft_printstr.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror
PRCS_CLR = \033[1;33m
SCSS_CLR = \033[0;32m
ERR_CLR = \033[0;31m
MKFLE_CLR = \033[0;33m
MKFLE = $(MKFLE_CLR)[COLLES]

#$(CC) $(CFLAGS) -o colle0$$number $(SRCS) main.c ft_colle0$$number.c 2>; \

all :
	@printf "$(MKFLE)>>${PRCS_CLR} Starting ex00 compilation ...\n\n"
	@number=0 ; \
	limit=`ls -1q ft_colle*.c | wc -l` ; \
	while [[ $$number -lt $$limit ]] ; do \
		printf "$(MKFLE)>>${PRCS_CLR} Compiling ft_colle0$$number.c ..."; \
		$(CC) $(CFLAGS) -o colle0$$number $(SRCS) main.c ft_colle0$$number.c 2> errors; \
		if [[ ! -s errors ]]; then \
			printf "${SCSS_CLR} OK.\n"; \
		else \
			printf "${ERR_CLR} Failed.\n"; \
			error=`cat errors`; \
			printf "$(MKFLE)>>${ERR_CLR} $$error.\n"; \
			break; \
		fi ; \
		((number = number + 1)) ; \
  done ; \
	if [[ $$number -eq $$limit ]]; then \
		printf "\n$(MKFLE)>>${SCSS_CLR} Compilation done.\n"; \
	fi ;

00 :
	@printf "$(MKFLE)>>${PRCS_CLR} Compiling ft_colle00.c ...\n";
	@$(CC) $(CFLAGS) -o colle00 $(SRCS) main.c ft_colle00.c;
	@printf "$(MKFLE)>>${SCSS_CLR} compilation done.\n"

01 :
	@printf "$(MKFLE)>>${PRCS_CLR} Compiling ft_colle01.c ...\n";
	@$(CC) $(CFLAGS) -o colle01 $(SRCS) main.c ft_colle01.c;
	@printf "$(MKFLE)>>${SCSS_CLR} compilation done.\n"

02 :
	@printf "$(MKFLE)>>${PRCS_CLR} Compiling ft_colle02.c ...\n";
	@$(CC) $(CFLAGS) -o colle02 $(SRCS) main.c ft_colle02.c;
	@printf "$(MKFLE)>>${SCSS_CLR} compilation done.\n"

03 :
	@printf "$(MKFLE)>>${PRCS_CLR} Compiling ft_colle03.c ...\n";
	@$(CC) $(CFLAGS) -o colle03 $(SRCS) main.c ft_colle03.c;
	@printf "$(MKFLE)>>${SCSS_CLR} compilation done.\n"

04 :
	@printf "$(MKFLE)>>${PRCS_CLR} Compiling ft_colle04.c ...\n";
	@$(CC) $(CFLAGS) -o colle04 $(SRCS) main.c ft_colle04.c;
	@printf "$(MKFLE)>>${SCSS_CLR} compilation done.\n"

clean:
	@printf "$(MKFLE)>>${PRCS_CLR} Deleting executables ..."
	@rm -f colle* errors
	@printf "\r$(MKFLE)>>${SCSS_CLR} Executables deleted.   \r"


re: clean all

.PHONY: all clean re