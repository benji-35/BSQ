##
## EPITECH PROJECT, 2021
## sudoku
## File description:
## Makefile
##

C_STANDARD_FLAGS =
C_WARNING_FLAGS = -Wextra -Wall -g
INCLUDE_FLAGS =
PATH_LIB = libs/kap-lib

C_FLAGS = $(C_WARNING_FLAGS) $(INCLUDE_FLAGS)

GCC = gcc

INCLUDE_FLAGS += -I $(PATH_LIB)/include

LIB_FLAGS += -L $(PATH_LIB) -lkap -lcriterion

SRC                 =   src/main.c\
						src/bsq/bsq.c\
						src/bsq/utils/display_bsq.c\
						src/bsq/utils/init_bsq_manager.c\
						src/bsq/utils/reset_current.c\
						src/bsq/utils/step_checking.c\
						src/bsq/utils/checking_file.c

OBJ = $(SRC:.c=.o)

all: build_sub BSQ
.PHONY : all

build_sub:
	@make -sC $(PATH_LIB)

.c.o:
	@echo "$(notdir $(CURDIR)): C '$<'"
	@$(GCC) $(C_FLAGS) -c -o $*.o $<

clean:
	@find . \( -name "*.o" -o -name "*.a" \) -delete
.PHONY : clean

BSQ: $(OBJ)
	@$(GCC) -o $@ $(OBJ) $(LIB_FLAGS)
	@rm -f $(OBJ)

fclean: clean
	@find . -type f -name 'vgcore*' -delete
	@rm -rf BSQ BSQ.dSYM
.PHONY : fclean

re: fclean all
.PHONY : re