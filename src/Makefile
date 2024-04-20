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
ACT = ${MAGENTA}${BOLD}
OK = ${GREEN}${BOLD}
FAIL = ${RED}${BOLD}
PASS = printf ""

define SUBMAKE
	@cd ${1} && ${MAKE} ${2}

endef

all: init
	@echo "${TASK}Building HexOS${NC}"
	@echo "    ${TASK}Prepairing${NC}"
	@${MAKE} clean
	@echo "        ${TASK}Prepairing build environment${NC}"
	@echo "            ${ACT}Activate build environment${NC}"
	@echo "        ${OK}Done${NC}"
	@${MAKE} kernel
	@echo "${OK}Done${NC}"

kernel:
	@cd src/kernel && ${MAKE}

clean:
	@echo "        ${ACT}Clean${NC}"
	$(call SUBMAKE, src/kernel, clean)

init:
	@${PASS}
