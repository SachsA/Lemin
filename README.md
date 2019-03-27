# Lemin

### Goal
###### The project : make a GPS for ants !
###### The goal is to make an algorithm that allows the ants to move between rooms and tunnels, at the end they have to be in the last room.
###### There has to be just one ant per tunnel and one ant per room, except the first one and the last one.

### Understand the outputs
The standard binary display the number of the ant that move and where she moves :
##### Example : 
P1-2 --> The first ant move to the room number two.
P1-3 --> The first ant move to the room number three.
...


### Program compilation and launch:
  ```sh
        make
```
***To use it :***
(There is some examples of files in the direcotry : ***"bonus/tests/"*** ; Do not hesitate to make you own files !)
  ```sh
        ./lem_in < [file]
        (Example : ./lem_in < bonus/tests/test1)
```

**====== BONUS ======**
I strongly recommand you to use it with the graphic bonus in CSFML !
With that, you can see the ants (**white dots**), move between the rooms.
The rooms are **green** when they are empty, **red** when they are full (1 ant in it).
Kust the last room is **blue** so that you can see where it is.

(First: ***make*** in the directory ***bonus***)

To use it :
  ```sh
        ./lem_in < [file] | ./bonus/visu_hex
        (Example : ./lem_in < bonus/tests/test1 | ./bonus/visu_hex)
```

#### Project realised by:
- **Alexandre Sachs : [alexandre.sachs@epitech.eu](https://github.com/SachsA)**
- **Kellian Cipierre : [kellian.cipierre@epitech.eu](https://github.com/K6PIR)**
- **Martin Cotoni : [martin.cotoni@epitech.eu](https://github.com/cotonim)**
- **Thomas Bleneau : [thomas.bleneau@epitech.eu](https://github.com/TBlenoX)**
