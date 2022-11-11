

#ifndef PARSING_H
# define PARSING_H

# include "libft.h"

# define ARG_OPTIONS	"h"
# define HELP_OPTION	0x01
# define LONG_HELP_OPTION	"help"

t_byte	retrieve_options(int argc, char **argv, char *op_chars);

#endif // PARSING_H
