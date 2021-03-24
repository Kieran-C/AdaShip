# ADA Ship
## Advanced Programming - Kieran Caruana

![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)

This is a game of battleships written in C++

## Summary and Review of the Problem:
I was tasked with creating a game of Battleships in C++. There was many differnent game modes that I was aiming to achieve, so I needed to ensure that my code could by reused as much as possible to acheieve all the game modes. This way even if the game modes couldnt be implemented within the time frame, I my code would still be written in a way that it could be scaled up to deal with the gamemoeds down the line. Because of this, I quickly decided that I needed to have a player class, ship class and a board class, this means each of these could be an object allowing me to infitely create more of each of them if I ever needed to. This also allowed me to store huge amounts of details about particular things, for example ships could have there own health and alive status, making it very easy to check if they were sunk. I also decided haveing a gameloop class would be helpful as then theoretically I could have mutliple games running at once, which could be useful if I ever decided to add networking to the game and make it online multiplayer, although this is outside the scope of the requirements, but its good to future proof.

## UML Diagram
![UML Diagram](diagrams/uml.png)

## Inital Plan
As I already breifly covered my plan was to have 3 main classes; Player, Ships, Board. I felt this would allow me the flexability I needed to create more objects of each type. I also start projects with the aim to make the code as scalable as possible so breaking these three main aspects of the program up seemed very obvious to me. I also knew that having all the ship objects being easily accessible would be important, this would allow me to run checks on all the players ships, which would need to be done for example, to detect if a player has won.

## Analysis and Breakdown of Overall Task

- [x] Inherits settings from adaship_config file.
  - [x] Config file is an INI file 
  - [x] Config file contains sections Board and Boat
  - [x] Board Section
    - [x] Size X
    - [x] Size Y
  - [x] Ship Section
    - [x] Ship name and Ship Length
- [x] Main Menu
  - [x] One Player VS Computer
  - [ ] Two Player Game
  - [ ] One Player VS Computer (salvo)
  - [ ] Two player game (salvo)
  - [ ] One player v computer (hidden mines)
  - [ ] Two player game (hidden mines)
  - [ ] Computer v computer (hidden mines)
  - [x] Quit
- [x] Ship Placements
  - [x] Auto-place (All)
  - [x] Manual
  - [x] Auto-place (Individual Ship)
  - [x] See status of ships placed via ship overview menu
- [x] Grids
  - [x] See you gameboard
  - [x] See opponents gameboard
  - [x] Formatted Tables for Data
- [x] Validation
  - [x] Validates user input
  - [x] Validates AI input
- [x] AI Setup
  - [x] Completes valid setup automatically with validation still 
- [x] Players Turn
  - [x] Their own, current and up to date ship and targetboards are displayed as well aligned tables
  - [x] Players are able to ‘fire’ a single torpedo at a valid location using the single notation coordinate
    - [x] If the location is invalid the player is asked to re-try.
  - [ ] Auto ‘fire’ option; this option targets and ‘fires’ at valid locations.
  - [x] Players are clearly notified of a ‘hit’ or ‘miss’ (or win) based on the outcome of their turn.
  - [x] Players are able to quit the game (if not already won).
  - [x] Players are required to ‘press a key’ to end their turn.
- [x] Computers Turn
  - [x] Its own, current and up to date ship and target boards are displayed as well aligned tables.
  - [x] It uses its own up to date ‘targetboard’ to randomly ‘fire’ a torpedo at a valid location
  - [x] A clear notification of a ‘hit’ or ‘miss’ (or win) based on the outcome is shown.
  - [x] Players are required to ‘press a key’ to end their turn.

## License

**Created and Owned by Kieran Caruana**

[//]: # (These are reference links used in the body of this note and get stripped out when the markdown processor does its job. There is no need to format nicely because it shouldn't be seen. Thanks SO - http://stackoverflow.com/questions/4823468/store-comments-in-markdown-syntax)

   [dill]: <https://github.com/joemccann/dillinger>
   [git-repo-url]: <https://github.com/joemccann/dillinger.git>
   [john gruber]: <http://daringfireball.net>
   [df1]: <http://daringfireball.net/projects/markdown/>
   [markdown-it]: <https://github.com/markdown-it/markdown-it>
   [Ace Editor]: <http://ace.ajax.org>
   [node.js]: <http://nodejs.org>
   [Twitter Bootstrap]: <http://twitter.github.com/bootstrap/>
   [jQuery]: <http://jquery.com>
   [@tjholowaychuk]: <http://twitter.com/tjholowaychuk>
   [express]: <http://expressjs.com>
   [AngularJS]: <http://angularjs.org>
   [Gulp]: <http://gulpjs.com>

   [PlDb]: <https://github.com/joemccann/dillinger/tree/master/plugins/dropbox/README.md>
   [PlGh]: <https://github.com/joemccann/dillinger/tree/master/plugins/github/README.md>
   [PlGd]: <https://github.com/joemccann/dillinger/tree/master/plugins/googledrive/README.md>
   [PlOd]: <https://github.com/joemccann/dillinger/tree/master/plugins/onedrive/README.md>
   [PlMe]: <https://github.com/joemccann/dillinger/tree/master/plugins/medium/README.md>
   [PlGa]: <https://github.com/RahulHP/dillinger/blob/master/plugins/googleanalytics/README.md>
