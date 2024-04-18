MAKE = make --no-print-directory -s
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
ORANGE = \033[0;33m
PURPLE = \033[0;35m
LIGHT_GRAY = \033[0;37m
DARK_GRAY = \033[1;30m
LIGHT_RED = \033[1;31m
LIGHT_GREEN = \033[1;32m
LIGHT_YELLOW = \033[1;33m
LIGHT_BLUE = \033[1;34m
LIGHT_MAGENTA = \033[1;35m
LIGHT_CYAN = \033[1;36m
LIGHT_WHITE = \033[1;37m
GRAY = \033[0;37m
NC = \033[0m
BOLD = \033[1m
NS = \033[0m
ITALIC = \033[3m
UNDERLINE = \033[4m
STRIKEOUT = \033[9m
TASK = ${YELLOW}${BOLD}
OK = ${GREEN}${BOLD}
FAIL = ${RED}${BOLD}
ACT = ${MAGENTA}${BOLD}

define SUBMAKE
	@cd ${1} && ${MAKE}
endef

all:
	echo "    ${TASK}Building HexOS kernel${NC}"
	echo "        ${ACT}Compile kernel${NC}"
	hcc src/main.c ../../dist/kernel.hxe config.json
	echo "    ${OK}Done${NC}"

clean:
	rm -f "${BENV_PROJ_PATH}/dist/kernel.hxe"
