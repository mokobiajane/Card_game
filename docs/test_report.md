Test Report

Test Suite Summary
 • Framework: Catch2
 • Files Tested: Test_deck.cpp, user_acceptance_test.cpp
 • Test Cases: 2 (Deck), 1 (User Acceptance)
 • Assertions: All passed

⸻

File: Test_deck.cpp

Test Case: Deck add, shuffle, draw, and empty behavior
 • Purpose: To verify correct behavior of Deck when adding, drawing, and checking if empty.
 • Assertions:
 • Deck::isEmpty() returns true on initialization.
 • Cards can be added and drawn correctly.
 • Deck is empty after all cards are drawn.
 • Result: PASS

Test Case: Deck reshuffle after empty
 • Purpose: Test reshuffling after the deck has been emptied and reused.
 • Assertions:
 • Cards are correctly re-added and shuffled.
 • Deck is not empty after reshuffling.
 • All cards can be redrawn and cleaned up.
 • Result: PASS

⸻

File: user_acceptance_test.cpp

Test Case: User acceptance scenario: Player takes damage and heals
 • Purpose: Simulate a basic gameplay interaction where a player takes damage and heals.
 • Assertions:
 • Player name and health are initialized correctly.
 • Health updates correctly after taking damage.
 • Healing restores health as expected.
 • Result: PASS

⸻

Overall Status: PASS

All test cases executed successfully with no assertion failures. Memory for dynamically allocated cards is also properly cleaned up in each test, indicating safe and correct use of resources.