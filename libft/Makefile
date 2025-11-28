# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/03 01:01:35 by ikawamuk          #+#    #+#              #
#    Updated: 2025/06/12 14:48:28 by ikawamuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

AR := ar
ARFLAGS := rcs
CC := cc
CFLAGS=-Wall -Wextra -Werror $(addprefix -I,$(INCLUDES))

SRCDIR := src
FT_PRINTF_SRCDIR := ft_printf_src
GNL_SRCDIR := get_next_line_src
OBJDIR := obj
INCDIR := include

SRCFILES := ft_strlen.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strnstr.c \
			ft_strncmp.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memchr.c \
			ft_memmove.c \
			ft_memcmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c\
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c

FT_PRINTF_SRCFILES :=	convert_specifier.c\
						ft_printf.c\
						get_format_spec.c\
						ltox.c\
						ft_ltoa.c\
						output.c\
						pad_char.c\
						pop_arg.c\
						print_arg.c\
						print_char.c\
						print_dec.c\
						print_hex.c\
						print_percent.c\
						print_ptr.c\
						print_str.c\
						print_u_int.c\
						ptox.c\
						set_ctx_utils.c

GNL_SRCFILES :=	get_next_line.c \
				get_next_line_utils.c \

SRCS := $(addprefix $(SRCDIR)/, $(SRCFILES)) \
		$(addprefix $(SRCDIR)/$(FT_PRINTF_SRCDIR)/, $(FT_PRINTF_SRCFILES))\
		$(addprefix $(SRCDIR)/$(GNL_SRCDIR)/, $(GNL_SRCFILES))
OBJS := $(patsubst %.c,$(OBJDIR)/%.o,$(notdir $(SRCS)))
INCLUDES := $(INCDIR)

vpath %.c $(SRCDIR) $(SRCDIR)/$(FT_PRINTF_SRCDIR) $(SRCDIR)/$(GNL_SRCDIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re