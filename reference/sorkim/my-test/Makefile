THE_SOURCE = main.cpp

SRCS = $(THE_SOURCE)
OBJS = $(addprefix ${OBJDIR}/,${SRCS:.cpp=.o})
OBJS_STD = $(addprefix ${OBJDIR_STD}/,${SRCS:.cpp=.o})

NAME = ft_containers
NAME_STD = std_containers
DEPF = -MMD -MP
DEP = ${OBJS:.o=.d}
OBJDIR = files
OBJDIR_STD = files_std
CXX = c++
RM = rm -f
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 #-g3 -fsanitize=address
all: ${NAME} $(NAME_STD)


$(NAME)	: ${OBJS}
	${CXX} ${CXXFLAGS} ${DEPF} ${OBJS} -o $@

$(NAME_STD)	: ${OBJS_STD}
	${CXX} ${CXXFLAGS} ${DEPF} ${OBJS_STD} -o $@

${OBJDIR}/%.o:%.cpp
	@mkdir -p ${@D}
	${CXX} ${CXXFLAGS} ${DEPF} -c $< -o $@

${OBJDIR_STD}/%.o:%.cpp
	@mkdir -p ${@D}
	${CXX} ${CXXFLAGS} ${DEPF} -c $< -D STD -o $@

clean:
	rm -rf ${OBJDIR} ${OBJDIR_STD}

fclean: clean
	${RM} ${NAME} ${NAME_STD}

re: fclean all

.PHONY: all clean fclean re

-include ${DEP}