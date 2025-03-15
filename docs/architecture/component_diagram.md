### Description of Components

1. Game Engine
   - Responsibilities: Manages the overall game flow, including initialization, starting, and ending the game.
   - Interfaces:
     - initialize(): Sets up the initial game state and resources.
     - startGame(): Begins the game loop and handles main game events.
     - endGame(): Cleans up resources and ends the game session.

2. Game Logic
   - Responsibilities: Handles core gameplay mechanics, including turn execution and state updates.
   - Interfaces:
     - executeTurn(): Processes the actions of players and enemies during a turn.
     - updateState(): Updates the game state based on the outcomes of actions and events.

3. Rendering Engine
   - Responsibilities: Manages graphical rendering of game elements, such as the game board, cards, and characters (for internal testing and debugging).
   - Interfaces:
     - drawBoard(): Renders the game board with all entities and objects.
     - renderCard(): Draws individual cards for testing purposes.

4. Entities
   - Responsibilities: Represents the different game entities, including players, enemies, cards, decks, and equipment.
   - Interfaces:
     - Player: Manages player attributes, actions, and interactions.
     - Enemy: Manages enemy attributes and behaviors.
     - Card: Represents individual cards with effects and costs.
     - Deck: Manages collections of cards for players and enemies.
     - Equipment: Manages equipment items and their effects on players.

5. AI Engine
   - Responsibilities: Implements artificial intelligence for enemy behavior and decision-making.
   - Interfaces:
     - enemyMove(): Determines the actions and movements of enemies.
     - calculateActions(): Calculates the optimal actions for enemies based on the game state.

6. Deck
    - This is the set of cards on the board which the player selects from to form a deck of card for game play.

7. Player
    - The real player takes  attributes like playing a card, attack the enemy, gain achievements. it is connected to the cards, deck e.t.c.

8. Cards
    - This is the signle card a player/ enemy picks, which has different actions and effects on the characters in play.         