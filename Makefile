MANDATORY = memset bzero memcpy memmove memchr memcmp \
				strlen isalpha isdigit isalnum isascii isprint \
				toupper tolower strchr strrchr strncmp strlcpy \
				strlcat strnstr atoi calloc strdup substr strjoin \
				strtrim split itoa strmapi \
				putchar_fd putstr_fd putendl_fd putnbr_fd striteri \
				test

BONUS = lstnew lstsize lstlast lstdelone lstclear \
				lstiter lstmap lstadd_front lstadd_back


LIBFT_PATH	= $(shell dirname $(shell pwd))

GCC					= gcc
CFLAGS			= -Wall -Wextra -Werror
UTILS				= $(addprefix utils/, leaks.c check.c)

ifdef DETAIL
OPTION = -debug
endif

$(MANDATORY): %: mandatory_start
	@echo ft_$*
	@$(GCC) $(CFLAGS) main.c $(UTILS) tests/$*_case.c -L $(LIBFT_PATH) -lft && ./a.out $(OPTION) && rm -f a.out

$(BONUS): %: bonus_start
	@echo ft_$*
	@$(GCC) $(CFLAGS) $(UTILS) tests/$*_case.c -L $(LIBFT_PATH) -lft && ./a.out $(OPTION) && rm -f a.out

mandatory_start: update
	@tput setaf 6
	make -C $(LIBFT_PATH)
	@tput setaf 4 && echo [Mandatory]
	@tput setaf 8

bonus_start: update
	@tput setaf 6
	make bonus -C $(LIBFT_PATH)
	@tput setaf 5 && echo [Bonus]
	@tput setaf 8

update:
	@echo update
	#@git pull

m: $(MANDATORY)
b: $(BONUS)

.PHONY: m b update $(FUNC)