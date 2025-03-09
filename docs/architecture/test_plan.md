Test Plan

 Testing Approach
1. Unit Tests:
   - Test individual classes (e.g., Card, Deck, Player) for correct initialization and behavior.
   - Verify methods such as shuffle, draw, addCard, and playCard to ensure they function as expected.
2. Integration Tests:
   - Simulate full game rounds to verify the interaction between different modules.
   - Ensure that sequences of actions (e.g., dealing cards, taking turns, checking win conditions) update the game state correctly.
3. System Tests:
   - Conduct end-to-end testing by simulating complete game sessions from start-up to game conclusion.
   - Validate that the game handles various edge cases (e.g., empty deck, invalid moves) gracefully.
4. Acceptance Tests:
   - Confirm that the game meets all specified objectives and requirements.
   - Verify that both human and AI players interact properly with the game engine.

 ~~Tools and Coverage
- Testing Framework:  
  - Utilize Google Test or Catch2 for unit and integration testing.
- CI Integration:  
  - Set up GitHub Actions to automatically build and run tests on each commit.
- Coverage Goals:  
  - Aim for a minimum of 80% code coverage on critical game components to ensure reliability and maintainability.