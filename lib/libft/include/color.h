#ifndef COLOR_H
# define COLOR_H

//	===== Regular text =====
# define BLK "\001\e[0;30\002m"
# define RED "\001\e[0;31\002m"
# define GRN "\001\e[0;32\002m"
# define YEL "\001\e[0;33\002m"
# define BLU "\001\e[0;34\002m"
# define MAG "\001\e[0;35\002m"
# define CYN "\001\e[0;36\002m"
# define WHT "\001\e[0;37\002m"

//	===== Regular bold text =====
# define BBLK "\001\e[1;30\002m"
# define BRED "\001\e[1;31\002m"
# define BGRN "\001\e[1;32\002m"
# define BYEL "\001\e[1;33\002m"
# define BBLU "\001\e[1;34\002m"
# define BMAG "\001\e[1;35\002m"
# define BCYN "\001\e[1;36\002m"
# define BWHT "\001\e[1;37\002m"

//	===== Regular underline text =====
# define UBLK "\001\e[4;30\002m"
# define URED "\001\e[4;31\002m"
# define UGRN "\001\e[4;32\002m"
# define UYEL "\001\e[4;33\002m"
# define UBLU "\001\e[4;34\002m"
# define UMAG "\001\e[4;35\002m"
# define UCYN "\001\e[4;36\002m"
# define UWHT "\001\e[4;37\002m"

//	===== Regular background =====
# define BLKB "\001\e[40\002m"
# define REDB "\001\e[41\002m"
# define GRNB "\001\e[42\002m"
# define YELB "\001\e[43\002m"
# define BLUB "\001\e[44\002m"
# define MAGB "\001\e[45\002m"
# define CYNB "\001\e[46\002m"
# define WHTB "\001\e[47\002m"

//	===== High intensty background =====
# define BLKHB "\001\e[0;100\002m"
# define REDHB "\001\e[0;101\002m"
# define GRNHB "\001\e[0;102\002m"
# define YELHB "\001\e[0;103\002m"
# define BLUHB "\001\e[0;104\002m"
# define MAGHB "\001\e[0;105\002m"
# define CYNHB "\001\e[0;106\002m"
# define WHTHB "\001\e[0;107\002m"

//	===== High intensty text =====
# define HBLK "\001\e[0;90\002m"
# define HRED "\001\e[0;91\002m"
# define HGRN "\001\e[0;92\002m"
# define HYEL "\001\e[0;93\002m"
# define HBLU "\001\e[0;94\002m"
# define HMAG "\001\e[0;95\002m"
# define HCYN "\001\e[0;96\002m"
# define HWHT "\001\e[0;97\002m"

//	===== Bold high intensity text =====
# define BHBLK "\001\e[1;90\002m"
# define BHRED "\001\e[1;91\002m"
# define BHGRN "\001\e[1;92\002m"
# define BHYEL "\001\e[1;93\002m"
# define BHBLU "\001\e[1;94\002m"
# define BHMAG "\001\e[1;95\002m"
# define BHCYN "\001\e[1;96\002m"
# define BHWHT "\001\e[1;97\002m"

//	===== Reset =====
# define END "\001\e[0\002m"

/*	===== Reference =====
	https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a
*/

#endif
