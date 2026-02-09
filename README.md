🌿 IoT-Based Tobacco Curing Chamber

📌 Project Overview

The IoT-Based Tobacco Curing Chamber is a smart agricultural automation project designed to modernize the traditional tobacco curing process. Conventional curing methods rely heavily on burning firewood, require continuous manual labor, cause deforestation, and take 7–10 days to complete.

This project replaces the traditional approach with an automated, sensor-based curing system using ESP8266, temperature and humidity control, heater coils, and exhaust fans, all monitored and configured through a web application integrated with Firebase.

The system reduces curing time to 4 days, eliminates the use of firewood, minimizes labor health risks, and ensures consistent curing quality.

🎯 Objectives

Automate tobacco curing using IoT

Maintain precise temperature and humidity levels

Reduce curing time from 7–10 days to 4 days

Eliminate wood usage and prevent deforestation

Allow remote temperature scheduling through a web page

Improve worker safety and curing consistency

🌱 Problems in Traditional Tobacco Curing

Large-scale deforestation due to firewood usage

High labor effort and exposure to smoke and heat

Poor temperature and humidity control

Longer curing duration

Inconsistent quality of cured tobacco leaves

💡 Proposed Smart Solution

The IoT-based curing chamber uses:

Heater coils for controlled heat generation

Draft fan to distribute heat uniformly

Top exhaust fan to remove excess moisture and humid air

PT100 temperature sensor for accurate temperature measurement

ESP8266 (NodeMCU) for IoT connectivity

Web page with Firebase to set temperature values day-wise

🛠️ Hardware Components Used
Component	Description
ESP8266 (NodeMCU)	Main IoT controller
PT100 Temperature Sensor	Accurate temperature sensing
Humidity Sensor	Detects moisture content
Heater Coils	Generates required heat
Draft Fan	Circulates hot air
Top Exhaust Fan	Removes humid air
Relay Module	Controls heaters and fans
Power Supply	System power
🌐 Software & Technologies

Arduino IDE

Embedded C / C++

Firebase Realtime Database

Web Page (HTML/CSS/JS)

ESP8266 Wi-Fi communication

🔌 Working Principle
🔥 Temperature Control

If chamber temperature falls below the set value:

Heater coils turn ON

Draft fan turns ON to distribute heat

If temperature reaches the desired value:

Heater coils turn OFF

💨 Humidity Control

If humidity at the top of the chamber becomes too high:

Top exhaust fan turns ON

Excess moisture and unwanted air are pushed out

🌍 Remote Control

Temperature values are set through a web page

Data is stored and synced using Firebase

ESP8266 fetches real-time setpoints automatically

📅 Day-Wise Temperature Scheduling
Day	Temperature Setpoint
Day 1	55°C
Day 2	49°C
Day 3	38°C
Day 4	30°C

These values can be modified remotely using the web interface.

🔁 System Flow

User sets temperature values on web page

Firebase updates real-time database

ESP8266 reads temperature setpoint

PT100 sensor measures chamber temperature

Heater & fans operate automatically

Humidity is controlled using top exhaust fan

📈 Results & Performance
Parameter	Traditional Method	Proposed System
Curing Time	7–10 days	4 days
Wood Usage	High	Zero
Labor Risk	High	Low
Temperature Accuracy	Poor	High
Environmental Impact	High	Eco-friendly
🌍 Environmental & Social Impact

🌳 Prevents deforestation (no firewood)

👷 Improves labor safety (less smoke & heat exposure)

⚡ Energy-efficient curing

📉 Reduces curing losses

📈 Improves tobacco quality consistency

📦 Applications

Tobacco curing chambers

Agricultural drying systems

Herbal leaf drying

Smart agro-processing units

⚠️ Limitations

Requires stable power supply

Internet connectivity needed for web control

Single-chamber implementation

🚀 Future Enhancements

Mobile application support

Multiple chamber control

Automated humidity scheduling

Solar power integration

Data analytics for curing optimization

📸 Project Outputs

✔️ Fully working curing chamber prototype

✔️ Web page with Firebase integration

✔️ Project demonstration video

✔️ Group photographs

✔️ Project completion certificate

🏁 Conclusion

The IoT-Based Tobacco Curing Chamber demonstrates how smart automation can replace traditional, inefficient, and environmentally harmful agricultural practices. By integrating IoT, sensors, and web-based control, the project achieves faster curing, better quality, reduced labor risk, and zero deforestation.

“Smart agriculture is not just about automation—it’s about sustainability.”
