NAME := scalar_converter
CXX := c++
CXXFLAGS := -Wall -Werror -Wextra -Wshadow -Wno-shadow -std=c++98 -g3 -I includes
SRCS := ${wildcard srcs/*.cpp}
PATH_OBJS := objs
OBJS := ${patsubst srcs/%.cpp, ${PATH_OBJS}/%.o, ${SRCS}}

all: ${NAME}

${OBJS}: ${PATH_OBJS}/%.o: srcs/%.cpp
	@mkdir -p ${PATH_OBJS}
	${CXX} ${CXXFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o $@

clean:
	rm -rf ${PATH_OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean ${NAME}

.PHONY: all clean fclean re