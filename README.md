# 🚗 Lane Following + 🧱 Obstacle Detection  

> **One-line:** An embedded C-based robot that follows a lane using IR sensors and automatically bypasses obstacles using an ultrasonic sensor before returning to the lane.

---

## 🧠 Overview  

This project demonstrates a simple and efficient **lane-following and obstacle detection** system using **two IR sensors** and **one ultrasonic sensor**.  
The car follows a black line on a white surface. When it detects an obstacle in front, it automatically moves aside, avoids it, and returns to the lane to continue its journey.

This project showcases the basics of **autonomous navigation**, **sensor-based control**, and **decision-making** in embedded systems.

---

## ✨ Features  

- 🛣️ **Lane Following:** Uses two IR sensors to stay on track.  
- 🚧 **Obstacle Detection:** Ultrasonic sensor detects obstacles ahead.  
- 🤖 **Automatic Avoidance:** Car moves aside, bypasses, and rejoins the lane.  
- ⚙️ **Compatible Hardware:** Works on Arduino UNO / Mega.  
- 🔋 **Low-Cost Implementation:** Simple yet reliable logic.  

---

## 🔌 Hardware Components  

- 🧠 Arduino UNO / Mega  
- ⚡ L298N or TB6612 Motor Driver  
- 🚗 2 DC Motors  
- ⚫ 2 IR Sensors  
- 📡 HC-SR04 Ultrasonic Sensor  
- 🔋 Battery Pack / Power Supply  

---

## 🧩 Working Principle  

1. **Lane Detection:**  
   - Both IR sensors on track → car moves forward.  
   - Left sensor off track → car turns left.  
   - Right sensor off track → car turns right.  

2. **Obstacle Detection & Avoidance:**  
   - Ultrasonic sensor measures distance ahead.  
   - If an obstacle is detected (within threshold distance), the car stops and steers to one side to bypass.  
   - Once clear, it realigns with the lane and resumes normal operation.  

3. **Return to Line:**  
   - After bypassing, the car detects the lane again and continues following the path.

---

## 🪄 How to Use  

1. Connect all sensors and motors as per your circuit design.  
2. Upload the Embedded C code to your Arduino board.  
3. Place the car on a lane-marked surface.  
4. Power it up — it will automatically follow the lane, detect obstacles, move aside, and come back to line!  

---

## 🧰 Troubleshooting  

- ⚙️ **Line following unstable:** Adjust IR sensor position and track contrast.  
- 🚧 **Doesn’t avoid obstacles:** Check ultrasonic sensor distance threshold and angle.  
- 🔋 **Motors not moving:** Ensure proper motor driver wiring and power supply.  
- 🌫️ **False ultrasonic readings:** Avoid reflective surfaces or measure sensor timing delay.  

---

## 👨‍💻 Author  

**Sujay J**  
🔗 [GitHub](https://github.com/Sir-dragmaster-j)  
💼 [LinkedIn](https://www.linkedin.com/in/sujay-j-b59959357)

---

✅ *A compact and smart embedded C project combining IR-based lane following with ultrasonic obstacle avoidance.*
