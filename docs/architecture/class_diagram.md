

### Core Classes in the Card RPG Game:

1. Game: Manages the overall flow of the game, including starting, ending, saving, and loading game states. It coordinates interactions between players, enemies, turns, and the board.

2. Player: Represents the player's character, tracking health, mana, experience, level, hand (cards in play), deck, skills, quests, and achievements. Players can draw and play cards, gain XP, complete quests, and use skills.

3. Enemy: Represents enemies, including their health, attack abilities, and status effects. They can attack the player or use special abilities based on AI behavior.

4. Deck: A collection of cards that belong to either the player or the enemy. It provides functionality to shuffle and draw cards.

5. Card: Represents individual cards with attributes like name, type, effect, and cost. Subclasses include specific card types like *Spell*, *Item*, and *Equipment*.

6. Turn: Manages the sequence of actions taken by players and enemies. It oversees the execution of turns and transitions between them.

7. Board: The game environment where players and enemies interact. It tracks their placement and manages updates to the battlefield.(

8. Mana: Tracks and manages the player's mana for casting cards and abilities.

9. Level: Tracks the player's progression, managing level-ups and their associated benefits.

10. Achievement: represents milestones or specific accomplishments that players can unlock during the game.

11. Effect: Manages status effects, such as buffs or debuffs, applied to players or enemies.

12. Quest: Represents quests available to the player, tracking progress and rewards upon completion.

13. Skill: Represents player abilities, with attributes like skill level, effects, and activation requirements.

14. Item: general representation of cocnsumable or single-use cards that provide an effect when played e.g healing

15. Equipment: Represents gear or items that provide persistent effects or stat bonuses when equipped by the player

16. Spell: Represents magic-based cards used to attack, heal, buff,debuff or apply other effects.

17. HealthPotion is a specific type of consumable item card(subclass od Item) used to restore a player's health.

18. Battle: Handles the combat encounters between the player and enemy.
---

### Relationships:
- Game interacts with almost all other classes to manage the gameplay flow.
- Player interacts closely with the Deck, Card, Skill, Quest, Mana, Level, and Experience classes for its attributes and actions.
- Enemy interacts with the Board, Effect, and Player classes during combat.
- Turn bridges actions between the Player and Enemy during each round.
- Effect works with both Player and Enemy to apply status effects.
- Cards have different kinds such as : Equipment,item,spell


This setup creates a modular and dynamic system for gameplay, allowing each class to play a distinct role while collaborating with others.