# Afro Fighter

![image](https://user-images.githubusercontent.com/104709648/212567909-8469300f-405c-4ce1-a82c-be62412ca029.png)

Atari ST game

Tobias Wondwossen & Jayden Mingle

## 1. General Game Overview

Afro Fighter is a 2D side-view fighting game that puts players in control of an Afro fighter who appears on the right side of the screen. A 3-second countdown starts the fight, during which players must utilize a combination of punches, kicks, and fireballs to defeat their opponent on the left. Defense is also crucial, as players can block, jump, and crouch to avoid incoming attacks. The objective is to deplete the opponent's health from 100 to zero before one's own health is reduced, thereby determining the winner of the fight.

Future updates will feature a 2 - player game mode allowing players to put their skills to the test against their friends

![](https://i.imgur.com/tMmlcPl.png)

## 2. Game Play Details for 1-Player Mode

### 2.1 Menu UI and Logic

The game will launch into a menu screen with the Afro Fighters logo and two game mode options; `1-player` and `2-player`.

![image](https://user-images.githubusercontent.com/104709648/212567852-d2971d61-3278-4f28-ac5f-557cd35d1e47.png)

The `1-Player` mode commences with the player's avatar positioned on the right side of the arena, while the opponent is situated on the left, accompanied by their respective health/information bars. A countdown, starting from three, will be displayed in the center of the screen, with each number displayed for a duration of two seconds.

![](https://i.imgur.com/Mp5RDhZ.png)

![](https://i.imgur.com/5bb38LU.png)

![](https://i.imgur.com/PGRWsFq.png)

Upon completion of the countdown, the word "Fight" will be displayed in the center of the screen for a duration of two seconds. Player controls will then become active, and the opponent will begin executing its pre-programmed movements.

![](https://i.imgur.com/JyPtDz1.png)![](https://i.imgur.com/8DkxzaI.png)![](https://i.imgur.com/rRSmzBG.png)![](https://i.imgur.com/SMSt1A3.png)![](https://i.imgur.com/dSRuw2y.png)![](https://i.imgur.com/j2H7QlA.png)

#### 2.1.3 Game Over State and UI


There are two possible `Game Over` states, one for a `Win` and a `Loss`

***Win Message and UI FINISH WITH REAL SCREEN***

If the player has beat the opponent this message will remain on screen untill a the player has chosen on of the two menu options; `Play Again` or `Back to Main Menu`

![](https://i.imgur.com/bOs0tIC.png) ![reference link](https://i.imgur.com/7XuwVZi.png) ![](https://i.imgur.com/H5oTX9V.png) ![](https://i.imgur.com/Gclwat6.png) ![](https://i.imgur.com/xFpkm7w.png) ![](https://i.imgur.com/vrtQuKT.png) ![](https://i.imgur.com/dngkfqX.png)


***Loss Message and UI FINISH WITH REAL SCREEN***

If the player has beat the opponent this message will remain on screen untill a the player has chosen on of the two menu options; `Play Again` or `Back to Main Menu`

![](https://i.imgur.com/BVhPqyf.png) ![](https://i.imgur.com/hDfnbYJ.png) ![reference link](https://i.imgur.com/7XuwVZi.png) ![](https://i.imgur.com/JkajbXT.png) ![](https://i.imgur.com/gDGlXHh.png) 

![](https://i.imgur.com/fysz63A.png) ![](https://i.imgur.com/BVhPqyf.png) ![](https://i.imgur.com/BVhPqyf.png) ![](https://i.imgur.com/vY0S0ju.png) ![](https://i.imgur.com/xFpkm7w.png)

### 2.2 Objectives and Rules

#### 2.2.1 Combat Mechanics 

***Health***

In this game, both the player and their opponent start with a `250px` width health bar. The objective is to maintain one's own health bar, ensuring that it is not depleted before their opponent's. Each combat move has a distinct impact on the player's health, and it is crucial to execute these moves strategically to achieve victory.

***Offense and Defense***

|Offensive/Defensive Moves| Description | Damage (pixels removed from health) |Keybind|
|---------------|-------------|-------|:-----:|
| `Light Attack`| A straight punch |`-8px`|`W`| 
| `Heavy Attack`| A side kick |`-16px`|`←`|
| `Ranged / Super`| A projectile fireball |`-64px`|`F`|
| `Block`         | A boxing highguard          |Halves incoming damage from the above attacks|`→` (press and hold)  |

***Movement States***

| State | Description |Keybind|
|-------|-------------|:-------:|
|  `Idle` | Boxing "Orthodox Stance" |             `None / Default State`  |
| `Running`|Fast shuffle of feet, allowing player <br> to move either left or right across the screen by increments of `4 pixels`  |              <li>Right: `A` </li><li>Left: `D` </li> |
| `Jump`|   Allows player to change its y position. <br> Player can still change its x position in this state|              `Space`  |
| `Crouching`| Player goes down on one knee  |              `↓`  |
| `Slide`| If the player is `Running` and `Crouches` <br> at the same time they will `Slide` for as <br> long as they crouch |              `↓` if in `Running` state |

#### 2.2.2 Opponent

Since the Opponent isn't controlled by a user's inputs, it operates under the following states:

***Approach***

The `Opponent` will be facing the `Player` at all times. If the distance between the `Player` and the `Opponent` is greater than 50px, the `Opponent` Moves forward towards the player using the appropriate movement input.

***Combo***

This is the default state that the`Opponent` will be in. In this state, it will perform a series of moves that go as follows: 3x`Light Attack`, `Block`, `Heavy Attack`, `Crouch`, `Jump`, `Heavy Attack`, `Block`. Each move will be performed 1 second apart.


### 2.3 Scene Objects

*Note: Coordinates given are assuming `(0,0)` is the top left corner of the screen, and that sprites are drawn from their top left corner aswell.*

***Afro Fighter***

| Properties | States | Combat Moves | Image |
|------------|--------|-------|-------|
|<li>`Size`: 98px by 64px  </li><li>`Orientaion`: Upright <br>and   facing  right if it  is a  <br>player, left if it is the opponent  </li><li>Has `Hitbox` that is <br>equal  to its `size`</li><li>`x and y coordinates` <br> Intitaly at `(446, 264)` <br> for the player, `(100,264)` <br> for the opponent </li>           | <li>Idle</li><li>Running</li><li>Jumping</li><li>Sliding</li><li>Crouching</li>|<li>Light Attack</li><li>Heavy Attack</li><li>Super / Ranged</li><li>Block</li>     |<img src="https://i.imgur.com/HEpC0ON.png" width="150" > 

***Afro Fighter Mechanics***

*Movement Boundaries:*

The Afro Fighter has the capability to traverse the full width of the `640 pixel` arena by using any of its `movement states` as many times as desired. Its jump state will allow it to reach a maximum height of `164 pixels` from its `initial y-coordinate`. Furthermore Afro Fighter is restricted from descending below its default `y-coordinate of 264`, which marks the starting point of the `arena floor.`

The player and the opponent both have complete control over the direction the Afro Fighter faces. In the event that they come to close such that their `hit boxes collide`, they are unable to advance forward until one executes a jump over the other.

*Combat Rules*

All of the `Combat moves` but `Super / Ranged` can be used as many times as desired.

In order for the Afro Fighter to unlock its `Super / Ranged` ability it must block to consectutive `Heavy Attacks` from its opponent.

***Fire Ball Projectile***

| Properties | Behaviour|Image|
|----------|---------|-----|
|<ul><li>Position Integers, `x` and `y` coordinate  </li><li>`Size:` 50px by 80px </li><li>`Hit Box` is a rectangle with the same dimensions as its size</li></ul>   |Travels accross on screen`y-vector`until it undegoes a collision      |![](https://i.imgur.com/xooOTP9.png) `Source` "Pixel art maker"



***Health and Info Bar***


![](https://i.imgur.com/Wx2WMlJ.png)

| Object  | Properties     | Behaviour|Image|
|-------------|----------|---------|:-----:|
|`Health-bar` |<ul><li>`Size:` 250 x 36 px </li><li>`Position` integers, x and y coordinate</li></li></ul>   |Displays player health|![](https://i.imgur.com/5ha6Tac.png)
|`Avatar-Name`|<ul><li>`Size:` 26 x 8 px </li><li>`Position` integers, x and y coordinate</li></li></ul>      | Displays avatar name|![](https://i.imgur.com/DO5GOhO.png)|
|`Avatar-Profile-Img` |<ul><li>`Size:` 48 x 48 px </li><li>`Position` integers, x and y coordinate</li></li></ul>  |  Displays profile picture of avatar|![](https://i.imgur.com/qECScbN.png)|

***Arena***

| Object  | Properties     | Behaviour|Image|
|-------------|----------|---------|-----|
|`Arena-Floor` |<ul><li>`Size:` 640 x 48 px </li><li>`Position` Integers, x and y coordinate</li></li></ul>   | Displays arena floor  |![](https://i.imgur.com/iE2Cvvo.png)|
| `Arena`|<ul><li>`Size:` 640 x 400 px</li> | Displays `Health and info bar`,`Arena Floor` and `Background`| ![](https://i.imgur.com/uEZrZb2.png)


### 2.4 Animations
   
All player animations will have a left and right variant to account for the 2 directions a player can face.
    
***Movement Animations***


| Animation | Behaviour | Properties | Image / Sprite Sheet |
|-----------|------------|------------|:-----:|
| `Idle` | <li>A bobbing up and down movement</li> |<li>Size: `96 x 64 px` </li><li>Duration: 35/70th seconds per frame</li>| <img src="https://i.imgur.com/aW4mL7R.png" width="120"> <img src="https://i.imgur.com/02760L3.png" width="120" >
| `Running` | <li>A fast shuffle walk</li> |  <li>Size: `96 x 64 px` </li><li>Duration: 35/70th seconds per frame</li>  | <img src="https://i.imgur.com/q6j3Lmy.png" width="150" >    |      
| `Jumping "Lift-Off"` |  <li>Bending knees to prepare for a jump / brace after one</li>  |  <li>Size: `96 x 64 px` </li><li>Duration: 35/70th seconds per frame</li> |<img src="https://i.imgur.com/oA3GBhm.png" width="250" >    |  
| `Jump`  |  <li>An airborne rising motion </li>  |   <li>Size: `96 x 64 px` </li><li>Duration: 35/70th seconds per frame</li>`airborne boolean set true` |   <img src="https://i.imgur.com/Km4LfZc.png" width="80" > |       
| `Crouch`  |  <li>Kneeling position</li>  | <li>Size: `96 x 64 px` </li><li>Duration: 35/70th seconds per frame</li>   |<img src="https://i.imgur.com/47cTzWg.png" width="175" >    |      
| `Slide`   |  <li>A soccer slide tackle</li> |  <li>Size: `96 x 64 px` </li><li>Duration: 35/70th seconds per frame</li>  |  <img src="https://i.imgur.com/FTZTZgV.png" width="175" > |    
| `Death`    |  <li>A defeated lying down pose</li> |  <li>Size: `96 x 64 px` </li><li>Duration: 35/70th seconds per frame</li>  | <img src="https://i.imgur.com/kwd6p5p.png" width="175" >   |    

***Combat and Defense Animations***
    
| Animation | Behaviour | Properties | Image |
|-------------|----------|------------|:-----:|   
| `Light Attack`    |   <li>A straight punch</li> |          |  ![](https://i.imgur.com/9N9XBRJ.png)  |    
| `Heavy Attack`    |   <li>A side kick</li> |          | <img src="https://i.imgur.com/axsQb4j.png" width="200" >   |   
| `Super / Ranged Attack Imbue` |  <li>A fire charge-up pose</li>  |    | ![](https://i.imgur.com/nTVbiwi.png)   |      
| `Block`    |  <li>A boxing highguard</li>  |    |    <img src="https://i.imgur.com/hs9Qqv3.png" width="180" >|    
    
### 2.5 Asynchronous Events



#### 2.5.1 Movement Keybinds

    
|Movement    | Key Bind | Request|
|------------|----------|--------|
| Move right |  `A`     |  Changes `Running State` for player to `True`, sets `Rs Running Animation` to `True` |   
| Move left  |   `D`    |  Changes `Running State` for player to `True`, sets `Ls Running Animation` to `True` |    
| Slide      |   `↓`    |  Changes `Slide State` for player to `True`, sets `Ls or Rs slide animation` to `True` (base on orientation) |    
| Jump       |    `Space`| Changes `Jump State`  for player to `True`, sets `Ls or Rs jump animation`  to `True` (base on orientation) |    

#### 2.5.2 Combat Keybinds

|Combat Move    | Key Bind | Request|
|------------|----------|--------|
| Light attack (Alternating) |  `W`    |  Changes `Running State` for player to `True`, sets `Rs Running Animation` to `True` |   
| Heavy attack  |   `←`     |  Changes `Running State` for player to `True`, sets `Ls Running Animation` to `True` |    
| Super / Ranged attack     |   `F`     |  Changes `Slide State` for player to `True`, sets `Ls or Rs slide animation` to `True` (base on orientation) |    
| Block       |    `Space`| Changes `Jump State`  for player to `True`, sets `Ls or Rs jump animation`  to `True` (base on orientation) |    


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
| Event Name  | Triggering Input Event | Description|
|-------------|----------|---------|
| Intro prompt | 1 second between each part| "3,2,1, FIGHT!"|
|Opponent moveset| could be in condition based||

### 2.7 Condition Based Events
| Event Name  | Triggering Input Event | Description|
|-------------|----------|---------|
| `Health-Bar` Updates | A collision is detected following an attack input | The player who was hit by an attack has their healthbar decrease based on the damage values in 2.2.1 |
| `Hit-Marker` shows | A collision is detected following an attack input | The player who was hit by an attack has their in 2.2.1 |

### 2.8 Hypothetical Gaming Session

The user is given the choice of a 1-player or 2-player game on the title screen when the game first launches. When a game mode is selected, the screen switches to the relevant game version (as explained in sections 2 and 3).

Upon entering a game mode, the arena with the players and their respective healthbars will be displayed. A prompt reading "3, 2, 1, FIGHT!" will be appear and the player(s) will be given control of their respective characters. 

As described in 2.2.1, 2.2.2, and 2.5, the players will have different moves they can make based on the set inputs. A combination of attacks can be used to damage the opposing player. The match continues until one of the player's healthbars reach 0% and that player is on the ground. The player that is still standing is the winner. This results in a prompt reading "Player 1/Player 2 Wins!" according to the appropriate player. If both players happen to take each other out at the same time the prompt will read "Draw" instead.

After a winner is declared via the prompt, the user is sent back to the starting title screen.

## 3. Game Play details for 2-player Mode

All the gameplay elements of 1-Player Mode apply to 2-Player Mode but the CPU-Player is replaced with a second actual player. The second player will have the same moveset and controls as the first player

***P1 WINS***

![](https://i.imgur.com/qAcI2UJ.png)![](https://i.imgur.com/PGRWsFq.png) ![](https://i.imgur.com/RBf6Yg4.png)![](https://i.imgur.com/OExSDBs.png)![](https://i.imgur.com/WroOcSl.png)![](https://i.imgur.com/g5tGLTD.png)![](https://i.imgur.com/j2H7QlA.png)


***P2 WINS***

![](https://i.imgur.com/0hyXnLx.png)![](https://i.imgur.com/5bb38LU.png) ![](https://i.imgur.com/RBf6Yg4.png)![](https://i.imgur.com/OExSDBs.png)![](https://i.imgur.com/WroOcSl.png)![](https://i.imgur.com/g5tGLTD.png)![](https://i.imgur.com/j2H7QlA.png)

## 4. Sound Effects

| Sound effect name | Brief Description | Event that triggers playback |
| ------------- | ------------- | ------------- |
| Main Theme | "Help urself Dyn remix" found on youtube | User starts the game |
| Attack | "woosh" sound effect like swinging a bat through the air - duration of a second | any of the players inputs an attack key |
| Attack connects | sound of a boxing glove hitting a punching bag - duration of a second | any of the players inputs an attack key and a collision is detected |
| Super | charge up sound effect - duration of a second | Super/Ranged attack input is pressed |

## 5. Additional Features (Time Permitting)
   
#### 5.1.1 More attacks:
- crouching punch/kick
- jumping punch/kick
- elbow
- energy blast (smaller than ultimate move)

#### 5.1.2 Multiple rounds: 
A round is over when one of the players' healthbar reaches 0px. The first player with 2 ko's wins the match. The Number of player ko's is displayed next to their name and healthbar. If both players are tied in ko's entering the 3rd round and the 3rd round ends in a draw, a sudden death round will occur with both players having decreased health.

#### 5.1.3 Stun meter: 
As a player takes hits that aren't blocked, a meter next to the healthbar fills up. When this meter fills up, the next hit a player takes will knock them to the ground and put them in a state where they can't do anything for 2 seconds.

The meter will be 96px x 16px and will fill up at the following rates:

| Move  | Stun |
| ------------- | ------------- |
| `Light Attack` | +16px |
| `Heavy Attack`  | +24px |
| `Ranged / Super` | +48px |
 
#### 5.1.4 Finishing move:
When a player is knocked out at match point, the player that's still standing will have the option to perform a mortal kombat style finishing move.

 
#### 5.1.5 "Smarter" CPU:
The `Opponent` has a chance to perfectly counter the player by reading input. For example the real player could enter the input to punch and the cpu would block. Outside of this phase the CPU will perform actions based on distance to the player and a predetermined sequence of moves.

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
- better background (stack implementation to know when pixels are overlapping)
- psuedo 3d floor
- shaded characters

#### 5.1.10 More Accurate Hitboxes:


---







