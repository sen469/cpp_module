# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssawa <ssawa@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/05 17:05:11 by ssawa             #+#    #+#              #
#    Updated: 2026/04/05 17:05:13 by ssawa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = ex00
CXX         = c++

UNAME_S     := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
    CXXFLAGS    = -Wall -Wextra -Werror -std=c++98 -pedantic
endif

ifeq ($(UNAME_S),Darwin)
    CXXFLAGS    = -Wall -Wextra -Werror -std=c++98 -pedantic
endif

RM          = rm -f
MAKE        = make
MAKE_FLAGS  += --no-print-directory

INCFLAGS    = -I./incs

RESET       = \033[0m
RED         = \033[31m
GREEN       = \033[32m
YELLOW      = \033[33m
BLUE        = \033[34m
MAGENTA     = \033[35m
CYAN        = \033[36m
WHITE       = \033[37m
L_RED       = \033[91m
L_GREEN     = \033[92m
L_BLUE      = \033[94m

INCDIR      = incs
SRCDIR      = srcs

INCS        = $(foreach dir, $(shell find $(INCDIR) -type d), $(wildcard $(dir)/*.hpp))
SRCS        = $(foreach dir, $(shell find $(SRCDIR) -type d), $(wildcard $(dir)/*.cpp))

# INCS        = \
# SRCS        = \

OBJS        = $(SRCS:%.cpp=%.o)

TOTAL       := $(if $(OBJS),$(words $(OBJS)),1)
COUNT       = 0

all: $(NAME)

$(NAME): $(INCS) $(OBJS)
	@if [ "$(COUNT)" = "0" ]; then echo "$(L_GREEN)🔧 Building $(NAME)...$(RESET)"; fi
	@printf "\r$(L_GREEN)[%s] 100%% Building $(NAME)...$(RESET)\n" "$$(printf '%0.s#' $$(seq 1 $(TOTAL)))"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "\n$(GREEN)🎉🎉 Build complete: $(NAME) 🎉🎉$(RESET)\n"

%.o: %.cpp
	@if [ "$(COUNT)" = "0" ]; then echo "$(L_GREEN)🔧 Building $(NAME)...$(RESET)"; fi
	@$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $< -o $@
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	@FILLED=$(COUNT); \
	EMPTY=$$(($(TOTAL) - $$FILLED)); \
	BAR="$$(printf '%0.s#' $$(seq 1 $$FILLED))$$(printf '%0.s.' $$(seq 1 $$EMPTY))"; \
	PERCENT=$$(( $$FILLED * 100 / $(TOTAL) )); \
	printf "\r$(L_GREEN)[%s] %d%% Building $(NAME)...$(RESET)" "$$BAR" "$$PERCENT"

clean:
	@echo "$(RED)🧹 Cleaning objects...$(RESET)"
	@$(RM) $(OBJS)
	@echo "$(L_GREEN)✅ clean done$(RESET)\n"

fclean: clean
	@echo "$(RED)🗑️  Removing binary...$(RESET)"
	@$(RM) $(NAME)
	@echo "$(L_GREEN)✅ fclean done$(RESET)\n"

re: fclean all

run: all
	@$(MAKE) $(MAKE_FLAGS) clean -s
	@./$(NAME)

.PHONY: all clean fclean re run
