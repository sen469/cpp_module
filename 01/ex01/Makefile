# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/30 10:59:04 by ssawa             #+#    #+#              #
#    Updated: 2026/01/31 16:34:16 by ssawa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = moar_brainz

CXX = c++

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	CXXFLAGS  = -Wall -Wextra -Werror -std=c++98
endif

ifeq ($(UNAME_S),Darwin)
	CXXFLAGS  = -Wall -Wextra -Werror -std=c++98
endif

RM = rm -f
MAKE = make
MAKE_FLAGS += --no-print-directory

INCFLAGS = -I./incs


SRCDIR = srcs

SRCS = $(foreach dir, $(shell find $(SRCDIR) -type d), $(wildcard $(dir)/*.cpp))

# SRCS = \

BASE_OBJS = $(SRCS:%.cpp=%.o)

OBJS = $(BASE_OBJS)

TOTAL := $(words $(OBJS))
COUNT = 0

all: $(NAME)

$(NAME): $(OBJS)
	@printf "\r\033[92m[%s] 100%% Building $(NAME)...\033[0m\n" "$$(printf '%0.s#' $$(seq 1 $(TOTAL)))"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "\n\033[32m🎉🎉 Build complete: $(NAME) 🎉🎉\033[0m\n"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $< -o $@
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	@FILLED=$(COUNT); \
	EMPTY=$$(($(TOTAL) - $$FILLED)); \
	BAR="$$(printf '%0.s#' $$(seq 1 $$FILLED))$$(printf '%0.s.' $$(seq 1 $$EMPTY))"; \
	PERCENT=$$(( $$FILLED * 100 / $(TOTAL) )); \
	printf "\r\033[92m[%s] %d%% Building $(NAME)...\033[0m" "$$BAR" "$$PERCENT"

clean:
	@echo "\033[31m🧹 Cleaning objects...\033[0m"
	@$(RM) $(BASE_OBJS)
	@echo "\033[92m✅ clean done\033[0m\n"

fclean: clean
	@echo "\033[31m🗑️  Removing binary...\033[0m"
	@$(RM) $(NAME)
	@echo "\033[92m✅ fclean done\033[0m\n"

re: fclean all

run: all
	@$(MAKE) $(MAKE_FLAGS) clean -s
	@./$(NAME)

.PHONY: all clean fclean re
