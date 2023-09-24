NAME = cub3D
NAME_BONUS = cub3D_BONUS
CC = cc
MSRC = cub3d.c Mandatory/start_game.c Mandatory/init_strct.c Mandatory/init_utlis.c \
	Mandatory/init_utils2.c Mandatory/manage_keys.c Mandatory/move_player.c Mandatory/draw.c Mandatory/cast_rays.c \
	Mandatory/camp_ver_hor.c Mandatory/cast_hor.c Mandatory/cast_ver.c Mandatory/draw_line.c \
	Mandatory/filetools.c Mandatory/parsemapkeys.c Mandatory/error.c Mandatory/parsetextures.c \
	Mandatory/parsemap.c Mandatory/parsetexturestools.c Mandatory/parsecolors.c Mandatory/parsecolorstools.c Mandatory/parsingtools.c get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c utils/ft_strcmp.c utils/split.c utils/ft_split.c utils/free.c utils/ft_strncmp.c \
	utils/ft_atoi.c utils/ft_strtrim.c
BSRC = cub3d.c bonus/start_game_bonus.c bonus/init_strct.c bonus/init_utlis.c \
	bonus/init_utils2.c bonus/manage_keys_bonus.c bonus/move_player_bonus.c bonus/draw_bonus.c bonus/cast_rays_bonus.c \
	bonus/camp_ver_hor_bonus.c bonus/cast_hor_bonus.c bonus/cast_ver_bonus.c bonus/draw_line_bonus.c  \
	bonus/map2d_bonus.c bonus/filetools.c bonus/parsemapkeys.c bonus/error.c bonus/parsetextures.c \
	bonus/parsemap.c bonus/parsetexturestools.c bonus/parsecolors.c bonus/parsecolorstools.c get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c utils/ft_strcmp.c utils/split.c utils/ft_split.c utils/free.c utils/ft_strncmp.c \
	utils/ft_atoi.c utils/ft_strtrim.c bonus/parsingtools.c
MOBJ = $(MSRC:.c=.o)
BOBJ = $(BSRC:.c=.o)
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -Imlx 
INCLUDES = include/cub3d.h include/define.h include/structers.h 

all :$(NAME)

$(NAME) :$(MOBJ)
	$(CC) $(MOBJ) -lmlx -framework OpenGL  -framework AppKit -o $(NAME) 

bonus :$(NAME_BONUS)

$(NAME_BONUS) :$(BOBJ) 
	$(CC) $(BOBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS) 
	
%.o : %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c  $< -o $@

clean:
	$(RM) $(MOBJ)
	$(RM) $(BOBJ)
	
fclean: clean 
	$(RM) $(NAME) $(NAME_BONUS)
re : fclean all