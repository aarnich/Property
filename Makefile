TARGET = kmusb

CC = gcc
CFLAGS = -g

OUTDIR = ./bin
DATADIR = ./data
SUBDIR = src 
DIR_OBJ = ./obj

INCS = $(wildcard *.h $(foreach fd, $(SUBDIR), $(fd)/*.h))
SRCS = $(wildcard *.c $(foreach fd, $(SUBDIR), $(fd)/*.c))
NODIR_SRC = $(notdir $(SRCS))
OBJS = $(addprefix $(DIR_OBJ)/, $(SRCS:c=o)) # obj/xxx.o obj/folder/xxx .o
INC_DIRS = $(addprefix -I, $(SUBDIR))

.PHONY: clean echoes

$(TARGET): $(OBJS)
    $(CC) -o $(OUTDIR)/$@ $(OBJS)

$(DIR_OBJ)/%.o: %.c $(INCS)
    mkdir -p $(@D)
    $(CC) -o $@ -c $< $(CFLAGS) $(INC_DIRS)

clean:
    rm -rf $(OUTDIR)/* $(DATADIR)/* $(DIR_OBJ)/*

echoes:
    @echo "INC files: $(INCS)"  
    @echo "SRC files: $(SRCS)"
    @echo "OBJ files: $(OBJS)"
