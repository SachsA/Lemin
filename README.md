# Lemin

Epitech, first year project.

Goal of the project : make a GPS for ants ! The goal is to make an algorithm that can allow the ants to move between rooms and tunnels, at the end they have to end in the last room.
There has to be just one ant per tunnel and one ant per room, except the first one and the last one.

The standard binary display the number of the ant that move and where she moves :
example : 
P1-2
P1-3
...
--> The first ant move to the room number two.
--> The first ant move to the room number three.
...

To compile : make.

To recompile : make re.

To clean all : make fclean.

To use it :
(There is some examples of files in the direcotry : bonus/tests/)
(Don't hesitate to make you own files !!!)

./lem_in < [file]

example => ./lem_in < bonus/tests/test1

====== BONUS ======
I strongly recommand you to use it with the graphic bonus in CSFML ! With that, you can see the ants (white dots), move between the rooms, the rooms are green when they are empty, red when they are full (1 ant in it) and just the last room is blue so that you can see where it is.

(first you have to 'make' in the directory 'bonus')

To use it :

./lem_in < [file] | ./bonus/visu_hex

example => ./lem_in < bonus/tests/test1 | ./bonus/visu_hex


Group of the project :
Alexandre Sachs,
Kellian Cipierre,
Thomas Bleneau,
Martin Cotoni,
(All in Epitech Bordeaux)
