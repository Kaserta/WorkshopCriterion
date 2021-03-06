##
## EPITECH PROJECT, 2017
## cesar
## File description:
## Makefile
##

## ---- COMPILER ---- ##
CC	=	gcc

## ---- BINARIES NAMES ---- ##
BIN	=	cesar_decypher
DEBUG_BIN	:=	$(BIN)_debug
TEST_BIN	:=	$(BIN)_test

## ---- SOURCE-C-AND-HEADER DIR ---- ##
SRCDIR	=	./src
SRCHEADER	=	./include
TESTDIR =	./tests

## ---- FILES ---- ##
MAIN	=	$(SRCDIR)/main.c

SRC	:=	$(SRCDIR)/decrypt_file.c	\
		$(SRCDIR)/file_manager.c	\
		$(SRCDIR)/error.c

OBJ	:=	$(SRC:.c=.o)	\
		$(MAIN:.c=.o)

## ---- FILES-TEST ---- ##
SRCTEST	:=	$(TESTDIR)/test_safe_open.c	\
			$(TESTDIR)/test_safe_close.c	\
			$(TESTDIR)/test_get_size_file.c	\
			$(TESTDIR)/test_get_file_content.c	\
			$(TESTDIR)/test_pexit_failure.c	\
			$(TESTDIR)/test_decrypt_string.c	\
			$(TESTDIR)/test_decrypt_file.c

## ---- FLAGS ---- ##
OPTI	=	-O3
DEBUG	=	-g3
CFLAGS	=	-I$(SRCHEADER) -W -Wall -Wextra -Werror -Wchkp
LDFLAGS_TEST	=	-lcriterion -lgcov --coverage

## ---- REMOVER ---- ##
RM	=	rm -f *.gc*	\
		rm -f vgcore.*
FRM	=	rm -f $(BIN)	\
		rm -f $(DEBUG_BIN)	\
		rm -f $(TEST_BIN)	\
		rm -f .history* \
		rm -f .tags*

## ---- RULE ---- ##
all	:	$(BIN)

$(BIN)	:	$(OBJ)
	@echo -ne "[1;36m"
	$(CC) $^ $(CFLAGS) $(OPTI) -o $@
	@echo -ne "[0m"

debug	:
	@echo -ne "[1;36m"
	$(CC) $(MAIN) $(SRC) $(CFLAGS) $(DEBUG) -o $(DEBUG_BIN)
	@echo -ne "[0m"

## ---- TEST ---- ##
tests_run	:	fclean
	$(CC) $(SRC) $(SRCTEST) $(CFLAGS) $(LDFLAGS_TEST) -o $(TEST_BIN)
	./$(TEST_BIN)

## ---- CLEANING ---- ##
clean	:
	@echo -e "[1;33mCleaning .o :[0m"
	@echo -ne "[0;34m"
	@$(foreach i, $(OBJ), $(shell rm -f $(i)) echo -e " rm -f $(i)";)
	@echo -e "[0m"
	$(RM)
fclean	:	clean
	$(FRM)

## ---- RE ---- ##
re	:	fclean	all

.PHONY: all tests_run debug clean fclean re
