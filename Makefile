# Compilador
CC = gcc

# Diretórios
SRC_DIR   = src
INC_DIR   = include
EXT_DIR   = external/SDL3
BUILD_DIR = build
OBJ_DIR   = $(BUILD_DIR)/obj

# Arquivos finais
TARGET      = $(BUILD_DIR)/game
SDL_DLL_SRC = $(EXT_DIR)/bin/SDL3.dll
SDL_DLL_DST = $(BUILD_DIR)/SDL3.dll

# Flags
CFLAGS = -Wall -Wextra -MMD -MP \
	-I$(INC_DIR) \
	-I$(EXT_DIR)/include

LDFLAGS = \
	-mwindows \
	-L$(EXT_DIR)/lib \
	-lSDL3 \
	-lm

# Fontes e objetos
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEP = $(OBJ:.o=.d)

# Regra principal
all: $(BUILD_DIR) $(OBJ_DIR) $(TARGET)

# Criar diretórios
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(OBJ_DIR): | $(BUILD_DIR)
	mkdir -p $(OBJ_DIR)

# Linkagem
$(TARGET): $(OBJ) $(SDL_DLL_DST)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

# Compilação .c -> .o (+ .d automático)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Copiar DLL apenas se necessário
$(SDL_DLL_DST): $(SDL_DLL_SRC) | $(BUILD_DIR)
	cp $< $@

# Executar
run: $(TARGET) $(SDL_DLL_DST)
	./$(TARGET)

# Limpeza
clean:
	rm -rf $(BUILD_DIR)

# Incluir dependências automaticamente (se existirem)
-include $(DEP)

.PHONY: all clean run