#ifndef _COLOR_H_
#define _COLOR_H_

#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"

#define ANSI_BOLD   "\x1b[1m"
#define ANSI_RESET  "\x1b[0m"


#define COLOR(color, ...) \
    ANSI_COLOR_ ## color __VA_ARGS__ ANSI_RESET

#define BOLD(...) \
    ANSI_BOLD __VA_ARGS__ ANSI_RESET

#define COLOR_BOLD(color, ...) \
    ANSI_COLOR_ ## color ANSI_BOLD __VA_ARGS__ ANSI_RESET

#endif
