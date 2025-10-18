# 🐍 Embedded System Design for a Real-Time Snake Game Using the 8051-Based AT89C52 Microcontroller

A classic **Snake Game** implemented on the **AT89C52 microcontroller** (8051 family) and displayed on an **8×8 LED matrix**.  
The project combines **Proteus simulation** and a **fully working hardware prototype**, showcasing real-time embedded logic, LED multiplexing, and directional control.

---

## 🧩 Project Overview

This project demonstrates how a simple yet interactive **real-time game** can be implemented using microcontroller logic and LED display multiplexing.  
It recreates the retro **Snake Game** where the snake moves based on user input and resets upon collision with itself or the boundary.

Key highlights:
- Hardware and software co-design  
- Real-time embedded control using C  
- Simulation and hardware validation  
- Visual output via LED matrix scanning  

---

## ⚙️ Hardware Components

| Component | Description |
|------------|-------------|
| **AT89C52 Microcontroller** | 8051-based MCU controlling display and logic |
| **8×8 LED Matrix (1588BS)** | Visual output for snake movement |
| **Push Buttons (K1–K4)** | Directional input: Up, Down, Left, Right |
| **Crystal Oscillator (12 MHz)** | Provides system clock for MCU |
| **Resistors (1 kΩ)** | Current limiting for LED matrix |
| **Capacitors (30 pF, 10 µF)** | Stabilization for power and clock |
| **Reset Switch (S1)** | Resets MCU or game state |
| **5 V DC Supply** | Power source for the system |

---

## 💻 Software Implementation

### Key Files
| File | Description |
|------|--------------|
| `Snake.c` | Main C source code implementing the game logic |
| `STARTUP.A51` | Keil startup assembly file |
| `.uvproj`, `.uvopt` | Keil µVision project configuration files |
| `.pdsprj` | Proteus simulation project file |

### Major Functions
| Function | Purpose |
|-----------|----------|
| `delay()` | Controls LED refresh and game speed |
| `mux()` | Maps coordinates to LED bit masks |
| `timer0()` | Handles LED scanning and snake movement display |
| `turnkey()` | Reads button inputs to change direction |
| `knock()` | Detects collision with wall or self |
| `main()` | Game initialization and loop control |

---

## 🕹️ Game Logic Flow

1. **Initialization**  
   - Snake starts with 3 segments centered on the LED matrix.  
   - Speed and direction are initialized.  

2. **Movement**  
   - Snake moves based on `addx` and `addy` (direction vectors).  
   - LED matrix dynamically refreshes to show motion.  

3. **Input Handling**  
   - Directional buttons on Port 2 change snake direction.  

4. **Collision Detection**  
   - `knock()` checks if the head touches boundary or body.  
   - On collision → resets game and restores speed.  

5. **Progressive Speed**  
   - Each successful round reduces delay, increasing difficulty.

---

## 🔧 Hardware Prototype and Simulation

This project was developed and tested in **two stages**:

### 🧩 1. Proteus Simulation
- Designed and simulated in **Proteus 8** to validate circuit connections and software logic.  
- Includes accurate modeling of the **AT89C52**, **LED matrix**, **directional keys**, and **reset circuitry**.  
- The simulation demonstrates real-time snake movement, direction control, and collision response.
![Schematic](https://github.com/pratik001010/Embedded-System-Design-for-a-Real-Time-Snake-Game-on-AT89C52-Microcontroller/blob/f756664d0c40feedb5dc7d3aa5c2dd94a0756b7d/my%20annaconda%20don/SNAKE.png)

### ⚙️ 2. Real Hardware Prototype
- Built and tested on a **physical AT89C52 microcontroller board**.  
- 8×8 LED matrix connected through current-limiting resistors and directly driven via Port 0 and Port 1.  
- Directional control achieved using **tactile push buttons** connected to Port 2.  
- Powered via 5 V regulated DC supply and clocked using a **12 MHz crystal oscillator**.  
- Fully functional — real snake movement visible on LEDs, matching the simulation behavior.

### 🖼️ Demo Gallery
You can include:

```markdown
![Hardware Prototype](prototype.jpg)
![Proteus Simulation](simulation.png)
