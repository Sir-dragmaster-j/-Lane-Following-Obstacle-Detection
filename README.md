<p align="center">
  <img src="https://img.icons8.com/?size=200&id=102356&format=png&color=FF1E1E" width="120"/>
</p>

<h1 align="center">🚗🧱 Autonomous Lane Following + Obstacle Avoidance Robot</h1>
<p align="center"><b>Intelligent Embedded C Robot with IR-Based Lane Tracking & Ultrasonic Obstacle Evasion</b></p>

<p align="center">
  <img src="https://img.shields.io/badge/Arduino-UNO/Mega-blue?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Sensors-IR_+_Ultrasonic-green?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Motor_Driver-L298N/TB6612-red?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Language-Embedded_C-yellow?style=for-the-badge" />
</p>

---

## 🧠 Overview  
A smart **autonomous robot** capable of following lanes using IR sensors and avoiding obstacles using an **HC-SR04 ultrasonic sensor**.  
The robot bypasses obstacles intelligently and returns to the lane — showcasing core robotics concepts like **real-time control**, **sensor fusion**, and **autonomous decision-making**.

---

## ✨ Highlight Features  
- 🛣️ **Lane Following** using dual IR sensors  
- 🚧 **Obstacle Detection** with ultrasonic distance sensing  
- 🤖 **Auto Bypass Logic** (stop → steer → bypass → rejoin lane)  
- 🔄 **Dynamic correction** based on sensor input  
- 💡 **Beginner-friendly & low-cost embedded system**  

---

## 🔌 Hardware Components  
- 🧠 Arduino UNO / Mega  
- ⚡ L298N or TB6612 Motor Driver  
- 🔋 2 × DC Motors  
- ⚫ 2 × IR Sensors (Line Tracking)  
- 📡 HC-SR04 Ultrasonic Sensor  
- 🔋 Battery Pack (7.4V–12V)

---

## 🧩 Working Principle  

### 🔍 1. Lane Following  
| IR Left | IR Right | Action |
|---------|----------|--------|
| 1 | 1 | Move Forward |
| 0 | 1 | Turn Left |
| 1 | 0 | Turn Right |
| 0 | 0 | Stop / Search |

### 🚧 2. Obstacle Detection  
- Ultrasonic sensor continuously measures distance.  
- If obstacle detected within threshold → **Stop → Avoid → Bypass**.

### 🔄 3. Return to Lane  
- After bypassing, robot re-aligns with the lane automatically and resumes forward motion.

---

## 🪄 How to Use  
1. Build the circuit with IR + Ultrasonic + Motor Driver + Arduino.  
2. Upload the provided Embedded C code to the board.  
3. Place the robot on a line-marked track.  
4. Power ON → Robot follows lane → Detects obstacles → Avoids them → Returns to lane.

---

## 🧰 Troubleshooting Guide  

| Issue | Cause | Fix |
|-------|--------|------|
| Bot not following line | Weak contrast | Thicker/darker tape |
| Obstacle not detected | Sensor misaligned | Adjust sensor angle |
| Motors not running | Wrong motor driver wiring | Recheck enable pins |
| Random distance readings | Reflective surface | Add small delays |

---

## 🧪 Recommended Thresholds  
- Ultrasonic detection distance: **15–20 cm**  
- IR sensitivity: Adjust trim pot until stable on track  
- Motor PWM: 120–180 for smooth turning  

---

## 👨‍💻 Author  
**Sujay J**  
📧 Email: *sujayj777@gmail.com*  
🔗 GitHub: https://github.com/Sir-dragmaster-j  
💼 LinkedIn: https://www.linkedin.com/in/sujay-j-b59959357  

---

<p align="center"><b>✔️ A compact, smart, and stylish embedded robotics project ready for GitHub portfolios & mini-project submissions.</b></p>

