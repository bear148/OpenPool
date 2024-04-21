SRC = ${wildcard src/*.cc}
DEPS = ${wildcard headers/*}
DEPS += ${wildcard src/*.hh}
OBJ = ${addsuffix .o, ${subst src/,bin/,${basename ${SRC}}}}

APP = ./bin/opool

CXX = clang++

CCACHE = ccache

CXXVER=c++17
CXXFLAGS = \
		   -std=${CXXVER} \
		   -Wall \
		   -Wextra \
		   -pedantic \
		   -Wno-deprecated-declarations -Wno-missing-field-initializers

ifeq (${releasemode}, on)
	CXXFLAGS += -O3 -s
else
	CXXFLAGS += -O0 -g
endif

ifeq (${debug}, on)
	CXXFLAGS += -DDEBUG_EXCEPTION
endif

ifeq (${triangles}, off)
	CXXFLAGS += -DDISABLE_TRIANGLES
endif

CXXLIBS += -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer -lm -lcurl

compile: ./bin ${OBJ} ${SRC}
	${CCACHE} ${CXX} -o ${APP} ${OBJ} ${CXXLIBS}

./bin:
	mkdir -p bin

bin/%.o: src/%.cc ${DEPS}
	${CCACHE} ${CXX} -c $< ${CXXFLAGS} -o $@

clean:
	rm bin/*.o $(APP)

all:
	@echo compile
	@echo clean
