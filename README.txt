-------OOP2 project 
-------- Twin Shot
By: Hadar Liel Harush- 211721568 

Twin Shot is a shooter game.
The player controls the angel who defend their homeland from invaders by using bows and arrows.
The levels end when the player has destroyed all of the enemies. 

The game is inspired by Disney princesses. When a player is selected, the enemies are 
automatically selected along with the song in the background.

The player's goal in each stage is to kill all enemies by shooting arrows. When all the enemies
in a stage are dead, you automatically move to the next stage.

The player plays using arrows, it automatically descends downwards using the law of gravity.
He shoots arrows using the "space" key.

At the beginning of the game a menu opens.
When pressed:
1. New game - a menu will open showing all the stages in the game and the stages that the player has already opened.
When a stage is clicked, the game opens the stage and can be played.
2. Design - the user will be able to choose which character he chooses. When the back button is pressed, it saves the character.
Now, when the player plays, it will change the character to the character he chose, change the enemies according to that Disney movie 
(Jasmine and Jaffer, Peter Pan and Captain Hook, Belle and the Beast and more). In addition, the music will change depending on the film.
3. Settings - you can choose whether the background music and game music will be turned on or not. The default is music on.
4. Help - shows the game rules and settings.
5. Exit button - exits the program.


There is a moving object class, from which the player, monster, and arrow classes inherit the drawing functions, and the displacement
update function.


The classes:
#Arrow-
#



1. board - the base of the game. all the actions is on the board.
2. buttoms - in order to finish, go back and go to the help menue.
3. cake- the pacman needs to eat all tjhe cakes in order to pass a level.
4. controller - in order to control the game.
5. direction- in order to know the direction
6. door- we made vector inorder to delete door 
7. gameobject- inorder to get position and scales
8. Ghost- All wind displacement and collision handling is there
9. GiftFrozen- makes all the Ghost froze in an ice cube.
10. GiftHeart- incrase life 
11. GiftSuper- for the super pacman.
12. GiftTime- add 20 sec
13. key- open a door
14. main- stat the game
15. moving object- for the ghost and pacman
16. resorcues- load music and texture in singeltone
17. staticobject- for the static object
18. superpacman- for the superpacman case. its open doors and kills ghosts
19. wall- we cant goes throw walls.