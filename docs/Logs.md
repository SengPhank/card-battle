# To Do :
- Complete UI with custom wxCards.
- Create a "Help" button for more information about each card
- Make heroes interactable via GUI
- Add more cards with unique abilities
- Add more Heroes
- Create a more sophisticated bot (Tricky bots, Cowardly bots, Aggressive bots)
- Each card should have their own unique check to see if its playable. Pass in the game panel to highlight necessary. This is stepping back from modularisation, but looks a lot more intuitive

## Feb 05
Added more cards, made characters interactable so Instants have more targets
- More Cards: (Instant) Soul Stealer, (Instant) Fireball
- Characters are now interactable (With instants)
- Colour manager added

## Jan 30
Cleaned up the UI and added emojis to make it less text-crowded. 
- UI now has colour feedback, telling you where you are able to use your cards
- Card behaviours are now implemented and fully working
- Basic Bot fixed to account for new card behaviours
- Rage feature fully added. 

## Jan 29
Redesigned old code, and added a basic bot which follows a greedy algorithm
- Card classes were redesigned to have two types, ENTITIES and INSTANTS
- Basic Bot to have somebody play the other side of the game.
- Managers and helper functions developed to help clean code.

## Jan 24
New gui implemented. This will make it easier to test new cards and features later. Working on a plan to ensure the project is coded cleanly
- Use of wxWidget to develop UI
- Develop future idea implementation to make modularisation easier

## Jan 21
Initial skeleton for the project is build. This includes
- Card class
- Character class
- Make files