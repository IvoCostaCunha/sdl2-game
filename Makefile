RELEASE_TIME := $(shell date +%Y%m%d-%Hh%M)
CC := g++ -m64 -std=c++17
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
SRC := $(wildcard $(SRC_DIR)/*.cpp)

# Remplace tout les .c par des .o et repertoire SUBSTRING
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
RELEASE := $(BIN_DIR)/game
DEBUG := $(BIN_DIR)/game_debug

ICON_SRC := $(SRC_DIR)/icon.rc
ICON_OBJ := $(OBJ_DIR)/icon.res

CFLAGS := -Wall -Werror -Werror=implicit-fallthrough=0 -Wno-unused-variable  -Wextra -DDEBUG -g --wrapv
# -g --wrapv disabled if release
RELEASE_CFLAGS := -O2 -UDEBUG
LFLAGS := -I./$(SRC_DIR)

ifeq ($(OS),Windows_NT)
	RELEASE := $(RELEASE).exe
	DEBUG := $(DEBUG).exe
	LFLAGS := -lmingw32 -L./lib -I./include -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf $(LFLAGS)
	RELEASE_CFLAGS := $(RELEASE_CFLAGS) -mwindows
else
	LFLAGS += $(shell pkg-config --cflags --libs sdl2)
	LFLAGS += $(shell pkg-config --cflags --libs SDL2_ttf)
	LFLAGS += $(shell pkg-config --cflags --libs SDL2_image)
endif

# Ignore des fichiers s'appelant all etc en tant que fichier
.PHONY: all release debug start clean mrproper

all: $(DEBUG)

debug: $(DEBUG)

release: $(RELEASE)

# -v n'existe pas sur Windows !
$(OBJ_DIR):
	mkdir -v $@

# | optionnels
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@echo Compiling $<
	$(CC) -c $< $(CFLAGS) $(LFLAGS) -o $@

$(DEBUG): $(OBJ)
	@echo Linking objects files to $@
	$(CC) $^ $(CFLAGS) $(LFLAGS) -o $@

ifeq ($(OS),Windows_NT)
$(ICON_OBJ): $(ICON_SRC)
	@echo Creating icon $<
	windres $^ -O coff $@

$(RELEASE): $(SRC) $(ICON_OBJ)
else
$(RELEASE): $(SRC)
endif
	@echo Compiling $<
	$(CC) $^ $(RELEASE_CFLAGS) $(LFLAGS) -o $@

start: $(DEBUG)
	cd $(BIN_DIR) && ./$(shell basename $(DEBUG))

clean:
	rm -fv $(RELEASE) $(DEBUG)

mrproper: clean
	rm -fv $(ICON_OBJ) $(OBJ)

archive: mrproper
	tar -cf archive-$(RELEASE_TIME) .