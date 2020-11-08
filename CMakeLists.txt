cmake_minimum_required(VERSION 3.15)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

include_directories(get_next_line inc libft)

add_library(libft STATIC ./libft/ft_abs.c
        ./libft/ft_assert.c
        ./libft/ft_atof.c
        ./libft/ft_atoi.c
        ./libft/ft_atol.c
        ./libft/ft_bzero.c
        ./libft/ft_calloc.c
        ./libft/ft_divmod.c
        ./libft/ft_intlen.c
        ./libft/ft_isalnum.c
        ./libft/ft_isalpha.c
        ./libft/ft_isascii.c
        ./libft/ft_isdigit.c
        ./libft/ft_isprint.c
        ./libft/ft_isspace.c
        ./libft/ft_itoa.c
        ./libft/ft_long_pow.c
        ./libft/ft_longlen.c
        ./libft/ft_lst_getinx.c
        ./libft/ft_lstadd.c
        ./libft/ft_lstadd_end.c
        ./libft/ft_lstdel.c
        ./libft/ft_lstdelinx.c
        ./libft/ft_lstdelone.c
        ./libft/ft_lstiter.c
        ./libft/ft_lstlen.c
        ./libft/ft_lstmap.c
        ./libft/ft_lstnew.c
        ./libft/ft_lstprint.c
        ./libft/ft_memalloc.c
        ./libft/ft_memccpy.c
        ./libft/ft_memchr.c
        ./libft/ft_memcmp.c
        ./libft/ft_memcpy.c
        ./libft/ft_memdel.c
        ./libft/ft_memmove.c
        ./libft/ft_memset.c
        ./libft/ft_memswap.c
        ./libft/ft_moddiv.c
        ./libft/ft_pow.c
        ./libft/ft_put_unicode.c
        ./libft/ft_putchar.c
        ./libft/ft_putchar_fd.c
        ./libft/ft_putendl.c
        ./libft/ft_putendl_fd.c
        ./libft/ft_putnbr.c
        ./libft/ft_putnbr_fd.c
        ./libft/ft_putstr.c
        ./libft/ft_putstr_fd.c
        ./libft/ft_realloc.c
        ./libft/ft_strany.c
        ./libft/ft_strcat.c
        ./libft/ft_strchr.c
        ./libft/ft_strclr.c
        ./libft/ft_strcmp.c
        ./libft/ft_strcmpi.c
        ./libft/ft_strcpy.c
        ./libft/ft_strdel.c
        ./libft/ft_strdup.c
        ./libft/ft_strequ.c
        ./libft/ft_striter.c
        ./libft/ft_striteri.c
        ./libft/ft_strjoin.c
        ./libft/ft_strlcat.c
        ./libft/ft_strlcpy.c
        ./libft/ft_strlen.c
        ./libft/ft_strmap.c
        ./libft/ft_strmapi.c
        ./libft/ft_strncat.c
        ./libft/ft_strncmp.c
        ./libft/ft_strncpy.c
        ./libft/ft_strndup.c
        ./libft/ft_strnequ.c
        ./libft/ft_strnew.c
        ./libft/ft_strnlen.c
        ./libft/ft_strnstr.c
        ./libft/ft_strrchr.c
        ./libft/ft_strrev.c
        ./libft/ft_strrew.c
        ./libft/ft_strsplit.c
        ./libft/ft_strstr.c
        ./libft/ft_strsub.c
        ./libft/ft_strtolower.c
        ./libft/ft_strtrim.c
        ./libft/ft_tolower.c
        ./libft/ft_toupper.c
        ./libft/ft_uitoa_base.c
        ./libft/ft_uitoa_dec.c
        ./libft/ft_uitoa_hex.c
        ./libft/ft_ultoa_base.c
        ./libft/ft_ultoa_hex.c
        ./libft/ft_wstrlen.c libft/ft_log_error.c libft/ft_log_info.c libft/ft_strequ_ignore_case.c)

set_target_properties(libft PROPERTIES PUBLIC_HEADER ./libft/libft.h  stack.h  operation.h  parser.h  checker.h properties/properties.h  printer.h)

add_executable(checker $<TARGET_OBJECTS:libft>
        src/common/stack.c
        src/common/operation.c
        src/common/parser.c
        src/checker/checker.c
        src/common/get_next_line.c
        src/common/properties/properties.c src/common/properties/property.c
        src/common/config.c
        src/common/printer.c)

set_target_properties(checker PROPERTIES PUBLIC_HEADER ./libft/libft.h  stack.h  operation.h  parser.h  checker.h properties/properties.h  printer.h)

add_executable(push_swap $<TARGET_OBJECTS:libft>
        src/push_swap/push_swap.c
        src/common/stack.c
        src/common/operation.c
        src/common/parser.c
        src/common/config.c
        src/common/printer.c
        src/common/get_next_line.c
        src/common/properties/properties.c src/common/properties/property.c
        src/push_swap/inc_seq.c src/push_swap/sort_main.c src/push_swap/move_set.c src/push_swap/sort_do.c src/push_swap/sort_prepare.c src/push_swap/util.c src/push_swap/sort_3.c)

set_target_properties(push_swap PROPERTIES PUBLIC_HEADER ./libft/libft.h push_swap.h stack.h operation.h parser.h printer.h properties/properties.h)
