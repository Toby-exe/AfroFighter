# Afro Fighter
![image](https://user-images.githubusercontent.com/104709648/212567909-8469300f-405c-4ce1-a82c-be62412ca029.png)

Atari ST game 
## 1. General Game Overview

Afro frighter is a 2d combat game that takes alot of insperation from the popular "Street Fighter" in the 80s. The player is placed in a flat arena with an opponent they must defeat with a combination of hand to hand combat and super powers while ensuring their own health is not depleted. 

Future updates will feature a 2 - player game mode allowing players to put their skills to the test against their friends

## <----ADD GAME VIEW IMAGE HERE---->


## 2. Game Play Details for 1-Player Mode

### 2.1 Menu UI and Logic

The game will launch into a menu screen with the Afro Fighters logo and two game mode options; `1-player` and `2-player`.

![image](https://user-images.githubusercontent.com/104709648/212567852-d2971d61-3278-4f28-ac5f-557cd35d1e47.png)

#### 2.1.2 Start State Logic and Game View UI 

The `1-Player` game mode beings with the players avatar and the cpu controlled opponent rendered in the arena along with their health bars and a count down starting from 3 in the center of the arena. After the count down has reached one "Fight" will be displayed in the center of the arena; player controls become active and the cpu opponent begins executing its scripted movesets.  

### 2.2 Objectives and Rules

#### 2.2.1 Health and Damage 
Player and Cpu opponent will begin with 100% health depicted by the `P-Health Bar` displayed in the top right corner of the screen and `CPU-Health Bar` displayed in the top left corner. When Damage is dealt the health bar of the player who was damaged will be re-renderd with a length `Damge-Value%` shorter. 

Below is a table defining all the offensive moves and their damage values.

| Move  | Damage |
| ------------- | ------------- |
| `Light Attack` | 5% |
| `Heavy Attack`  | 10% |
| `Ranged / Super` | 20% |


#### 2.2.2 Combat Mechanics

*Ability and Combat Balancing* 

In order to discourage a playstyle that spams the `Ranged / Super` attack, this move will only be avaible if the play can block two consecutive `Heavy Attacks` from the opponent. 
   - When this event is completed a small star will appear below the players health bar to indicate that a their `Ranged / Super` attack is avaiable
      - Once this attack is used the star will diseappear untill the event is completed again.
   - The event can be completed multiple times, but each play can only have at most 3 stars at once.  

*Dodging and Defense*


### 2.3 Objects

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

## 5. Additional Features (Time Permitting)



