## Want to add your own custom Card/Hero?
If you're interested Here's a step-by-step on how to integrate your own card/character into the game.

# Card addition
Create a new .h and .cpp file for the card
Make sure the new .cpp constructor sends all relevant data to EntityCard or InstantCard
Add any behavioural/hooks to the code
Update include/boot/CardManager.h and include it both as a header, and inside the constructor

# Character addition
Create a new .h and .cpp file for the given character
Make sure the new .cpp constructor sends all relevant data to Character
You must modify the "activateRage()" function to do what you need it to (No ability means no hero)
Update include/boot/CharacterManager.h and include it both as a header, and inside the constructor