# Afro Fighter
![image](https://user-images.githubusercontent.com/104709648/212567909-8469300f-405c-4ce1-a82c-be62412ca029.png)

Atari ST game 
## 1. General Game Overview

Afro frighter is a 2d combat game that takes alot of insperation from the popular "Street Fighter" in the 80s. The player is placed in a flat arena with an opponent they must defeat with a combination of hand to hand combat and super powers while ensuring their own health is not depleted. 

Future updates will feature a 2 - player game mode allowing players to put their skills to the test against their friends

![](https://i.imgur.com/tMmlcPl.png)





## 2. Game Play Details for 1-Player Mode

### 2.1 Menu UI and Logic

The game will launch into a menu screen with the Afro Fighters logo and two game mode options; `1-player` and `2-player`.

![image](https://user-images.githubusercontent.com/104709648/212567852-d2971d61-3278-4f28-ac5f-557cd35d1e47.png)

#### 2.1.2 Start State Logic and Game View UI 

The `1-Player` game mode beings with the players avatar and the cpu controlled opponent rendered in the arena along with their health bars and a count down starting from 3 in the center of the arena. After the count down has reached one "Fight" will be displayed in the center of the arena; player controls become active and the cpu opponent begins executing its scripted movesets.  

### 2.2 Objectives and Rules

#### 2.2.1 Health and Damage 
Player and Cpu opponent will begin with 100% health depicted by the `P-Health Bar` displayed in the top right corner of the screen and `CPU-Health Bar` displayed in the top left corner. When Damage is dealt the health bar of the player who was damaged will be re-renderd with a length `Damage-Value%` shorter. 

Below is a table defining all the offensive moves and their damage values.

| Move  | Damage |
| ------------- | ------------- |
| `Light Attack` | 2% |
| `Heavy Attack`  | 6% |
| `Ranged / Super` | 16% |

#### 2.2.2 Combat Mechanics 

*Offense*

 `Player` 
- Can use a combination of light and heavy as many times as they wish to deal damage to the opponent.
    - see 2.3.1 for implementation details  

 `Cpu-Player`
- This will be the players opponent. It will be "controlled" by the cpu.
    - it is not intelligent since its offense and defense is not a reaction to is enviroment but a scripted set of moves and actions.
    - see 2.3.2 for implementation details


 *Defense*

- If any of the players is hit by an attack while they're in the blocking state, damage is reduced by 50%

 *Ability and Combat Balancing* 

In order to discourage a playstyle that spams the `Ranged / Super` attack, this move will only be avaible if the play can block two consecutive `Heavy Attacks` from the opponent. 
   - When this event is completed a small star will appear below the players health bar to indicate that a their `Ranged / Super` attack is avaiable
      - Once this attack is used the star will diseappear untill the event is completed again.
   - The event can be completed multiple times, but each play can only have at most 3 stars at once.  

### 2.3 Scene Objects

`Scene` will display all objects to a `640px x 400px` screen, below are all the current `Scene Objects`

- `Afro Fighter` (2x)
    - see 2.3.1 for details
- `Health bar` 
- `Arena floor` 
- `Count Down Numbers`
- `Super Indicator`
- `Fire Beam`
- `Avatar Profile Image`
- `Avatar Name`

This means that at any given time during a fight there at least 6 scene objects being displayed on the screen.

#### 2.3.1 Afro Fighter Avatar and Functional Compenents

<p align="center">
  <img src="https://i.imgur.com/HEpC0ON.png" width="200" > 
</p>


#### 2.3.2 CPU-Player 

#### 2.3.3 Arena and HUD 

`| Arena` 

![](https://i.imgur.com/h2uduBM.png)



| Component            | Properties | Behaviour|Image|
|-----------|----------|---------|-----|
|`Arena-Floor` |<ul><li>Size: `640 x 48 px` </li><li>Position Integers, `x` and `y` coordinate</li></li></ul>   |      |![](https://i.imgur.com/iE2Cvvo.png)|

<br/><br/>

`| Health and Info bar`

![](https://i.imgur.com/Wx2WMlJ.png)

| Component   | Properties     | Behaviour|Image|
|-------------|----------|---------|-----|
|`Health-bar` |<ul><li>Size: `248 x 36 px` </li><li>Position Integers, `x` and `y` coordinate</li></li></ul>   |<ul><li>Represents Players current Health </li><li>When damage is delt to player it is rerenders with the its `current length - (damage-value% x current length)` </li></ul>       |![](https://i.imgur.com/5ha6Tac.png)
|`Avatar-Name`|          |         |![](https://i.imgur.com/DO5GOhO.png)|
|`Avatar-Profile-Img` | |  |![](https://i.imgur.com/qECScbN.png)|


### 2.4 Physics

### 2.5 Asynchronous Events

#### 2.5.1  Input

*Movement*

1. Move right: `A`
   - changes players position 1 unit to the right and triggers `Rs Running Animation` 
   
2. Move left: `D`
   - changes players position 1 unit to the left and triggers `Ls Running Animation`
   
3. Slide: `↓`   
   - triggers `Slide pose`
   
4. Jump: `Space`

*Combat*

5. Light attack (Alternating): `W`      
   - On 1st click 
      - Triggers `Left Punch` pose
   - On 2nd Click
      - Triggers `Right Punch` pose  
      
6. Heavy attack: `←`     
   - Triggers `Left Foot Kick` pose

7. Super / Ranged attack: `F`     
   - Triggers `Imbue` pose
   - Triggers `Fire Beam Imbue` Sprite
   - `Fire Beam` projectile object travels across its intial y-axis until a collision is encounterd 

8. Block: `→`      
   - Triggers `Block` pose
   - Player can not take damage in this state

### 2.6 Synchronous Events

### 2.7 Condition Based Events

### 2.8 Hypothetical Gaming Session

## 3. Game Play details for 2-player Mode

## 4. Sound Effects

| Sound effect name | Brief Description | Event that triggers playback |
| ------------- | ------------- | ------------- |
| Main Theme | "Help urself Dyn remix" found on youtube | User starts the game |
| Attack misses | - duration of a second | any of the players inputs an attack key but no collision is detected |
| Attack connects | - duration of a second | any of the players inputs an attack key and a collision is detected |
| Super | - duration of a second | Super/Ranged attack input is pressed |

## 5. Additional Features (Time Permitting)
   
#### 5.1.1 More attacks:
- crouching punch/kick
- jumping punch/kick
- elbow
- energy blast (smaller than ultimate move)

#### 5.1.2 Multiple rounds: 
A round is over when 1 player's health reaches 0%. The first player with 2 ko's wins the match. The Number of player ko's is displayed next to their name and healthbar.

#### 5.1.3 Stun meter: 
As a player takes hits that aren't blocked, a meter next to the healthbar fills up. When this meter fills up, the next hit a player takes will knock them to the ground and put them in a state where they can't do anything for 2 seconds.

The healthbar will fill up at the following rates:

| Move  | Stun |
| ------------- | ------------- |
| `Light Attack` | 10% |
| `Heavy Attack`  | 30% |
| `Ranged / Super` | 60% |
 
#### 5.1.4 Finishing move:
When a player is knocked out at match point, the player that's still standing will have the option to perform a mortal kombat style finishing move.

 
#### 5.1.5 "Smarter" CPU:
The `CPU-Player` has a chance to perfectly counter the player by reading input. For example the real player could enter the input to punch and the cpu would block. Outside of this phase the CPU will perform actions based on distance to the player and a predetermined sequence of moves.

#### 5.1.6 Difficulty levels
As difficulty increases, the probablitiy of a perfect counter also increases (should never be 100% or the CPU will be unbeatable)

 
#### 5.1.7 Character select: 
If any player picks a character, that character is grayed out and cannot be selected by someone else. The cpu will pick a character out of the remaining ones at random. The player also has this option.

#### 5.1.8 Announcer:
| Voiceline | Event that triggers playback |
| ------------- | ------------- |
| "Round 1/2, Fight!" | The start of the first or second round |
| "Final Round, Fight!" | The start of the third round |
| "Player 1/2 Wins!" | Match is over and winner is declared |

#### 5.1.9 Graphics Overhaul:
[] better background (stack implementation to know when pixels are overlapping)
[] psuedo 3d floor
[] shaded characters

