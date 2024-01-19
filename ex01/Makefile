NAME := serialization
CXX := c++
CXXFLAGS := -Wall -Werror -Wextra -Wshadow -Wno-shadow -std=c++98 -g3 -I includes
SRCS := ${wildcard *.cpp}
PATH_OBJS := objs
OBJS := ${patsubst %.cpp, ${PATH_OBJS}/%.o, ${SRCS}}

all: ${NAME}

${OBJS}: ${PATH_OBJS}/%.o: %.cpp
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