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
All types of bricks are inherited from the brick class.
All objects that appear on the screen inherit from the Object class.


The classes:
# Arrow - inherits from the class of moving objects, which inherits from the object class.
		 The arrow is shot from the player according to the player's direction. The player
		 can stand on the arrow, and it disappears after 5 seconds. It alerts before it
		 disappears by flashing. Handles encounter with whites.
# BlockBrick - a brick painted black. It is not possible to pass through, under or over it. 
			  Heir from the "Blanka" department. An arrow stuck in her.
# Brick - all types of bricks inherit from it.
# Buttons - a class responsible for all types of buttons in the game. Load images of buttons,
			place in positions and settings.
# Character - inherits from the moving object class which inherits from the object class.
			  The player holds his life count and handles a collision with a monster.
# Controll - responsible for the opening screen of the game and the opening menu. 
			 Sends to departments according to the button the user clicked.
# Design - the user can choose which player he wants. He selects by the characters on the left 
		   and when he presses all the back button, it saves the selected player. 
		   The enemies and the song are automatically selected according to the selected player.
# FallBrick - brick painted in gray. Heir from the "Blanka" department. You can pass under it,
			  not from the sides, and you can step on it. From the moment the player steps on it,
			  it disappears after 5 seconds and then returns after a few seconds to appear on the screen.
			  Handles a collision with an actor. An arrow stuck in her.
# Help - a screen with game instructions will open.
# Level - the stage that opens is according to the stage that the user chose on the "select stage" screen.
		  Reads each pixel from the map it opened, and by colors it knows what type of object it is,
		  sends to the right place and puts it in the appropriate vectors. Creates a "unique ptr" for each. 
		  All types of objects go into a vector of objects. A monster and a protected monster go into a 
		  vector of monsters.
# Map - Checks if the moving objects go beyond the borders of the screen, and if so they return from the
		other side if nothing blocks them (like bricks). There is a function that checks the maximum distance
		that the same moving object can move before it is blocked by another object. A function that adds an
		arrow to the vector of arrows and a function that removes it from the vector after it is gone.
# Monster - inherits from the moving object class that inherits from the object class. Handles collision 
			with an arrow. There is a protected monster, which looks different from the rest, and you have
			to shoot it twice before it dies. After one shot he turns into a normal monster.
# MovingObject - All moving objects inherit from this class and inherit the "try move" function and this
				 function checks according to the function from the Map class if it can move and returns
				 to the same object if yes or not.
# Music structure - holds two boolean variables. Background music for the game itself and background music
					for the menu.
# Consts - holds global variables.
# Object - all the objects read from the screen, go into a unique ptr vector.
# RegularBrick - brown dyed white. Heir from the "Blanka" department. You can pass under it, not from the
				 sides, and you can step on it. Handles a collision with an actor. An arrow stuck in her.
# Resources - Loads all images by singletons.
# SelectLevel - when in the menu you click "New Game" a screen opens allowing the user to choose which stage
				he wants to play. The steps he has not yet passed are locked. When a step number is clicked,
				it sends the step number the user selected to the step class.
# Settings - The player can decide whether he wants to turn on or off the background music in the menu
			 and the background music in the game. The default is that they are on.
