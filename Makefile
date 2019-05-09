LIB_NAMES		=	ft
PROG_NAMES		=	bf_vm

ARGS			=	kek
PRJ_ROOT		=	.

DEBUG			=	$(filter debug,$(MAKECMDGOALS))

INCDIR			=	$(PRJ_ROOT)/include/
SRCDIR			=	$(PRJ_ROOT)/src/
OBJDIR			=	$(PRJ_ROOT)/obj/
LIBDIR			=	$(PRJ_ROOT)/lib/
RLSDIR			=	$(PRJ_ROOT)/release/
DBGDIR			=	$(PRJ_ROOT)/debug/
BINDIR			=	$(if $(DEBUG),$(DBGDIR),$(RLSDIR))

LIB_FULL_NAMES	=	$(addprefix lib, $(LIB_NAMES))
LIBS			=	$(addprefix $(LIBDIR),$(addsuffix .a, $(LIB_FULL_NAMES)))
PROGS			=	$(addprefix $(BINDIR),$(addsuffix .exe, $(PROG_NAMES)))
BINS			=	$(RLSDIR)* $(DBGDIR)*

FIND_FILES		=	$(addprefix $(dir)/,$(notdir $(basename $(wildcard \
					$(SRCDIR)$(dir)/*.c))))
LIB_FILES		=	$(foreach dir,$(LIB_FULL_NAMES),$(FIND_FILES))
PRG_FILES		=	$(foreach dir,$(PROG_NAMES),$(FIND_FILES))
#FILES			+=	$(addprefix bf_vm/,$(notdir $(basename $(wildcard $(SRCDIR)bf_vm/*.c))))
#FILES			+=	$(addprefix ft_lib/,$(notdir $(basename $(wildcard $(SRCDIR)ft_lib/*.c))))
LIB_SRCS		=	$(addprefix $(SRCDIR), $(addsuffix .c, $(LIB_FILES)))
LIB_OBJS		=	$(addprefix $(OBJDIR), $(addsuffix .o, $(LIB_FILES)))
PRG_SRCS		=	$(addprefix $(SRCDIR), $(addsuffix .c, $(PRG_FILES)))
PRG_OBJS		=	$(addprefix $(OBJDIR), $(addsuffix .o, $(PRG_FILES)))

LINKLIBS		=	$(addprefix -l, $(LIB_NAMES))

LINKER			=	ar rc
CC				=	gcc
RM				=	rm -rf

CFLAGS			=	-Wall -Wextra -Werror -Wimplicit -ansi -pedantic \
					$(if $(DEBUG),$(DBGCFLAGS),)
DBGCFLAGS		=	-g

.PRECIOUS		:	$(PRG_OBJS) $(LIB_OBJS) $(LIBS)

all				:	$(PROGS)

debug			:	$(PROGS)
					@:

%.a				:	$(LIB_OBJS)
					$(LINKER) $@ $^
					ranlib $@

%.exe			:	$(LIBS) $(PRG_OBJS)
					$(CC) $(CFLAGS) -I$(INCDIR) -o $@ $^ -L$(LIBDIR) $(LINKLIBS)

$(OBJDIR)%.o	:	$(SRCDIR)%.c
					@mkdir -p $(@D)
					$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean			:
					@$(RM) $(OBJDIR)*
					@:

fclean			:	clean
					@$(RM) $(LIBS) $(BINS)
					@:

re				:	fclean all

run				:	all
					$(foreach prog,$(PROGS),./$(prog) $(ARGS);)

rerun			:	re run
